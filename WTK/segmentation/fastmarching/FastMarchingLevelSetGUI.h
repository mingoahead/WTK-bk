# ifndef WTK_SEGMENTATION_FASTMARCHING_FASTMARCHINGLEVELSETGUI_H_
# define WTK_SEGMENTATION_FASTMARCHING_FASTMARCHINGLEVELSETGUI_H_

# include <FL/Fl.H>
# include <FL/Fl_Double_Window.H>
# include <FL/Fl_Group.H>
# include <FL/Fl_Box.H>
# include <FL/Fl_Button.H>
# include <FL/Fl_Value_Input.H>
# include <FL/Fl_Output.H>
# include "fltkProgressBar.h"
# include "fltkLightButton.h"
# include "FastMarchingLevelSetBase.h"

class FastMarchingLevelSetGUI : public FastMarchingLevelSetBase
{
public:
    FastMarchingLevelSetGUI();
    virtual ~FastMarchingLevelSetGUI();
    virtual void Quit( void );
    virtual void Load( void );
    virtual void ShowAbout( void );
    virtual void ShowInputImage( void );
    virtual void ShowConsole( void );
    virtual void ShowThresholdedImage( void );
    virtual void UpdateExtract();
    virtual void ShowThresholdedImageWithVTK( void );
    virtual void ShowTimeCrossingMapImage( void );
    virtual void ShowGradientMagnitudeImage( void );
    virtual void ShowEdgePotentialImage( void );
    virtual void ShowSegmentedImage( void );
    virtual void SaveOutputImage( void );

private:
    inline void cb_inputImageButton_i(fltk::LightButton*, void*);
    static void cb_inputImageButton(fltk::LightButton*, void*);
    inline void cb_Fast_i(Fl_Button*, void*);
    static void cb_Fast(Fl_Button*, void*);
    inline void cb_thresholdedImageButton_i(fltk::LightButton*, void*);
    static void cb_thresholdedImageButton(fltk::LightButton*, void*);
    inline void cb_thresholdedImageVTKButton_i(fltk::LightButton*, void*);
    static void cb_thresholdedImageVTKButton(fltk::LightButton*, void*);
    inline void cb_Clear_i(Fl_Button*, void*);
    static void cb_Clear(Fl_Button*, void*);
    inline void cb_Threshold_i(Fl_Button*, void*);
    static void cb_Threshold(Fl_Button*, void*);
    inline void cb_upperThresholdValueInput_i(Fl_Value_Input*, void*);
    static void cb_upperThresholdValueInput(Fl_Value_Input*, void*);
    inline void cb_lowerThresholdValueInput_i(Fl_Value_Input*, void*);
    static void cb_lowerThresholdValueInput(Fl_Value_Input*, void*);
    inline void cb_timeCrossingButton_i(fltk::LightButton*, void*);
    static void cb_timeCrossingButton(fltk::LightButton*, void*);
    inline void cb_Gradient_i(Fl_Button*, void*);
    static void cb_Gradient(Fl_Button*, void*);
    inline void cb_gradientMagnitudeButton_i(fltk::LightButton*, void*);
    static void cb_gradientMagnitudeButton(fltk::LightButton*, void*);
    inline void cb_Linear_i(Fl_Button*, void*);
    static void cb_Linear(Fl_Button*, void*);
    inline void cb_edgePotentialButton_i(fltk::LightButton*, void*);
    static void cb_edgePotentialButton(fltk::LightButton*, void*);
    inline void cb_sigmaValueInput_i(Fl_Value_Input*, void*);
    static void cb_sigmaValueInput(Fl_Value_Input*, void*);
    inline void cb_segmentedImageButton_i(fltk::LightButton*, void*);
    static void cb_segmentedImageButton(fltk::LightButton*, void*);
    inline void cb_betaValueInput_i(Fl_Value_Input*, void*);
    static void cb_betaValueInput(Fl_Value_Input*, void*);
    inline void cb_alphaValueInput_i(Fl_Value_Input*, void*);
    static void cb_alphaValueInput(Fl_Value_Input*, void*);
    inline void cb_stoppingValueInput_i(Fl_Value_Input*, void*);
    static void cb_stoppingValueInput(Fl_Value_Input*, void*);
    inline void cb_Save_i(Fl_Button*, void*);
    static void cb_Save(Fl_Button*, void*);
    inline void cb_Quit_i(Fl_Button*, void*);
    static void cb_Quit(Fl_Button*, void*);
    inline void cb_Load_i(Fl_Button*, void*);
    static void cb_Load(Fl_Button*, void*);

public:
    Fl_Double_Window *consoleWindow;
    Fl_Group *Connectors;
    Fl_Group *controlsGroup;
    fltk::LightButton *inputImageButton;
    fltk::LightButton *thresholdedImageButton;
    fltk::LightButton *thresholdedImageVTKButton;
    Fl_Value_Input *upperThresholdValueInput;
    Fl_Value_Input *lowerThresholdValueInput;
    fltk::LightButton *timeCrossingButton;
    fltk::LightButton *gradientMagnitudeButton;
    fltk::LightButton *edgePotentialButton;
    Fl_Value_Input *sigmaValueInput;
    fltk::LightButton *segmentedImageButton;
    Fl_Value_Input *betaValueInput;
    Fl_Value_Input *alphaValueInput;
    Fl_Value_Input *stoppingValueInput;
    fltk::ProgressBar *progressSlider;
    Fl_Output *statusTextOutput;
};

# endif // WTK_SEGMENTATION_FASTMARCHING_FASTMARCHINGLEVELSETGUI_H_
