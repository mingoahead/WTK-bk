# ifndef WKT_SEGMENTATION_FASTMARCHING_FASTMARCHINGBASE_H_
# define WKT_SEGMENTATION_FASTMARCHING_FASTMARCHINGBASE_H_

# include "itkImageFileReader.h"
# include "itkImageFileWriter.h"
# include "itkImage.h"
# include "itkCastImageFilter.h"
# include "itkFastMarchingImageFilter.h"
# include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
# include "itkSigmoidImageFilter.h"
# include "itkBinaryThresholdImageFilter.h"
# include "itkIntensityWindowingImageFilter.h"
# include "itkGradientMagnitudeImageFilter.h"
# include "itkRescaleIntensityImageFilter.h"
# include "itkCastImageFilter.h"

class FastMarchingLevelSetBase
{
public:
    /** image dimension */
    enum { ImageDimension = 3 };

    /// typedefs
    /** pixel type of input image */
    typedef short InputPixelType;

    /** pixel type for computation */
    typedef double InternalPixelType;

    /** pixel type for thresholded image (output images) */
    typedef unsigned char ThresholdPixelType;

    /** type of input image */
    typedef itk::Image< InputPixelType, ImageDimension > InputImageType;

    /** type of internal image */
    typedef itk::Image< InternalPixelType, ImageDimension > InternalImageType;

    /** type of thresholded image */
    typedef itk::Image< ThresholdPixelType, ImageDimension > ThresholdedImageType;

    /** seed point type */
    typedef InternalImageType::IndexType IndexType;

    /** filter for reading input image */
    typedef itk::ImageFileReader< InputImageType > ImageReaderType;

    /** filter for writing output images */
    typedef itk::ImageFileWriter< ThresholdedImageType > ImageWriterType;

    /** cast filter for transform between input image and internal image */
    typedef itk::CastImageFilter< InputImageType, InternalImageType > CastImageFilterType;

    /** gradient magnitude filter type */
    typedef itk::GradientMagnitudeRecursiveGaussianImageFilter< InternalImageType > DerivativeFilterType;
	//typedef itk::GradientMagnitudeImageFilter< InternalImageType, InternalImageType > DerivativeFilterType;

    /** fast marching filter type */
    typedef itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingImageFilter;

    /** Threshold filter used to eliminate the infinite times assigned to non-visited pixels in the FastMarching filter. */
    typedef itk::IntensityWindowingImageFilter< InternalImageType, InternalImageType > FastMarchingWindowingFilterType;

    /** threshold filter used to select a time from the time map */
    typedef itk::BinaryThresholdImageFilter< InternalImageType, ThresholdedImageType > ThresholdFilterType;

    /** Fast Marching filter use to evolve the contours */
    typedef itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

    /** Filter to compute negative exponential of the gradient magnitude */
    typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType > SigmoidFilterType;

    /** Auxiliary types for seeds (Nodes) */
    typedef FastMarchingFilterType::NodeType NodeType;
    typedef FastMarchingFilterType::NodeContainer NodeContainer;


	typedef short DataFileOutputPixelType;
	
	typedef itk::Image<DataFileOutputPixelType, ImageDimension> DataFileOutputImageType;
	typedef itk::RescaleIntensityImageFilter< ThresholdedImageType, DataFileOutputImageType > DataFileOutputRescaleType;
	typedef itk::CastImageFilter< DataFileOutputImageType, DataFileOutputImageType > DataFileOutputCastFilterType;
	typedef itk::ImageFileWriter< DataFileOutputImageType > DataFileOutputImageWriterType;

public:
    FastMarchingLevelSetBase();
    virtual ~FastMarchingLevelSetBase();

    virtual void LoadInputImage() = 0;
    virtual void LoadInputImage(const char * filename);

    virtual void SaveOutputImage() = 0;
    virtual void SaveOutputImage(const char * filename);

    virtual void ShowStatus(const char * text) = 0;

    virtual void ComputeGradientMagnitude();

    virtual void ComputeEdgePotential();

    virtual void RunFastMarching();

    virtual void Stop();

    virtual void AddSeed(const IndexType & seed);

    virtual void ClearSeeds();

protected:
    void SetStoppingValue(double value);

protected:
    ImageReaderType::Pointer                 m_ImageReader;

    DataFileOutputImageWriterType::Pointer                 m_ImageWriter;

    bool                                     m_InputImageIsLoaded;

    CastImageFilterType::Pointer             m_CastImageFilter;

    FastMarchingFilterType::Pointer          m_FastMarchingFilter;

    FastMarchingWindowingFilterType::Pointer m_FastMarchingWindowingFilter;

    DerivativeFilterType::Pointer            m_DerivativeFilter;

    SigmoidFilterType::Pointer               m_SigmoidFilter;

    ThresholdFilterType::Pointer             m_ThresholdFilter;

    NodeContainer::Pointer                   m_TrialPoints;

    InternalPixelType                        m_SeedValue;

    unsigned int                             m_NumberOfSeeds;

	DataFileOutputRescaleType::Pointer		 m_OutputRescaler;
	DataFileOutputCastFilterType::Pointer	 m_OutputCastFilter;

};

# endif  // WKT_SEGMENTATION_FASTMARCHING_FASTMARCHINGBASE_H_
 