// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef fltkVTKImageViewerGUI_h
#define fltkVTKImageViewerGUI_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "fltkVTKImageViewerBase.h"
#include "vtkFlRenderWindowInteractor.h"

class fltkVTKImageViewerGUI : public fltk::VTKImageViewerBase {
public:
  fltkVTKImageViewerGUI();
  Fl_Double_Window *externalWindow;
  vtkFlRenderWindowInteractor *fltkRenderWindowInteractor;
  virtual ~fltkVTKImageViewerGUI();
  virtual void Show();
  virtual void Hide();
};
#endif