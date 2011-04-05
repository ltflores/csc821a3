/*=========================================================================

  Program:   Image Viewer for CSC821@SFSU region growing project (A3)
  Language:  C++
  Date:      March 30, 2011
  Version:   v1.0

=========================================================================*/

#ifndef _imViewBase_h
#define _imViewBase_h

#include <stdio.h>

// Native ITK stuff
#include "itkSize.h"
#include "itkIndex.h"
#include "itkImage.h"
#include "itkRegionGrowImageFilter.h"
#include <itkKLMRegionGrowImageFilter.h>
#include <itkCastImageFilter.h>
#include "itkVTKImageExport.h"

// File reader stuff
#include "itkImageFileReader.h"
#include "itkOrientedImage.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"

// Image viewer window
#include "imViewWindow.h"


class imViewBase {
public:

  /** Image Type Definitions, these facilitate a 1D vector based vector
	  image, used by the KLMRegionGrowImageFilter.
  typedef itk::Vector< float, 1 >                PixelType;
  typedef itk::Image< PixelType, 3 >        TImageType;
  typedef itk::Image< PixelType, 3 > InputImageType;
  typedef itk::Image< PixelType, 3 > OutputImageType;
  */
  
  /** Basic Image pixel types for testing purposes. 
  typedef itk::Image<double, 3> TImageType;
  typedef itk::Image<double, 3> InputImageType;
  typedef itk::Image<double, 3> OutputImageType;
  */
  
  /** For Dicom Images */
  typedef signed short    PixelType;
  typedef itk::OrientedImage< PixelType, 3 >	TImageType;
  
  /** Series image reader */
  //typedef itk::ImageFileReader< TImageType > ImageFileReaderType;
  typedef itk::ImageSeriesReader< TImageType >	ImageFileReaderType;
  
  /** DICOM image reader */
  typedef itk::GDCMImageIO       ImageIOType;
  
  /** DICOM Series File names */
  typedef itk::GDCMSeriesFileNames GDCMSeriesFileNamesType;
  typedef std::vector< std::string >   FileNamesContainer;
  
  /** DICOM Series file container, contains references to individual 
	  file names */
  //TODO figure out why they use 'std' for these types
  typedef std::vector< std::string >    SeriesIdContainer;
  
  /** ITK VTK pipeline stuff, for connecting the two */
  typedef itk::VTKImageExport<TImageType> itkVTKImageExportType;
  typedef itkVTKImageExportType::Pointer itkVTKImageExportPointerType;
  
  /** NEED FILTER typedef HERE */

  /** Read a META format image from disk */
  void ReadImage();
  
  /** Hook together an ITK pipeline */
  void CreateITKPipeline();
  
  /** Callback for making the ITK pipeline do something */
  void UpdateFilterCallback();

  /** Constructor - not much to see */
  imViewBase();

  /** Destructor - not much to see */
  virtual ~imViewBase();

protected:

  /** Input image file name */
  char* m_InputImageFilename;

  /** The image reader */
  ImageFileReaderType::Pointer m_ImageReader;
  
  /** DICOM IO */
  ImageIOType::Pointer m_ImageIOType;
  
  /** DICOM file names */
  GDCMSeriesFileNamesType::Pointer m_GDCMSeriesFileNamesType;
  FileNamesContainer fileNames;
  
  
  /** The image we loaded from the file */
  TImageType::Pointer m_InputImage;
  
  /** The image that results from running the pipeline */
  TImageType::Pointer m_ProcessedImage;

  /** Tracks whether this is the first time we've pressed "update" */
  bool m_IsFirstUpdate;
  
  /** The image viewer prior to the pipeline */
  imViewWindow* m_BeforeWindow;
  
  /** The image viewer after the pieline */
  imViewWindow* m_AfterWindow;
  
  /** The _EXAMPLE_ filter used here... you should change this */
  //RegionGrowingType::Pointer m_RegionGrowingTypeFilter;
  
  
};

#endif
