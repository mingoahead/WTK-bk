# ifndef WTK_WTKAPP_H_
# define WTK_WTKAPP_H_

# include <FL/Fl.H>
# include <FL/Fl_Double_Window.H>
# include <FL/Fl_Sys_Menu_Bar.H>
# include "wtkutil.h"
# include "RegisterAllFactories.h"

class WtkApp
{
public:
    WtkApp(void);
    ~WtkApp(void);

    inline int x(void) {return win->x();}
    inline int y(void) {return win->y();}

private:
    void InitGui(void);

    static void cb_segmentation_fastmarching_2d(Fl_Widget *w, void *p);
    static void cb_segmentation_fastmarching_3d(Fl_Widget *w, void *p);
	static void cb_segmentation_regiongrowing_3d(Fl_Widget *w, void *p);

    Fl_Double_Window *win;
    Fl_Sys_Menu_Bar *menu_bar;
};

# endif  // WTK_WTKAPP_H_
