/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    RegionGrowingSegmentationBase.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

//#include <RegionGrowingSegmentationBase.h>
#include "RegionGrowingSegmentationBase.h"
#include <FL/fl_ask.H>


/************************************
 *
 *  Constructor
 *
 ***********************************/
RegionGrowingSegmentationBase 
::RegionGrowingSegmentationBase()
{

  m_ImageReader                  = ImageReaderType::New();
  m_ImageWriter                  = ImageWriterType::New();

  m_CastImageFilter = CastImageFilterType::New();
  m_CastImageFilter->SetInput( m_ImageReader->GetOutput() );

  m_ExtractImageFilter = ExtractImageFilterType::New();
  m_ExtractImageFilter->SetInput( m_CastImageFilter->GetOutput() );

  m_CurvatureFlowImageFilter = CurvatureFlowImageFilterType::New();
  m_CurvatureFlowImageFilter->SetInput( m_ExtractImageFilter->GetOutput() );

  m_CurvatureAnisotropicDiffusionImageFilter = CurvatureAnisotropicDiffusionImageFilterType::New();
  m_CurvatureAnisotropicDiffusionImageFilter->SetInput( m_ExtractImageFilter->GetOutput() );
  
  m_GradientAnisotropicDiffusionImageFilter = GradientAnisotropicDiffusionImageFilterType::New();
  m_GradientAnisotropicDiffusionImageFilter->SetInput( m_ExtractImageFilter->GetOutput() );
  
  m_NullImageFilter = NullImageFilterType::New();
  m_NullImageFilter->SetInput( m_CurvatureFlowImageFilter->GetOutput() );

  m_ConnectedThresholdImageFilter = ConnectedThresholdImageFilterType::New();
  m_ConnectedThresholdImageFilter->SetInput( m_NullImageFilter->GetOutput() );

  m_ConfidenceConnectedImageFilter = ConfidenceConnectedImageFilterType::New();
  m_ConfidenceConnectedImageFilter->SetInput( m_NullImageFilter->GetOutput() );

  m_InputImageIsLoaded  = false;

}




/************************************
 *
 *  Destructor
 *
 ***********************************/
RegionGrowingSegmentationBase 
::~RegionGrowingSegmentationBase()
{

}



 
/************************************
 *
 *  Load Input Image
 *
 ***********************************/
void
RegionGrowingSegmentationBase 
::LoadInputImage( const char * filename )
{
  if( !filename )
  {
    return;
  }

  m_ImageReader->SetFileName( filename );
  m_ImageReader->Update();
  
  m_InputImageIsLoaded = true;

}


 
/************************************
 *
 *  Write Output Image
 *
 ***********************************/
void
RegionGrowingSegmentationBase 
::WriteOutputImage( const char * filename )
{
  if( !filename )
  {
    return;
  }

  m_ImageWriter->SetFileName( filename );
  m_ImageWriter->Update();
  
}



/************************************
 *
 *  Select Smoothing Filter
 *
 ***********************************/
void
RegionGrowingSegmentationBase
::SelectSmoothingFilter( unsigned int choice )
{
  switch(choice)
    {
    case 0:
      m_NullImageFilter->SetInput( m_CurvatureFlowImageFilter->GetOutput() );
      break;
    case 1:
      m_NullImageFilter->SetInput( m_GradientAnisotropicDiffusionImageFilter->GetOutput() );
      break;
    case 2:
      m_NullImageFilter->SetInput( m_CurvatureAnisotropicDiffusionImageFilter->GetOutput() );
      break;
    }
}








/************************************
 *
 *  Stop Registration
 *
 ***********************************/
void
RegionGrowingSegmentationBase
::Stop( void )
{
  // TODO: add a Stop() method to Filters

}




