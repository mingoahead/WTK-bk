#include "FastMarchingFltkGUI.h"

std::string FastMarchingFltkGUI::recent_file = "";
std::string FastMarchingFltkGUI::image_name = "";

FastMarchingFltkGUI::FastMarchingFltkGUI(void)
{
    console_window = new Fl_Double_Window(25, 25, 1000, 400, "FastMarching Segmentor");
    {   
        input_btn = new Fl_Light_Button(45, 300, 100, 25, "input");
        smooth_btn = new Fl_Light_Button(205, 300, 100, 25, "smooth");
        gm_btn = new Fl_Light_Button(365, 300, 100, 25, "GM");
        sigmoid_btn = new Fl_Light_Button(530, 300, 100, 25, "sigmoid");
        fm_btn = new Fl_Light_Button(695, 300, 100, 25, "FM");

        /// load image
        input_group = new Fl_Group(20, 50, 150, 190, "Input an image");
        input_group->box(FL_PLASTIC_DOWN_BOX);
        {
            load_image = new Fl_Light_Button(input_group->x()+10, input_group->y()+10, input_group->w()-20, 22, "Load Image");
            load_image->callback( load_cb, 0 );
        }
        input_group->end();

        /// smooth
        smooth_group = new Fl_Group( input_group->x()+input_group->w()+10, input_group->y(), input_group->w(), input_group->h(), "Anisotropic Diffusion" );
        smooth_group->box(FL_PLASTIC_DOWN_BOX);
        {
            int x = smooth_group->x();
            int y = smooth_group->y();
            int w = smooth_group->w();
            int h = smooth_group->h();

            // time step spinner
            smooth_timeStep = new Fl_Spinner(x+10, y+10, w-20, 22, "Time step");
            smooth_timeStep->align(FL_ALIGN_BOTTOM);
            smooth_timeStep->type(FL_FLOAT_INPUT);
            smooth_timeStep->step(0.1);
            smooth_timeStep->range(0, 1.0e30);  // 0, max_float

            // iterations spinner
            smooth_iters = new Fl_Spinner(x+10, y+10+45, w-20, 22, "Iterations" );
            smooth_iters->align(FL_ALIGN_BOTTOM);
            smooth_iters->type(FL_INT_INPUT);
            smooth_iters->step(1);
            smooth_iters->range(0, 0x7FFFFFFF);  // 0, max_int

            // smooth conductance
            smooth_conductance = new Fl_Spinner(x+10, y+10+2*45, w-20, 22, "Conductance");
            smooth_conductance->align(FL_ALIGN_BOTTOM);
            smooth_conductance->type(FL_FLOAT_INPUT);
            smooth_conductance->step(0.1);
            smooth_conductance->range(0, 1.0e30);  // 0, max_float
        }
        smooth_group->end();

        /// gradient magnitude
        gradientMagnitude_group = new Fl_Group( input_group->x()+2*(input_group->w()+10), input_group->y(), input_group->w(), input_group->h(), "Gradient Magnitude");
        gradientMagnitude_group->box(FL_PLASTIC_DOWN_BOX);
        gradientMagnitude_group->begin();
        {
            gm_sigma = new Fl_Spinner(gradientMagnitude_group->x()+10, gradientMagnitude_group->y()+10, gradientMagnitude_group->w()-20, 22, "Sigma");
            gm_sigma->align(FL_ALIGN_BOTTOM);
            gm_sigma->type(FL_FLOAT_INPUT);
            gm_sigma->step(0.1);
            gm_sigma->range(0, 1.0e30);  // 0, max_float
        }
        gradientMagnitude_group->end();

        /// sigmoid
        sigmoid_group = new Fl_Group(input_group->x()+3*(input_group->w()+10), input_group->y(), input_group->w(), input_group->h(), "Sigmoid");
        sigmoid_group->box(FL_PLASTIC_DOWN_BOX);
        sigmoid_group->begin();
        {
            int x = sigmoid_group->x();
            int y = sigmoid_group->y();
            int w = sigmoid_group->w();
            int h = sigmoid_group->h();

            sigmoid_alpha = new Fl_Spinner(x+10, y+10+0*45, w-20, 22, "Alpha");
            sigmoid_alpha->align(FL_ALIGN_BOTTOM);
            sigmoid_alpha->type(FL_FLOAT_INPUT);
            sigmoid_alpha->step(0.1);
            sigmoid_alpha->range(0, 1.0e30);  // 0, max_float

            sigmoid_beta  = new Fl_Spinner(x+10, y+10+1*45, w-20, 22, "Beta");
            sigmoid_beta->align(FL_ALIGN_BOTTOM);
            sigmoid_beta->type(FL_FLOAT_INPUT);
            sigmoid_beta->step(0.1);
            sigmoid_beta->range(0, 1.0e30);  // 0, max_float
            
            sigmoid_outputMin = new Fl_Spinner(x+10, y+10+2*45, w-20, 22, "Output minimum");
            sigmoid_outputMin->align(FL_ALIGN_BOTTOM);
            sigmoid_outputMin->type(FL_FLOAT_INPUT);
            sigmoid_outputMin->step(0.1);
            sigmoid_outputMin->range(0, 1.0e30);  // 0, max_float

            sigmoid_outputMax = new Fl_Spinner(x+10, y+10+3*45, w-20, 22, "Output maximum");
            sigmoid_outputMax->align(FL_ALIGN_BOTTOM);
            sigmoid_outputMax->type(FL_FLOAT_INPUT);
            sigmoid_outputMax->step(0.1);
            sigmoid_outputMax->range(0, 1.0e30);  // 0, max_float
        }
        sigmoid_group->end();

        /// fastmarching
        fastMarching_group = new Fl_Group(input_group->x()+4*(input_group->w()+10), input_group->y(), input_group->w(), input_group->h(), "Fast-marching");
        fastMarching_group->box(FL_PLASTIC_DOWN_BOX);
        fastMarching_group->begin();
        {
            fm_stoppingTime = new Fl_Spinner(fastMarching_group->x()+10, fastMarching_group->y()+10, fastMarching_group->w()-20, 22, "Stopping time");
            fm_stoppingTime->align(FL_ALIGN_BOTTOM);
            fm_stoppingTime->type(FL_FLOAT_INPUT);
            fm_stoppingTime->step(0.1);
            fm_stoppingTime->range(0, 1.0e30);  // 0, max_float
        }
        fastMarching_group->end();

        /// binary thresholder
        thresholder_group = new Fl_Group(input_group->x()+5*(input_group->w()+10), input_group->y(), input_group->w(), input_group->h(), "Binary Thresholder");
        thresholder_group->box(FL_PLASTIC_DOWN_BOX);
        thresholder_group->begin();
        {
            int x = thresholder_group->x();
            int y = thresholder_group->y();
            int w = thresholder_group->w();
            int h = thresholder_group->h();

            // lower threshold
            th_lowerTh = new Fl_Spinner(x+10, y+10+0*45, w-20, 22, "Lower threshold");
            th_lowerTh->align(FL_ALIGN_BOTTOM);
            th_lowerTh->type(FL_FLOAT_INPUT);
            th_lowerTh->step(0.1);
            th_lowerTh->range(0, 1.0e30);  // 0, max_float

            // upper threshold
            th_upperTh = new Fl_Spinner(x+10, y+10+1*45, w-20, 22, "Upper threshold");
            th_upperTh->align(FL_ALIGN_BOTTOM);
            th_upperTh->type(FL_FLOAT_INPUT);
            th_upperTh->step(0.1);
            th_upperTh->range(0, 1.0e30);  // 0, max_float

            // inside value
            th_insideValue = new Fl_Spinner(x+10, y+10+2*45, w-20, 22, "Inside value");
            th_insideValue->align(FL_ALIGN_BOTTOM);
            th_insideValue->type(FL_FLOAT_INPUT);
            th_insideValue->step(0.1);
            th_insideValue->range(0, 1.0e30);  // 0, max_float

            // outside value
            th_outsideValue = new Fl_Spinner(x+10, y+10+3*45, w-20, 22, "Outside value");
            th_outsideValue->align(FL_ALIGN_BOTTOM);
            th_outsideValue->type(FL_FLOAT_INPUT);
            th_outsideValue->step(0.1);
            th_outsideValue->range(0, 1.0e30);  // 0, max_float
        }
        thresholder_group->end();
    }
    console_window->end();

    console_window->show();
}

FastMarchingFltkGUI::~FastMarchingFltkGUI(void)
{
    delete console_window;  //  automatically delete all the children
}

void FastMarchingFltkGUI::load_cb(Fl_Widget *obj, void *data) {
    image_name = std::string( fl_file_chooser("Open File", "*", recent_file.c_str()) );
}
