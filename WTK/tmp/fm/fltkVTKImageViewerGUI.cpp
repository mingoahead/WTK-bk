// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "fltkVTKImageViewerGUI.h"

fltkVTKImageViewerGUI::fltkVTKImageViewerGUI() {
  { externalWindow = new Fl_Double_Window(435, 465);
    externalWindow->user_data((void*)(this));
    { fltkRenderWindowInteractor = new vtkFlRenderWindowInteractor(5, 10, 425, 445);
      fltkRenderWindowInteractor->box(FL_DOWN_FRAME);
      fltkRenderWindowInteractor->color(FL_BACKGROUND_COLOR);
      fltkRenderWindowInteractor->selection_color(FL_BACKGROUND_COLOR);
      fltkRenderWindowInteractor->labeltype(FL_NORMAL_LABEL);
      fltkRenderWindowInteractor->labelfont(0);
      fltkRenderWindowInteractor->labelsize(14);
      fltkRenderWindowInteractor->labelcolor(FL_FOREGROUND_COLOR);
      fltkRenderWindowInteractor->align(Fl_Align(FL_ALIGN_CENTER));
      fltkRenderWindowInteractor->when(FL_WHEN_RELEASE);
      Fl_Group::current()->resizable(fltkRenderWindowInteractor);
    } // vtkFlRenderWindowInteractor* fltkRenderWindowInteractor
    externalWindow->end();
  } // Fl_Double_Window* externalWindow
}

fltkVTKImageViewerGUI::~fltkVTKImageViewerGUI() {
}

void fltkVTKImageViewerGUI::Show() {
  externalWindow->show();
            fltkRenderWindowInteractor->show();
}

void fltkVTKImageViewerGUI::Hide() {
  externalWindow->hide();
}
