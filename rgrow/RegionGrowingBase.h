/*=========================================================================

  Program:   Region Gorwing Application
  Course:	 CSC821
  Date:      April 13, 2011
  Version:   1.0
  
  Author: Lorenzo Flores
  Notes: Code based on ITK region growing segmentation application.

=========================================================================*/

#ifndef REGIONGROWINGBASE
#define REGIONGROWINGBASE

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "DICOMFileReader.h"

#include "itkImage.h"
#include "itkCastImageFilter.h"
#include "itkExtractImageFilter.h"

#include "itkConnectedThresholdImageFilter.h"
#include "itkConfidenceConnectedImageFilter.h"
#include "itkCustomRegionGrowingImageFilter.h"

#include "itkCurvatureFlowImageFilter.h"
#include "itkGradientAnisotropicDiffusionImageFilter.h"
#include "itkCurvatureAnisotropicDiffusionImageFilter.h"

#include "itkRescaleIntensityImageFilter.h"
#include "itkUnaryFunctorImageFilter.h"

/**
 * RegionGrowingBase class that instantiate
 * the elements required for a Region Growing approach for segmentation
 */
 
 class RegionGrowingBase
 {
	public:
		/** image dimensions */
		enum { ImageDimension = 3 };
		
		/** input image pixel type */
		typedef signed short		InputPixelType;
		
		/** dicom pixel type */
		typedef signed short 		DicomPixelType;
		
		/** output image pixel type */
		typedef unsigned char		OutputPixelType;
		
		/** internal pixel type */
		typedef float				InternalPixelType;
		
		/** input image type */
		typedef   itk::Image<InputPixelType,ImageDimension>    InputImageType;
		
		/** output image type */
		typedef   itk::Image<OutputPixelType,ImageDimension>   OutputImageType;
		
		/** internal image type */
		typedef   itk::Image<InternalPixelType,ImageDimension> InternalImageType;
		
		/** dicom image type */
		typedef itk::Image< InputPixelType, ImageDimension> 		   DicomImageType;
		
		/** input image reader */
		typedef   itk::ImageFileReader< InputImageType >       ImageReaderType;
		
		/** write input image */
		typedef   itk::ImageFileWriter< OutputImageType >      ImageWriterType;
		
		/** DICOM reader */
		typedef  itk::ImageFileReader< InputImageType   >  DicomReaderType;
		
		/** DICOM to internal image type filter */
		typedef itk::RescaleIntensityImageFilter<DicomImageType, InternalImageType> DicomToInternalImageTypeFilterType;
		
		/** cast filter to convert from input to internal image */
		typedef	itk::CastImageFilter<InputImageType,InternalImageType>		CastImageFilterType;
		
		/** extract filter used for actual region growing results */
		typedef itk::ExtractImageFilter<InternalImageType,InternalImageType> ExtractImageFilterType;
		
		/** null filter, commented code would allow filtered images as input */
		//typedef itk::CastImageFilter<InternalImageType,InternalImageType> NullImageFilterType;
		typedef itk::CastImageFilter<InputImageType,InternalImageType> NullImageFilterType;
		
		//INSERT OTHER FILTERS HERE
		
		/** threshold image filter */
		typedef itk::ConnectedThresholdImageFilter<InternalImageType,OutputImageType> ConnectedThresholdImageFilterType;
		
		/** confidence connected image filter */
		typedef itk::ConfidenceConnectedImageFilter<InternalImageType,OutputImageType> ConfidenceConnectedImageFilterType;
		
		/** custom region growing fillter*/
		typedef itk::CustomRegionGrowingImageFilter<InternalImageType,OutputImageType> CustomRegionGrowingImageFilterType;
		
	public:
	
		RegionGrowingBase();
		virtual ~RegionGrowingBase();
		
		virtual void LoadInputImage(void)=0;
		virtual void LoadInputImage(const char * filename);
		virtual void LoadInputImageSeries(void)=0;
		virtual void LoadInputImageSeries(const char * dirname);
		
		virtual void WriteOutputImage()=0;
		virtual void WriteOutputImage(const char * filename);
		virtual void WriteConnectedThresholdImage()=0;
		virtual void WriteConfidenceConnectedImage()=0;
		
		virtual void ShowStatus(const char * text)=0;
		
		virtual void Stop(void);
		
		virtual void SelectSmoothingFilter( unsigned int );
		
	protected:
	
		ImageReaderType::Pointer                    m_ImageReader;
  
		ImageWriterType::Pointer                    m_ImageWriter;
		
		DICOMFileReader::Pointer					m_DicomReader;

		bool                                        m_InputImageIsLoaded;

		CastImageFilterType::Pointer                m_CastImageFilter;

		ExtractImageFilterType::Pointer             m_ExtractImageFilter;

		NullImageFilterType::Pointer                m_NullImageFilter;
		
		//INSERT OTHER FILTER VARIABLE DEFINITIONS

		ConnectedThresholdImageFilterType::Pointer  m_ConnectedThresholdImageFilter;

		ConfidenceConnectedImageFilterType::Pointer m_ConfidenceConnectedImageFilter;
		
		CustomRegionGrowingImageFilterType::Pointer m_CustomRegionGrowingImageFilter;
		
		/** boolean that indicates DICOM image */
		bool 										m_InputImageIsDICOM;
		
		/** dicom conversion filters*/
		DicomToInternalImageTypeFilterType::Pointer m_DicomToInternalImageTypeFilter;
		
};

#endif