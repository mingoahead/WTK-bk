/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    fltkImageViewer.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __fltkImageViewer_h
#define __fltkImageViewer_h

#include "fltkImageViewerGUI.h"

namespace fltk
{

template <class ImagePixelType, class OverlayPixelType>
class ImageViewer : public fltkImageViewerGUI
{
public:

    /** Standard "Self" typedef.  */
    typedef ImageViewer         Self;

    /** Smart pointer typedef support.  */
    typedef itk::SmartPointer<Self>        Pointer;
    typedef itk::SmartPointer<const Self>  ConstPointer;

    typedef itk::Image< ImagePixelType, 3 >   ImageType;
    typedef itk::Image< OverlayPixelType, 3 > OverlayType;
    typedef itk::GLSliceView< ImagePixelType, OverlayPixelType > GLSliceViewType;
    typedef typename GLSliceViewType::ColorTablePointer ColorTablePointer;

    ImageViewer() {
        glSliceView = 0;
        CreateGUI();
    }

    virtual ~ImageViewer() {
    }

    virtual void SetImage(itk::ImageBase<3> * img) {
        ImageType * image = dynamic_cast<ImageType *>( img );
        glSliceView->SetInputImage( image );
        Synchronize();
    }

    virtual void SetOverlay(itk::ImageBase<3> * img) {
        OverlayType * overlay = dynamic_cast<OverlayType *>( img );
        glSliceView->SetInputOverlay( overlay );
        Synchronize();
    }

    virtual void Show(void) {
        static bool firstTime = true;
        iviewWindow->show();
        glSliceView->show();
        glSliceView->update();
        if( firstTime ) {
            firstTime = false;
            Fl::check();
            glSliceView->redraw();
            Fl::check();
        }
    }

    virtual void Hide(void) {
        iviewWindow->hide();
        clickedPointsWindow->hide();
        overlayOpacityControlWindow->hide();
    }

    virtual void Update(void) {
        glSliceView->update();
    }

    virtual void Synchronize(void) {
        float iwDiff  = glSliceView->iwMax() - glSliceView->iwMin();
        float b       = (float)((int)log10(iwDiff)-2);
        double iwMin  = ((int)(glSliceView->iwMin()*pow((float)10, (float)-b)))/pow((float)10,(float)-b);
        double iwMax  = ((int)(glSliceView->iwMax()*pow((float)10, (float)-b)))/pow((float)10,(float)-b);
        double iwStep = (iwMax-iwMin)/100.0;
        sliceNumberSlider->range( 0.0f, glSliceView->numSlices() );
        intensityWindowingMinSlider->range(iwMin-iwStep,iwMax+iwStep);
        intensityWindowingMaxSlider->range(iwMin-iwStep,iwMax+iwStep);
        sliceNumberSlider->value((float)glSliceView->sliceNum());
        intensityWindowingMinSlider->step(iwStep);
        intensityWindowingMaxSlider->step(iwStep);
        intensityWindowingMinSlider->value(iwMin);
        intensityWindowingMaxSlider->value(iwMax);
    }

    virtual void ImageMode(itk::ImageModeType mode) {
        glSliceView->imageMode(mode);
        glSliceView->update();
    }
    virtual void SelectSlice(unsigned int num) {
        sliceNumberSlider->value(num);
        glSliceView->sliceNum((int)sliceNumberSlider->value());
        glSliceView->update();
    }

    virtual void SetIntensityWindowingMin(float val) {
        intensityWindowingMinSlider->value(val);
		std::cout << "SetIntensityWindowingMin: " << glSliceView->iwMin() << std::endl;
        glSliceView->iwMin(intensityWindowingMinSlider->value());
        glSliceView->update();
    }

    virtual void SetIntensityWindowingMax(float val) {
        intensityWindowingMaxSlider->value(val);
		std::cout << "SetIntensityWindowingMax: " << glSliceView->iwMax() << std::endl;
        glSliceView->iwMax(intensityWindowingMaxSlider->value());
        glSliceView->update();
    }

    virtual void CenterWindow(void) {
        glSliceView->winCenter();
        glSliceView->update();
    }

    virtual void ZoomIn(void) {
        glSliceView->winZoom(glSliceView->winZoom()*2.0f);
        glSliceView->update();
    }

    virtual void ZoomOut(void) {
        glSliceView->winZoom(glSliceView->winZoom()/2.0f);
        glSliceView->update();
    }

    virtual void ShiftUp(void) {
        glSliceView->winShift(1,0);
        glSliceView->update();
    }

    virtual void ShiftDown(void) {
        glSliceView->winShift(-1,0);
        glSliceView->update();
    }

    virtual void ShiftLeft(void) {
        glSliceView->winShift(0,-1);
        glSliceView->update();
    }

    virtual void ShiftRight(void) {
        glSliceView->winShift(0,1);
        glSliceView->update();
    }

    virtual void SetOrientation(void) {
        glSliceView->orientation( orientationChoice->value() );
        glSliceView->update();
        Synchronize();
    }

    virtual void CreateGLSliceView( Fl_Group * group, Fl_Gl_Window * original ) {
        short int x = original->x();
        short int y = original->y();
        short int w = original->w();
        short int h = original->h();

        const char * label = original->label();


        this->glSliceView = new GLSliceViewType(x,y,w,h,label);

        glSliceView->box( FL_EMBOSSED_BOX );

        group->remove( original );

        delete original;
    }

    virtual void SetLabel(const char * label) {
        iviewWindow->label( label );
    }

    virtual void ShowClickedPointsWindow(void) {
        clickedPointsWindow->show();
    }

    virtual void UpdateClickedPoints(void) {
        clickedPointsBrowser->clear();
        char buffer[200];
        const int numPoints = glSliceView->numClickedPointsStored();

        for(int i=numPoints-1; i>=0; i--) {
            itk::ClickPoint point;
            if( glSliceView->getClickedPoint(i,point) ) {
                const int x = (int)(point.x);
                const int y = (int)(point.y);
                const int z = (int)(point.z);
                const float value = point.value;
                sprintf(buffer,"%3d %3d %3d %f",x,y,z,value);
                clickedPointsBrowser->add( buffer );
            }
        }
    }

    virtual void ClearClickedPoints(void) {
        glSliceView->clearClickedPointsStored();
        clickedPointsBrowser->clear();
    }

    virtual void ClickSelectCallBack(
        void (*newClickSelectArgCallBack)(double, double,
                                          double, double,
                                          void *),
        void * newClickSelectArg) {
        glSliceView->clickSelectCallBack( newClickSelectArgCallBack,
                                          newClickSelectArg           );
    }


    virtual void ViewDetails(bool detail) {
        glSliceView->viewDetails(detail);
    }

    virtual void ViewValue(bool value) {
        glSliceView->viewValue(value);
    }

    virtual void ViewCrosshairs(bool crosshairs) {
        glSliceView->viewCrosshairs(crosshairs);
    }

    /** Specify the opacity of the overlay */
    virtual void  SetOverlayOpacity(float newOverlayOpacity) {
        glSliceView->OverlayOpacity( newOverlayOpacity );
        glSliceView->update();
    }

    /** Get the opacity of the overlay */
    virtual float GetOverlayOpacity(void) const {
        return glSliceView->OverlayOpacity();
    }

    /** Show slider to control overlay opacity */
    virtual void ShowOverlayOpacityControl(void) {
        overlayOpacitySlider->value( this->GetOverlayOpacity() );
        overlayOpacityControlWindow->show();
    }

    /** Get the ColorTable for the Overlay */
    virtual ColorTablePointer GetOverlayColorTable(void) {
        return glSliceView->GetColorTable();
    }

    /** Set the ColorTable for the Overlay */
    virtual void SetOverlayColorTable(ColorTablePointer newColorTable) {
        glSliceView->SetColorTable(newColorTable);
    }

    void SetOverlayColorIndex( unsigned int c ) {
        glSliceView->SetOverlayColorIndex( c );
    }

private:
    GLSliceViewType * glSliceView;
};


} // end namespace fltk

#endif
