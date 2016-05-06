# ifndef WTK_SEGMENTATION_FASTMARCHING_TEST_FASTMARCHINGLEVELSET_H_
# define WTK_SEGMENTATION_FASTMARCHING_TEST_FASTMARCHINGLEVELSET_H_

# include "FastMarchingLevelSet.h"

class TEST_FastMarchingLevelSet {
public:
    TEST_FastMarchingLevelSet() {};
    virtual ~TEST_FastMarchingLevelSet() {};

    void RunTest() {
        try {
            FastMarchingLevelSet * console = new FastMarchingLevelSet();
            console->ShowConsole();
            Fl::run();
            delete console;
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

# endif  // WTK_SEGMENTATION_FASTMARCHING_TEST_FASTMARCHINGLEVELSET_H_
