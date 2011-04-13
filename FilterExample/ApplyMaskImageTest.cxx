#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif
 
#ifdef __BORLANDC__
#define ITK_LEAN_AND_MEAN
#endif
    
 
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkApplyMaskImageFilter.h"
 

int main( int argc, char * argv[] )
{
 if ( argc < 5 ) 
   { 
   std::cerr << "Usage: " << std::endl;
   std::cerr << argv[0] << "  inputImageFile  inputMaskFile ";  
   std::cerr << "Invert OutputImageFile";
   std::cerr <<  std::endl;
   return EXIT_FAILURE;
   }
 
 
 const int dimension = 2;
 typedef    unsigned char InputPixelType;
 typedef    unsigned char OutputPixelType;
  
 typedef itk::Image< InputPixelType,  dimension >   InputImageType;
 typedef itk::Image< OutputPixelType, dimension  >   OutputImageType;
 


 typedef itk::ImageFileReader< InputImageType >  ReaderType;

 typedef itk::ApplyMaskImageFilter<
                     InputImageType, OutputImageType >  FilterType;


 ReaderType::Pointer imageReader = ReaderType::New();
 imageReader->SetFileName( argv[1] );
 imageReader->Update( );


 ReaderType::Pointer maskReader = ReaderType::New();
 maskReader->SetFileName( argv[2] );
 maskReader->Update( );


 FilterType::Pointer maskFilter= FilterType::New();
 maskFilter->SetInput( imageReader->GetOutput () );
 maskFilter->SetMaskImage( maskReader->GetOutput () );
 maskFilter->SetInvertMask( static_cast<bool>( atoi( argv[3] ) ) );
 maskFilter->Update();


 typedef itk::ImageFileWriter< InputImageType >  WriterType;
 WriterType::Pointer imageWriter = WriterType::New();
 imageWriter->SetFileName( argv[4] );
 imageWriter->SetInput( maskFilter->GetOutput() );
 imageWriter->Update();


}