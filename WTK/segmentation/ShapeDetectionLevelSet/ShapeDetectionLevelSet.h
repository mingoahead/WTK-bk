/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    ShapeDetectionLevelSet.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef SHAPEDETECTIONLEVELSET
#define SHAPEDETECTIONLEVELSET

#include "ShapeDetectionLevelSetGUI.h"
#include "fltkImageViewer.h"
#include "itkMaskImageFilter.h"
#include "fltkVTKImageViewer.h"
#include "itkImageToVTKImageFilter.h"

# include "VTKImageViewer.h"
# include "vtkMarchingCubes.h"
# include "vtkSTLWriter.h"
# include "vtkPolyDataMapper.h"
# include "vtkSmoothPolyDataFilter.h"

/**
 * \brief ShapeDetectionLevelSet class that instantiate
 * the elements required for a LevelSet approach for segmentation
 *
 */
class ShapeDetectionLevelSet : public ShapeDetectionLevelSetGUI
{
public:

  /** Dimension of the images to be registered */ 
  enum { ImageDimension = ShapeDetectionLevelSetBase::ImageDimension };

  /** Pixel type used for reading the input image */
  typedef   ShapeDetectionLevelSetBase::InputPixelType       InputPixelType;

  /** Pixel type to be used internally */
  typedef   ShapeDetectionLevelSetBase::InternalPixelType    InternalPixelType;

  /** Input image type */
  typedef   ShapeDetectionLevelSetBase::InputImageType       InputImageType;

  /** Internal image type */
  typedef   ShapeDetectionLevelSetBase::InternalImageType    InternalImageType;

  /** Image Viewer Types */
  typedef ShapeDetectionLevelSetBase::SeedPixelType        OverlayPixelType;

  /** FLTK viewer module */
  typedef fltk::ImageViewer< InternalPixelType, 
                                    OverlayPixelType >     InternalImageViewerType;

  typedef fltk::ImageViewer< InternalPixelType, 
                                    ThresholdPixelType >   SegmentedImageViewerType;

  typedef fltk::VTKImageViewer< ThresholdPixelType >       VTKImageViewerType;

  typedef itk::Image< unsigned char, 3 >                   ImageType;
  typedef itk::ImageToVTKImageFilter< ImageType >          AdaptorFilterType;

public:
  ShapeDetectionLevelSet();
  virtual ~ShapeDetectionLevelSet();

  virtual void Load();

  virtual void SaveOutputImage();

  virtual void ShowConsole();

  virtual void ShowStatus(const char * text);

  virtual void ShowInputImage();

  virtual void ShowOutputLevelSet();

  virtual void ShowGradientMagnitudeImage();

  virtual void ShowEdgePotentialImage();

  virtual void ShowThresholdedImage();

  virtual void ShowFastMarchingResultImage();
    
  virtual void ShowThresholdedImageWithVTK();

  virtual void Quit();

  virtual void SelectSeedPoint( float x, float y, float z );
  
  static  void ClickSelectCallback(double x, double y, double z, double value, void * args );

  virtual void ClearSeeds();

private:

  SegmentedImageViewerType        m_ThresholdedImageViewer;

  SegmentedImageViewerType        m_FastMarchingImageViewer;
  
  InternalImageViewerType         m_OutputLevelSetViewer;

  InternalImageViewerType         m_InputImageViewer;

  InternalImageViewerType         m_GradientMagnitudeImageViewer;

  InternalImageViewerType         m_EdgePotentialImageViewer;

  InternalImageViewerType         m_ZeroSetImageViewer;

  VTKImageViewerType::Pointer     m_VTKSegmentedImageViewer;

  unsigned long                   m_IterationCounter;
  AdaptorFilterType::Pointer      m_AdaptorFilterMC;
  vtkMarchingCubes * m_MCFilter;
  vtkSmoothPolyDataFilter *       m_SmoothFilter;
  vtkSTLWriter *                  m_STLWriter;
};



#endif
