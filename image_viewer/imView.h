/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#ifndef _imView_h
#define _imView_h

#include "imViewGUI.h"

class imView : public imViewGUI {  
public:

  /** Display the window */
  void Show(void);

  imView();
  ~imView();
};

#endif

