/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#include "imViewBase.h"

#include <FL/Fl.H>
#include <FL/Fl_File_Chooser.H>

#include <itkMetaImageIOFactory.h>

imViewBase::imViewBase()
{
  // The file name of the image we're reading
  m_InputImageFilename = new char[256];

  // The first time update is called we need to do some extra stuff
  m_IsFirstUpdate = true;

  m_InputImage = 0;
  m_ProcessedImage = 0;
  m_BeforeWindow = 0;
  m_AfterWindow = 0;
}

imViewBase::~imViewBase()
{
  if( m_InputImageFilename )
    delete[] m_InputImageFilename;
  
  if(m_BeforeWindow)
    delete m_BeforeWindow;
  
  if(m_AfterWindow)
    delete m_AfterWindow;
}

void imViewBase::ReadImage()
{
  cout << "In ReadImage()" << endl;

  // Can only read an image once
  if(m_InputImage != (void*)0)
	  return;
  
  // Show a dialog box to let the user pick a file
  //char* fileName = fl_file_chooser("Choose DICOM image folder.", "*.dcm", 4, 0);
  char* fileName = fl_dir_chooser("Choose DICOM image folder",0,0);

  // Store the filename
  strcpy( m_InputImageFilename, fileName );

  cout << "Opening directory: " << m_InputImageFilename << endl;

  // Now we can read the file
  m_ImageReader = ImageFileReaderType::New();
  m_ImageIOType = ImageIOType::New();
  m_GDCMSeriesFileNamesType = GDCMSeriesFileNamesType::New();
  
  m_ImageReader->SetImageIO( m_ImageIOType );
  m_GDCMSeriesFileNamesType->SetUseSeriesDetails( true );
  m_GDCMSeriesFileNamesType->SetDirectory( m_InputImageFilename );
  
  const SeriesIdContainer & seriesUID = m_GDCMSeriesFileNamesType->GetSeriesUIDs();
  fileNames = m_GDCMSeriesFileNamesType->GetFileNames( seriesUID.begin()->c_str() );
  
  //itk::MetaImageIOFactory::RegisterOneFactory(); //Part of original code
  
  m_ImageReader->SetFileNames( fileNames );
  try
      {
      m_ImageReader->Update();
      }
	catch (itk::ExceptionObject &ex)
      {
      std::cout << ex << std::endl;
      }
	  
  m_InputImage = m_ImageReader->GetOutput();
  
  /** Code from original example
  m_InputImage->SetRequestedRegionToLargestPossibleRegion();
  m_ImageReader->Update();
  */

  // Create and show the two image viewer windows
  m_BeforeWindow = new imViewWindow;
  m_BeforeWindow->renderWindow->label("ImageViewer - 'Before' Image");
  m_BeforeWindow->Show();
  m_BeforeWindow->CreateRenderer();
  
  /** Only show BeforeWindow for now, worry about after window later
  m_AfterWindow = new imViewWindow;
  m_AfterWindow->renderWindow->label("ImageViewer - 'After' Image");
  m_AfterWindow->Show();
  m_AfterWindow->CreateRenderer(); 
  */

  // Finally, create the ITK pipeline (but don't run it)
  this->CreateITKPipeline();
}

void imViewBase::CreateITKPipeline() {
  
  /** Forget the filter for now
  // Set up our example filter
  m_RegionGrowingTypeFilter = RegionGrowingType::New();
  m_RegionGrowingTypeFilter->SetInput(m_InputImage);
  
  // Get the final pipeline output... be sure to do this in your revisions!
  m_ProcessedImage = m_RegionGrowingTypeFilter->GetOutput();
  */
  
  //Draw image to before window
  m_BeforeWindow->SetImage(m_InputImage);
  m_BeforeWindow->CreateImagePlanes();
  m_BeforeWindow->Render();
}

void imViewBase::UpdateFilterCallback()
{
  /** Disable the update filter callback for now
  // Update the pipeline
  m_RegionGrowingTypeFilter->Update();
  */

  if(m_IsFirstUpdate) {
  
    // Show the input image
    m_BeforeWindow->SetImage(m_InputImage);
    m_BeforeWindow->CreateImagePlanes();
  
    // Show the output image
    //m_AfterWindow->SetImage(m_ProcessedImage);
    //m_AfterWindow->CreateImagePlanes();

    // No longer the first update
    m_IsFirstUpdate = false;
  }
  
  m_BeforeWindow->Render();
  //m_AfterWindow->Render();
}