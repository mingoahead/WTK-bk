#include "FastMarching.h"

FastMarching::FastMarching(void)
{
    set_input_image("");
    set_output_image("");
    set_lower_threshold(0.0);

    // lower time threshold
    lower_threshold = 0.0;

    // background: black
    // foreground: white
    set_inside_value(255);
    set_outside_value(0);

    // smooth filter
    set_smooth_timestep(0.125);
    set_smooth_iterations(1);
    set_smooth_conductance(9.0);

    // seeds
    try {
        seeds = NodeContainer::New();
        seeds->Initialize();
    } catch ( itk::ExceptionObject & excep ) {
        std::cerr << "Exception caught !" << std::endl;
        std::cerr << excep << std::endl;
        return;
    }
}

FastMarching::~FastMarching(void)
{
}

bool FastMarching::Perform()
{
    /************************************************************************/
    /* flowchart : doc/InsightSoftwareGuide-Book2-4.7.1.pdf Figure 4.15     */
    /************************************************************************/

    try {
        // register IO
        // references:
        // 1. http://itk.org/ITKExamples/src/IO/ImageBase/ReadUnknownImageType/Documentation.html
        // 2. http://itk.org/ITKExamples/src/IO/ImageBase/RegisterIOFactories/Documentation.html#results
        itk::MetaImageIOFactory::RegisterOneFactory();

        // set reader & writer
        ReaderType::Pointer reader = ReaderType::New();
        reader->SetFileName( input_image.c_str() );
        WriterType::Pointer writer = WriterType::New();
        writer->SetFileName( output_image.c_str() );

        // smoothing filter
        SmoothingFilterType::Pointer smoothing = SmoothingFilterType::New();

        // gradient filter
        GradientFilterType::Pointer  gradientMagnitude = GradientFilterType::New();

        // sigmoid filter
        // references:
        // 1. http://www.52cs.org/?p=363
        SigmoidFilterType::Pointer sigmoid = SigmoidFilterType::New();
        sigmoid->SetOutputMinimum(  0.0  );
        sigmoid->SetOutputMaximum(  1.0  );

        // fast-marching filter
        FastMarchingFilterType::Pointer fastMarching = FastMarchingFilterType::New();

        // threshold filter
        ThresholdingFilterType::Pointer thresholder = ThresholdingFilterType::New();
        thresholder->SetLowerThreshold( lower_threshold );
        thresholder->SetUpperThreshold( upper_threshold );
        thresholder->SetOutsideValue( outside_value );
        thresholder->SetInsideValue( inside_value );

        // set pipeline
        smoothing->SetInput( reader->GetOutput() );
        gradientMagnitude->SetInput( smoothing->GetOutput() );
        sigmoid->SetInput( gradientMagnitude->GetOutput() );
        fastMarching->SetInput( sigmoid->GetOutput() );
        thresholder->SetInput( fastMarching->GetOutput() );
        writer->SetInput( thresholder->GetOutput() );

        // CurvatureAnisotropicDiffusionImageFilter
        smoothing->SetTimeStep( smooth_timestep );
        smoothing->SetNumberOfIterations( smooth_iterations );
        smoothing->SetConductanceParameter( smooth_conductance );

        // GradientMagnitudeRecursiveGaussianImageFilter
        gradientMagnitude->SetSigma( guassian_sigma );

        sigmoid->SetAlpha( sigmoid_alpha );
        sigmoid->SetBeta( sigmoid_beta );

        // prepare nodes
        fastMarching->SetTrialPoints( seeds );

        // TODOs: intermediate outputs
        fastMarching->SetOutputSize( reader->GetOutput()->GetBufferedRegion().GetSize() );
        fastMarching->SetStoppingValue(  stopping_time  );

        // execution of the pipeline
        writer->Update();
    } catch ( itk::ExceptionObject & excep ) {
        std::cerr << "Exception caught !" << std::endl;
        std::cerr << excep << std::endl;
        return false;
    }

    return true;
}

/// add a new seed of (pos_x, pos_y)
void FastMarching::AddSeed(unsigned int pos_x, unsigned int pos_y)
{
    InternalImageType::IndexType  seed_position;
    seed_position[0] = pos_x;
    seed_position[1] = pos_y;

    NodeType node;
    double seed_value = 0.0;
    node.SetValue( seed_value );
    node.SetIndex( seed_position );

    seeds->InsertElement( seeds->Size(), node );
}

/// remove all seeds
void FastMarching::ClearSeeds(void)
{
    seeds->clear();
}

unsigned int FastMarching::SeedSize(void)
{
    return seeds->Size();
}

/// TODO: remove a seed of (pos_x, pos_y)
void FastMarching::RemoveSeed(unsigned int pos_x, unsigned int pos_y)
{
}
