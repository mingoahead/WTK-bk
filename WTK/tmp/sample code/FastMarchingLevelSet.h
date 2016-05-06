/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    FastMarchingLevelSet.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef FASTMARCHINGLEVELSET
#define FASTMARCHINGLEVELSET

#include "FastMarchingLevelSetGUI.h"
#include "fltkImageViewer.h"

#include "fltkVTKImageViewer.h"


/**
 * \brief FastMarchingLevelSet class that instantiate
 * the elements required for a LevelSet approach for segmentation
 *
 */
class FastMarchingLevelSet : public FastMarchingLevelSetGUI
{
public:

  /** Dimension of the images to be registered */ 
  enum { ImageDimension = FastMarchingLevelSetBase::ImageDimension };

  /** Pixel type used for reading the input image */
  typedef   FastMarchingLevelSetBase::InputPixelType       InputPixelType;

  /** Pixel type to be used internally */
  typedef   FastMarchingLevelSetBase::InternalPixelType    InternalPixelType;

  /** Input image type */
  typedef   FastMarchingLevelSetBase::InputImageType       InputImageType;

  /** Internal image type */
  typedef   FastMarchingLevelSetBase::InternalImageType    InternalImageType;

  /** Pixel type to be used for the seeds */
  typedef   unsigned char                                  SeedPixelType;
  
  /** Type of the seeds image */
  typedef   itk::Image<SeedPixelType,ImageDimension>       SeedImageType;

  /** Image Viewer Types */
  typedef SeedPixelType OverlayPixelType;

  /** FLTK viewer module */
  typedef fltk::ImageViewer< InternalPixelType, 
                                    OverlayPixelType >     InternalImageViewerType;

  typedef fltk::ImageViewer< ThresholdPixelType, 
                                    OverlayPixelType >     ThresholdedImageViewerType;

  typedef fltk::ImageViewer< InternalPixelType, 
                                  ThresholdPixelType >     SegmentationImageViewerType;


  typedef fltk::VTKImageViewer< ThresholdPixelType >       VTKImageViewerType;


public:
  FastMarchingLevelSet();
  virtual ~FastMarchingLevelSet();

  virtual void LoadInputImage();

  virtual void SaveOutputImage();

  virtual void ShowConsole();

  virtual void ShowStatus(const char * text);

  virtual void ShowInputImage();

  virtual void ShowTimeCrossingMapImage();

  virtual void ShowGradientMagnitudeImage();

  virtual void ShowEdgePotentialImage();

  virtual void ShowThresholdedImage();

  virtual void ShowSegmentedImage();

  virtual void ShowThresholdedImageWithVTK();

  virtual void Quit();

  virtual void SelectSeedPoint( float x, float y, float z );
  
  static  void ClickSelectCallback(float x, float y, float z, float value, void * args );

  virtual void ClearSeeds();


private:

  SeedImageType::Pointer          m_SeedImage;

  ThresholdedImageViewerType      m_ThresholdedImageViewer;

  SegmentationImageViewerType     m_SegmentationImageViewer;

  InternalImageViewerType         m_TimeCrossingMapViewer;

  InternalImageViewerType         m_InputImageViewer;

  InternalImageViewerType         m_GradientMagnitudeImageViewer;

  InternalImageViewerType         m_EdgePotentialImageViewer;

  VTKImageViewerType::Pointer     m_VTKSegmentedImageViewer;

  unsigned long                   m_IterationCounter;

};



#endif
