# ifndef WTK_SEGMENTATION_FASTMARCHING_FMBASE_H_
# define WTK_SEGMENTATION_FASTMARCHING_FMBASE_H_

# include <cmath>
# include <FL/fl_ask.H>
# include "itkImageFileReader.h"
# include "itkImageFileWriter.h"
# include "itkImage.h"
# include "itkCastImageFilter.h"
# include "itkCurvatureAnisotropicDiffusionImageFilter.h"
# include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
# include "itkSigmoidImageFilter.h"
# include "itkFastMarchingImageFilter.h"
# include "itkIntensityWindowingImageFilter.h"
# include "itkBinaryThresholdImageFilter.h"

class FMBase {
public:
    // 二维
    enum { ImageDimension = 3 };

    /// typedefs
    /** pixel type of input image */
    typedef unsigned short InputPixelType;

    /** type of input image */
    typedef itk::Image< InputPixelType, ImageDimension > InputImageType;

    /** filter for reading input image */
    typedef itk::ImageFileReader< InputImageType > ImageReaderType;

    /** pixel type for computation */
    typedef double InternalPixelType;

    /** type of internal image */
    typedef itk::Image< InternalPixelType, ImageDimension > InternalImageType;

    /** cast filter for transform between input image and internal image */
    typedef itk::CastImageFilter< InputImageType, InternalImageType > CastImageFilterType;

    /** smooth filter type */
    typedef itk::CurvatureAnisotropicDiffusionImageFilter< InternalImageType, InternalImageType > SmoothingFilterType;

    /** gradient magnitude filter type */
    typedef itk::GradientMagnitudeRecursiveGaussianImageFilter< InternalImageType > DerivativeFilterType;

    /** Filter to compute negative exponential of the gradient magnitude */
    typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType > SigmoidFilterType;

    /** Fast Marching filter use to evolve the contours */
    typedef itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

    /** seed point type */
    typedef InternalImageType::IndexType IndexType;

    /** Auxiliary types for seeds (Nodes) */
    typedef FastMarchingFilterType::NodeType NodeType;
    typedef FastMarchingFilterType::NodeContainer NodeContainer;

    /** Threshold filter used to eliminate the infinite times assigned to non-visited pixels in the FastMarching filter. */
    typedef itk::IntensityWindowingImageFilter< InternalImageType, InternalImageType > FastMarchingWindowingFilterType;

    /** pixel type for thresholded image (output images) */
    typedef unsigned char ThresholdPixelType;

    /** type of thresholded image */
    typedef itk::Image< ThresholdPixelType, ImageDimension > ThresholdedImageType;

    /** threshold filter used to select a time from the time map */
    typedef itk::BinaryThresholdImageFilter< InternalImageType, ThresholdedImageType > ThresholdFilterType;

    /** filter for writing output images */
    typedef itk::ImageFileWriter< ThresholdedImageType > ImageWriterType;

public:
    FMBase();
    virtual ~FMBase();

    virtual void LoadInputImage() = 0;
    virtual void LoadInputImage(const char * filename);

    virtual void SaveOutputImage() = 0;
    virtual void SaveOutputImage(const char * filename);

    virtual void ShowStatus(const char * text) = 0;

    virtual void ComputeCurvatureAnisotropicDiffusion();

    virtual void ComputeGradientMagnitude();

    virtual void ComputeEdgePotential();

    virtual void AddSeed(const IndexType & seed);

    virtual void ClearSeeds();

    virtual void RunFastMarching();

    virtual void Stop();

protected:
    void SetStoppingValue(double value);

protected:
    bool                                     m_InputImageIsLoaded;
    ImageReaderType::Pointer                 m_ImageReader;

    CastImageFilterType::Pointer             m_CastImageFilter;

    unsigned int                             m_DerivativeIterNums;
    SmoothingFilterType::Pointer             m_SmoothFilter;

    DerivativeFilterType::Pointer            m_DerivativeFilter;

    SigmoidFilterType::Pointer               m_SigmoidFilter;

    NodeContainer::Pointer                   m_TrialPoints;
    InternalPixelType                        m_SeedValue;
    unsigned int                             m_NumberOfSeeds;
    FastMarchingFilterType::Pointer          m_FastMarchingFilter;

    FastMarchingWindowingFilterType::Pointer m_FastMarchingWindowingFilter;

    ThresholdFilterType::Pointer             m_ThresholdFilter;

    ImageWriterType::Pointer                 m_ImageWriter;
};

# endif  // WTK_SEGMENTATION_FASTMARCHING_FMBASE_H_
