# include "FMBase.h"


FMBase::FMBase()
{
    m_ImageReader = ImageReaderType::New();
    m_ImageWriter = ImageWriterType::New();

    m_CastImageFilter = CastImageFilterType::New();
    m_CastImageFilter->SetInput( m_ImageReader->GetOutput() );

    m_SmoothFilter = SmoothingFilterType::New();
    m_SmoothFilter->SetInput( m_CastImageFilter->GetOutput() );
    m_SmoothFilter->SetTimeStep( pow(0.5, ImageDimension + 1) ); 

    m_DerivativeFilter = DerivativeFilterType::New();
    m_DerivativeFilter->SetInput( m_SmoothFilter->GetOutput() );

    m_SigmoidFilter = SigmoidFilterType::New();
    m_SigmoidFilter->SetInput( m_DerivativeFilter->GetOutput() );
    m_SigmoidFilter->SetOutputMinimum( 0.0 );
    m_SigmoidFilter->SetOutputMaximum( 1.0 );

    m_FastMarchingFilter = FastMarchingFilterType::New();
    m_FastMarchingFilter->SetInput( m_SigmoidFilter->GetOutput() );

    m_SeedValue = 0.0;

    m_FastMarchingWindowingFilter = FastMarchingWindowingFilterType::New();
    m_FastMarchingWindowingFilter->SetInput( m_FastMarchingFilter->GetOutput() );
    m_FastMarchingWindowingFilter->SetWindowMinimum( m_SeedValue );
    m_FastMarchingWindowingFilter->SetWindowMaximum( m_FastMarchingFilter->GetStoppingValue() );
    m_FastMarchingWindowingFilter->SetOutputMinimum( m_SeedValue );
    m_FastMarchingWindowingFilter->SetOutputMaximum( m_FastMarchingFilter->GetStoppingValue() );

    m_ThresholdFilter = ThresholdFilterType::New();
    m_ThresholdFilter->SetInput( m_FastMarchingWindowingFilter->GetOutput() );
    m_ThresholdFilter->SetInsideValue(   1 );
    m_ThresholdFilter->SetOutsideValue(  0 );

    m_ImageWriter->SetInput( m_ThresholdFilter->GetOutput() );

    m_TrialPoints = NodeContainer::New();
    m_FastMarchingFilter->SetTrialPoints( m_TrialPoints );

    m_NumberOfSeeds = 0;

    m_InputImageIsLoaded  = false;

    m_DerivativeIterNums = 1;
}


FMBase::~FMBase(){}


/************************************
 *
 *  Load Input Image
 *
 ***********************************/
void FMBase::LoadInputImage( const char * filename )
{
    if( !filename ) {
        return;
    }

    //  所需的 ITK IO 工厂类由 utils/RegisterAllFactories.h 注册
    try {
        m_ImageReader->SetFileName( filename );
        m_ImageReader->Update();

        InputImageType::RegionType region = m_ImageReader->GetOutput()->GetBufferedRegion();

        InputImageType::SizeType size = region.GetSize();

        for (unsigned int i = 0; i < ImageDimension; ++i) {
            if( size[i] < 10 ) {
                this->ShowStatus("Image must be 2D and with at least 10 pixels along each Dimension.");
                itk::ExceptionObject excp;
                excp.SetDescription("Image must be 2D and with at least 10 pixels along each Dimension.");
                throw excp;
            }
        }

        m_InputImageIsLoaded = true;

        m_FastMarchingFilter->SetOutputSize( m_ImageReader->GetOutput()->GetBufferedRegion().GetSize() );
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::LoadInputImage( const char * filename ),  filename = \""
                  << filename
                  << "\""
                  << std::endl;
    }
}


/************************************
 *
 *  Save Output Image
 *
 ***********************************/
void FMBase::SaveOutputImage( const char * filename )
{
    if( !filename ) {
        return;
    }

    try {
        m_ImageWriter->SetFileName( filename );
        m_ImageWriter->Update();
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::SaveOutputImage( const char * filename ),  filename = \""
                  << filename
                  << "\""
                  << std::endl;
    }
}


/************************************
 *
 *  Clear Seeds
 *
 ***********************************/
void FMBase::ClearSeeds()
{
    try {
        m_TrialPoints->Initialize();
        m_FastMarchingFilter->Modified();
        m_NumberOfSeeds = 0;
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::ClearSeeds() "<< std::endl;
    }
}


/************************************
 *
 *  Add a seed
 *
 ***********************************/
void FMBase::AddSeed( const IndexType & seedPosition  )
{
    try {
        // setup trial points
        NodeType node;

        node.SetValue( m_SeedValue );
        node.SetIndex( seedPosition );

        m_TrialPoints->InsertElement( m_NumberOfSeeds, node );
        m_FastMarchingFilter->Modified();
        m_NumberOfSeeds++;
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::AddSeed( const IndexType & seedPosition  )" << std::endl;
    }
}

/************************************
 *
 *  Compute Curvature Anisotropic Diffusion
 *
 ***********************************/
void FMBase::ComputeCurvatureAnisotropicDiffusion(void)
{
    try {
        this->ShowStatus("Running Curvature Anisotropic Diffusion");
        m_SmoothFilter->UpdateLargestPossibleRegion();
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::ComputCurvatureAnisotropicDiffusion( void )" << std::endl;
    }
}


/************************************
 *
 *  Compute Gradient Magnitude
 *
 ***********************************/
void FMBase::ComputeGradientMagnitude( void )
{
    try {
        this->ShowStatus("Computing Gradient Image");
        m_DerivativeFilter->UpdateLargestPossibleRegion();
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::ComputeGradientMagnitude( void )" << std::endl;
    }
}


/************************************
 *
 *  Compute Edge Potential Image
 *
 ***********************************/
void FMBase::ComputeEdgePotential( void )
{
    try {
        this->ComputeGradientMagnitude();
        this->ShowStatus("Computing Edge Potential Image");
        m_SigmoidFilter->UpdateLargestPossibleRegion();
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::ComputeEdgePotential( void )" << std::endl;
    }
}


/***********************************************************
 *
 *   Set the stopping value of the FastMarching and update
 *   the value for the subsequent intensity window filter.
 *
 ***********************************************************/
void FMBase::SetStoppingValue( double value )
{
    try {
        m_FastMarchingFilter->SetStoppingValue( value );
        m_FastMarchingWindowingFilter->SetWindowMaximum( value );
        m_FastMarchingWindowingFilter->SetOutputMaximum( value );
    } catch (itk::ExceptionObject & excp) {
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::SetStoppingValue( double value )" << std::endl;
    }
}


/************************************
 *
 *  Start Segmentation
 *
 ***********************************/
void FMBase::RunFastMarching( void )
{
    // update the marching filter
    try {
        this->ComputeGradientMagnitude();
        this->ShowStatus("Computing Fast Marching Filter");
        m_FastMarchingWindowingFilter->UpdateLargestPossibleRegion();
    } catch( itk::ExceptionObject & excp ) {
# ifdef _DEBUG
        // 仅在调试模式下打开
        fl_alert( excp.GetDescription() );
# endif
        std::cerr << excp << std::endl;
    } catch (...) {
        std::cerr << "Exception: void FMBase::RunFastMarching( void )" << std::endl;
    }
}


/************************************
 *
 *  Stop Segmentation
 *
 ***********************************/
void FMBase::Stop( void )
{
    // TODO: add a Stop() method to Filters
}
