/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#include "imViewWindow.h"
#include "vtkActor.h"
#include "vtkAxes.h"
#include "vtkPolyDataMapper.h"
#include "vtkTubeFilter.h"

imViewWindow::imViewWindow() {}

imViewWindow::~imViewWindow() {}

void imViewWindow::Show(void) {
  this->imViewWindowGUI::Show();
}

void imViewWindow::CreateRenderer() {
  cout << "begin CreateRenderer" << endl;

  // Create a new renderer and add it to the render window
  m_Renderer = vtkRenderer::New();
  m_RenderWindow = vtkRenderWindow::New();
  m_RenderWindow->AddRenderer( m_Renderer );

  // Set the render window of the FLTK window
  m_FlRenderWindowInteractor->SetRenderWindow(m_RenderWindow);
  m_FlRenderWindowInteractor->Initialize();

  // The background is black
  m_Renderer->SetBackground( 0.0, 0.0, 0.0 );

  // Make some axes
  vtkAxes *axes = vtkAxes::New();
    axes->SetOrigin(0, 0, 0);
    axes->SetScaleFactor(10.0);
  vtkTubeFilter *axesTubes = vtkTubeFilter::New();
    axesTubes->SetInput(axes->GetOutput());
    axesTubes->SetRadius(axes->GetScaleFactor()/25.0);
    axesTubes->SetNumberOfSides(6);
  vtkPolyDataMapper *axesMapper = vtkPolyDataMapper::New();
    axesMapper->SetInput(axesTubes->GetOutput());
  vtkActor *axesActor = vtkActor::New();
    axesActor->SetMapper(axesMapper);

  m_Renderer->AddActor(axesActor);

  // Now that the actor is added we can safely call delete
  axes->Delete();
  axesTubes->Delete();
  axesMapper->Delete();
  axesActor->Delete();

  // Render everything
  m_Renderer->ResetCamera();

  cout << "end CreateRenderer" << endl;
}