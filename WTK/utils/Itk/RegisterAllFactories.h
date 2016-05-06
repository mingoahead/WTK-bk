# ifndef WTK_UTILS_REGISTERALLFACTORIES_H_
# define WTK_UTILS_REGISTERALLFACTORIES_H_

# include "itkImageIOFactory.h"
# include "itkPNGImageIOFactory.h"
# include "itkMetaImageIOFactory.h"
# include "itkBMPImageIOFactory.h"
# include "itkJPEGImageIOFactory.h"
# include "itkGDCMImageIOFactory.h"

class RegisterAllFactories {
public:
    RegisterAllFactories() {} ;
    virtual ~RegisterAllFactories() {} ;

    static void Register() {
        // TODO :
        // ���ｫ���ǵ���IO��ע��һ��
        // ���Կ��Ǹ�Ϊֻע����Ҫ��IO
        itk::PNGImageIOFactory::RegisterOneFactory();
        itk::BMPImageIOFactory::RegisterOneFactory();
        itk::MetaImageIOFactory::RegisterOneFactory();
        itk::JPEGImageIOFactory::RegisterOneFactory();
        itk::GDCMImageIOFactory::RegisterOneFactory();
    }
};

# endif  // WTK_UTILS_REGISTERALLFACTORIES_H_
