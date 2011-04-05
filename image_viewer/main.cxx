/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#include "imView.h"
#include <FL/Fl.H>

int main(int, char**)
{
  imView theImViewer;
  theImViewer.Show();

  Fl::run();
  return 0;
}