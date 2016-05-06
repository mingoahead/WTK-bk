# ifndef WTK_SEGMENTATION_FASTMARCHING_FASTMARCHINGLEVELSET_H_
# define WTK_SEGMENTATION_FASTMARCHING_FASTMARCHINGLEVELSET_H_

# include "fltkImageViewer.h"
# include "VTKImageViewer.h"
# include "FastMarchingLevelSetGUI.h"
# include "itkMaskImageFilter.h"
# include "vtkMarchingCubes.h"

# include "itkImageToVTKImageFilter.h"
# include "vtkSTLWriter.h"
# include "vtkPolyDataMapper.h"
# include "vtkSmoothPolyDataFilter.h"

class FastMarchingLevelSet : public FastMarchingLevelSetGUI
{
public:
    /** dimension of input images */
    enum { ImageDimension = FastMarchingLevelSetBase::ImageDimension };

    /** pixel type used for reading the input image */
    typedef FastMarchingLevelSetBase::InputPixelType InputPixelType;

    /** pixel type to be used internally */
    typedef FastMarchingLevelSetBase::InternalPixelType InternalPixelType;

    /** input image type */
    typedef FastMarchingLevelSetBase::InputImageType InputImageType;

    /** internal image type */
    typedef FastMarchingLevelSetBase::InternalImageType InternalImageType;

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

    typedef itk::MaskImageFilter< InputImageType, ThresholdedImageType > MaskFilterType;

	typedef fltk::VTKImageViewer< InputPixelType > VTKImageViewerType;

	typedef itk::Image< unsigned char, 3 > ImageType;
	typedef itk::ImageToVTKImageFilter< ImageType >   AdaptorFilterType;

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

    MaskFilterType::Pointer         m_MaskFilter;

    VTKImageViewerType::Pointer     m_VTKSegmentedImageViewer;

	unsigned long                   m_IterationCounter;

	AdaptorFilterType::Pointer            m_AdaptorFilterMC;
	vtkMarchingCubes * m_MCFilter;
	vtkPolyDataMapper * m_MCMapper;
	vtkSTLWriter * m_STLWriter;
	vtkSmoothPolyDataFilter * m_SmoothFilter;
};

# endif  // WTK_SEGMENTATION_FASTMARCHING_FASTMARCHINGLEVELSET_H_
