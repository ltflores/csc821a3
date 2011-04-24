/*=========================================================================

  Program:   Region Gorwing Application
  Course:	 CSC821
  Date:      April 13, 2011
  Version:   1.0
  
  Author: Lorenzo Flores
  Notes: Code based on ITK region growing segmentation application.

=========================================================================*/

#include "RegionGrowingBase.h"
#include <FL/fl_ask.H>

/** constructor */
RegionGrowingBase::RegionGrowingBase()
{
	m_ImageReader                  	= ImageReaderType::New();
	m_ImageWriter                  	= ImageWriterType::New();
	m_DicomReader					= DICOMFileReader::New();
	
	//boolean to indicate DICOM image
	m_InputImageIsDICOM 			= 1;
	
	/** initialize DICOM conversion filters */
	
	//m_DicomToInternalImageTypeFilter = DicomToInternalImageTypeFilterType::New();
	m_DicomToInternalImageTypeFilter = DicomToInternalImageTypeFilterType::New();
	m_DicomToInternalImageTypeFilter->SetOutputMinimum( 0 );
	m_DicomToInternalImageTypeFilter->SetOutputMaximum( 0xffffffff );

	/** initialize cast image filter */
	m_CastImageFilter = CastImageFilterType::New();
	m_CastImageFilter->SetInput( m_ImageReader->GetOutput() );
	
	m_CastImageFilter2 = CastImageFilterType2::New();
	m_CastImageFilter2->SetInput( m_DicomReader->GetOutput() );

	m_ExtractImageFilter = ExtractImageFilterType::New();
	m_ExtractImageFilter->SetInput( m_CastImageFilter->GetOutput() );
	
	/** initialize data structures */
	m_NullImageFilter = NullImageFilterType::New();
	m_GradientAnisotropicDiffusionImageFilter = GradientAnisotropicDiffusionImageFilterType::New();
	m_CurvatureAnisotropicDiffusionImageFilter = CurvatureAnisotropicDiffusionImageFilterType::New();
	m_ConnectedThresholdImageFilter = ConnectedThresholdImageFilterType::New();
	m_ConfidenceConnectedImageFilter = ConfidenceConnectedImageFilterType::New();
	m_CustomRegionGrowingImageFilter = CustomRegionGrowingImageFilterType::New();
	
	/** convert input image to internal type */
	m_DicomToInternalImageTypeFilter->SetInput( m_DicomReader->GetOutput() );
	
	/** connect preprocessing filter input to converted reader output */
	m_GradientAnisotropicDiffusionImageFilter->SetInput(m_DicomToInternalImageTypeFilter->GetOutput());
	m_CurvatureAnisotropicDiffusionImageFilter->SetInput(m_DicomToInternalImageTypeFilter->GetOutput());
	
	/** set null filter input, default to raw image */
	m_NullImageFilter->SetInput( m_DicomToInternalImageTypeFilter->GetOutput() );
	
	/** connect r-grow filters to null output */
	m_ConnectedThresholdImageFilter->SetInput( m_NullImageFilter->GetOutput() );
	m_ConfidenceConnectedImageFilter->SetInput( m_NullImageFilter->GetOutput() );
	m_CustomRegionGrowingImageFilter->SetInput( m_NullImageFilter->GetOutput() );
	
	m_InputImageIsLoaded  = false;
}

/** destructor */
RegionGrowingBase::~RegionGrowingBase()
{

}

/** input image loader */
void RegionGrowingBase::LoadInputImage( const char * filename )
{
	if( !filename )
	{
		return;
	}

	m_ImageReader->SetFileName( filename );
	m_ImageReader->Update();
  
	m_InputImageIsDICOM = 0;
	m_InputImageIsLoaded = 1;
}

/** dicom image loader */
void RegionGrowingBase::LoadInputImageSeries( const char * dirname )
{
	if ( !dirname )
	{
		return;
	}
	
	m_DicomReader->SetDirectoryName(dirname);
	
	m_InputImageIsDICOM = 1;
	m_InputImageIsLoaded = 1;
}

/** output image writer */
void RegionGrowingBase::WriteOutputImage( const char * filename )
{
	if( !filename )
	{
		return;
	}

	m_ImageWriter->SetFileName( filename );
	m_ImageWriter->Update();
}

/** smoothing filter selector */
void RegionGrowingBase::SelectSmoothingFilter( unsigned int choice )
{
  switch(choice)
    {
    case 0:
      m_NullImageFilter->SetInput( m_DicomToInternalImageTypeFilter->GetOutput() );
      break;
    case 1:
      m_NullImageFilter->SetInput( m_GradientAnisotropicDiffusionImageFilter->GetOutput() );
      break;
    case 2:
      m_NullImageFilter->SetInput( m_CurvatureAnisotropicDiffusionImageFilter->GetOutput() );
      break;
    }
}

void RegionGrowingBase::Stop( void )
{
	//Application code indicates Stop() method will be added to filters.
}

