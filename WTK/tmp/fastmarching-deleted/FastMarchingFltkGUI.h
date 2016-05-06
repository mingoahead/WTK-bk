# ifndef WTK_SEGMENTATION_FASTMARCHINGFLTKGUI_H_
# define WTK_SEGMENTATION_FASTMARCHINGFLTKGUI_H_

# include <FL/Enumerations.H>
# include <FL/Fl_Double_Window.H>
# include <FL/Fl_Group.H>
# include <FL/Fl_Light_Button.H>
# include <FL/Fl_Spinner.H>
# include <FL/Fl_Box.H>
# include <FL/Fl_File_Chooser.H>
# include <string>

class FastMarchingFltkGUI
{
public:
    FastMarchingFltkGUI(void);
    virtual ~FastMarchingFltkGUI(void);

    /// 
    static std::string recent_file;
    static std::string image_name;
    
    /// callbacks
    static void load_cb(Fl_Widget *obj, void *data);

    /// GUI window
    Fl_Double_Window *console_window;

    /// Groups
    Fl_Group *input_group;
    Fl_Light_Button *load_image;

    Fl_Group *smooth_group;
    Fl_Spinner *smooth_iters;
    Fl_Spinner *smooth_timeStep;
    Fl_Spinner *smooth_conductance;

    Fl_Group *gradientMagnitude_group;
    Fl_Spinner *gm_sigma;

    Fl_Group *sigmoid_group;
    Fl_Spinner *sigmoid_alpha;
    Fl_Spinner *sigmoid_beta;
    Fl_Spinner *sigmoid_outputMin;
    Fl_Spinner *sigmoid_outputMax;

    Fl_Group *fastMarching_group;
    Fl_Spinner *fm_stoppingTime;

    Fl_Group *thresholder_group;
    Fl_Spinner *th_lowerTh;
    Fl_Spinner *th_upperTh;
    Fl_Spinner *th_insideValue;
    Fl_Spinner *th_outsideValue;

    Fl_Group *seeds_group;

    /// executors
    Fl_Light_Button *input_btn;
    Fl_Light_Button *smooth_btn;
    Fl_Light_Button *gm_btn;
    Fl_Light_Button *sigmoid_btn;
    Fl_Light_Button *fm_btn;
};

# endif  // WTK_SEGMENTATION_FASTMARCHINGFLTKGUI_H_
