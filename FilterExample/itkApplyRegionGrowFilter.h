#ifndef __itkApplyMaskImageFilter_h
#define __itkApplyMaskImageFilter_h
 
#include <itkImageToImageFilter.h>
 
namespace itk
{

 
template <class TInputImage, class TOutputImage>
class ITK_EXPORT ApplyMaskImageFilter:
   public ImageToImageFilter<TInputImage,TOutputImage>
{
public:     /* Define methods available to everyone */

 /** Standard class typedefs. */
 typedef ApplyMaskImageFilter    Self;
 typedef ImageToImageFilter<TInputImage,TOutputImage>  Superclass;
 typedef SmartPointer<Self>  Pointer;
 typedef SmartPointer<const Self>  ConstPointer;

 /** Method for creation through the object factory. */
 itkNewMacro(Self);  

 /** Run-time type information (and related methods). */
 itkTypeMacro(ApplyMaskImageFilter, ImageToImageFilter);

 /** ImageDimension enumeration. */
 itkStaticConstMacro(ImageDimension, unsigned int,
                     TInputImage::ImageDimension);
 itkStaticConstMacro(OutputImageDimension, unsigned int,
                     TOutputImage::ImageDimension);

 /** Typedef to describe the output image region type. */
 typedef typename TOutputImage::RegionType OutputImageRegionType;

 /** Inherited typedefs. */
 typedef typename Superclass::InputImageType InputImageType;
 typedef typename Superclass::InputImagePointer InputImagePointer;
 typedef typename Superclass::InputImageConstPointer InputImageConstPointer;
 typedef typename Superclass::OutputImageType OutputImageType;
 typedef typename Superclass::OutputImagePointer OutputImagePointer;
  
 /** Pixel related typedefs. */
 typedef typename InputImageType::PixelType InputPixelType;
 typedef typename OutputImageType::PixelType OutputPixelType;
 
 /** Set/Get the mask to be applied to the image. */
 void SetMaskImage( const InputImageType * reference );
 const InputImageType * GetMaskImage(void);
 
 /** Set/Get Macro */
 itkSetMacro(InvertMask, bool);
 itkGetMacro(InvertMask, bool);

 
protected:  /* Define methods available only to related classes */

 /** Constructor / Destructor */
 ApplyMaskImageFilter();
 ~ApplyMaskImageFilter() {}
 void PrintSelf(std::ostream& os, Indent indent) const;
 
 /** Generate Data */
 void GenerateData( );

 
private:   /* Define methods available only to this class */

 /** variables */
 bool m_InvertMask;

 ApplyMaskImageFilter(const Self&); //purposely not implemented
 void operator=(const Self&); //purposely not implemented

};

  
} // end namespace itk
  
#ifndef ITK_MANUAL_INSTANTIATION
#include "itkApplyMaskImageFilter.txx"
#endif
 
#endif
