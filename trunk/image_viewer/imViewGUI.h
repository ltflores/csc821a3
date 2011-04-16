// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef imViewGUI_h
#define imViewGUI_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "imViewBase.h"
#include <FL/Fl_Button.H>

class imViewGUI : public imViewBase {
public:
  imViewGUI();
  Fl_Double_Window *imView;
private:
  void cb_Load_i(Fl_Button*, void*);
  static void cb_Load(Fl_Button*, void*);
  void cb_Run_i(Fl_Button*, void*);
  static void cb_Run(Fl_Button*, void*);
  void cb_Quit_i(Fl_Button*, void*);
  static void cb_Quit(Fl_Button*, void*);
public:
  ~imViewGUI();
  void Show();
  void Hide(void);
};
#endif