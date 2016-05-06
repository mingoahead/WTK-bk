# ifndef WTK_SEGMENTATION_FASTMARCHING2D_FMGUI_H_
# define WTK_SEGMENTATION_FASTMARCHING2D_FMGUI_H_

# include <FL/Fl.H>
# include <FL/Fl_Double_Window.H>
# include <FL/Fl_Group.H>
# include <FL/Fl_Box.H>
# include <FL/Fl_Button.H>
# include <FL/Fl_Value_Input.H>
# include <FL/Fl_Output.H>
# include "fltkProgressBar.h"
# include "fltkLightButton.h"
# include "FMBase.h"

class FMGUI :
    public FMBase
{
public:
    FMGUI(void);
    virtual ~FMGUI(void);
    virtual void Load( void );
    virtual void ShowInputImage( void );
    virtual void ShowSmoothingImage( void );
    virtual void ShowGradientMagnitudeImage( void );
    virtual void ShowEdgePotentialImage( void );
    virtual void ShowTimeCrossingMapImage( void );
    virtual void ShowThresholdedImage( void );
    virtual void SaveOutputImage( void );
    virtual void ShowSegmentedImage( void );
    virtual void ShowThresholdedImageWithVTK( void );
    virtual void Quit( void );
    virtual void ShowAbout( void );
    virtual void ShowConsole( void );
    virtual void UpdateExtract();

private:
    /** Load input image */
    inline void cb_Load_i(Fl_Button*, void*);
    static void cb_Load(Fl_Button*, void*);

    /** Show input image */
    inline void cb_inputImageButton_i(fltk::LightButton*, void*);
    static void cb_inputImageButton(fltk::LightButton*, void*);

    /** Run Curvature anisotropic diffusion image filter */
    inline void cb_CurvatureAnisotropicDiffusion_i(Fl_Button*, void*);
    static void cb_CurvatureAnisotropicDiffusion(Fl_Button*, void*);

    /** Display Curvature anisotropic diffusion image */
    inline void cb_CuravtureImageButton_i(fltk::LightButton*, void*);
    static void cb_CuravtureImageButton(fltk::LightButton*, void*);

    /** Set num of interations */
    inline void cb_numOfItersInput_i(Fl_Value_Input*, void*);
    static void cb_numOfItersInput(Fl_Value_Input*, void*);

    /** Set conductance */
    inline void cb_conductanceInput_i(Fl_Value_Input*, void*);
    static void cb_conductanceInput(Fl_Value_Input*, void*);

    /** Run gradient magnitude filter */
    inline void cb_Gradient_i(Fl_Button*, void*);
    static void cb_Gradient(Fl_Button*, void*);

    /** Set gradient magnitude sigma */
    inline void cb_sigmaValueInput_i(Fl_Value_Input*, void*);
    static void cb_sigmaValueInput(Fl_Value_Input*, void*);

    /** Show gradient magnitude image */
    inline void cb_gradientMagnitudeButton_i(fltk::LightButton*, void*);
    static void cb_gradientMagnitudeButton(fltk::LightButton*, void*);

    /** Run sigmoid filter */
    inline void cb_Linear_i(Fl_Button*, void*);
    static void cb_Linear(Fl_Button*, void*);

    /** Set sigmoid alpha & beta */
    inline void cb_betaValueInput_i(Fl_Value_Input*, void*);
    static void cb_betaValueInput(Fl_Value_Input*, void*);
    inline void cb_alphaValueInput_i(Fl_Value_Input*, void*);
    static void cb_alphaValueInput(Fl_Value_Input*, void*);

    /** Show sigmoid image */
    inline void cb_edgePotentialButton_i(fltk::LightButton*, void*);
    static void cb_edgePotentialButton(fltk::LightButton*, void*);

    /** Run fast-marching filter */
    inline void cb_Fast_i(Fl_Button*, void*);
    static void cb_Fast(Fl_Button*, void*);

    /** Set stopping value */
    inline void cb_stoppingValueInput_i(Fl_Value_Input*, void*);
    static void cb_stoppingValueInput(Fl_Value_Input*, void*);

    /** Clear seeds */
    inline void cb_Clear_i(Fl_Button*, void*);
    static void cb_Clear(Fl_Button*, void*);

    /** Show time-crossing map image */
    inline void cb_timeCrossingButton_i(fltk::LightButton*, void*);
    static void cb_timeCrossingButton(fltk::LightButton*, void*);

    /** Set upper & lower threshold value */
    inline void cb_upperThresholdValueInput_i(Fl_Value_Input*, void*);
    static void cb_upperThresholdValueInput(Fl_Value_Input*, void*);
    inline void cb_lowerThresholdValueInput_i(Fl_Value_Input*, void*);
    static void cb_lowerThresholdValueInput(Fl_Value_Input*, void*);

    /** Run threshold filter */
    inline void cb_Threshold_i(Fl_Button*, void*);
    static void cb_Threshold(Fl_Button*, void*);

    /** Save output image */
    inline void cb_Save_i(Fl_Button*, void*);
    static void cb_Save(Fl_Button*, void*);

    /** Show thresholded image */
    inline void cb_thresholdedImageButton_i(fltk::LightButton*, void*);
    static void cb_thresholdedImageButton(fltk::LightButton*, void*);

    /** Show segmentation iamge */
    inline void cb_segmentedImageButton_i(fltk::LightButton*, void*);
    static void cb_segmentedImageButton(fltk::LightButton*, void*);

    /** Show thresholded image using vtk */
    inline void cb_thresholdedImageVTKButton_i(fltk::LightButton*, void*);
    static void cb_thresholdedImageVTKButton(fltk::LightButton*, void*);

    /** Quit app */
    inline void cb_Quit_i(Fl_Button*, void*);
    static void cb_Quit(Fl_Button*, void*);

protected:
    // 主界面
    Fl_Double_Window *consoleWindow;

    // 所有连接线放在一个Group中
    Fl_Group *connectors;

    // 所有控制组件放在另一个Group中
    Fl_Group *controlsGroup;

    // 打开图像按钮: Display
    fltk::LightButton *inputImageButton;

    // 显示平滑结果
    fltk::LightButton *smoothImageButton;

    // 平滑参数
    Fl_Value_Input *numItersValueInput;
    Fl_Value_Input *conductanceValueInput;

    // 阈值输出：Display和VTK Render
    fltk::LightButton *thresholdedImageButton;
    fltk::LightButton *thresholdedImageVTKButton;

    // 设置阈值上下限： Upper， Lower
    Fl_Value_Input *upperThresholdValueInput;
    Fl_Value_Input *lowerThresholdValueInput;

    // 显示Time Cross图像： Time Crossing Map
    fltk::LightButton *timeCrossingButton;

    // 显示梯度图像： Display
    fltk::LightButton *gradientMagnitudeButton;

    // 显示Sigmoid处理后的图像：Display
    fltk::LightButton *edgePotentialButton;

    // 梯度图像参数：sigma
    Fl_Value_Input *sigmaValueInput;

    // FastMarching分割结果，使用覆盖方式显示： Overlay
    fltk::LightButton *segmentedImageButton;

    // sigmoid的参数： alplha和beta
    Fl_Value_Input *betaValueInput;
    Fl_Value_Input *alphaValueInput;

    // fastmarching的stopping time： Stopping
    Fl_Value_Input *stoppingValueInput;

    // 进度条
    fltk::ProgressBar *progressSlider;

    // 状态栏
    Fl_Output *statusTextOutput;
};

# endif  // WTK_SEGMENTATION_FASTMARCHING2D_FMGUI_H_
