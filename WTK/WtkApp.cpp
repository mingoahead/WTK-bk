# include "WtkApp.h"

WtkApp::WtkApp(void)
{
    RegisterAllFactories::Register();

    InitGui();
}

WtkApp::~WtkApp(void)
{
    delete win;
}

void WtkApp::InitGui(void)
{
    // set window colors
    Fl::get_system_colors();

    // window
    win = new Fl_Double_Window(0, 0, 800, 600, "WtkApp");

    // menu
    menu_bar = new Fl_Sys_Menu_Bar(0, 0, win->w(), 25);

    // menu items
    menu_bar->add("File", 0, 0, 0, FL_SUBMENU);
    menu_bar->add("File/Open", 0, 0, 0, 0);
    menu_bar->add("File/Exit", 0, 0, 0, 0);
    menu_bar->add("Segmentation", 0, 0, 0, FL_SUBMENU);
    //menu_bar->add("Segmentation/Fast Marching 2D", 0, cb_segmentation_fastmarching_2d, this);
    menu_bar->add("Segmentation/Fast Marching 3D", 0, cb_segmentation_fastmarching_3d, this);
	menu_bar->add("Segmentation/Region growing 3D", 0, cb_segmentation_regiongrowing_3d, this);

    win->end();
    win->show();
}

void WtkApp::cb_segmentation_fastmarching_3d(Fl_Widget *w, void *p) 
{
    WtkApp *app = static_cast<WtkApp*> (p);
    FastMarchingLevelSet * console = new FastMarchingLevelSet();
    console->ShowConsole();
}

void WtkApp::cb_segmentation_fastmarching_2d(Fl_Widget *w, void *p)
{
    FM2D *app = new FM2D();
    app->ShowConsole();
}

void WtkApp::cb_segmentation_regiongrowing_3d(Fl_Widget *w, void *p)
{
	WtkApp *app = static_cast<WtkApp*> (p);
	RegionGrowingSegmentation * console = new RegionGrowingSegmentation();
	console->ShowConsole();
}
