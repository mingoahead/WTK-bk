/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    FastMarchingLevelSet.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include <FastMarchingLevelSet.h>
#include <FL/Fl_File_Chooser.H>





/************************************
 *
 *  Constructor
 *
 ***********************************/
FastMarchingLevelSet
::FastMarchingLevelSet()
{
  // This image is only used for providing visual 
  // feedback to the user. The actual structure
  // holding the seeds is in the base class.
  m_SeedImage = SeedImageType::New();

  m_InputImageViewer.SetLabel("Input Image");

  m_ThresholdedImageViewer.SetLabel("Thresholded Image");

  m_SegmentationImageViewer.SetLabel("Segmented Image");
  m_SegmentationImageViewer.SetOverlayOpacity( 0.5 );

  m_GradientMagnitudeImageViewer.SetLabel("Gradient Magnitude Image");

  m_EdgePotentialImageViewer.SetLabel("Edge Potential Image");

  m_InputImageViewer.ClickSelectCallBack( ClickSelectCallback, (void *)this);

  // Initialize ITK filter with GUI values
  m_ThresholdFilter->SetLowerThreshold( 
      static_cast<InternalPixelType>( lowerThresholdValueInput->value() ) );

  m_ThresholdFilter->SetUpperThreshold( 
      static_cast<InputPixelType>( upperThresholdValueInput->value() ) );

  m_DerivativeFilter->SetSigma( sigmaValueInput->value() );

  m_SigmoidFilter->SetAlpha( alphaValueInput->value() );
  m_SigmoidFilter->SetBeta(  betaValueInput->value()  );

  this->SetStoppingValue( stoppingValueInput->value() );

  m_VTKSegmentedImageViewer = VTKImageViewerType::New();
  m_VTKSegmentedImageViewer->SetImage( m_ThresholdFilter->GetOutput() );

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

  m_IterationCounter = 0;

}



/************************************
 *
 *  Destructor
 *
 ***********************************/
FastMarchingLevelSet
::~FastMarchingLevelSet()
{

}




/************************************
 *
 * Show main console
 *
 ***********************************/
void
FastMarchingLevelSet
::ShowConsole(void)
{
  consoleWindow->show();
}




/********************************************
 *
 * Quit : requires to hide all fltk windows
 *
 *******************************************/
void
FastMarchingLevelSet
::Quit(void)
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
void
FastMarchingLevelSet
::LoadInputImage( void )
{

  const char * filename = fl_file_chooser("Input Image filename","*.*","");
  if( !filename )
  {
    return;
  }

  this->ShowStatus("Loading input image file...");
  
  try 
  {
    this->FastMarchingLevelSetBase::LoadInputImage( filename );
  }
  catch( itk::ExceptionObject & excp ) 
  {
    fl_alert( excp.GetDescription() );
    controlsGroup->deactivate();
    return;
  }
  catch( ... ) 
  {
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
void
FastMarchingLevelSet
::SaveOutputImage( void )
{

  const char * filename = fl_file_chooser("Output Image filename","*.*","");
  if( !filename )
  {
    return;
  }

  this->ShowStatus("Saving output image file...");
  
  try 
    {
    FastMarchingLevelSetBase::SaveOutputImage( filename );
    }
  catch( ... ) 
    {
    this->ShowStatus("Problems writing output file");
    return;
    }

  this->ShowStatus("Output Image Saved");

}





/************************************
 *
 *  Show Status
 *
 ***********************************/
void
FastMarchingLevelSet
::ShowStatus( const char * message )
{
  statusTextOutput->value( message );
  Fl::check();
}




 
/************************************
 *
 *  Clear Seeds
 *
 ***********************************/
void
FastMarchingLevelSet
::ClearSeeds( void )
{
  this->FastMarchingLevelSetBase::ClearSeeds();
  m_SeedImage->FillBuffer( itk::NumericTraits<SeedImageType::PixelType>::Zero );
}



 
/************************************
 *
 *  Show Input Image
 *
 ***********************************/
void
FastMarchingLevelSet
::ShowInputImage( void )
{

  if( !m_InputImageIsLoaded )
    {
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
void
FastMarchingLevelSet
::ShowTimeCrossingMapImage( void )
{

  if( !m_InputImageIsLoaded )
    {
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
void
FastMarchingLevelSet
::ShowGradientMagnitudeImage( void )
{

  if( !m_InputImageIsLoaded )
    {
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
void
FastMarchingLevelSet
::ShowEdgePotentialImage( void )
{

  if( !m_InputImageIsLoaded )
    {
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
void
FastMarchingLevelSet
::ShowThresholdedImage( void )
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
void
FastMarchingLevelSet
::ShowSegmentedImage( void )
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
void
FastMarchingLevelSet
::ShowThresholdedImageWithVTK( void )
{
  m_VTKSegmentedImageViewer->Show();
}




 
/*****************************************
 *
 *  Callback for Selecting a seed point
 *
 *****************************************/
void
FastMarchingLevelSet
::ClickSelectCallback(float x, float y, float z, float, void * args )
{

  FastMarchingLevelSet * self = 
     static_cast<FastMarchingLevelSet *>( args );

  self->SelectSeedPoint( x, y, z );

}



 
/*****************************************
 *
 *  Callback for Selecting a seed point
 *
 *****************************************/
void
FastMarchingLevelSet
::SelectSeedPoint(float x, float y, float z)
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


  
 


/*  Finaly the main() that will instantiate the application  */
int main()
{

  try 
    {
    FastMarchingLevelSet * console = new FastMarchingLevelSet();
    console->ShowConsole();
    Fl::run();
    delete console;
    }
  catch( itk::ExceptionObject & e )
    {
    std::cerr << "ITK exception caught in main" << std::endl;
    std::cerr << e << std::endl;
    }
  catch( std::exception & e )
    {
    std::cerr << "STD exception caught in main" << std::endl;
    std::cerr << e.what() << std::endl;
    }
  catch( ... )
    {
    std::cerr << "unknown exception caught in main" << std::endl;
    }


  return 0;

}



