/*=========================================================================

  Program:   Region Gorwing Application
  Course:	 CSC821
  Date:      April 13, 2011
  Version:   1.0
  
  Author: Lorenzo Flores
  Notes: Code based on ITK region growing segmentation application.

=========================================================================*/

#include "RegionGrowing.h"
#include <FL/fl_file_chooser.H>

/** constructor */
RegionGrowing::RegionGrowing() {

	m_InputImageViewer.SetLabel("Input Image");
	m_DicomImageViewer.SetLabel("DICOM Image");
	
	// filter values
	m_ConnectedThresholdImageViewer.SetLabel("Connected Threshold Image");
	m_ConfidenceConnectedImageViewer.SetLabel("Confidence Connected Image");
	m_CustomRegionGrowingImageViewer.SetLabel("Custom Region Growing Image");
	
	m_HomogeneousImageViewer.SetLabel("Homogeneous Image");
	m_HomogeneousImageViewer.ClickSelectCallBack( ClickSelectCallback, (void *)this);
	m_HomogeneousImageViewer.SetImage( m_NullImageFilter->GetOutput() );
	
	// init itk filter
	m_ConnectedThresholdImageFilter->SetLower( 
      static_cast<unsigned long>( lowerThresholdCounter->value() ) );

	m_ConnectedThresholdImageFilter->SetUpper( 
      static_cast<unsigned long>( upperThresholdCounter->value() ) );
	  
	m_ConfidenceConnectedImageFilter->SetMultiplier( multiplierValueInput->value() );

	m_ConfidenceConnectedImageFilter->SetNumberOfIterations( 
      static_cast<InputPixelType>( iterationsConfidenceValueInput->value() ) );
	  
	/*********** HARD VALUES FOR OUR CUSTOM REGION GROWING FILTER **************/
	m_CustomRegionGrowingImageFilter->SetMultiplier( static_cast<InputPixelType>( 2.5 ) );
	m_CustomRegionGrowingImageFilter->SetNumberOfIterations( static_cast<InputPixelType>( 2 ) );
	/***************************************************************************/
	
	m_VTKSegmentedImageViewer = VTKImageViewerType::New();
	m_VTKSegmentedImageViewer->SetImage( m_ConfidenceConnectedImageFilter->GetOutput() );
	
	// GUI Observers
	//inputImageButton->Observe( m_ImageReader.GetPointer() );
	inputImageButton->Observe( m_NullImageFilter.GetPointer() );
	homogeneousImageButton->Observe( m_NullImageFilter.GetPointer() );
	thresholdConnectedImageButton->Observe( m_ConnectedThresholdImageFilter.GetPointer() );
	confidenceConnectedImageButton->Observe( m_ConfidenceConnectedImageFilter.GetPointer() );
	
	
	//progressSlider->Observe( m_NullImageFilter.GetPointer() );
	//progressSlider->Observe( m_ConnectedThresholdImageFilter.GetPointer() );
	//progressSlider->Observe( m_ConfidenceConnectedImageFilter.GetPointer() );
	
}

/** Destructor */
RegionGrowing::~RegionGrowing() {}

/** show main console */
void RegionGrowing::ShowConsole( void )
{
	consoleWindow->show();
}

/** quit */
void RegionGrowing::Quit(void) 
{
	m_InputImageViewer.Hide();
	m_DicomImageViewer.Hide();
	m_ConnectedThresholdImageViewer.Hide();
	m_ConfidenceConnectedImageViewer.Hide();
	m_CustomRegionGrowingImageViewer.Hide();
	m_HomogeneousImageViewer.Hide();
	m_VTKSegmentedImageViewer->Hide();
	consoleWindow->hide();
}

/** save output image */
void RegionGrowing::WriteOutputImage( void )
{	
	const char * filename = fl_file_chooser("Output Image filename","*.*","");
	if( !filename )
	{
		return;
	}

	this->ShowStatus("Writing output image file...");
  
	try 
	{
		RegionGrowingBase::WriteOutputImage( filename );
	}
	catch( ... ) 
	{
		this->ShowStatus("Problems writing image");
		return;
	}

	this->ShowStatus("Output Image saved");
}

/** write confidence connected image */
void RegionGrowing::WriteConfidenceConnectedImage( void )
{
	m_ImageWriter->SetInput( m_ConfidenceConnectedImageFilter->GetOutput() );
	this->WriteOutputImage();
}

/** write connected threshold image */
void RegionGrowing::WriteConnectedThresholdImage( void )
{
	m_ImageWriter->SetInput( m_ConnectedThresholdImageFilter->GetOutput() );
	this->WriteOutputImage();
}

/** load input image */
void RegionGrowing::LoadInputImage( void )
{
	const char * filename = fl_file_chooser("Input Image filename","*.*","");
	if (!filename)
	{
		return;
	}
	
	this->ShowStatus("Loading input image file...");
	
	try
	{
		RegionGrowingBase::LoadInputImage( filename );
	}
	catch( ... )
	{
		this->ShowStatus("Problems reading file format");
		controlsGroup->deactivate();
		return;
	}
	
	this->ShowStatus("Input Image Loaded");
	
	controlsGroup->activate();
	
	InputImageType::RegionType region = m_ImageReader->GetOutput()->GetBufferedRegion();

	InputImageType::IndexType start = region.GetIndex();
	InputImageType::SizeType  size  = region.GetSize();
 
	/** x/y/zStartValueInput meant to come from GUI for region selection */
	/**
	xStartValueInput->value( start[0] );
	yStartValueInput->value( start[1] );
	zStartValueInput->value( start[2] );

	xEndValueInput->value( start[0]+size[0] );
	yEndValueInput->value( start[1]+size[1] );
	zEndValueInput->value( start[2]+size[2] );
	*/
	
	/** default region values, remove if region selected implemented */
	float_xStartValueInput = start[0];
    float_yStartValueInput = start[1];
	float_zStartValueInput = start[2];
	
	float_xEndValueInput =  start[0]+size[0];
	float_yEndValueInput =  start[0]+size[0];
	float_zEndValueInput =  start[0]+size[0];
	
	this->UpdateExtract();
}

/** load input image */
void RegionGrowing::LoadInputImageSeries( void )
{
	const  char * dirname = fl_dir_chooser("Choose DICOM image folder",0,0);
	
	try
	{
		RegionGrowingBase::LoadInputImageSeries( dirname );
	}
	catch( ... )
	{
		this->ShowStatus("Problems reading file format");
		controlsGroup->deactivate();
		return;
	}
	
	this->ShowStatus("Input Image Loaded");
	
	m_DicomReader->Update();
	
	controlsGroup->activate();
	
	InputImageType::RegionType region = m_DicomReader->GetOutput()->GetBufferedRegion();

	InputImageType::IndexType start = region.GetIndex();
	InputImageType::SizeType  size  = region.GetSize();
	
	float_xStartValueInput = start[0];
    float_yStartValueInput = start[1];
	float_zStartValueInput = start[2];
	
	float_xEndValueInput =  start[0]+size[0];
	float_yEndValueInput =  start[0]+size[0];
	float_zEndValueInput =  start[0]+size[0];
	
	this->UpdateExtract();
	
}

/** show status */
void RegionGrowing::ShowStatus( const char * message )
{
	//statusTextOutput->value( message );
	//Fl::check();
}

/** show input image */
void RegionGrowing::ShowInputImage( void )
{
	if( !m_InputImageIsLoaded )
    {
		return;
    }
	
	if (m_InputImageIsDICOM)
	{
		m_DicomToInternalImageTypeFilter->SetInput( m_DicomReader->GetOutput() );
		m_DicomToInternalImageTypeFilter->Update();
		m_HomogeneousImageViewer.SetImage( m_DicomToInternalImageTypeFilter->GetOutput() );		
		m_HomogeneousImageViewer.Show();	
		
		//m_DicomImageViewer.SetImage( m_DicomReader->GetOutput() );
		//m_DicomImageViewer.Show();
	} else {
		m_InputImageViewer.SetImage( m_ImageReader->GetOutput() );  
		m_InputImageViewer.Show();
	}
	
}

/***********************************************
	Window Call for Custom Region Growing Filter
***********************************************/

void RegionGrowing::ShowCustomRegionGrowingImage( void )
{
	m_CustomRegionGrowingImageFilter->Update();
	if (m_InputImageIsDICOM)
	{
		m_DicomToInternalImageTypeFilter->SetInput( m_DicomReader->GetOutput() );
		m_DicomToInternalImageTypeFilter->Update();
		m_CustomRegionGrowingImageViewer.SetImage( m_DicomToInternalImageTypeFilter->GetOutput() );
	} else {
		m_CustomRegionGrowingImageViewer.SetImage( m_ImageReader->GetOutput() );  
	} 
	m_CustomRegionGrowingImageViewer.SetOverlay( m_CustomRegionGrowingImageFilter->GetOutput() );
	m_CustomRegionGrowingImageViewer.Show();
}

/***********************************************/

/** show threshold connected image */
void RegionGrowing::ShowConnectedThresholdImage( void )
{
	m_ConnectedThresholdImageFilter->Update();
	if (m_InputImageIsDICOM)
	{
		m_DicomToInternalImageTypeFilter->SetInput( m_DicomReader->GetOutput() );
		m_DicomToInternalImageTypeFilter->Update();
		m_ConnectedThresholdImageViewer.SetImage( m_DicomToInternalImageTypeFilter->GetOutput() );
	} else {
		m_ConnectedThresholdImageViewer.SetImage( m_ImageReader->GetOutput() );  
	}
	
	m_ConnectedThresholdImageViewer.SetOverlay( m_ConnectedThresholdImageFilter->GetOutput() );
	m_ConnectedThresholdImageViewer.Show();
}

/** show confidence connected image */
void RegionGrowing::ShowConfidenceConnectedImage( void )
{
	m_ConfidenceConnectedImageFilter->Update();
	if (m_InputImageIsDICOM)
	{
		m_DicomToInternalImageTypeFilter->SetInput( m_DicomReader->GetOutput() );
		m_DicomToInternalImageTypeFilter->Update();
		m_ConfidenceConnectedImageViewer.SetImage( m_DicomToInternalImageTypeFilter->GetOutput() );
	} else {
		m_ConfidenceConnectedImageViewer.SetImage( m_ImageReader->GetOutput() );  
	} 
	m_ConfidenceConnectedImageViewer.SetOverlay( m_ConfidenceConnectedImageFilter->GetOutput() );
	m_ConfidenceConnectedImageViewer.Show();
}

/** show homogeneous image */
void RegionGrowing::ShowHomogeneousImage( void )
{
	m_NullImageFilter->Update();
	m_HomogeneousImageViewer.SetImage( m_NullImageFilter->GetOutput() );  
	m_HomogeneousImageViewer.Show();
}

/** show homogeneous image w/ vtk */
void RegionGrowing::ShowHomogeneousImageWithVTK( void )
{
	//m_VTKSegmentedImageViewer->SetColorLevel(127.5);
	//m_VTKSegmentedImageViewer->SetColorWindow(255); 
	m_VTKSegmentedImageViewer->Show();
}

/** INSERT OTHER FILTER METHODS HERE */

/** click select seed point callback */
void RegionGrowing::ClickSelectCallback(float x, float y, float z, float itkNotUsed(value), void * args)
{
	RegionGrowing * self = 
		static_cast<RegionGrowing *>( args );

	self->SelectSeedPoint( x, y, z );
}

/** select seed point callback */
void RegionGrowing::SelectSeedPoint(float x, float y, float z)
{
	xSeedPointValueOutput->value( x );
	ySeedPointValueOutput->value( y );
	zSeedPointValueOutput->value( z );

	typedef ConnectedThresholdImageFilterType::IndexType IndexType;
	IndexType seed;
	seed[0] = static_cast<IndexType::IndexValueType>( x );
	seed[1] = static_cast<IndexType::IndexValueType>( y );
	seed[2] = static_cast<IndexType::IndexValueType>( z );

	m_ConnectedThresholdImageFilter->SetSeed( seed );
	m_ConfidenceConnectedImageFilter->SetSeed( seed );
}

/** extract region */
void RegionGrowing::UpdateExtract()
{
	typedef InputImageType::IndexType IndexType;
	typedef InputImageType::SizeType  SizeType;

	IndexType start;
	SizeType  size;
 
	/** Code to facilitate region selection */
	/**
	start[0] = static_cast<IndexType::IndexValueType>( xStartValueInput->value() );
	start[1] = static_cast<IndexType::IndexValueType>( yStartValueInput->value() );
	start[2] = static_cast<IndexType::IndexValueType>( zStartValueInput->value() );

	size[0] = static_cast<SizeType::SizeValueType>( xEndValueInput->value() ) - start[0];
	size[1] = static_cast<SizeType::SizeValueType>( yEndValueInput->value() ) - start[1];
	size[2] = static_cast<SizeType::SizeValueType>( zEndValueInput->value() ) - start[2];
	*/
	
	/** default values, remove if region selection implemented in GUI */
	start[0] = static_cast<IndexType::IndexValueType>( float_xStartValueInput );
    start[1] = static_cast<IndexType::IndexValueType>( float_yStartValueInput );
	start[2] = static_cast<IndexType::IndexValueType>( float_zStartValueInput );InputImageType::RegionType region;
    
	size[0] = static_cast<SizeType::SizeValueType>( float_xEndValueInput ) - start[0];region.SetIndex( start );
	size[1] = static_cast<SizeType::SizeValueType>( float_yEndValueInput ) - start[1];region.SetSize( size );
    size[2] = static_cast<SizeType::SizeValueType>( float_zEndValueInput ) - start[2];
	m_ExtractImageFilter->SetExtractionRegion( region );
}

/** main */
int main()
{
	try 
	{
		RegionGrowing * console = new RegionGrowing();
		console->ShowConsole();
		Fl::run();
		delete console;
    }
	catch( itk::ExceptionObject & e )
    {
		std::cerr << "ITK exception caught in main" << std::endl;
		std::cerr << e << std::endl;
    }
	catch( std::exception & e )
    {
		std::cerr << "STD exception caught in main" << std::endl;
		std::cerr << e.what() << std::endl;
    }
	catch( ... )
    {
		std::cerr << "unknown exception caught in main" << std::endl;
    }


	return 0;
}