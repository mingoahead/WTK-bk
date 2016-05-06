// FMConsole 作为FMGUI的基类，提供fastmarching算法的整个流程
//

# ifndef WTK_SEGMENTATION_FASTMARCHING_FMCONSOLE_H_
# define WTK_SEGMENTATION_FASTMARCHING_FMCONSOLE_H_

# include <iostream>
# include <string>
# include <set>
# include "itkImageFileReader.h"
# include "itkImageFileWriter.h"
# include "itkCurvatureAnisotropicDiffusionImageFilter.h"
# include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
# include "itkSigmoidImageFilter.h"
# include "itkFastMarchingImageFilter.h"
# include "itkBinaryThresholdImageFilter.h"
# include "itkRescaleIntensityImageFilter.h"
# include "itkLabelObject.h"
# include "itkLabelMap.h"
# include "itkLabelImageToLabelMapFilter.h"
# include "itkLabelMapOverlayImageFilter.h"

static const unsigned int kDimension = 2;
static const double kSeedValue = 0.0;

// typedefs
typedef double InternalPixelType;
typedef unsigned char OutputPixelType;
typedef itk::Image< InternalPixelType, kDimension > InternalImageType;
typedef itk::Image< OutputPixelType, kDimension > OutputImageType;
typedef itk::BinaryThresholdImageFilter< InternalImageType, OutputImageType > ThresholdingFilterType;
typedef itk::ImageFileReader< InternalImageType > ReaderType;
typedef itk::ImageFileWriter<  OutputImageType  > WriterType;
typedef itk::RescaleIntensityImageFilter< InternalImageType, OutputImageType > CastFilterType;
typedef itk::CurvatureAnisotropicDiffusionImageFilter< InternalImageType, InternalImageType > SmoothingFilterType;
typedef itk::GradientMagnitudeRecursiveGaussianImageFilter< InternalImageType, InternalImageType > GradientFilterType;
typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType > SigmoidFilterType;
typedef itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;
typedef FastMarchingFilterType::NodeContainer NodeContainer;
typedef FastMarchingFilterType::NodeType NodeType;

typedef OutputPixelType LabelType;
typedef itk::Image< LabelType, kDimension > LabelImageType;
typedef itk::ImageFileReader< LabelImageType >  LabelReaderType;
typedef itk::LabelObject< LabelType, kDimension > LabelObjectType;
typedef itk::LabelMap< LabelObjectType > LabelMapType;
typedef itk::LabelImageToLabelMapFilter< OutputImageType, LabelMapType > LabelConverterType;
typedef itk::LabelMapOverlayImageFilter< LabelMapType, OutputImageType > LabelFilterType;
typedef itk::ImageFileWriter< LabelFilterType::OutputImageType > LabelWriterType;

class Point2i{
public:
    int x, y;
    Point2i(int _x, int _y): x(_x), y(_y) {}
    friend bool operator < (Point2i const & _a, Point2i const & _b) {
        if (_a.x == _b.x) {
            return _a.y < _b.y;
        } else {
            return _a.x < _b.x;
        }
    }
};

typedef std::set< Point2i > PointSet;

class FMConsole
{
public:
    FMConsole();   // 完成参数的默认初始化值

    virtual ~FMConsole();

    bool Run();  // 执行Fast Marching

    inline void ClearAllSeed(void) { seedSet.clear(); }
    inline void AddSeed(int x, int y) { seedSet.insert( Point2i(x, y) ); }
    inline void DelSeed(int x, int y) { seedSet.erase( Point2i(x, y) ); }

    std::string m_inputImage;
    std::string m_outputImage;
    std::string m_smoothImage;
    std::string m_GMImage;
    std::string m_sigmoidImage;
    std::string m_FMoutputImage;
    std::string m_overlayOutputImage;

protected:
    int BuildSeedContainer(NodeContainer::Pointer &);

    unsigned int m_nItersSmooth;
    double m_timeStepSmooth;
    double m_conductanceSmooth;

    double m_sigmaGM;

    double m_alphaSigmoid;
    double m_betaSigmoid;

    InternalPixelType m_timeThreshold;

    double m_stoppingTime;
    
    double m_labelOpacity;

private:
    PointSet seedSet;
};

# endif  // WTK_SEGMENTATION_FASTMARCHING_FMCONSOLE_H_
