#pragma once
#include "itkImage.h"
#include "itkImageSeriesReader.h"
#include "itkProcessObject.h"

class DICOMFileReader : public itk::ImageSeriesReader<typename itk::Image<signed short,3>>
{
public:

	/** Standard class typedefs. */
	typedef DICOMFileReader          Self;
	typedef itk::ImageSource<typename itk::Image<signed short,3>>  Superclass;
	typedef itk::SmartPointer<Self>         Pointer;
  
	/** Method for creation through the object factory. */
	itkNewMacro(Self);

	/** Run-time type information (and related methods). */
	itkTypeMacro(ImageSeriesReader, ImageSource);
	//typedef TDICOMImage DicomImageType;

	DICOMFileReader();
	DICOMFileReader(std::string dirname);
	~DICOMFileReader();
	void SetDirectoryName(std::string dirname);
	//override the base class output
	void Update();
	const itk::Image<signed short, 3> * GetOutput();

private:

	std::string m_dirname;
	
};