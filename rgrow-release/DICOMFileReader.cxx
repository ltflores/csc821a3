#include "DICOMFileReader.h"
#include "itkImageToImageFilter.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"

DICOMFileReader::DICOMFileReader(std::string dirname)
{
	m_dirname = dirname;
}

DICOMFileReader::DICOMFileReader()
{
}

DICOMFileReader::~DICOMFileReader(void)
{
}


void DICOMFileReader::SetDirectoryName(std::string dirname)
{
	m_dirname = dirname;
}

const itk::Image<signed short, 3> * DICOMFileReader::GetOutput() 
{
	return itk::ImageSeriesReader<itk::Image<signed short, 3>>::GetOutput();
}

void DICOMFileReader::Update()
{

	typedef itk::GDCMImageIO       ImageIOType;
	ImageIOType::Pointer dicomIO = ImageIOType::New();

  	this->SetImageIO( dicomIO );

	typedef itk::GDCMSeriesFileNames NamesGeneratorType;
	NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();

	nameGenerator->SetUseSeriesDetails( true );
	nameGenerator->AddSeriesRestriction("0008|0021" );

	nameGenerator->SetDirectory( m_dirname );
	


	try
	{
		std::cout << std::endl << "The directory: " << std::endl;
		std::cout << std::endl << m_dirname << std::endl << std::endl;
		std::cout << "Contains the following DICOM Series: ";
		std::cout << std::endl << std::endl;
		typedef std::vector< std::string >    SeriesIdContainer;
		SeriesIdContainer seriesUID;
		typedef std::vector< std::string >   FileNamesContainer;
		FileNamesContainer fileNames;

		seriesUID = nameGenerator->GetSeriesUIDs();
    
		SeriesIdContainer::const_iterator seriesItr = seriesUID.begin();
		SeriesIdContainer::const_iterator seriesEnd = seriesUID.end();
		while( seriesItr != seriesEnd )
		{
			std::cout << seriesItr->c_str() << std::endl;
			seriesItr++;
		}
		std::string seriesIdentifier;
		seriesIdentifier = seriesUID.begin()->c_str();
		std::cout << std::endl << std::endl;
		std::cout << "Now reading series: " << std::endl << std::endl;
		std::cout << seriesIdentifier << std::endl;
		std::cout << std::endl << std::endl;

		fileNames = nameGenerator->GetFileNames( seriesIdentifier );
		this->SetFileNames( fileNames );
		try
		{
			// call inherited Update to call all the ancestor class reading code
			itk::ImageSeriesReader<itk::Image<signed short, 3>>::Update();
		
		}
		catch (itk::ExceptionObject &ex)
		{
			std::cout << ex << std::endl;
		}
	}
	catch (itk::ExceptionObject &ex)
    {
		std::cout << ex << std::endl;
    }
	//return ;
}