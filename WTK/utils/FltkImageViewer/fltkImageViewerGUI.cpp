// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "fltkImageViewerGUI.h"

void fltkImageViewerGUI::cb_orientationChoice_i(Fl_Choice*, void*)
{
    SetOrientation();
}
void fltkImageViewerGUI::cb_orientationChoice(Fl_Choice* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->parent()->user_data()))->cb_orientationChoice_i(o,v);
}

Fl_Menu_Item fltkImageViewerGUI::menu_orientationChoice[] = {
    {"X", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
    {"Y", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
    {"Z", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
    {0,0,0,0,0,0,0,0,0}
};

void fltkImageViewerGUI::cb_Value_i(Fl_Menu_*, void*)
{
    ImageMode(itk::IMG_VAL);
}
void fltkImageViewerGUI::cb_Value(Fl_Menu_* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Value_i(o,v);
}

void fltkImageViewerGUI::cb_Log_i(Fl_Menu_*, void*)
{
    ImageMode(itk::IMG_LOG);
}
void fltkImageViewerGUI::cb_Log(Fl_Menu_* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Log_i(o,v);
}

void fltkImageViewerGUI::cb_Opacity_i(Fl_Menu_*, void*)
{
    ShowOverlayOpacityControl();
}
void fltkImageViewerGUI::cb_Opacity(Fl_Menu_* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Opacity_i(o,v);
}

Fl_Menu_Item fltkImageViewerGUI::menu_[] = {
    {"Filter", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
    {"Value", 0,  (Fl_Callback*)fltkImageViewerGUI::cb_Value, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
    {"Log", 0,  (Fl_Callback*)fltkImageViewerGUI::cb_Log, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
    {0,0,0,0,0,0,0,0,0},
    {"Overlay", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
    {"Opacity", 0,  (Fl_Callback*)fltkImageViewerGUI::cb_Opacity, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

void fltkImageViewerGUI::cb_sliceNumberSlider_i(Fl_Value_Slider* o, void*)
{
    SelectSlice((unsigned int)o->value());
}
void fltkImageViewerGUI::cb_sliceNumberSlider(Fl_Value_Slider* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_sliceNumberSlider_i(o,v);
}

void fltkImageViewerGUI::cb_intensityWindowingMinSlider_i(Fl_Value_Slider* o, void*)
{
    SetIntensityWindowingMin(o->value());
}
void fltkImageViewerGUI::cb_intensityWindowingMinSlider(Fl_Value_Slider* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_intensityWindowingMinSlider_i(o,v);
}

void fltkImageViewerGUI::cb_intensityWindowingMaxSlider_i(Fl_Value_Slider* o, void*)
{
    SetIntensityWindowingMax(o->value());
}
void fltkImageViewerGUI::cb_intensityWindowingMaxSlider(Fl_Value_Slider* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_intensityWindowingMaxSlider_i(o,v);
}

void fltkImageViewerGUI::cb_Zoom_i(Fl_Button*, void*)
{
    ZoomIn();
}
void fltkImageViewerGUI::cb_Zoom(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Zoom_i(o,v);
}

void fltkImageViewerGUI::cb_Zoom1_i(Fl_Button*, void*)
{
    ZoomOut();
}
void fltkImageViewerGUI::cb_Zoom1(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Zoom1_i(o,v);
}

void fltkImageViewerGUI::cb_U_i(Fl_Button*, void*)
{
    ShiftUp();
}
void fltkImageViewerGUI::cb_U(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_U_i(o,v);
}

void fltkImageViewerGUI::cb_Reset_i(Fl_Button*, void*)
{
    CenterWindow();
}
void fltkImageViewerGUI::cb_Reset(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Reset_i(o,v);
}

void fltkImageViewerGUI::cb_R_i(Fl_Button*, void*)
{
    ShiftRight();
}
void fltkImageViewerGUI::cb_R(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_R_i(o,v);
}

void fltkImageViewerGUI::cb_L_i(Fl_Button*, void*)
{
    ShiftLeft();
}
void fltkImageViewerGUI::cb_L(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_L_i(o,v);
}

void fltkImageViewerGUI::cb_D_i(Fl_Button*, void*)
{
    ShiftDown();
}
void fltkImageViewerGUI::cb_D(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_D_i(o,v);
}

void fltkImageViewerGUI::cb_Points_i(Fl_Button*, void*)
{
    ShowClickedPointsWindow();
}
void fltkImageViewerGUI::cb_Points(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Points_i(o,v);
}

void fltkImageViewerGUI::cb_Update_i(Fl_Button*, void*)
{
    UpdateClickedPoints();
}
void fltkImageViewerGUI::cb_Update(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Update_i(o,v);
}

void fltkImageViewerGUI::cb_Clear_i(Fl_Button*, void*)
{
    ClearClickedPoints();
}
void fltkImageViewerGUI::cb_Clear(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Clear_i(o,v);
}

void fltkImageViewerGUI::cb_Close_i(Fl_Button*, void*)
{
    clickedPointsWindow->hide();
}
void fltkImageViewerGUI::cb_Close(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Close_i(o,v);
}

void fltkImageViewerGUI::cb_Close1_i(Fl_Button*, void*)
{
    overlayOpacityControlWindow->hide();
}
void fltkImageViewerGUI::cb_Close1(Fl_Button* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_Close1_i(o,v);
}

void fltkImageViewerGUI::cb_overlayOpacitySlider_i(Fl_Value_Slider* o, void*)
{
    SetOverlayOpacity( o->value() );
}
void fltkImageViewerGUI::cb_overlayOpacitySlider(Fl_Value_Slider* o, void* v)
{
    ((fltkImageViewerGUI*)(o->parent()->user_data()))->cb_overlayOpacitySlider_i(o,v);
}

Fl_Double_Window* fltkImageViewerGUI::CreateGUI()
{
    {
        iviewWindow = new Fl_Double_Window(295, 400);
        iviewWindow->labelsize(10);
        iviewWindow->user_data((void*)(this));
        {
            glWindowGroup = new Fl_Group(0, 25, 260, 320);

            // 三视图选择
            {
                orientationChoice = new Fl_Choice(20, 325, 50, 20);
                orientationChoice->down_box(FL_BORDER_BOX);
                orientationChoice->callback((Fl_Callback*)cb_orientationChoice);
                orientationChoice->menu(menu_orientationChoice);
            } // Fl_Choice* orientationChoice
            glWindowGroup->end();

            // 三维显示
            glRenderGroup = new Fl_Group(0, 25, 260, 250);
            {
                Fl_Gl_Window* o = new Fl_Gl_Window(0, 25, 260, 250, "3D Win");
                o->box(FL_EMBOSSED_BOX);
                o->color(FL_BACKGROUND_COLOR);
                o->selection_color(FL_BACKGROUND_COLOR);
                o->labeltype(FL_NORMAL_LABEL);
                o->labelfont(0);
                o->labelsize(14);
                o->labelcolor(FL_FOREGROUND_COLOR);
                o->align(Fl_Align(FL_ALIGN_CENTER));
                o->when(FL_WHEN_RELEASE);
                CreateGLSliceView( glWindowGroup, o );
            } // Fl_Gl_Window* o
            glRenderGroup->end();
        } // Fl_Group* glWindowGroup

        // 菜单栏
        {
            Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 260, 25);
            {
                Fl_Menu_Item* o = &menu_[0];
                AddFilterMenuOptions();
            }
            {
                Fl_Menu_Item* o = &menu_[4];
                AddFilterMenuOptions();
            }
            o->menu(menu_);
            AddMenuBarOptions();
        } // Fl_Menu_Bar* o

        // 滚动条
        {
            sliceNumberSlider = new Fl_Value_Slider(270, 25, 20, 250, "序号");
            sliceNumberSlider->type(4);
            sliceNumberSlider->labelsize(11);
            sliceNumberSlider->step(1);
            sliceNumberSlider->textsize(12);
            sliceNumberSlider->callback((Fl_Callback*)cb_sliceNumberSlider);
            sliceNumberSlider->align(Fl_Align(FL_ALIGN_TOP));
        } // Fl_Value_Slider* sliceNumberSlider

        // 窗宽窗位映射窗口的下界
        {
            intensityWindowingMinSlider = new Fl_Value_Slider(10, 360, 300, 20);
            intensityWindowingMinSlider->type(FL_HOR_SLIDER);
            intensityWindowingMinSlider->selection_color( FL_DARK1 );
            intensityWindowingMinSlider->labeltype(FL_NO_LABEL);
            intensityWindowingMinSlider->labelsize(9);
            intensityWindowingMinSlider->step(1);
            //intensityWindowingMinSlider->value(1);
            intensityWindowingMinSlider->textsize(9);
            intensityWindowingMinSlider->callback((Fl_Callback*)cb_intensityWindowingMinSlider);
        } // Fl_Value_Slider* intensityWindowingMinSlider

        // 窗宽窗位映射窗口的上界
        {
            intensityWindowingMaxSlider = new Fl_Value_Slider(10, 380, 300, 20);
            intensityWindowingMaxSlider->type(FL_HOR_SLIDER);
            intensityWindowingMaxSlider->selection_color( FL_DARK1 ); // FL_DARK1
            intensityWindowingMaxSlider->labeltype(FL_NO_LABEL);
            intensityWindowingMaxSlider->labelsize(9);
            intensityWindowingMaxSlider->step(1);
            intensityWindowingMaxSlider->value(1);
            intensityWindowingMaxSlider->textsize(9);
            intensityWindowingMaxSlider->callback((Fl_Callback*)cb_intensityWindowingMaxSlider);
        } // Fl_Value_Slider* intensityWindowingMaxSlider

        //
        {
            Fl_Button* o = new Fl_Button(170, 280, 55, 20, "Zoom In");
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_Zoom);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(170, 335, 55, 20, "Zoom Out");
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_Zoom1);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(110, 280, 35, 35, "U");
            o->box(FL_DIAMOND_UP_BOX);
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_U);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(180, 305, 35, 25, "Reset");
            o->box(FL_ROUND_UP_BOX);
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_Reset);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(130, 300, 35, 35, "R");
            o->box(FL_DIAMOND_UP_BOX);
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_R);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(90, 300, 35, 35, "L");
            o->box(FL_DIAMOND_UP_BOX);
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_L);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(110, 320, 35, 35, "D");
            o->box(FL_DIAMOND_UP_BOX);
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_D);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(15, 290, 55, 20, "Points");
            o->labelsize(10);
            o->callback((Fl_Callback*)cb_Points);
        } // Fl_Button* o
        iviewWindow->end();
        iviewWindow->resizable(glRenderGroup);
    } // Fl_Double_Window* iviewWindow
    {
        clickedPointsWindow = new Fl_Double_Window(290, 405, "Clicked Points");
        clickedPointsWindow->user_data((void*)(this));
        {
            clickedPointsBrowser = new Fl_Browser(10, 15, 270, 345);
            clickedPointsBrowser->textfont(4);
        } // Fl_Browser* clickedPointsBrowser
        {
            Fl_Button* o = new Fl_Button(27, 370, 65, 25, "Update");
            o->callback((Fl_Callback*)cb_Update);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(115, 370, 65, 25, "Clear");
            o->callback((Fl_Callback*)cb_Clear);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(200, 370, 65, 25, "Close");
            o->callback((Fl_Callback*)cb_Close);
        } // Fl_Button* o
        clickedPointsWindow->end();
    } // Fl_Double_Window* clickedPointsWindow
    {
        overlayOpacityControlWindow = new Fl_Double_Window(400, 100, "Overlay Opacity");
        overlayOpacityControlWindow->user_data((void*)(this));
        {
            Fl_Button* o = new Fl_Button(145, 64, 115, 25, "Close");
            o->callback((Fl_Callback*)cb_Close1);
        } // Fl_Button* o
        {
            overlayOpacitySlider = new Fl_Value_Slider(25, 29, 360, 25, "Opacity");
            overlayOpacitySlider->type(3);
            overlayOpacitySlider->color((Fl_Color)29);
            overlayOpacitySlider->selection_color((Fl_Color)21);
            overlayOpacitySlider->value(1);
            overlayOpacitySlider->callback((Fl_Callback*)cb_overlayOpacitySlider);
            overlayOpacitySlider->align(Fl_Align(FL_ALIGN_TOP));
        } // Fl_Value_Slider* overlayOpacitySlider
        overlayOpacityControlWindow->end();
    } // Fl_Double_Window* overlayOpacityControlWindow
    return overlayOpacityControlWindow;
}
