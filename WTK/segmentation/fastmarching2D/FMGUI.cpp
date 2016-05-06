#include "FMGUI.h"


FMGUI::FMGUI(void)
{
    {
        consoleWindow = new Fl_Double_Window(830 + 165, 280, "Fast Marching Segmentation Level Set (2D)");
        consoleWindow->user_data((void*)(this));
        {
            connectors = new Fl_Group(0, 0, 820, 210);
            {
                Fl_Box* o = new Fl_Box(679 + 165, 39, 61, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(245, 80, 10, 70);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(200, 78, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(230 + 165, 80, 10, 70);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(65, 79, 80, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(200 + 165, 78, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(679 + 165, 79, 61, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(505 + 165, 80, 10, 70);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(680 + 165, 119, 61, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(650 + 165, 82, 10, 100);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(679 + 165, 39, 10, 90);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(470 + 165, 79, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(610 + 165, 79, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(65, 45, 10, 95);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(360 + 165, 80, 10, 100);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(325 + 165, 79, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(415 + 165, 90, 10, 95);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)21);
            } // Fl_Box* o
            connectors->end();
        } // Fl_Group* Connectors

        /// controls group
        {
            controlsGroup = new Fl_Group(5, 5, 815, 215);
            controlsGroup->deactivate();
            {
                inputImageButton = new fltk::LightButton(34, 129, 70, 29, "Display");
                inputImageButton->type(0);
                inputImageButton->box(FL_UP_BOX);
                inputImageButton->value(1);
                inputImageButton->color(FL_BACKGROUND_COLOR);
                inputImageButton->selection_color((Fl_Color)1);
                inputImageButton->labeltype(FL_NORMAL_LABEL);
                inputImageButton->labelfont(0);
                inputImageButton->labelsize(12);
                inputImageButton->labelcolor(FL_FOREGROUND_COLOR);
                inputImageButton->callback((Fl_Callback*)cb_inputImageButton);
                inputImageButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                inputImageButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* inputImageButton
            {
                smoothImageButton = new fltk::LightButton(220, 147, 70, 29, "Display");
                smoothImageButton->type(0);
                smoothImageButton->box(FL_UP_BOX);
                smoothImageButton->value(1);
                smoothImageButton->color(FL_BACKGROUND_COLOR);
                smoothImageButton->selection_color((Fl_Color)1);
                smoothImageButton->labeltype(FL_NORMAL_LABEL);
                smoothImageButton->labelfont(0);
                smoothImageButton->labelsize(12);
                smoothImageButton->labelcolor(FL_FOREGROUND_COLOR);
                smoothImageButton->callback((Fl_Callback*)cb_CuravtureImageButton);
                smoothImageButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                smoothImageButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* smoothImageButton
            {
                Fl_Button* o = new Fl_Button(381 + 165, 66, 117, 34, "Fast Marching");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Fast);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                thresholdedImageButton = new fltk::LightButton(714 + 165, 68, 90, 31, "Display");
                thresholdedImageButton->type(0);
                thresholdedImageButton->box(FL_UP_BOX);
                thresholdedImageButton->value(1);
                thresholdedImageButton->color(FL_BACKGROUND_COLOR);
                thresholdedImageButton->selection_color((Fl_Color)1);
                thresholdedImageButton->labeltype(FL_NORMAL_LABEL);
                thresholdedImageButton->labelfont(0);
                thresholdedImageButton->labelsize(12);
                thresholdedImageButton->labelcolor(FL_FOREGROUND_COLOR);
                thresholdedImageButton->callback((Fl_Callback*)cb_thresholdedImageButton);
                thresholdedImageButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                thresholdedImageButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* thresholdedImageButton
            {
                thresholdedImageVTKButton = new fltk::LightButton(714 + 165, 109, 90, 30, "VTK Render");
                thresholdedImageVTKButton->type(0);
                thresholdedImageVTKButton->box(FL_UP_BOX);
                thresholdedImageVTKButton->value(1);
                thresholdedImageVTKButton->color(FL_BACKGROUND_COLOR);
                thresholdedImageVTKButton->selection_color((Fl_Color)1);
                thresholdedImageVTKButton->labeltype(FL_NORMAL_LABEL);
                thresholdedImageVTKButton->labelfont(0);
                thresholdedImageVTKButton->labelsize(12);
                thresholdedImageVTKButton->labelcolor(FL_FOREGROUND_COLOR);
                thresholdedImageVTKButton->callback((Fl_Callback*)cb_thresholdedImageVTKButton);
                thresholdedImageVTKButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                thresholdedImageVTKButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* thresholdedImageVTKButton
            {
                Fl_Button* o = new Fl_Button(400 + 165, 170, 94, 35, "Clear Seeds");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Clear);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                Fl_Button* o = new Fl_Button(525 + 165, 66, 117, 34, "Threshold");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Threshold);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                numItersValueInput = new Fl_Value_Input(159, 110, 55, 25, "nIters");
                numItersValueInput->labelsize(12);
                numItersValueInput->maximum(1000);
                numItersValueInput->step(1);
                numItersValueInput->value(5);
                numItersValueInput->textsize(12);
                numItersValueInput->callback((Fl_Callback*)cb_numOfItersInput);
            } // Fl_Value_Input *numItersValueInput
            {
                conductanceValueInput = new Fl_Value_Input(159, 135, 55, 25, "Condc.");
                conductanceValueInput->labelsize(12);
                conductanceValueInput->maximum(10.0);
                conductanceValueInput->step(0.01);
                conductanceValueInput->value(9.0);
                conductanceValueInput->textsize(12);
                conductanceValueInput->callback((Fl_Callback*)cb_conductanceInput);
            } // Fl_Value_Input *conductanceValueInput
            {
                upperThresholdValueInput = new Fl_Value_Input(570 + 165, 15, 55, 25, "Upper");
                upperThresholdValueInput->labelsize(12);
                upperThresholdValueInput->maximum(1000);
                upperThresholdValueInput->step(0.1);
                upperThresholdValueInput->value(100);
                upperThresholdValueInput->textsize(12);
                upperThresholdValueInput->callback((Fl_Callback*)cb_upperThresholdValueInput);
            } // Fl_Value_Input* upperThresholdValueInput
            {
                lowerThresholdValueInput = new Fl_Value_Input(570 + 165, 40, 55, 25, "Lower");
                lowerThresholdValueInput->labelsize(12);
                lowerThresholdValueInput->maximum(1000);
                lowerThresholdValueInput->step(0.1);
                lowerThresholdValueInput->textsize(12);
                lowerThresholdValueInput->callback((Fl_Callback*)cb_lowerThresholdValueInput);
            } // Fl_Value_Input* lowerThresholdValueInput
            {
                timeCrossingButton = new fltk::LightButton(442 + 165, 129, 145, 29, "Time Crossing Map");
                timeCrossingButton->type(0);
                timeCrossingButton->box(FL_UP_BOX);
                timeCrossingButton->value(1);
                timeCrossingButton->color(FL_BACKGROUND_COLOR);
                timeCrossingButton->selection_color((Fl_Color)1);
                timeCrossingButton->labeltype(FL_NORMAL_LABEL);
                timeCrossingButton->labelfont(0);
                timeCrossingButton->labelsize(12);
                timeCrossingButton->labelcolor(FL_FOREGROUND_COLOR);
                timeCrossingButton->callback((Fl_Callback*)cb_timeCrossingButton);
                timeCrossingButton->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
                timeCrossingButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* timeCrossingButton
            {
                Fl_Button* o = new Fl_Button(112 + 165, 61, 103, 49, "Gradient Magnitude");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Gradient);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                gradientMagnitudeButton = new fltk::LightButton(200 + 165, 147, 65, 29, "Display");
                gradientMagnitudeButton->type(0);
                gradientMagnitudeButton->box(FL_UP_BOX);
                gradientMagnitudeButton->value(1);
                gradientMagnitudeButton->color(FL_BACKGROUND_COLOR);
                gradientMagnitudeButton->selection_color((Fl_Color)1);
                gradientMagnitudeButton->labeltype(FL_NORMAL_LABEL);
                gradientMagnitudeButton->labelfont(0);
                gradientMagnitudeButton->labelsize(12);
                gradientMagnitudeButton->labelcolor(FL_FOREGROUND_COLOR);
                gradientMagnitudeButton->callback((Fl_Callback*)cb_gradientMagnitudeButton);
                gradientMagnitudeButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                gradientMagnitudeButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* gradientMagnitudeButton
            {
                Fl_Button* o = new Fl_Button(257 + 165, 61, 95, 49, "Linear + Sigmoid");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Linear);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                edgePotentialButton = new fltk::LightButton(325 + 165, 171, 67, 29, "Display");
                edgePotentialButton->type(0);
                edgePotentialButton->box(FL_UP_BOX);
                edgePotentialButton->value(1);
                edgePotentialButton->color(FL_BACKGROUND_COLOR);
                edgePotentialButton->selection_color((Fl_Color)1);
                edgePotentialButton->labeltype(FL_NORMAL_LABEL);
                edgePotentialButton->labelfont(0);
                edgePotentialButton->labelsize(12);
                edgePotentialButton->labelcolor(FL_FOREGROUND_COLOR);
                edgePotentialButton->callback((Fl_Callback*)cb_edgePotentialButton);
                edgePotentialButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                edgePotentialButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* edgePotentialButton
            {
                sigmaValueInput = new Fl_Value_Input(159 + 165, 110, 35, 25, "Sigma");
                sigmaValueInput->labelsize(12);
                sigmaValueInput->maximum(50);
                sigmaValueInput->step(0.1);
                sigmaValueInput->value(1.2);
                sigmaValueInput->textsize(12);
                sigmaValueInput->callback((Fl_Callback*)cb_sigmaValueInput);
            } // Fl_Value_Input* sigmaValueInput
            {
                segmentedImageButton = new fltk::LightButton(715 + 165, 28, 90, 31, "Overlay");
                segmentedImageButton->type(0);
                segmentedImageButton->box(FL_UP_BOX);
                segmentedImageButton->value(1);
                segmentedImageButton->color(FL_BACKGROUND_COLOR);
                segmentedImageButton->selection_color((Fl_Color)1);
                segmentedImageButton->labeltype(FL_NORMAL_LABEL);
                segmentedImageButton->labelfont(0);
                segmentedImageButton->labelsize(12);
                segmentedImageButton->labelcolor(FL_FOREGROUND_COLOR);
                segmentedImageButton->callback((Fl_Callback*)cb_segmentedImageButton);
                segmentedImageButton->align(Fl_Align(132|FL_ALIGN_INSIDE));
                segmentedImageButton->when(FL_WHEN_RELEASE);
            } // fltk::LightButton* segmentedImageButton
            {
                betaValueInput = new Fl_Value_Input(300 + 165, 135, 35, 25, "Beta");
                betaValueInput->labelsize(12);
                betaValueInput->maximum(100);
                betaValueInput->step(0.1);
                betaValueInput->value(5);
                betaValueInput->textsize(12);
                betaValueInput->callback((Fl_Callback*)cb_betaValueInput);
            } // Fl_Value_Input* betaValueInput
            {
                alphaValueInput = new Fl_Value_Input(300 + 165, 110, 35, 25, "Alpha");
                alphaValueInput->labelsize(12);
                alphaValueInput->minimum(-20);
                alphaValueInput->maximum(20);
                alphaValueInput->step(0.01);
                alphaValueInput->value(-1);
                alphaValueInput->textsize(12);
                alphaValueInput->callback((Fl_Callback*)cb_alphaValueInput);
            } // Fl_Value_Input* alphaValueInput
            {
                stoppingValueInput = new Fl_Value_Input(435 + 165, 40, 55, 25, "Stopping");
                stoppingValueInput->labelsize(12);
                stoppingValueInput->maximum(50000);
                stoppingValueInput->step(1);
                stoppingValueInput->value(50);
                stoppingValueInput->textsize(12);
                stoppingValueInput->callback((Fl_Callback*)cb_stoppingValueInput);
            } // Fl_Value_Input* stoppingValueInput
            {
                Fl_Button* o = new Fl_Button(626 + 165, 173, 60, 35, "Save");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Save);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                Fl_Button* o = new Fl_Button(130, 61, 103, 49, "Curvature Anisotropic");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_CurvatureAnisotropicDiffusion);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            controlsGroup->end();
        } // Fl_Group* controlsGroup
        {
            progressSlider = new fltk::ProgressBar(5, 222, 815 + 165, 15);
            progressSlider->type(3);
            progressSlider->box(FL_DOWN_BOX);
            progressSlider->color(FL_BACKGROUND_COLOR);
            progressSlider->selection_color((Fl_Color)2);
            progressSlider->labeltype(FL_NORMAL_LABEL);
            progressSlider->labelfont(0);
            progressSlider->labelsize(14);
            progressSlider->labelcolor(FL_FOREGROUND_COLOR);
            progressSlider->align(Fl_Align(FL_ALIGN_BOTTOM));
            progressSlider->when(FL_WHEN_CHANGED);
        } // fltk::ProgressBar* progressSlider
        {
            statusTextOutput = new Fl_Output(5, 245, 815 + 165, 25);
        } // Fl_Output* statusTextOutput
        {
            Fl_Button* o = new Fl_Button(715 + 165, 170, 90, 35, "Quit");
            o->box(FL_ROUND_UP_BOX);
            o->labelsize(12);
            o->callback((Fl_Callback*)cb_Quit);
            o->align(Fl_Align(FL_ALIGN_WRAP));
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(30, 25, 81, 35, "Load");
            o->box(FL_ROUND_UP_BOX);
            o->labelsize(12);
            o->callback((Fl_Callback*)cb_Load);
            o->align(Fl_Align(FL_ALIGN_WRAP));
        } // Fl_Button* o
        consoleWindow->end();
    } // Fl_Double_Window* consoleWindow
}

FMGUI::~FMGUI(void){}

void FMGUI::cb_CurvatureAnisotropicDiffusion_i(Fl_Button*o, void*v)
{
    this->ComputeCurvatureAnisotropicDiffusion();
}

void FMGUI::cb_CurvatureAnisotropicDiffusion(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_CurvatureAnisotropicDiffusion_i(o, v);
}

void FMGUI::cb_CuravtureImageButton_i(fltk::LightButton* o, void* v)
{
    ShowSmoothingImage();
}

void FMGUI::cb_CuravtureImageButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_CuravtureImageButton_i(o, v);
}

inline void FMGUI::cb_numOfItersInput_i(Fl_Value_Input* o, void*)
{
    m_SmoothFilter->SetNumberOfIterations( o->value() );
}

void FMGUI::cb_numOfItersInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_numOfItersInput_i(o, v);
}

inline void FMGUI::cb_conductanceInput_i(Fl_Value_Input* o, void*)
{
    m_SmoothFilter->SetConductanceParameter( o->value() );
}

void FMGUI::cb_conductanceInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_conductanceInput_i(o, v);
}

void FMGUI::cb_inputImageButton_i(fltk::LightButton*, void*)
{
    ShowInputImage();
}

void FMGUI::cb_inputImageButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_inputImageButton_i(o,v);
}

void FMGUI::cb_Fast_i(Fl_Button*, void*)
{
    this->RunFastMarching();
}

void FMGUI::cb_Fast(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_Fast_i(o,v);
}

void FMGUI::cb_thresholdedImageButton_i(fltk::LightButton*, void*)
{
    this->ShowThresholdedImage();
}

void FMGUI::cb_thresholdedImageButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_thresholdedImageButton_i(o,v);
}

void FMGUI::cb_thresholdedImageVTKButton_i(fltk::LightButton*, void*)
{
    ShowThresholdedImageWithVTK();
}

void FMGUI::cb_thresholdedImageVTKButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_thresholdedImageVTKButton_i(o,v);
}

void FMGUI::cb_Clear_i(Fl_Button*, void*)
{
    this->ClearSeeds();
}

void FMGUI::cb_Clear(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_Clear_i(o,v);
}

void FMGUI::cb_Threshold_i(Fl_Button*, void*)
{
    m_ThresholdFilter->UpdateLargestPossibleRegion();
}

void FMGUI::cb_Threshold(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_Threshold_i(o,v);
}

void FMGUI::cb_upperThresholdValueInput_i(Fl_Value_Input* o, void*)
{
    m_ThresholdFilter->SetUpperThreshold( o->value() );
}

void FMGUI::cb_upperThresholdValueInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_upperThresholdValueInput_i(o,v);
}

void FMGUI::cb_lowerThresholdValueInput_i(Fl_Value_Input* o, void*)
{
    m_ThresholdFilter->SetLowerThreshold( o->value() );
}

void FMGUI::cb_lowerThresholdValueInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_lowerThresholdValueInput_i(o,v);
}

void FMGUI::cb_timeCrossingButton_i(fltk::LightButton*, void*)
{
    ShowTimeCrossingMapImage();
}

void FMGUI::cb_timeCrossingButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_timeCrossingButton_i(o,v);
}

void FMGUI::cb_Gradient_i(Fl_Button*, void*)
{
    this->ComputeGradientMagnitude();
}

void FMGUI::cb_Gradient(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_Gradient_i(o,v);
}

void FMGUI::cb_gradientMagnitudeButton_i(fltk::LightButton*, void*)
{
    ShowGradientMagnitudeImage();
}

void FMGUI::cb_gradientMagnitudeButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_gradientMagnitudeButton_i(o,v);
}

void FMGUI::cb_Linear_i(Fl_Button*, void*)
{
    this->ComputeEdgePotential();
}

void FMGUI::cb_Linear(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_Linear_i(o,v);
}

void FMGUI::cb_edgePotentialButton_i(fltk::LightButton*, void*)
{
    ShowEdgePotentialImage();
}

void FMGUI::cb_edgePotentialButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_edgePotentialButton_i(o,v);
}

void FMGUI::cb_sigmaValueInput_i(Fl_Value_Input* o, void*)
{
    m_DerivativeFilter->SetSigma( o->value() );
}

void FMGUI::cb_sigmaValueInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_sigmaValueInput_i(o,v);
}

void FMGUI::cb_segmentedImageButton_i(fltk::LightButton*, void*)
{
    this->ShowSegmentedImage();
}

void FMGUI::cb_segmentedImageButton(fltk::LightButton* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_segmentedImageButton_i(o,v);
}

void FMGUI::cb_betaValueInput_i(Fl_Value_Input* o, void*)
{
    m_SigmoidFilter->SetBeta( o->value() );
}

void FMGUI::cb_betaValueInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_betaValueInput_i(o,v);
}

void FMGUI::cb_alphaValueInput_i(Fl_Value_Input* o, void*)
{
    m_SigmoidFilter->SetAlpha( o->value() );
}

void FMGUI::cb_alphaValueInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_alphaValueInput_i(o,v);
}

void FMGUI::cb_stoppingValueInput_i(Fl_Value_Input* o, void*)
{
    this->SetStoppingValue( o->value()  );
}

void FMGUI::cb_stoppingValueInput(Fl_Value_Input* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_stoppingValueInput_i(o,v);
}

void FMGUI::cb_Save_i(Fl_Button*, void*)
{
    this->SaveOutputImage();
}

void FMGUI::cb_Save(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->parent()->user_data()))->cb_Save_i(o,v);
}

void FMGUI::cb_Quit_i(Fl_Button*, void*)
{
    this->Quit();
}

void FMGUI::cb_Quit(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

void FMGUI::cb_Load_i(Fl_Button*, void*)
{
    this->LoadInputImage();
}

void FMGUI::cb_Load(Fl_Button* o, void* v)
{
    ((FMGUI*)(o->parent()->user_data()))->cb_Load_i(o,v);
}


void FMGUI::Quit( void ){}

void FMGUI::Load( void ){}

void FMGUI::ShowAbout( void ){}

void FMGUI::ShowInputImage( void ){}

void FMGUI::ShowConsole( void ){}

void FMGUI::ShowThresholdedImage( void ){}

void FMGUI::UpdateExtract(){}

void FMGUI::ShowThresholdedImageWithVTK( void ){}

void FMGUI::ShowTimeCrossingMapImage( void ){}

void FMGUI::ShowGradientMagnitudeImage( void ){}

void FMGUI::ShowEdgePotentialImage( void ){}

void FMGUI::ShowSegmentedImage( void ){}

void FMGUI::SaveOutputImage( void ){}

void FMGUI::ShowSmoothingImage( void ){}
