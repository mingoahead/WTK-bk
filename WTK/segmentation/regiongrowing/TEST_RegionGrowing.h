# ifndef WTK_SEGMENTATION_REGIONGROWING_TEST_REGIONGROWING_H_
# define WTK_SEGMENTATION_REGIONGROWING_TEST_REGIONGROWING_H_

class TEST_RegionGrowing {
public:
	TEST_RegionGrowing() {};
	virtual ~TEST_RegionGrowing() {};
	void RunTest() {
		try {
			RegionGrowingSegmentation * console = new RegionGrowingSegmentation();
			console->ShowConsole();
			Fl::run();
			delete console;
		}catch (itk::ExceptionObject & e) {
			std::cerr << "ITK exception caught in main" << std::endl;
			std::cerr << e << std::endl;
		}catch( std::exception & e ) {
			std::cerr << "STD exception caught in main" << std::endl;
		    std::cerr << e.what() << std::endl;
		}catch( ... ){
			std::cerr << "unknown exception caught in main" << std::endl;
		}
	}
}
# endif