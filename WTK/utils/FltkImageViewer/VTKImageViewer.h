/*=========================================================================

Program:   Insight Segmentation & Registration Toolkit
Module:    fltkVTKImageViewer.h
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) 2002 Insight Consortium. All rights reserved.
See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __fltkVTKImageViewer_h
#define __fltkVTKImageViewer_h

#include <string>
# include "vtkImageData.h"
#include <itkImage.h>
#include "itkImageToVTKImageFilter.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkVolumeRayCastMapper.h"
#include "vtkVolumeRayCastCompositeFunction.h"
#include "vtkVersion.h"
#include "vtkCamera.h"
#include "fltkVTKImageViewerGUI.h"
# include "vtkImageCast.h"
# include "vtkSTLWriter.h"
# include "vtkMarchingCubes.h"
# include "vtkPolyDataMapper.h"
# include <vtkMetaImageWriter.h>

namespace fltk
{

#define USE_PROP ((VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION <= 5) || (VTK_MAJOR_VERSION <= 4))

    template <class ImagePixelType >
    class VTKImageViewer : public fltkVTKImageViewerGUI
    {
    public:

        /**
        * Standard "Self" typedef.
        */
        typedef VTKImageViewer         Self;

        /**
        * Smart pointer typedef support.
        */
        typedef itk::SmartPointer<Self>        Pointer;
        typedef itk::SmartPointer<const Self>  ConstPointer;

        typedef itk::Image< ImagePixelType, 3 > ImageType;

        typedef fltkVTKImageViewerGUI     Superclass;

        /**
        * Run-time type information (and related methods).
        */
        itkTypeMacro(VTKImageViewerBase, Object);

        /**
        * Method for creation through the object factory.
        */
        itkNewMacro(Self);

        /** Filter for connecting and end of the ITK pipeline
        to the beggining of a VTK pipeline */
        typedef ::itk::ImageToVTKImageFilter< ImageType >   AdaptorFilterType;
        typedef typename AdaptorFilterType::Pointer          AdaptorFilterPointer;
		
        virtual void SetImage(ImageType * img) {
            m_AdaptorFilter->SetInput( img );
        }

        virtual void Show() {
            fltkRenderWindowInteractor->Initialize();
            Superclass::Show();
        }

        virtual void Hide() {
            Superclass::Hide();
        }

    protected:

        VTKImageViewer() {
            try {
                m_RenderWindow   = vtkRenderWindow::New();  // double buffering turned on by default
                m_Renderer       = vtkRenderer::New();

                m_AdaptorFilter  = AdaptorFilterType::New();

				m_CastFilter = vtkImageCast::New();

                // ray casting can only be performed on
                // unsigned short or unsigned char data
                m_AdaptorFilter->GetImporter()->SetDataScalarTypeToUnsignedChar();

                fltkRenderWindowInteractor->SetRenderWindow( m_RenderWindow );

                // a renderer and render window
                m_RenderWindow->AddRenderer( m_Renderer );

                m_Renderer->SetBackground( .1, .2, .3 );
                m_Renderer->GetActiveCamera()->Zoom( 1.0 );
                m_Renderer->GetActiveCamera()->SetPosition(0.0, 0.0, 20.0 );

                // Create a transfer function mapping scalar value to opacity
                vtkPiecewiseFunction *opacity = vtkPiecewiseFunction::New();
                opacity->AddSegment(80, 0.0, 255, 1.0);

                // Create a transfer function mapping scalar value to color (grey)
                vtkPiecewiseFunction *color = vtkPiecewiseFunction::New();
                color->AddSegment(0, 1.0, 255, 1.0);

                // Create a property for the volume and set the transfer functions.
                // Turn shading on and use trilinear interpolation
                vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
                volumeProperty->SetColor(color);
                volumeProperty->SetScalarOpacity(opacity);
                volumeProperty->SetInterpolationTypeToLinear();
                volumeProperty->ShadeOn();

                // Create a ray function - this is a compositing ray function
                vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();

                // Create the volume mapper and set the ray function and scalar input
                vtkVolumeRayCastMapper *volumeMapper = vtkVolumeRayCastMapper::New();
#if VTK_MAJOR_VERSION <= 5
				//vtkImageData * data = vtkImageData::New();
				//data->DeepCopy(m_AdaptorFilter->GetOutput());
				//data->SetScalarTypeToUnsignedShort(m_AdaptorFilter->GetOutput());
				//data->Update();
				m_CastFilter->SetInput((vtkDataObject *)m_AdaptorFilter->GetOutput());
				m_CastFilter->SetOutputScalarTypeToUnsignedShort();
                volumeMapper->SetInput(m_CastFilter->GetOutput());
#else
                m_AdaptorFilter->Update();
                volumeMapper->SetInputData( m_AdaptorFilter->GetOutput() );
#endif
                volumeMapper->SetVolumeRayCastFunction(compositeFunction);

                // Create the volume and set the mapper and property
                vtkVolume *volume = vtkVolume::New();
                volume->SetMapper( volumeMapper );
                volume->SetProperty( volumeProperty );

                // Add this volume to the renderer
#if USE_PROP
                m_Renderer->AddProp( volume );
#else
                m_Renderer->AddViewProp( volume );
#endif

                // Interact with the data at 3 frames per second
                fltkRenderWindowInteractor->SetDesiredUpdateRate(3.0);
                fltkRenderWindowInteractor->SetStillUpdateRate(0.001);
            } catch (itk::ExceptionObject & excp) {
                std::cerr << "ExceptionObject caught !" << std::endl;
                std::cerr << excp << std::endl;
            } catch (std::exception & excp) {
                std::cerr << excp.what() << std::endl;
            } catch (...) {
                std::cerr << "Exception: VTKImageViewer::VTKImageViewer()" << std::endl;
            }
        }

        virtual ~VTKImageViewer() {
            // Delete only VTK objects
            if( m_RenderWindow ) {
                m_RenderWindow->Delete();
            }

            if( m_Renderer ) {
                m_Renderer->Delete();
            }
        }

    private:

        vtkRenderWindow           *  m_RenderWindow;
        vtkRenderer               *  m_Renderer;

        AdaptorFilterPointer         m_AdaptorFilter;

		vtkImageCast * m_CastFilter;
    };

} // end namespace fltk

#ifndef ITK_MANUAL_INSTANTIATION
#include "fltkVTKImageViewer.cpp"
#endif

#endif
