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
	m_SeriesWriter 					= SeriesWriterType::New();
	m_ImageIO 						= ImageIOType::New();
	m_OutputNames 					= OutputNamesType::New();
	
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

void RegionGrowingBase::SaveConfConSeries( const char * outputDirectory )
{

	std::cout << "SaveConfConSeries: saving series...";
	
	m_SeriesWriter->SetInput( m_ConfidenceConnectedImageFilter->GetOutput() );
	m_SeriesWriter->SetImageIO( m_ImageIO );
	
	//Set up OutputNames Writer
	itksys::SystemTools::MakeDirectory( outputDirectory );
	std::string seriesFormat( outputDirectory );
	seriesFormat = seriesFormat + "/" + "IM%d.dcm";
	m_OutputNames->SetSeriesFormat (seriesFormat.c_str());
	m_OutputNames->SetStartIndex (1);
	
	//Find and set end index
	const OutputImageType::RegionType& inputRegion = m_DicomReader->GetOutput()->GetLargestPossibleRegion();
	const OutputImageType::SizeType& inputSize = inputRegion.GetSize();
	m_OutputNames->SetEndIndex (inputSize[2]);
	
	//set writer file names
	m_SeriesWriter->SetFileNames( m_OutputNames->GetFileNames() );
	
	//copy metadata
	m_SeriesWriter->SetMetaDataDictionaryArray( m_DicomReader->GetMetaDataDictionaryArray() );
	
	//try to write series
	try
    {
		m_SeriesWriter->Update();
	}
	catch( itk::ExceptionObject & excp )
    {
		std::cerr << "Exception thrown while writing the series " << std::endl;
		std::cerr << excp << std::endl;
    }
	std::cout << "Series written!\n";
	
	std::cout << "done!";
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
	  std::cout << "SelectSmoothingFilter: No preprocessing selected\n";
      m_NullImageFilter->SetInput( m_DicomToInternalImageTypeFilter->GetOutput() );
      break;
    case 1:
	  std::cout << "SelectSmoothingFilter: Gradient Anisotropic diffusion selected\n";
      m_NullImageFilter->SetInput( m_GradientAnisotropicDiffusionImageFilter->GetOutput() );
      break;
    case 2:
	  std::cout << "SelectSmoothingFilter: Curvature Anisotropic diffusion selected\n";
      m_NullImageFilter->SetInput( m_CurvatureAnisotropicDiffusionImageFilter->GetOutput() );
      break;
    }
}

void RegionGrowingBase::Stop( void )
{
	//Application code indicates Stop() method will be added to filters.
}

