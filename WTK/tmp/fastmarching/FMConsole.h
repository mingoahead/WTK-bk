// FMConsole 作为FMGUI的基类，提供fastmarching算法的整个流程
//

# ifndef WTK_FMCONSOLE_H_
# define WTK_FMCONSOLE_H_

# include <iostream>
# include <string>
# include <set>
# include "itkCurvatureAnisotropicDiffusionImageFilter.h"
# include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
# include "itkSigmoidImageFilter.h"
# include "itkFastMarchingImageFilter.h"
# include "itkBinaryThresholdImageFilter.h"
# include "itkImageFileReader.h"
# include "itkImageFileWriter.h"
# include "itkRescaleIntensityImageFilter.h"
# include "itkTestDriverIncludeRequiredIOFactories.h"

const unsigned int kDimension = 2;
const double kSeedValue = 0.0;

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

typedef std::set< Point2i > PointSet;

struct Point2i{
    int x, y;
    Point2i(int _x, int _y): x(_x), y(_y) {}
    bool operator < (Point2i const & _a, Point2i const & _b) {
        if (_a.x == _b.x) {
            return _a.y < _b.y;
        } else {
            return _a.x < _b.x;
        }
    }
}

class FMConsole
{
public:
    FMConsole();  // 完成参数的默认初始化值
    virtual ~FMConsole();

    bool Run();  // 执行 Fast Marching

    void ClearAllSeed(void) { seedSet.clear(); }
    void AddSeed(int x, int y) { seedSet.insert( Point2i(x, y) ); }
    void DelSeed(int x, int y) { seedSet.erase( Point2i(x, y) ); }

protected:
    int BuildSeedContainer();

    std::string m_inputImage;
    std::string m_outputImage;
    std::string m_smoothImage;
    std::string m_GMImage;
    std::string m_sigmoidImage;
    std::string m_FMoutputImage;

    unsigned int m_nItersSmooth;
    double m_timeStepSmooth;
    double m_conductanceSmooth;

    double m_sigmaGM;

    double m_alphaSigmoid;
    double m_betaSigmoid;

    InternalPixelType m_timeThreshold;

    double m_stoppingTime;

private:
    PointSet seedSet;
};

# endif  // WTK_FMCONSOLE_H_
