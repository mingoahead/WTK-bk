# ifndef WTK_SEGMENTATION_FASTMARCHING2D_FM2D_H_
# define WTK_SEGMENTATION_FASTMARCHING2D_FM2D_H_

# include "utils/FltkImageViewer/fltkImageViewer.h"
# include "VTKImageViewer.h"
# include "FMGUI.h"

class FM2D : public FMGUI
{
public:
    /** dimension of input images */
    enum { ImageDimension = FMBase::ImageDimension };

    /** pixel type used for reading the input image */
    typedef FMBase::InputPixelType InputPixelType;

    /** pixel type to be used internally */
    typedef FMBase::InternalPixelType InternalPixelType;

    /** input image type */
    typedef FMBase::InputImageType InputImageType;

    /** internal image type */
    typedef FMBase::InternalImageType InternalImageType;

    /** pixel type to be used for the seeds */
    typedef unsigned char SeedPixelType;

    /** type of the seeds image */
    typedef itk::Image< SeedPixelType, ImageDimension > SeedImageType;

    /** image Viewer Types */
    typedef SeedPixelType OverlayPixelType;

    /** FLTK viewer module */
    typedef fltk::ImageViewer< InternalPixelType, OverlayPixelType > InternalImageViewerType;

    typedef fltk::ImageViewer< ThresholdPixelType, OverlayPixelType > ThresholdedImageViewerType;

    typedef fltk::ImageViewer< InternalPixelType, ThresholdPixelType > SegmentationImageViewerType;

    typedef fltk::VTKImageViewer< ThresholdPixelType > VTKImageViewerType;

public:
    FM2D();
    virtual ~FM2D();

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

    virtual void SelectSeedPoint( double x, double y, double z );

    static  void ClickSelectCallback(double x, double y, double z, double value, void * args );

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

# endif  // WTK_SEGMENTATION_FASTMARCHING2D_FM2D_H_
