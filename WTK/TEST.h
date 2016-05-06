# ifndef WTK_TEST_H_
# define WTK_TEST_H_

# include <iostream>
# include <fstream>

#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

# include "segmentation/fastmarching2D/TEST_FMConsole.h"
# include "segmentation/fastmarching/TEST_FastMarchingLevelSet.h"
# include "segmentation/regiongrowing/RegionGrowingSegmentation.h"
# include "RegisterAllFactories.h"

using namespace std;

class WTK_Test {
public:
    WTK_Test() {
        RegisterAllFactories::Register();
    };

    virtual ~WTK_Test() {};

    inline void Run(bool rdbuf = false, const char *fn = "", ios_base::openmode mode = ios_base::out) {
        // redirect output
        ofstream outfile( fn, mode );
        streambuf* coutBuf = cout.rdbuf();
        streambuf* cerrBuf = cerr.rdbuf();
        if (rdbuf) {
            cout.rdbuf(outfile.rdbuf());
            cerr.rdbuf(outfile.rdbuf());
        }

        /************************************************************************/
        /* BEGIN OF TEST                                                        */
        /************************************************************************/

        // Fast Marching (2D version)
        //TEST_FMConsole *test_fmconsole = new TEST_FMConsole();
        //test_fmconsole->RunTest();
        //delete test_fmconsole;

        // Fast Marching (3D version)
        TEST_FastMarchingLevelSet *test_FastMarchingLevelSet = new TEST_FastMarchingLevelSet();
        test_FastMarchingLevelSet->RunTest();
        delete test_FastMarchingLevelSet;

        /************************************************************************/
        /*  END OF TEST                                                      */
        /************************************************************************/

        outfile.flush();
        outfile.close();
        if (rdbuf) {
            cout.rdbuf( coutBuf );
            cerr.rdbuf( cerrBuf );
        }
    }
};     

# endif  // WTK_TEST_H_
