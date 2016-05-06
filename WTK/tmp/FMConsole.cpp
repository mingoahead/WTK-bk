# include "FMConsole.h"

FMConsole::FMConsole()
{
    m_outputImage = "Output.png";
    m_smoothImage = "Output_smooth.png";
    m_GMImage = "Ouput_GM.png";
    m_sigmoidImage = "Output_sigmoid.png";
    m_FMoutputImage = "Output_timestep.png";
    m_overlayOutputImage = "Output_overlay.png";

	m_sigmaGM = 1.2;

	m_alphaSigmoid = -1.0;
	m_betaSigmoid = 5.0;

	m_stoppingTime = 90;

	m_timeThreshold = 100.0;

    m_nItersSmooth = 20;
    m_timeStepSmooth = 0.125;
    m_conductanceSmooth = 2.0;

    m_labelOpacity = 0.5;
}

FMConsole::~FMConsole()
{
    //
}

int FMConsole::BuildSeedContainer(NodeContainer::Pointer &seeds)
{
    NodeType node;
    InternalImageType::IndexType  seedPosition;
    for (PointSet::iterator it = seedSet.begin(); it != seedSet.end(); ++it) {
        seedPosition[0] = it->x;
        seedPosition[1] = it->y;
        node.SetValue( kSeedValue );
        node.SetIndex( seedPosition );
        seeds->InsertElement( seeds->Size(), node );
    }
    return seeds->Size();
}

bool FMConsole::Run()
{
    try {
        ReaderType::Pointer reader = ReaderType::New();
        WriterType::Pointer writer = WriterType::New();
        reader->SetFileName( m_inputImage.c_str() );
        writer->SetFileName( m_outputImage.c_str() );

        SmoothingFilterType::Pointer smoothing = SmoothingFilterType::New();

        GradientFilterType::Pointer  gradientMagnitude = GradientFilterType::New();

        SigmoidFilterType::Pointer sigmoid = SigmoidFilterType::New();
        sigmoid->SetOutputMinimum(  0.0  );
        sigmoid->SetOutputMaximum(  1.0  );

        FastMarchingFilterType::Pointer  fastMarching = FastMarchingFilterType::New();

        ThresholdingFilterType::Pointer thresholder = ThresholdingFilterType::New();
        thresholder->SetLowerThreshold(             0.0 );
        thresholder->SetUpperThreshold( m_timeThreshold );
        thresholder->SetOutsideValue(  0  );
        thresholder->SetInsideValue(  255 );

        smoothing->SetInput( reader->GetOutput() );
        gradientMagnitude->SetInput( smoothing->GetOutput() );
        sigmoid->SetInput( gradientMagnitude->GetOutput() );
        fastMarching->SetInput( sigmoid->GetOutput() );
        thresholder->SetInput( fastMarching->GetOutput() );
        writer->SetInput( thresholder->GetOutput() );

        smoothing->SetTimeStep( m_timeStepSmooth );
        smoothing->SetNumberOfIterations( m_nItersSmooth );
        smoothing->SetConductanceParameter( m_conductanceSmooth );

        gradientMagnitude->SetSigma(  m_sigmaGM  );

        sigmoid->SetAlpha( m_alphaSigmoid );
        sigmoid->SetBeta( m_betaSigmoid );

        // set seeds
        NodeContainer::Pointer seeds = NodeContainer::New();
        seeds->Initialize();
        BuildSeedContainer( seeds );

        fastMarching->SetTrialPoints(  seeds  );

        // smoothingOutputImage
        CastFilterType::Pointer caster1 = CastFilterType::New();
        WriterType::Pointer writer1 = WriterType::New();
        caster1->SetInput( smoothing->GetOutput() );
        writer1->SetInput( caster1->GetOutput() );
        writer1->SetFileName( m_smoothImage.c_str() );
        caster1->SetOutputMinimum(   0 );
        caster1->SetOutputMaximum( 255 );
        writer1->Update();
        // gradientMagnitudeOutputImage
        CastFilterType::Pointer caster2 = CastFilterType::New();
        WriterType::Pointer writer2 = WriterType::New();
        caster2->SetInput( gradientMagnitude->GetOutput() );
        writer2->SetInput( caster2->GetOutput() );
        writer2->SetFileName( m_GMImage.c_str() );
        caster2->SetOutputMinimum(   0 );
        caster2->SetOutputMaximum( 255 );
        writer2->Update();
        // sigmoidOutputImage
        CastFilterType::Pointer caster3 = CastFilterType::New();
        WriterType::Pointer writer3 = WriterType::New();
        caster3->SetInput( sigmoid->GetOutput() );
        writer3->SetInput( caster3->GetOutput() );
        writer3->SetFileName( m_sigmoidImage.c_str() );
        caster3->SetOutputMinimum(   0 );
        caster3->SetOutputMaximum( 255 );
        writer3->Update();

        fastMarching->SetOutputSize( reader->GetOutput()->GetBufferedRegion().GetSize() );

        fastMarching->SetStoppingValue( m_stoppingTime  );

        writer->Update();

        // fast
        CastFilterType::Pointer caster4 = CastFilterType::New();
        WriterType::Pointer writer4 = WriterType::New();
        caster4->SetInput( fastMarching->GetOutput() );
        writer4->SetInput( caster4->GetOutput() );
        writer4->SetFileName( m_FMoutputImage.c_str() );
        caster4->SetOutputMinimum(   0 );
        caster4->SetOutputMaximum( 255 );
        writer4->Update();

        // overlay output
        LabelReaderType::Pointer featureReader = LabelReaderType::New();
        featureReader->SetFileName( m_inputImage.c_str() );
        LabelReaderType::Pointer labelReader = LabelReaderType::New();
        labelReader->SetFileName( m_outputImage.c_str() );
		LabelConverterType::Pointer labelConverter = LabelConverterType::New();
		labelConverter->SetInput( labelReader->GetOutput() );
		LabelFilterType::Pointer labelFilter = LabelFilterType::New();
		labelFilter->SetInput( labelConverter->GetOutput() );
		labelFilter->SetFeatureImage( featureReader->GetOutput() );
		labelFilter->SetOpacity( m_labelOpacity );
		LabelWriterType::Pointer labelWriter = LabelWriterType::New();
		labelWriter->SetFileName( m_overlayOutputImage.c_str() );
		labelWriter->SetInput( labelFilter->GetOutput() );
		labelWriter->Update();
    } catch ( itk::ExceptionObject & err ) {
        std::cerr << "ExceptionObject caught !" << std::endl;
        std::cerr << err << std::endl;
        return false;
    }
    std::cout << "FMConsole::Run() success !" << std::endl;
    return true;
}
