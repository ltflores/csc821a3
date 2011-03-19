#include "myProjectGUI.h"
#include "itkImageFileReader.h"
#include "itkImage.h"
#include "itkCurvatureFlowImageFilter.h"

int main(int argc, char ** argv)
{
	typedef itk::Image<float, 2>			ImageType;
	typedef itk::ImageFileReader<ImageType> ReaderType;
	typedef itk::CurvatureFlowImageFilter<ImageType, ImageType> SmootherFilterType;
	
	ReaderType::Pointer reader = ReaderType::New();
	SmootherFilterType::Pointer smoother = SmootherFilterType::New();
	
	reader->SetFileName( argv[1]);
	
	smoother->SetInput( reader->GetOutput() );
	smoother->SetNumberOfIterations(7);
	smoother->SetTimeStep( 0.5 );
	
	myProjectGUI gui;
	gui.Show();
	
	Fl::run();
	
	return 0;
}
	