# ifndef WTK_SEGMENTATION_FASTMARCHINGAPP_H_
# define WTK_SEGMENTATION_FASTMARCHINGAPP_H_

# include "FastMarchingFltkGUI.h"
# include "WtkApp.h"

class FastMarchingApp: public FastMarchingFltkGUI
{
public:
    FastMarchingApp(/*WtkApp */);
    ~FastMarchingApp(void);
    /*
private:
    void InitGui(void);

    // callbacks
    static void perform_btn_cb(Fl_Widget *w, void *data);

    // app : parent
    static WtkApp *app;

    // win : main window
    Fl_Double_Window *win;

    // btns
    Fl_Light_Button *open_image_btn;
    Fl_Light_Button *perform_btn;
    
    // fastmarching : executor
    FastMarching *fastmarching;*/
};

# endif  // WTK_FASTMARCHINGAPP_H_
