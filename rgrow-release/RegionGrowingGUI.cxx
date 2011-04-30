// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "RegionGrowingGUI.h"

void RegionGrowingGUI::cb_load_i(Fl_Button*, void*) {
  this->LoadInputImageSeries();
}
void RegionGrowingGUI::cb_load(Fl_Button* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->user_data()))->cb_load_i(o,v);
}

void RegionGrowingGUI::cb_inputImageButton_i(fltk::LightButton*, void*) {
  ShowInputImage();
}
void RegionGrowingGUI::cb_inputImageButton(fltk::LightButton* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->user_data()))->cb_inputImageButton_i(o,v);
}

void RegionGrowingGUI::cb_homogeneousImageVTKButton_i(fltk::LightButton*, void*) {
  ShowHomogeneousImageWithVTK();
}
void RegionGrowingGUI::cb_homogeneousImageVTKButton(fltk::LightButton* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->user_data()))->cb_homogeneousImageVTKButton_i(o,v);
}

void RegionGrowingGUI::cb_quit_i(Fl_Button*, void*) {
  this->Quit();
}
void RegionGrowingGUI::cb_quit(Fl_Button* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->user_data()))->cb_quit_i(o,v);
}

void RegionGrowingGUI::cb_Run_i(Fl_Button*, void*) {
  m_CurvatureAnisotropicDiffusionImageFilter->Update();
}
void RegionGrowingGUI::cb_Run(Fl_Button* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_Run_i(o,v);
}

void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionTimeStepValueInput_i(Fl_Value_Input* o, void*) {
  m_CurvatureAnisotropicDiffusionImageFilter->SetTimeStep( o->value() );
}
void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionTimeStepValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_curvatureAnisotropicDiffusionTimeStepValueInput_i(o,v);
}

void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionIterationsValueInput_i(Fl_Value_Input* o, void*) {
  m_CurvatureAnisotropicDiffusionImageFilter->SetNumberOfIterations( static_cast<unsigned int>( o->value() ) );
}
void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionIterationsValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_curvatureAnisotropicDiffusionIterationsValueInput_i(o,v);
}

void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionConductanceValueInput_i(Fl_Value_Input* o, void*) {
  m_CurvatureAnisotropicDiffusionImageFilter->SetConductanceParameter( o->value() );
}
void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionConductanceValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_curvatureAnisotropicDiffusionConductanceValueInput_i(o,v);
}

void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionImageButton_i(fltk::LightButton*, void*) {
  this->ShowCurvatureAnisotropicDiffusionImage();
}
void RegionGrowingGUI::cb_curvatureAnisotropicDiffusionImageButton(fltk::LightButton* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_curvatureAnisotropicDiffusionImageButton_i(o,v);
}

void RegionGrowingGUI::cb_gradientAnisotropicDiffusionTimeStepValueInput_i(Fl_Value_Input* o, void*) {
  m_GradientAnisotropicDiffusionImageFilter->SetTimeStep( o->value() );
}
void RegionGrowingGUI::cb_gradientAnisotropicDiffusionTimeStepValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_gradientAnisotropicDiffusionTimeStepValueInput_i(o,v);
}

void RegionGrowingGUI::cb_gradientAnisotropicDiffusionIterationsValueInput_i(Fl_Value_Input* o, void*) {
  m_GradientAnisotropicDiffusionImageFilter->SetNumberOfIterations( static_cast<unsigned int>( o->value() ) );
}
void RegionGrowingGUI::cb_gradientAnisotropicDiffusionIterationsValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_gradientAnisotropicDiffusionIterationsValueInput_i(o,v);
}

void RegionGrowingGUI::cb_gradientAnisotropicDiffusionConductanceValueInput_i(Fl_Value_Input* o, void*) {
  m_GradientAnisotropicDiffusionImageFilter->SetConductanceParameter( o->value() );
}
void RegionGrowingGUI::cb_gradientAnisotropicDiffusionConductanceValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_gradientAnisotropicDiffusionConductanceValueInput_i(o,v);
}

void RegionGrowingGUI::cb_gradientAnisotropicDiffusionImageButton_i(fltk::LightButton*, void*) {
  this->ShowGradientAnisotropicDiffusionImage();
}
void RegionGrowingGUI::cb_gradientAnisotropicDiffusionImageButton(fltk::LightButton* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_gradientAnisotropicDiffusionImageButton_i(o,v);
}

void RegionGrowingGUI::cb_Run1_i(Fl_Button*, void*) {
  m_CustomRegionGrowingImageFilter->Update();
}
void RegionGrowingGUI::cb_Run1(Fl_Button* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_Run1_i(o,v);
}

void RegionGrowingGUI::cb_customRegionGrowingImageButton_i(fltk::LightButton*, void*) {
  this->ShowCustomRegionGrowingImage();
}
void RegionGrowingGUI::cb_customRegionGrowingImageButton(fltk::LightButton* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_customRegionGrowingImageButton_i(o,v);
}

void RegionGrowingGUI::cb_confidenceConnectedImageButton_i(fltk::LightButton*, void*) {
  this->ShowConfidenceConnectedImage();
}
void RegionGrowingGUI::cb_confidenceConnectedImageButton(fltk::LightButton* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_confidenceConnectedImageButton_i(o,v);
}

void RegionGrowingGUI::cb_iterationsConfidenceValueInput_i(Fl_Value_Input* o, void*) {
  m_ConfidenceConnectedImageFilter->SetNumberOfIterations( static_cast<unsigned int>( o->value() ) );
}
void RegionGrowingGUI::cb_iterationsConfidenceValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_iterationsConfidenceValueInput_i(o,v);
}

void RegionGrowingGUI::cb_multiplierValueInput_i(Fl_Value_Input* o, void*) {
  m_ConfidenceConnectedImageFilter->SetMultiplier( o->value() );
}
void RegionGrowingGUI::cb_multiplierValueInput(Fl_Value_Input* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_multiplierValueInput_i(o,v);
}

void RegionGrowingGUI::cb_Run2_i(Fl_Button*, void*) {
  m_ConfidenceConnectedImageFilter->Update();
this->ShowVolume();
}
void RegionGrowingGUI::cb_Run2(Fl_Button* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_Run2_i(o,v);
}

void RegionGrowingGUI::cb_saveConfConSeriesButton_i(Fl_Button*, void*) {
  this->SaveConfConSeries();
}
void RegionGrowingGUI::cb_saveConfConSeriesButton(Fl_Button* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_saveConfConSeriesButton_i(o,v);
}

void RegionGrowingGUI::cb_None_i(Fl_Menu_*, void*) {
  this->SelectSmoothingFilter( 0 );
}
void RegionGrowingGUI::cb_None(Fl_Menu_* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->user_data()))->cb_None_i(o,v);
}

void RegionGrowingGUI::cb_Curvature_i(Fl_Menu_*, void*) {
  this->SelectSmoothingFilter( 2 );
}
void RegionGrowingGUI::cb_Curvature(Fl_Menu_* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->user_data()))->cb_Curvature_i(o,v);
}

void RegionGrowingGUI::cb_Gradient_i(Fl_Menu_*, void*) {
  this->SelectSmoothingFilter( 1 );
}
void RegionGrowingGUI::cb_Gradient(Fl_Menu_* o, void* v) {
  ((RegionGrowingGUI*)(o->parent()->parent()->parent()->user_data()))->cb_Gradient_i(o,v);
}

Fl_Menu_Item RegionGrowingGUI::menu_Choose[] = {
 {"None", 0,  (Fl_Callback*)RegionGrowingGUI::cb_None, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Curvature Anisotropic Diffusion ", 0,  (Fl_Callback*)RegionGrowingGUI::cb_Curvature, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Gradient Anisotropic Diffusion", 0,  (Fl_Callback*)RegionGrowingGUI::cb_Gradient, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

RegionGrowingGUI::RegionGrowingGUI() {
  { consoleWindow = new Fl_Double_Window(519, 620, "Region Growing");
    consoleWindow->user_data((void*)(this));
    { controlsGroup = new Fl_Group(5, 21, 1031, 624);
      { Fl_Group* o = new Fl_Group(10, 25, 495, 86, "Input");
        o->box(FL_THIN_DOWN_BOX);
        o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
        { Fl_Button* o = new Fl_Button(16, 50, 90, 35, "load DICOM");
          o->box(FL_ROUND_UP_BOX);
          o->callback((Fl_Callback*)cb_load);
        } // Fl_Button* o
        { inputImageButton = new fltk::LightButton(115, 42, 95, 20, "Input Image");
          inputImageButton->type(0);
          inputImageButton->box(FL_UP_BOX);
          inputImageButton->value(1);
          inputImageButton->color(FL_BACKGROUND_COLOR);
          inputImageButton->selection_color((Fl_Color)1);
          inputImageButton->labeltype(FL_NORMAL_LABEL);
          inputImageButton->labelfont(0);
          inputImageButton->labelsize(14);
          inputImageButton->labelcolor(FL_FOREGROUND_COLOR);
          inputImageButton->callback((Fl_Callback*)cb_inputImageButton);
          inputImageButton->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
          inputImageButton->when(FL_WHEN_RELEASE);
        } // fltk::LightButton* inputImageButton
        { homogeneousImageVTKButton = new fltk::LightButton(113, 78, 97, 20, "VTK Render");
          homogeneousImageVTKButton->box(FL_UP_BOX);
          homogeneousImageVTKButton->value(1);
          homogeneousImageVTKButton->color(FL_BACKGROUND_COLOR);
          homogeneousImageVTKButton->selection_color((Fl_Color)1);
          homogeneousImageVTKButton->labeltype(FL_NORMAL_LABEL);
          homogeneousImageVTKButton->labelfont(0);
          homogeneousImageVTKButton->labelsize(14);
          homogeneousImageVTKButton->labelcolor(FL_FOREGROUND_COLOR);
          homogeneousImageVTKButton->callback((Fl_Callback*)cb_homogeneousImageVTKButton);
          homogeneousImageVTKButton->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
          homogeneousImageVTKButton->when(FL_WHEN_RELEASE);
        } // fltk::LightButton* homogeneousImageVTKButton
        { seedGroup = new Fl_Group(216, 49, 278, 49, "Seed Point");
          seedGroup->box(FL_THIN_UP_BOX);
          { xSeedPointValueOutput = new Fl_Value_Output(232, 58, 70, 23, "x");
            xSeedPointValueOutput->step(0.01);
          } // Fl_Value_Output* xSeedPointValueOutput
          { ySeedPointValueOutput = new Fl_Value_Output(321, 58, 70, 23, "y");
            ySeedPointValueOutput->step(0.01);
          } // Fl_Value_Output* ySeedPointValueOutput
          { zSeedPointValueOutput = new Fl_Value_Output(412, 58, 68, 23, "z");
            zSeedPointValueOutput->step(0.01);
          } // Fl_Value_Output* zSeedPointValueOutput
          seedGroup->end();
        } // Fl_Group* seedGroup
        o->end();
      } // Fl_Group* o
      { Fl_Button* o = new Fl_Button(210, 580, 90, 30, "quit");
        o->box(FL_ROUNDED_BOX);
        o->callback((Fl_Callback*)cb_quit);
      } // Fl_Button* o
      { Fl_Group* o = new Fl_Group(8, 135, 497, 200, "Preprocessing Filters");
        o->box(FL_THIN_DOWN_BOX);
        o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
        { Fl_Group* o = new Fl_Group(56, 163, 203, 152, "Curvature Anisotropic Diffusion");
          o->box(FL_THIN_UP_BOX);
          o->align(Fl_Align(133));
          { Fl_Button* o = new Fl_Button(65, 275, 46, 23, "Run");
            o->box(FL_ROUND_UP_BOX);
            o->callback((Fl_Callback*)cb_Run);
            o->align(Fl_Align(FL_ALIGN_WRAP));
          } // Fl_Button* o
          { curvatureAnisotropicDiffusionTimeStepValueInput = new Fl_Value_Input(149, 177, 55, 23, "Time Step");
            curvatureAnisotropicDiffusionTimeStepValueInput->maximum(10);
            curvatureAnisotropicDiffusionTimeStepValueInput->value(0.05);
            curvatureAnisotropicDiffusionTimeStepValueInput->callback((Fl_Callback*)cb_curvatureAnisotropicDiffusionTimeStepValueInput);
          } // Fl_Value_Input* curvatureAnisotropicDiffusionTimeStepValueInput
          { curvatureAnisotropicDiffusionIterationsValueInput = new Fl_Value_Input(146, 208, 56, 24, "Iterations");
            curvatureAnisotropicDiffusionIterationsValueInput->maximum(100);
            curvatureAnisotropicDiffusionIterationsValueInput->value(1);
            curvatureAnisotropicDiffusionIterationsValueInput->callback((Fl_Callback*)cb_curvatureAnisotropicDiffusionIterationsValueInput);
          } // Fl_Value_Input* curvatureAnisotropicDiffusionIterationsValueInput
          { curvatureAnisotropicDiffusionConductanceValueInput = new Fl_Value_Input(147, 240, 55, 24, "Conductance");
            curvatureAnisotropicDiffusionConductanceValueInput->maximum(10);
            curvatureAnisotropicDiffusionConductanceValueInput->step(0.01);
            curvatureAnisotropicDiffusionConductanceValueInput->value(3);
            curvatureAnisotropicDiffusionConductanceValueInput->callback((Fl_Callback*)cb_curvatureAnisotropicDiffusionConductanceValueInput);
          } // Fl_Value_Input* curvatureAnisotropicDiffusionConductanceValueInput
          { curvatureAnisotropicDiffusionImageButton = new fltk::LightButton(139, 273, 75, 25, "Display");
            curvatureAnisotropicDiffusionImageButton->box(FL_UP_BOX);
            curvatureAnisotropicDiffusionImageButton->value(1);
            curvatureAnisotropicDiffusionImageButton->color(FL_BACKGROUND_COLOR);
            curvatureAnisotropicDiffusionImageButton->selection_color((Fl_Color)1);
            curvatureAnisotropicDiffusionImageButton->labeltype(FL_NORMAL_LABEL);
            curvatureAnisotropicDiffusionImageButton->labelfont(0);
            curvatureAnisotropicDiffusionImageButton->labelsize(14);
            curvatureAnisotropicDiffusionImageButton->labelcolor(FL_FOREGROUND_COLOR);
            curvatureAnisotropicDiffusionImageButton->callback((Fl_Callback*)cb_curvatureAnisotropicDiffusionImageButton);
            curvatureAnisotropicDiffusionImageButton->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
            curvatureAnisotropicDiffusionImageButton->when(FL_WHEN_RELEASE);
          } // fltk::LightButton* curvatureAnisotropicDiffusionImageButton
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(270, 163, 191, 152, "Gradient AnisotropicDiffusion");
          o->box(FL_THIN_UP_BOX);
          o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
          { Fl_Button* o = new Fl_Button(283, 278, 48, 23, "Run");
            o->box(FL_ROUND_UP_BOX);
            o->align(Fl_Align(FL_ALIGN_WRAP));
          } // Fl_Button* o
          { gradientAnisotropicDiffusionTimeStepValueInput = new Fl_Value_Input(369, 176, 48, 24, "Time Step");
            gradientAnisotropicDiffusionTimeStepValueInput->maximum(10);
            gradientAnisotropicDiffusionTimeStepValueInput->value(0.05);
            gradientAnisotropicDiffusionTimeStepValueInput->callback((Fl_Callback*)cb_gradientAnisotropicDiffusionTimeStepValueInput);
          } // Fl_Value_Input* gradientAnisotropicDiffusionTimeStepValueInput
          { gradientAnisotropicDiffusionIterationsValueInput = new Fl_Value_Input(368, 207, 50, 24, "Iteration");
            gradientAnisotropicDiffusionIterationsValueInput->maximum(100);
            gradientAnisotropicDiffusionIterationsValueInput->value(1);
            gradientAnisotropicDiffusionIterationsValueInput->callback((Fl_Callback*)cb_gradientAnisotropicDiffusionIterationsValueInput);
          } // Fl_Value_Input* gradientAnisotropicDiffusionIterationsValueInput
          { gradientAnisotropicDiffusionConductanceValueInput = new Fl_Value_Input(368, 240, 50, 24, "Conductance");
            gradientAnisotropicDiffusionConductanceValueInput->maximum(10);
            gradientAnisotropicDiffusionConductanceValueInput->step(0.01);
            gradientAnisotropicDiffusionConductanceValueInput->value(3);
            gradientAnisotropicDiffusionConductanceValueInput->callback((Fl_Callback*)cb_gradientAnisotropicDiffusionConductanceValueInput);
          } // Fl_Value_Input* gradientAnisotropicDiffusionConductanceValueInput
          { gradientAnisotropicDiffusionImageButton = new fltk::LightButton(352, 275, 73, 23, "Display");
            gradientAnisotropicDiffusionImageButton->box(FL_UP_BOX);
            gradientAnisotropicDiffusionImageButton->value(1);
            gradientAnisotropicDiffusionImageButton->color(FL_BACKGROUND_COLOR);
            gradientAnisotropicDiffusionImageButton->selection_color((Fl_Color)1);
            gradientAnisotropicDiffusionImageButton->labeltype(FL_NORMAL_LABEL);
            gradientAnisotropicDiffusionImageButton->labelfont(0);
            gradientAnisotropicDiffusionImageButton->labelsize(14);
            gradientAnisotropicDiffusionImageButton->labelcolor(FL_FOREGROUND_COLOR);
            gradientAnisotropicDiffusionImageButton->callback((Fl_Callback*)cb_gradientAnisotropicDiffusionImageButton);
            gradientAnisotropicDiffusionImageButton->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
            gradientAnisotropicDiffusionImageButton->when(FL_WHEN_RELEASE);
          } // fltk::LightButton* gradientAnisotropicDiffusionImageButton
          o->end();
        } // Fl_Group* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(9, 365, 496, 208, "Region Growing Filters");
        o->box(FL_THIN_DOWN_BOX);
        o->align(Fl_Align(FL_ALIGN_TOP_LEFT));
        { Fl_Group* o = new Fl_Group(45, 418, 125, 113, "Custom");
          o->box(FL_THIN_UP_BOX);
          o->color(FL_LIGHT1);
          { Fl_Button* o = new Fl_Button(85, 444, 50, 22, "Run");
            o->box(FL_ROUNDED_BOX);
            o->color(FL_LIGHT1);
            o->callback((Fl_Callback*)cb_Run1);
          } // Fl_Button* o
          { customRegionGrowingImageButton = new fltk::LightButton(70, 483, 75, 23, "Display");
            customRegionGrowingImageButton->box(FL_UP_BOX);
            customRegionGrowingImageButton->color(FL_LIGHT1);
            customRegionGrowingImageButton->selection_color((Fl_Color)36);
            customRegionGrowingImageButton->labeltype(FL_NORMAL_LABEL);
            customRegionGrowingImageButton->labelfont(0);
            customRegionGrowingImageButton->labelsize(14);
            customRegionGrowingImageButton->labelcolor(FL_FOREGROUND_COLOR);
            customRegionGrowingImageButton->callback((Fl_Callback*)cb_customRegionGrowingImageButton);
            customRegionGrowingImageButton->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
            customRegionGrowingImageButton->when(FL_WHEN_RELEASE);
          } // fltk::LightButton* customRegionGrowingImageButton
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(187, 416, 300, 152, "Confidence Connected");
          o->box(FL_THIN_UP_BOX);
          { confidenceConnectedImageButton = new fltk::LightButton(347, 532, 75, 18, "Display");
            confidenceConnectedImageButton->type(0);
            confidenceConnectedImageButton->box(FL_UP_BOX);
            confidenceConnectedImageButton->value(1);
            confidenceConnectedImageButton->color(FL_BACKGROUND_COLOR);
            confidenceConnectedImageButton->selection_color((Fl_Color)1);
            confidenceConnectedImageButton->labeltype(FL_NORMAL_LABEL);
            confidenceConnectedImageButton->labelfont(0);
            confidenceConnectedImageButton->labelsize(14);
            confidenceConnectedImageButton->labelcolor(FL_FOREGROUND_COLOR);
            confidenceConnectedImageButton->callback((Fl_Callback*)cb_confidenceConnectedImageButton);
            confidenceConnectedImageButton->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
            confidenceConnectedImageButton->when(FL_WHEN_RELEASE);
          } // fltk::LightButton* confidenceConnectedImageButton
          { iterationsConfidenceValueInput = new Fl_Value_Input(270, 424, 52, 24, "iterations");
            iterationsConfidenceValueInput->minimum(1);
            iterationsConfidenceValueInput->maximum(100);
            iterationsConfidenceValueInput->value(2);
            iterationsConfidenceValueInput->callback((Fl_Callback*)cb_iterationsConfidenceValueInput);
          } // Fl_Value_Input* iterationsConfidenceValueInput
          { multiplierValueInput = new Fl_Value_Input(403, 423, 55, 24, "multiplier");
            multiplierValueInput->maximum(100);
            multiplierValueInput->value(2.5);
            multiplierValueInput->callback((Fl_Callback*)cb_multiplierValueInput);
          } // Fl_Value_Input* multiplierValueInput
          { Fl_Button* o = new Fl_Button(210, 531, 45, 22, "Run");
            o->box(FL_ROUNDED_BOX);
            o->callback((Fl_Callback*)cb_Run2);
          } // Fl_Button* o
          { volumeOutput = new Fl_Value_Output(337, 459, 98, 24, "Region Voxels");
          } // Fl_Value_Output* volumeOutput
          { saveConfConSeriesButton = new Fl_Button(265, 530, 45, 22, "Save");
            saveConfConSeriesButton->box(FL_ROUNDED_BOX);
            saveConfConSeriesButton->callback((Fl_Callback*)cb_saveConfConSeriesButton);
          } // Fl_Button* saveConfConSeriesButton
          o->end();
        } // Fl_Group* o
        { totalVolumeOutput = new Fl_Value_Output(335, 493, 100, 24, "Total Voxels");
        } // Fl_Value_Output* totalVolumeOutput
        { Fl_Choice* o = new Fl_Choice(205, 373, 225, 20, "Choose Filter");
          o->down_box(FL_BORDER_BOX);
          o->menu(menu_Choose);
        } // Fl_Choice* o
        o->end();
      } // Fl_Group* o
      controlsGroup->end();
    } // Fl_Group* controlsGroup
    consoleWindow->end();
  } // Fl_Double_Window* consoleWindow
}
