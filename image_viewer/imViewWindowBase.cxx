/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#include "imViewWindowBase.h"
#include <FL/Fl.H>
#include <FL/Fl_File_Chooser.H>

imViewWindowBase::imViewWindowBase() {

  // Clear VTK stuff
  m_Renderer = 0;
  m_RenderWindow = 0;
  
  // No initial image to display
  m_InputImage = 0;
}

imViewWindowBase::~imViewWindowBase() {
  if( m_RenderWindow )
    m_RenderWindow->Delete();

  if( m_Renderer )
    m_Renderer->Delete();

  if( m_ImagePlaneX != 0)
    m_ImagePlaneX->Delete();

  if( m_ImagePlaneY != 0)
    m_ImagePlaneY->Delete();

  if( m_ImagePlaneZ != 0)
    m_ImagePlaneZ->Delete();
}


void imViewWindowBase::CreateImagePlanes() {
  // Abort if the user is being stupid
  if(m_InputImage==(void*)0)
    return;
    
  // Hook the VTK pipeline up to the ITK pipeline
  itkVTKExporter = itkVTKImageExportType::New();
  vtkImporter = vtkImageImport::New();
  itkVTKExporter->SetInput( m_InputImage );
  
  // Connect pipeline events
  vtkImporter->SetUpdateInformationCallback(itkVTKExporter->GetUpdateInformationCallback());
  vtkImporter->SetPipelineModifiedCallback(itkVTKExporter->GetPipelineModifiedCallback());
  vtkImporter->SetWholeExtentCallback(itkVTKExporter->GetWholeExtentCallback());
  vtkImporter->SetSpacingCallback(itkVTKExporter->GetSpacingCallback());
  vtkImporter->SetOriginCallback(itkVTKExporter->GetOriginCallback());
  vtkImporter->SetScalarTypeCallback(itkVTKExporter->GetScalarTypeCallback());
  vtkImporter->SetNumberOfComponentsCallback(itkVTKExporter->GetNumberOfComponentsCallback());
  vtkImporter->SetPropagateUpdateExtentCallback(itkVTKExporter->GetPropagateUpdateExtentCallback());
  vtkImporter->SetUpdateDataCallback(itkVTKExporter->GetUpdateDataCallback());
  vtkImporter->SetDataExtentCallback(itkVTKExporter->GetDataExtentCallback());
  vtkImporter->SetBufferPointerCallback(itkVTKExporter->GetBufferPointerCallback());
  vtkImporter->SetCallbackUserData(itkVTKExporter->GetCallbackUserData());

  // Need to update prior to creating the cutting planes
  itkVTKExporter->Update();
  vtkImporter->Update();

  // Create the image cutting planes
  m_ImagePlaneX = vtkImagePlaneWidget::New();
  m_ImagePlaneX->RestrictPlaneToVolumeOn();
  m_ImagePlaneX->SetResliceInterpolateToCubic();
  m_ImagePlaneX->SetInput( (vtkDataSet*) vtkImporter->GetOutput() );
  m_ImagePlaneX->SetPlaneOrientationToXAxes();
  m_ImagePlaneX->SetSliceIndex( 0 );
  
  m_ImagePlaneY = vtkImagePlaneWidget::New();
  m_ImagePlaneY->RestrictPlaneToVolumeOn();
  m_ImagePlaneY->SetResliceInterpolateToCubic();
  m_ImagePlaneY->SetInput( (vtkDataSet*) vtkImporter->GetOutput() );
  m_ImagePlaneY->SetPlaneOrientationToYAxes();
  m_ImagePlaneY->SetSliceIndex( 0 );
  
  m_ImagePlaneZ = vtkImagePlaneWidget::New();
  m_ImagePlaneZ->RestrictPlaneToVolumeOn();
  m_ImagePlaneZ->SetResliceInterpolateToCubic();
  m_ImagePlaneZ->SetInput( (vtkDataSet*) vtkImporter->GetOutput() );
  m_ImagePlaneZ->SetPlaneOrientationToZAxes();
  m_ImagePlaneZ->SetSliceIndex( 0 );
  
  this->ResetImagePlaneWidgets();

  m_ImagePlaneX->SetInteractor( this->GetFLInteractor() );
  m_ImagePlaneY->SetInteractor( this->GetFLInteractor() );
  m_ImagePlaneZ->SetInteractor( this->GetFLInteractor() );
  
  m_ImagePlaneX->On();
  m_ImagePlaneY->On();
  m_ImagePlaneZ->On();

  // Now redraw everything
  m_Renderer->ResetCamera();
  m_RenderWindow->Render();
}

void imViewWindowBase::ResetImagePlaneWidgets() {
  // abort if there's no image loaded
  if(m_InputImage == (void*)0)
    return;

  // otherwise, reset everything
  m_ImagePlaneZ->SetPlaneOrientationToZAxes();
  m_ImagePlaneY->SetPlaneOrientationToYAxes();
  m_ImagePlaneX->SetPlaneOrientationToXAxes();

  // Figure out how big the image is
  itk::Size<3> imageSize = m_InputImage->GetLargestPossibleRegion().GetSize();

  int xmax = imageSize[0];
  int ymax = imageSize[1];
  int zmax = imageSize[2];

  // Set the image planes to the center of the image
  m_ImagePlaneX->SetSlicePosition( xmax/2 );
  m_ImagePlaneY->SetSlicePosition( ymax/2 );
  m_ImagePlaneZ->SetSlicePosition( zmax/2 );
}

void imViewWindowBase::Render()
{
  // Need to update prior to creating the cutting planes
  itkVTKExporter->Update();
  vtkImporter->Update();
 
  // Render
  m_RenderWindow->Render();
}
