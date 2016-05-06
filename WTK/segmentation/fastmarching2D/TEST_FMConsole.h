# ifndef WTK_SEGMENTATION_FASTMARCHING_TEST_FMCONSOLE_H_
# define WTK_SEGMENTATION_FASTMARCHING_TEST_FMCONSOLE_H_

# include <iostream>
# include "FM2D.h"

using namespace std;

class TEST_FMConsole {
public:
    TEST_FMConsole() {}
    void RunTest() {        
        try {
            FM2D * cons = new FM2D();
            cons->ShowConsole();
            Fl::run();
            delete cons;
        } catch( itk::ExceptionObject & e ) {
            std::cerr << "ITK exception caught in main" << std::endl;
            std::cerr << e << std::endl;
        } catch( std::exception & e ) {
            std::cerr << "STD exception caught in main" << std::endl;
            std::cerr << e.what() << std::endl;
        } catch( ... ) {
            std::cerr << "unknown exception caught in main" << std::endl;
        }
    }
};

# endif  // WTK_SEGMENTATION_FASTMARCHING_TEST_FMCONSOLE_H_
