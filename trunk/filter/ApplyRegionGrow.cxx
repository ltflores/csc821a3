#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif
 
#ifdef __BORLANDC__
#define ITK_LEAN_AND_MEAN
#endif
    	
#include <itksys/SystemTools.hxx>
#include "itkImage.h"
#include "itkImageSeriesWriter.h"
#include "itkNumericSeriesFileNames.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkGDCMImageIO.h"
#include "itkCustomRegionGrowingImageFilter.h" //custom filter
#include "DICOMFileReader.h"

 

int main( int argc, char * argv[] )
{
	if ( argc < 3 ) 
	{ 
		std::cerr << "Usage: " << std::endl;
		std::cerr << argv[0] << "  inputDicomDirectory  outputDicomDirectory ";
		std::cerr <<  std::endl;
		return EXIT_FAILURE;
	}
 
	/***************************************************************
	 *	Typedefs
	 **************************************************************/
  
	//Image typedefs
	const int dimension = 3;
	const int outDimension = 2;
	
	typedef signed short PixelType;
	typedef itk::Image< PixelType, dimension > ImageType;
	typedef itk::Image< PixelType, outDimension > Image2DType;
	
	//Series Writer
	typedef itk::GDCMImageIO
		ImageIOType;
		
	typedef itk::GDCMSeriesFileNames
		OutputNamesGeneratorType;
	
	typedef itk::ImageSeriesWriter< ImageType, Image2DType >
		SeriesWriterType;
 
	//Filters
	typedef itk::CustomRegionGrowingImageFilter<ImageType,ImageType> 
		CustomRegionGrowingImageFilterType;
		
	typedef CustomRegionGrowingImageFilterType::IndexType
		IndexType;
 
	/***************************************************************
	 *	Object Definitions
	 **************************************************************/
	std::cout << "Object definitions...";
	//DICOM Reader, no need for typedef, already in DICOMFileReader.cxx
	DICOMFileReader::Pointer					m_DicomReader;
	
	//File Writer
	OutputNamesGeneratorType::Pointer 			m_OutputNamesGenerator;
	ImageIOType::Pointer 						m_ImageIO;
	SeriesWriterType::Pointer						m_SeriesWriter;
	
	//Filter 
	IndexType 									seed;
	CustomRegionGrowingImageFilterType::Pointer m_CustomRegionGrowingImageFilter;
	
	std::cout << "Done!\n";
	/***************************************************************
	 *	Initilize Objects
	 **************************************************************/
	std::cout << "Initializing objects...";
	//DICOM Reader
	m_DicomReader = DICOMFileReader::New();
	
	//Writer
	m_SeriesWriter = SeriesWriterType::New();
	m_ImageIO = ImageIOType::New();
	m_OutputNamesGenerator = OutputNamesGeneratorType::New();
	
	//Filter
	m_CustomRegionGrowingImageFilter = CustomRegionGrowingImageFilterType::New();
	
	std::cout << "Done!\n";
	/***************************************************************
	 *	Define Seed Coordinates
	 **************************************************************/
	seed[0] = static_cast<IndexType::IndexValueType>( 149.50 ); //x
	seed[1] = static_cast<IndexType::IndexValueType>( 245.76 ); //y
	seed[2] = static_cast<IndexType::IndexValueType>( 38.00 );		//z
	
	
	/***************************************************************
	 *	Read DICOM Series
	 **************************************************************/
	m_DicomReader->SetDirectoryName( argv[1] );
	m_DicomReader->Update();
	
	
	/***************************************************************
	 *	Apply Filter
	 **************************************************************/
	std::cout << "Applying filter...\n";
	
	std::cout << "Setting Seed...\n";
	m_CustomRegionGrowingImageFilter->SetSeed( seed );
	std::cout << "Seed set!\n";
	std::cout << "Setting multiplier and iterations...\n";
	m_CustomRegionGrowingImageFilter->SetMultiplier( static_cast<PixelType>( 2.5 ) );
	m_CustomRegionGrowingImageFilter->SetNumberOfIterations( static_cast<PixelType>( 2 ) );
	std::cout << "Multiplier and iterations set!\n";
	std::cout << "Setting input...\n";
	m_CustomRegionGrowingImageFilter->SetInput( m_DicomReader->GetOutput() );
	std::cout << "Input Set!\n";
	std::cout << "Updating filter...\n";
	m_CustomRegionGrowingImageFilter->Update();
	std::cout << "Filter updated!\n";
	
	std::cout << "Filter applied!\n";
	 
	 
	/***************************************************************
	 *	Write Series
	 **************************************************************/
	const char * outputDirectory = argv[2];
	std::string outDir = argv[2];
	itksys::SystemTools::MakeDirectory( outputDirectory );
	std::cout << "Writing series...\n";
	m_SeriesWriter->SetInput( m_CustomRegionGrowingImageFilter->GetOutput() );
	m_SeriesWriter->SetImageIO( m_ImageIO );
	
	//Set up OutputNames Writer
	m_OutputNamesGenerator->SetInputDirectory( argv[1] );
	m_OutputNamesGenerator->SetOutputDirectory( outDir );
	m_SeriesWriter->SetFileNames( m_OutputNamesGenerator->GetOutputFileNames() );
	m_SeriesWriter->SetMetaDataDictionaryArray( m_DicomReader->GetMetaDataDictionaryArray() );
	try
    {
		m_SeriesWriter->Update();
	}
	catch( itk::ExceptionObject & excp )
    {
		std::cerr << "Exception thrown while writing the series " << std::endl;
		std::cerr << excp << std::endl;
		return EXIT_FAILURE;
    }
	std::cout << "Series written!\n";

}