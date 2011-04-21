cmake_minimum_required(VERSION 2.8)

PROJECT(ApplyRegionGrow)

# Find ITK.
FIND_PACKAGE(ITK REQUIRED)
IF(ITK_FOUND)
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

SET(ApplyRegionGrow_SRCS
ApplyRegionGrow.cxx
DICOMFileReader.cxx
DICOMFileReader.h
)

ADD_EXECUTABLE(ApplyRegionGrow ${ApplyRegionGrow_SRCS} )

TARGET_LINK_LIBRARIES(ApplyRegionGrow
ITKCommon 
ITKBasicFilters
ITKIO
)