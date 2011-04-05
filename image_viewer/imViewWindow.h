/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#ifndef _imViewWindow_h
#define _imViewWindow_h

#include "imViewWindowGUI.h"

class imViewWindow : public imViewWindowGUI {  
public:

  /** Display the window */
  void Show(void);

  /** Returns the interactor */
  vtkFlRenderWindowInteractor* GetFLInteractor() {return m_FlRenderWindowInteractor;}

  /** Creates the rendering stuff */
  void CreateRenderer();
  imViewWindow();
  ~imViewWindow();

};



#endif


