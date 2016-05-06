# ifndef WTK_SEGMENTATION_FASTMARCHING_H_
# define WTK_SEGMENTATION_FASTMARCHING_H_

# include <string>
# include "itkCurvatureAnisotropicDiffusionImageFilter.h"
# include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
# include "itkSigmoidImageFilter.h"
# include "itkFastMarchingImageFilter.h"
# include "itkBinaryThresholdImageFilter.h"
# include "itkImageFileReader.h"
# include "itkImageFileWriter.h"
# include "itkRescaleIntensityImageFilter.h"
# include "itkMetaImageIOFactory.h"

// const
const unsigned int Dimension = 2;

// typedefs
// PixelTypes
typedef float InternalPixelType;
typedef unsigned char OutputPixelType;

// ImageTytpes
typedef itk::Image< InternalPixelType, Dimension > InternalImageType;
typedef itk::Image< OutputPixelType,   Dimension > OutputImageType;

typedef itk::BinaryThresholdImageFilter< InternalImageType, OutputImageType > ThresholdingFilterType;

typedef itk::ImageFileReader< InternalImageType > ReaderType;
typedef itk::ImageFileWriter<  OutputImageType  > WriterType;
typedef itk::ImageFileWriter< InternalImageType > InternalWriterType;

typedef itk::RescaleIntensityImageFilter< InternalImageType, OutputImageType > CastFilterType;
typedef itk::CurvatureAnisotropicDiffusionImageFilter< InternalImageType, InternalImageType > SmoothingFilterType;
typedef itk::GradientMagnitudeRecursiveGaussianImageFilter< InternalImageType, InternalImageType > GradientFilterType;
typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType > SigmoidFilterType;
typedef itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

typedef FastMarchingFilterType::NodeContainer NodeContainer;
typedef FastMarchingFilterType::NodeType NodeType;

class FastMarching
{
public:
    FastMarching(void);
    ~FastMarching(void);

    bool Perform();

    // set input output
    void set_input_image(std::string str) { input_image = str; }
    void set_output_image(std::string str) { output_image = str; }
    
    // output threshold filter
    void set_lower_threshold(double lb) { lower_threshold = lb; }
    void set_upper_threshold(double ub) { upper_threshold = ub; }
    void set_inside_value(unsigned int iv) { inside_value = iv; }
    void set_outside_value(unsigned int ov) { outside_value = ov; }

    // smooth filter
    void set_smooth_timestep(double st) { smooth_timestep = st; }
    void set_smooth_iterations(unsigned int nums) { smooth_iterations = nums; }
    void set_smooth_conductance(double c) { smooth_conductance = c; }

    // sigmoid filter
    void set_sigmoid_alpha(double a) { sigmoid_alpha = a; }
    void set_sigmoid_beta(double b) { sigmoid_beta = b; }

    // fastMarching
    void AddSeed(unsigned int pos_x, unsigned int pos_y);
    void RemoveSeed(unsigned int pos_x, unsigned int pos_y);
    void ClearSeeds();
    unsigned int SeedSize();
    void set_stopping_time(double st) { stopping_time = st; }

private:
    std::string input_image;
    std::string output_image;

    // parameters
    InternalPixelType lower_threshold;
    InternalPixelType upper_threshold;

    OutputPixelType inside_value;
    OutputPixelType outside_value;

    double smooth_timestep;
    unsigned int smooth_iterations;
    double smooth_conductance;

    double guassian_sigma;

    double sigmoid_alpha;
    double sigmoid_beta;

    NodeContainer::Pointer seeds;

    double stopping_time;
};

# endif  // WTK_SEGMENTATION_FASTMARCHING_H_
