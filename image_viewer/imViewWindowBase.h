/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#ifndef _imViewWindowBase_h
#define _imViewWindowBase_h

#include <stdio.h>

// Native ITK stuff
#include "itkSize.h"
#include "itkIndex.h"
#include "itkImage.h"
#include "itkOrientedImage.h"

// For importing ITK images into VTK
#include <vtkImageImport.h>
#include "itkVTKImageExport.h"

// here we have all the usual VTK stuff that we need for our pipeline
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkActor.h>
#include <vtkActorCollection.h>

// for hooking into FLTK
#include "vtkFlRenderWindowInteractor.h"

// For the cutting planes
#include <vtkImagePlaneWidget.h>

// For hooking up pipelines
#include "itkCommand.h"

class imViewWindowBase {
public:

  /** Type of input image (we read META format data*/
  //typedef itk::Image<unsigned char, 3> InputImageType;
  //typedef itk::Vector< float, 1 >                PixelType;
  //typedef itk::Image< PixelType, 3 > InputImageType;
  typedef signed short    PixelType;
  typedef itk::OrientedImage< PixelType, 3 >	InputImageType;
  
  // This is included in case we're using VTK 4.2, where the floating
  // point type is undefined
  #ifndef SWIG
   # ifndef vtkFloatingPointType
   #  define vtkFloatingPointType float
   # endif
  #endif
  
  /** Type of image exported from ITK to VTK */
  typedef itk::VTKImageExport<InputImageType> itkVTKImageExportType;
  
  /** Type of image imported from ITK into VTK */
  typedef itkVTKImageExportType::Pointer itkVTKImageExportPointerType;
  
  /** Set the ITK image we're going to display */
  void SetImage(InputImageType::Pointer p) {m_InputImage = p;}

  /** Puts the image planes in the center of the volume */
  void CreateImagePlanes();

  /** Put the image planes back at the center of the volume */
  void ResetImagePlaneWidgets();
  
  /** Cause the local render window to update */
  void Render();

  /** Gets the render window actor, for creating widgets */
  virtual vtkFlRenderWindowInteractor* GetFLInteractor() = 0;

  /** Constructor - not much to see */
  imViewWindowBase();

  /** Destructor - not much to see */
  virtual ~imViewWindowBase();

protected:

  /** The image we're going to display */
  InputImageType::Pointer m_InputImage;

  /** VTK rendering architecture */
  vtkRenderWindow * m_RenderWindow;
  vtkRenderer     * m_Renderer;

  /** Converter from ITK to VTK */
  itkVTKImageExportPointerType itkVTKExporter;
  vtkImageImport* vtkImporter;

  /** Slices through the volume */
  vtkImagePlaneWidget* m_ImagePlaneX;
  vtkImagePlaneWidget* m_ImagePlaneY;
  vtkImagePlaneWidget* m_ImagePlaneZ;
};

#endif
