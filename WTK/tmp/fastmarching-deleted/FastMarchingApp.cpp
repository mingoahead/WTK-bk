# include "FastMarchingApp.h"
# include <Fl/Fl_Box.H>
# include <Fl/Enumerations.H> 
# include <segmentation/fastmarching/FMConsole.h>
# include <vector>

//WtkApp *FastMarchingApp::app = NULL;

FastMarchingApp::FastMarchingApp(/*WtkApp *p*/)
{/*
    app = static_cast<WtkApp*>(p);

    InitGui();

    fastmarching = new FastMarching();*/
}

FastMarchingApp::~FastMarchingApp(void)
{/*
    delete fastmarching;
    delete win;   */ 
}

/*
void FastMarchingApp::InitGui(void)
{
    // app window
    win = new Fl_Double_Window(app->x()+50, app->y()+50, 665, 400, "Fast marching");

    Fl_Box *menu_box = new Fl_Box(5, 5, 360, 45);
    menu_box->label("Menu");
    menu_box->labelfont(1);
    menu_box->align(21);

    Fl_Box *input_box = new Fl_Box(5, 55, 140, 235);
    input_box->label("Image to Segment");
    input_box->labelfont(1);
    input_box->type(FL_ROUND_UP_BOX);
    input_box->color(255);
    input_box->redraw();

    open_image_btn = new Fl_Light_Button(0,0,100,20, "Input Image");
    perform_btn = new Fl_Light_Button(0,20, 80, 20, "Peform");
    perform_btn->selection_color( FL_BACKGROUND_COLOR );
    //perform_btn->callback( perform_btn_cb, this );

    Fl_Box *params_box = new Fl_Box(370, 5, 290, 285);

    win->end();
    win->show(); 
}
void FastMarchingApp::perform_btn_cb(Fl_Widget *w, void *p)
{
    Fl_Light_Button *btn = static_cast<Fl_Light_Button*> (w);
    FastMarchingApp *pt = static_cast<FastMarchingApp*> (p);

    btn->deactivate();
    if ( pt->fastmarching->Perform() ) {
        btn->selection_color( FL_GREEN );
    } else {
        btn->selection_color( FL_RED );
    }
    btn->value(1);
    btn->activate();
}
*/
