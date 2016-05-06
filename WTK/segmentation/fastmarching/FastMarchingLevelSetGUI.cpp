# include "FastMarchingLevelSetGUI.h"

void FastMarchingLevelSetGUI::cb_inputImageButton_i(fltk::LightButton*, void*)
{
    ShowInputImage();
}

void FastMarchingLevelSetGUI::cb_inputImageButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_inputImageButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Fast_i(Fl_Button*, void*)
{
    this->RunFastMarching();
}

void FastMarchingLevelSetGUI::cb_Fast(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_Fast_i(o,v);
}

void FastMarchingLevelSetGUI::cb_thresholdedImageButton_i(fltk::LightButton*, void*)
{
    this->ShowThresholdedImage();
}

void FastMarchingLevelSetGUI::cb_thresholdedImageButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_thresholdedImageButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_thresholdedImageVTKButton_i(fltk::LightButton*, void*)
{
    ShowThresholdedImageWithVTK();
}

void FastMarchingLevelSetGUI::cb_thresholdedImageVTKButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_thresholdedImageVTKButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Clear_i(Fl_Button*, void*)
{
    this->ClearSeeds();
}

void FastMarchingLevelSetGUI::cb_Clear(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_Clear_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Threshold_i(Fl_Button*, void*)
{
    m_ThresholdFilter->UpdateLargestPossibleRegion();
}

void FastMarchingLevelSetGUI::cb_Threshold(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_Threshold_i(o,v);
}

void FastMarchingLevelSetGUI::cb_upperThresholdValueInput_i(Fl_Value_Input* o, void*)
{
    m_ThresholdFilter->SetUpperThreshold( o->value() );
}

void FastMarchingLevelSetGUI::cb_upperThresholdValueInput(Fl_Value_Input* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_upperThresholdValueInput_i(o,v);
}

void FastMarchingLevelSetGUI::cb_lowerThresholdValueInput_i(Fl_Value_Input* o, void*)
{
    m_ThresholdFilter->SetLowerThreshold( o->value() );
}

void FastMarchingLevelSetGUI::cb_lowerThresholdValueInput(Fl_Value_Input* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_lowerThresholdValueInput_i(o,v);
}

void FastMarchingLevelSetGUI::cb_timeCrossingButton_i(fltk::LightButton*, void*)
{
    ShowTimeCrossingMapImage();
}

void FastMarchingLevelSetGUI::cb_timeCrossingButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_timeCrossingButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Gradient_i(Fl_Button*, void*)
{
    this->ComputeGradientMagnitude();
}

void FastMarchingLevelSetGUI::cb_Gradient(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_Gradient_i(o,v);
}

void FastMarchingLevelSetGUI::cb_gradientMagnitudeButton_i(fltk::LightButton*, void*)
{
    ShowGradientMagnitudeImage();
}

void FastMarchingLevelSetGUI::cb_gradientMagnitudeButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_gradientMagnitudeButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Linear_i(Fl_Button*, void*)
{
    this->ComputeEdgePotential();
}

void FastMarchingLevelSetGUI::cb_Linear(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_Linear_i(o,v);
}

void FastMarchingLevelSetGUI::cb_edgePotentialButton_i(fltk::LightButton*, void*)
{
    ShowEdgePotentialImage();
}

void FastMarchingLevelSetGUI::cb_edgePotentialButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_edgePotentialButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_sigmaValueInput_i(Fl_Value_Input* o, void*)
{
    m_DerivativeFilter->SetSigma( o->value() );
}

void FastMarchingLevelSetGUI::cb_sigmaValueInput(Fl_Value_Input* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_sigmaValueInput_i(o,v);
}

void FastMarchingLevelSetGUI::cb_segmentedImageButton_i(fltk::LightButton*, void*)
{
    this->ShowSegmentedImage();
}

void FastMarchingLevelSetGUI::cb_segmentedImageButton(fltk::LightButton* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_segmentedImageButton_i(o,v);
}

void FastMarchingLevelSetGUI::cb_betaValueInput_i(Fl_Value_Input* o, void*)
{
    m_SigmoidFilter->SetBeta( o->value() );
}

void FastMarchingLevelSetGUI::cb_betaValueInput(Fl_Value_Input* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_betaValueInput_i(o,v);
}

void FastMarchingLevelSetGUI::cb_alphaValueInput_i(Fl_Value_Input* o, void*)
{
    m_SigmoidFilter->SetAlpha( o->value() );
}

void FastMarchingLevelSetGUI::cb_alphaValueInput(Fl_Value_Input* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_alphaValueInput_i(o,v);
}

void FastMarchingLevelSetGUI::cb_stoppingValueInput_i(Fl_Value_Input* o, void*)
{
    this->SetStoppingValue( o->value()  );
}

void FastMarchingLevelSetGUI::cb_stoppingValueInput(Fl_Value_Input* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_stoppingValueInput_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Save_i(Fl_Button*, void*)
{
    this->SaveOutputImage();
}

void FastMarchingLevelSetGUI::cb_Save(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->parent()->user_data()))->cb_Save_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Quit_i(Fl_Button*, void*)
{
    this->Quit();
}

void FastMarchingLevelSetGUI::cb_Quit(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

void FastMarchingLevelSetGUI::cb_Load_i(Fl_Button*, void*)
{
    this->LoadInputImage();
}

void FastMarchingLevelSetGUI::cb_Load(Fl_Button* o, void* v)
{
    ((FastMarchingLevelSetGUI*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

FastMarchingLevelSetGUI::FastMarchingLevelSetGUI()
{
    {
        consoleWindow = new Fl_Double_Window(830, 280, "Fast Marching Segmentation Level Set");
        consoleWindow->user_data((void*)(this));
        {
            Connectors = new Fl_Group(0, 0, 820, 210);
            {
                Fl_Box* o = new Fl_Box(679, 39, 61, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(230, 80, 10, 70);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(65, 79, 80, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(200, 78, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(679, 79, 61, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(505, 80, 10, 70);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(680, 119, 61, 10);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(650, 82, 10, 100);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(679, 39, 10, 90);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(470, 79, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(610, 79, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(65, 45, 10, 95);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(360, 80, 10, 100);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(325, 79, 80, 11);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)4);
            } // Fl_Box* o
            {
                Fl_Box* o = new Fl_Box(415, 90, 10, 95);
                o->box(FL_UP_BOX);
                o->color((Fl_Color)21);
            } // Fl_Box* o
            Connectors->end();
        } // Fl_Group* Connectors
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
                Fl_Button* o = new Fl_Button(381, 66, 117, 34, "Fast Marching");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Fast);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                thresholdedImageButton = new fltk::LightButton(714, 68, 90, 31, "Display");
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
                thresholdedImageVTKButton = new fltk::LightButton(714, 109, 90, 30, "VTK Render");
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
                Fl_Button* o = new Fl_Button(400, 170, 94, 35, "Clear Seeds");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Clear);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                Fl_Button* o = new Fl_Button(525, 66, 117, 34, "Threshold");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Threshold);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                upperThresholdValueInput = new Fl_Value_Input(570, 15, 55, 25, "Upper");
                upperThresholdValueInput->labelsize(12);
                upperThresholdValueInput->maximum(1000);
                upperThresholdValueInput->step(0.1);
                upperThresholdValueInput->value(50.0);
                upperThresholdValueInput->textsize(12);
                upperThresholdValueInput->callback((Fl_Callback*)cb_upperThresholdValueInput);
            } // Fl_Value_Input* upperThresholdValueInput
            {
                lowerThresholdValueInput = new Fl_Value_Input(570, 40, 55, 25, "Lower");
                lowerThresholdValueInput->labelsize(12);
                lowerThresholdValueInput->maximum(1000);
                lowerThresholdValueInput->step(0.1);
                lowerThresholdValueInput->textsize(12);
                lowerThresholdValueInput->callback((Fl_Callback*)cb_lowerThresholdValueInput);
            } // Fl_Value_Input* lowerThresholdValueInput
            {
                timeCrossingButton = new fltk::LightButton(442, 129, 145, 29, "Time Crossing Map");
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
                Fl_Button* o = new Fl_Button(112, 61, 103, 49, "Gradient Magnitude");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Gradient);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                gradientMagnitudeButton = new fltk::LightButton(180, 147, 65, 29, "Display");
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
                Fl_Button* o = new Fl_Button(257, 61, 95, 49, "Linear + Sigmoid");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Linear);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            {
                edgePotentialButton = new fltk::LightButton(315, 171, 67, 29, "Display");
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
                sigmaValueInput = new Fl_Value_Input(159, 110, 35, 25, "Sigma");
                sigmaValueInput->labelsize(12);
                sigmaValueInput->maximum(50);
                sigmaValueInput->step(0.1);
                sigmaValueInput->value(1.2);
                sigmaValueInput->textsize(12);
                sigmaValueInput->callback((Fl_Callback*)cb_sigmaValueInput);
            } // Fl_Value_Input* sigmaValueInput
            {
                segmentedImageButton = new fltk::LightButton(715, 28, 90, 31, "Overlay");
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
                betaValueInput = new Fl_Value_Input(300, 135, 35, 25, "Beta");
                betaValueInput->labelsize(12);
                betaValueInput->maximum(100);
                betaValueInput->step(0.1);
                betaValueInput->value(10.0);
                betaValueInput->textsize(12);
                betaValueInput->callback((Fl_Callback*)cb_betaValueInput);
            } // Fl_Value_Input* betaValueInput
            {
                alphaValueInput = new Fl_Value_Input(300, 110, 35, 25, "Alpha");
                alphaValueInput->labelsize(12);
                alphaValueInput->minimum(-20);
                alphaValueInput->maximum(20);
                alphaValueInput->step(0.01);
                alphaValueInput->value(-10.0);
                alphaValueInput->textsize(12);
                alphaValueInput->callback((Fl_Callback*)cb_alphaValueInput);
            } // Fl_Value_Input* alphaValueInput
            {
                stoppingValueInput = new Fl_Value_Input(435, 40, 55, 25, "Stopping");
                stoppingValueInput->labelsize(12);
                stoppingValueInput->maximum(50000);
                stoppingValueInput->step(1);
                stoppingValueInput->value(100);
                stoppingValueInput->textsize(12);
                stoppingValueInput->callback((Fl_Callback*)cb_stoppingValueInput);
            } // Fl_Value_Input* stoppingValueInput
            {
                Fl_Button* o = new Fl_Button(626, 173, 60, 35, "Save");
                o->box(FL_ROUND_UP_BOX);
                o->labelsize(12);
                o->callback((Fl_Callback*)cb_Save);
                o->align(Fl_Align(FL_ALIGN_WRAP));
            } // Fl_Button* o
            controlsGroup->end();
        } // Fl_Group* controlsGroup
        {
            progressSlider = new fltk::ProgressBar(5, 222, 815, 15);
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
            statusTextOutput = new Fl_Output(5, 245, 815, 25);
        } // Fl_Output* statusTextOutput
        {
            Fl_Button* o = new Fl_Button(715, 170, 90, 35, "Quit");
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

FastMarchingLevelSetGUI::~FastMarchingLevelSetGUI()
{
}

void FastMarchingLevelSetGUI::Quit( void )
{
}

void FastMarchingLevelSetGUI::Load( void )
{
}

void FastMarchingLevelSetGUI::ShowAbout( void )
{
}

void FastMarchingLevelSetGUI::ShowInputImage( void )
{
}

void FastMarchingLevelSetGUI::ShowConsole( void )
{
}

void FastMarchingLevelSetGUI::ShowThresholdedImage( void )
{
}

void FastMarchingLevelSetGUI::UpdateExtract()
{
}

void FastMarchingLevelSetGUI::ShowThresholdedImageWithVTK( void )
{
}

void FastMarchingLevelSetGUI::ShowTimeCrossingMapImage( void )
{
}

void FastMarchingLevelSetGUI::ShowGradientMagnitudeImage( void )
{
}

void FastMarchingLevelSetGUI::ShowEdgePotentialImage( void )
{
}

void FastMarchingLevelSetGUI::ShowSegmentedImage( void )
{
}

void FastMarchingLevelSetGUI::SaveOutputImage( void )
{
}
