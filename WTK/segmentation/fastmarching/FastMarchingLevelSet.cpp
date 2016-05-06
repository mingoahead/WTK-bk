# include <FL/Fl_File_Chooser.H>
# include "FastMarchingLevelSet.h"
# include "vtkSmartPointer.h"
# include "vtkMetaImageWriter.h"

/************************************
 *
 *  Constructor
 *
 ***********************************/
FastMarchingLevelSet::FastMarchingLevelSet()
{
    // This image is only used for providing visual
    // feedback to the user. The actual structure
    // holding the seeds is in the base class.
    try {
		m_SmoothFilter = vtkSmoothPolyDataFilter::New();

        m_MaskFilter = MaskFilterType::New();

        m_SeedImage = SeedImageType::New();

        m_InputImageViewer.SetLabel("Input Image");

        m_ThresholdedImageViewer.SetLabel("Thresholded Image");

        m_SegmentationImageViewer.SetLabel("Segmented Image");
        m_SegmentationImageViewer.SetOverlayOpacity( 0.5 );

        m_GradientMagnitudeImageViewer.SetLabel("Gradient Magnitude Image");

        m_EdgePotentialImageViewer.SetLabel("Edge Potential Image");

        m_InputImageViewer.ClickSelectCallBack( ClickSelectCallback, (void *)this);

        // Initialize ITK filter with GUI values
        m_ThresholdFilter->SetLowerThreshold( static_cast<InternalPixelType>( lowerThresholdValueInput->value() ) );

        m_ThresholdFilter->SetUpperThreshold( static_cast<InputPixelType>( upperThresholdValueInput->value() ) );

        m_DerivativeFilter->SetSigma( sigmaValueInput->value() );

        m_SigmoidFilter->SetAlpha( alphaValueInput->value() );
        m_SigmoidFilter->SetBeta(  betaValueInput->value()  );

        this->SetStoppingValue( stoppingValueInput->value() );

        m_VTKSegmentedImageViewer = VTKImageViewerType::New();
        m_VTKSegmentedImageViewer->SetImage( m_MaskFilter->GetOutput() );

        m_TimeCrossingMapViewer.SetLabel("Time Crossing Map");

        // Connect Observers in the GUI
        inputImageButton->Observe( m_ImageReader.GetPointer() );
        thresholdedImageButton->Observe( m_ThresholdFilter.GetPointer() );
        segmentedImageButton->Observe( m_ThresholdFilter.GetPointer() );
        thresholdedImageVTKButton->Observe( m_ThresholdFilter.GetPointer() );
        timeCrossingButton->Observe( m_FastMarchingFilter.GetPointer() );
        gradientMagnitudeButton->Observe( m_DerivativeFilter.GetPointer() );
        edgePotentialButton->Observe( m_SigmoidFilter.GetPointer() );

        progressSlider->Observe( m_CastImageFilter.GetPointer() );
        progressSlider->Observe( m_DerivativeFilter.GetPointer() );
        progressSlider->Observe( m_ThresholdFilter.GetPointer() );
        progressSlider->Observe( m_SigmoidFilter.GetPointer() );
        progressSlider->Observe( m_ImageReader.GetPointer() );
        progressSlider->Observe( m_FastMarchingFilter.GetPointer() );
        progressSlider->Observe( m_FastMarchingWindowingFilter.GetPointer() );

        m_ThresholdFilter->SetLowerThreshold( lowerThresholdValueInput->value() );
        m_ThresholdFilter->SetUpperThreshold( upperThresholdValueInput->value() );

        m_MaskFilter->SetInput( m_ImageReader->GetOutput() );
        m_MaskFilter->SetMaskImage( m_ThresholdFilter->GetOutput() );

        m_IterationCounter = 0;

		m_AdaptorFilterMC = AdaptorFilterType::New();

		m_AdaptorFilterMC->SetInput(m_ThresholdFilter->GetOutput());
		m_AdaptorFilterMC->GetImporter()->SetDataScalarTypeToUnsignedChar();

		m_MCFilter = vtkMarchingCubes::New();
		//m_MCFilter->SetInput(m_AdaptorFilterMC->GetOutput());
		//m_MCFilter->ComputeNormalsOn();
		
		//m_MCMapper = vtkPolyDataMapper::New();
		//m_MCMapper->SetInput(m_MCFilter->GetOutput());
		//m_MCMapper->ScalarVisibilityOff();

		m_STLWriter = vtkSTLWriter::New();		

		m_SmoothFilter->SetInputConnection(m_MCFilter->GetOutputPort());
		m_SmoothFilter->SetNumberOfIterations(30);
		m_SmoothFilter->SetRelaxationFactor(0.1);
		m_SmoothFilter->FeatureEdgeSmoothingOff();
		m_SmoothFilter->BoundarySmoothingOn();
		//m_STLWriter->SetInputConnection(m_MCFilter->GetOutputPort());
    } catch (...) {
        std::cerr << "Exception: FastMarchingLevelSet" << std::endl;
    }
}

/************************************
 *
 *  Destructor
 *
 ***********************************/
FastMarchingLevelSet::~FastMarchingLevelSet()
{
    //
}

/************************************
 *
 * Show main console
 *
 ***********************************/
void FastMarchingLevelSet::ShowConsole(void)
{
    consoleWindow->show();
}

/********************************************
 *
 * Quit : requires to hide all fltk windows
 *
 *******************************************/
void FastMarchingLevelSet::Quit(void)
{
    m_InputImageViewer.Hide();
    m_ThresholdedImageViewer.Hide();
    m_SegmentationImageViewer.Hide();
    m_EdgePotentialImageViewer.Hide();
    m_GradientMagnitudeImageViewer.Hide();
    m_TimeCrossingMapViewer.Hide();

    m_VTKSegmentedImageViewer->Hide();

    consoleWindow->hide();
}

/************************************
 *
 *  Load Input Image
 *
 ***********************************/
void FastMarchingLevelSet::LoadInputImage( void )
{
    const char * filename = fl_file_chooser("Input Image filename","*.*","");
    if( !filename ) {
        return;
    }

    this->ShowStatus("Loading input image file...");

    try {
        this->FastMarchingLevelSetBase::LoadInputImage( filename );
    } catch( itk::ExceptionObject & excp ) {
        fl_alert( excp.GetDescription() );
        controlsGroup->deactivate();
        return;
    } catch( ... ) {
        this->ShowStatus("Problems reading file format");
        controlsGroup->deactivate();
        return;
    }

    // Allocate a image of seeds of the same size
    m_SeedImage->SetRegions( m_ImageReader->GetOutput()->GetBufferedRegion() );
    m_SeedImage->Allocate();
    m_SeedImage->FillBuffer( itk::NumericTraits<SeedImageType::PixelType>::Zero );

    this->ShowStatus("Input Image Loaded");

    controlsGroup->activate();
}

/************************************
 *
 *  Save Output Image
 *
 ***********************************/
void FastMarchingLevelSet::SaveOutputImage( void )
{
    const char * filename = fl_file_chooser("Output Image filename","*.*","");
    if( !filename ) {
        return;
    }

	std::string fileName = filename;

	std::string mhdFileName = fileName + ".mhd";

    this->ShowStatus("Saving output image file...");

    try {
        FastMarchingLevelSetBase::SaveOutputImage( mhdFileName.c_str() );
    } catch( ... ) {
        this->ShowStatus("Problems writing output file");
        return;
    }

	try {

		std::string aMhdFilename = fileName + "vtk.mhd";
		std::string aRawFilename = fileName + "vtk.raw";

		vtkSmartPointer<vtkMetaImageWriter> writer = vtkSmartPointer<vtkMetaImageWriter>::New();
		writer->SetInput(m_AdaptorFilterMC->GetOutput());
		writer->SetFileName(aMhdFilename.c_str());
		writer->SetRAWFileName(aRawFilename.c_str());
		writer->Write();
	} catch (...) {
        this->ShowStatus("Problems writing output file");
		return ;
	}

    this->ShowStatus("Output Image Saved");

	std::string stlFileName = fileName + ".stl" ;
	m_MaskFilter->UpdateLargestPossibleRegion();

	m_MaskFilter->Update();

	m_AdaptorFilterMC->UpdateLargestPossibleRegion();

	m_AdaptorFilterMC->Update();

	vtkImageData* pData = m_AdaptorFilterMC->GetOutput();

	int *dims = pData->GetDimensions();

	std::cout << dims[0] << ", " << dims[1] << ", " << dims[2] << std::endl;

	//int cnt = 10;

	//for (int z = 0; z < dims[2]; z++)
	//{
	//	for (int y = 0; y < dims[1]; y++)
	//	{
	//		for (int x = 0; x < dims[0]; x++)
	//		{
	//			unsigned char* pixel = static_cast<unsigned char*>(pData->GetScalarPointer(x,y,z));
	//			if (*pixel != 0 && cnt > 0) {
	//				std::cout << (int)(*pixel) << std::endl;
	//				--cnt;
	//			}
	//		}
	//	}
	//}

	m_MCFilter->SetInput(m_AdaptorFilterMC->GetOutput());
	m_MCFilter->ComputeNormalsOn();
	m_MCFilter->SetValue(0, 1);

	//m_MCMapper = vtkPolyDataMapper::New();
	//m_MCMapper->SetInput(m_MCFilter->GetOutput());
	//m_MCMapper->ScalarVisibilityOff();

	m_STLWriter->SetInputConnection(m_SmoothFilter->GetOutputPort());
	// m_STLWriter->SetInputConnection(m_MCFilter->GetOutputPort());

	//m_MCMapper = vtkPolyDataMapper::New();
	//m_MCMapper->SetInput(m_MCFilter->GetOutput());
	//m_MCMapper->ScalarVisibilityOff();

	m_STLWriter->SetFileTypeToBinary();
	m_STLWriter->SetFileName(stlFileName.c_str());
	m_STLWriter->Write();

	m_SmoothFilter->SetNumberOfIterations(300);
	m_STLWriter->SetFileTypeToBinary();
	m_STLWriter->SetFileName("d:/smoothed.stl");
	m_STLWriter->Write();
}

/************************************
 *
 *  Show Status
 *
 ***********************************/
void FastMarchingLevelSet::ShowStatus( const char * message )
{
    statusTextOutput->value( message );
    Fl::check();
}

/************************************
 *
 *  Clear Seeds
 *
 ***********************************/
void FastMarchingLevelSet::ClearSeeds( void )
{
    this->FastMarchingLevelSetBase::ClearSeeds();
    m_SeedImage->FillBuffer( itk::NumericTraits<SeedImageType::PixelType>::Zero );
	// m_SeedImage->Update();
}

/************************************
 *
 *  Show Input Image
 *
 ***********************************/
void FastMarchingLevelSet::ShowInputImage( void )
{
    if( !m_InputImageIsLoaded ) {
        return;
    }

    m_CastImageFilter->UpdateLargestPossibleRegion();
    m_InputImageViewer.SetImage( m_CastImageFilter->GetOutput() );
    m_InputImageViewer.SetOverlay( m_SeedImage );
    m_InputImageViewer.Show();
}

/************************************
 *
 *  Show Time Crossing Map Image
 *
 ***********************************/
void FastMarchingLevelSet::ShowTimeCrossingMapImage( void )
{
    if( !m_InputImageIsLoaded ) {
        return;
    }
    this->RunFastMarching();
    m_TimeCrossingMapViewer.SetImage( m_FastMarchingWindowingFilter->GetOutput() );
    m_TimeCrossingMapViewer.Show();
}

/************************************
 *
 *  Show Gradient Magnitude
 *
 ***********************************/
void FastMarchingLevelSet::ShowGradientMagnitudeImage( void )
{
    if( !m_InputImageIsLoaded ) {
        return;
    }
    this->ComputeGradientMagnitude();
    m_GradientMagnitudeImageViewer.SetImage( m_DerivativeFilter->GetOutput() );
    m_GradientMagnitudeImageViewer.Show();
}

/************************************
 *
 *  Show The Edge Potential Map
 *
 ***********************************/
void FastMarchingLevelSet::ShowEdgePotentialImage( void )
{
    if( !m_InputImageIsLoaded ) {
        return;
    }
    this->ComputeEdgePotential();
    m_EdgePotentialImageViewer.SetImage( m_SigmoidFilter->GetOutput() );
    m_EdgePotentialImageViewer.Show();
}

/************************************
 *
 *  Show Thresholded Image
 *
 ***********************************/
void FastMarchingLevelSet::ShowThresholdedImage( void )
{
    m_ThresholdFilter->UpdateLargestPossibleRegion();
    m_ThresholdedImageViewer.SetImage( m_ThresholdFilter->GetOutput() );
    m_ThresholdedImageViewer.SetOverlay( m_SeedImage );
    m_ThresholdedImageViewer.Show();
}

/************************************
 *
 *  Show Segmented Image
 *
 ***********************************/
void FastMarchingLevelSet::ShowSegmentedImage( void )
{
    m_ThresholdFilter->UpdateLargestPossibleRegion();
    m_SegmentationImageViewer.SetImage( m_CastImageFilter->GetOutput() );
    m_SegmentationImageViewer.SetOverlay( m_ThresholdFilter->GetOutput() );
    m_SegmentationImageViewer.Show();
    m_SegmentationImageViewer.SetOverlayOpacity( 0.5 );
}

/************************************
 *
 *  Show Homogeneous Image
 *
 ***********************************/
void FastMarchingLevelSet::ShowThresholdedImageWithVTK( void )
{
    m_MaskFilter->UpdateLargestPossibleRegion();
    m_VTKSegmentedImageViewer->SetImage( m_MaskFilter->GetOutput() );
    m_VTKSegmentedImageViewer->Show();	
}

/*****************************************
 *
 *  Callback for Selecting a seed point
 *
 *****************************************/
void FastMarchingLevelSet::ClickSelectCallback(double x, double y, double z, double, void * args )
{
    FastMarchingLevelSet * self = static_cast<FastMarchingLevelSet *>( args );

    self->SelectSeedPoint( x, y, z );
}

/*****************************************
 *
 *  Callback for Selecting a seed point
 *
 *****************************************/
void FastMarchingLevelSet::SelectSeedPoint(double x, double y, double z)
{
    typedef SeedImageType::IndexType IndexType;
    IndexType seed;
    seed[0] = static_cast<IndexType::IndexValueType>( x );
    seed[1] = static_cast<IndexType::IndexValueType>( y );
    seed[2] = static_cast<IndexType::IndexValueType>( z );

    FastMarchingLevelSetBase::AddSeed( seed );

    m_SeedImage->SetPixel( seed, 1 );

    m_InputImageViewer.Update();
}
