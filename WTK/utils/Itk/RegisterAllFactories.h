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
        // 这里将考虑到的IO都注册一遍
        // 可以考虑改为只注册需要的IO
        itk::PNGImageIOFactory::RegisterOneFactory();
        itk::BMPImageIOFactory::RegisterOneFactory();
        itk::MetaImageIOFactory::RegisterOneFactory();
        itk::JPEGImageIOFactory::RegisterOneFactory();
        itk::GDCMImageIOFactory::RegisterOneFactory();
    }
};

# endif  // WTK_UTILS_REGISTERALLFACTORIES_H_
