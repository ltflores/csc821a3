// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "imViewGUI.h"

void imViewGUI::cb_Load_i(Fl_Button*, void*) {
  this->ReadImage();
}
void imViewGUI::cb_Load(Fl_Button* o, void* v) {
  ((imViewGUI*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

void imViewGUI::cb_Run_i(Fl_Button*, void*) {
  this->UpdateFilterCallback();
}
void imViewGUI::cb_Run(Fl_Button* o, void* v) {
  ((imViewGUI*)(o->parent()->user_data()))->cb_Run_i(o,v);
}

void imViewGUI::cb_Quit_i(Fl_Button*, void*) {
  this->Hide();
}
void imViewGUI::cb_Quit(Fl_Button* o, void* v) {
  ((imViewGUI*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

imViewGUI::imViewGUI() {
  { imView = new Fl_Double_Window(275, 185);
    imView->user_data((void*)(this));
    { Fl_Button* o = new Fl_Button(95, 20, 85, 30, "Load Image");
      o->callback((Fl_Callback*)cb_Load);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(95, 70, 85, 30, "Run Filter");
      o->callback((Fl_Callback*)cb_Run);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(95, 120, 85, 30, "Quit");
      o->callback((Fl_Callback*)cb_Quit);
    } // Fl_Button* o
    imView->end();
  } // Fl_Double_Window* imView
}

imViewGUI::~imViewGUI() {
  this->Hide();
}

void imViewGUI::Show() {
  imView->show();
}

void imViewGUI::Hide(void) {
  if( m_BeforeWindow ) m_BeforeWindow->Hide();
  if( m_AfterWindow ) m_AfterWindow->Hide();
  imView->hide();
}
