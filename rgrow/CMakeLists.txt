cmake_minimum_required(VERSION 2.8)

PROJECT( RegionGrowing )

FIND_PACKAGE(ITK)
IF(ITK_FOUND)
	INCLUDE(${ITK_USE_FILE})
ELSE(ITK_FOUND)
	MESSAGE(FATAL_ERROR
        "Cannot build RegionGrowing program without ITK.  Please set ITK_DIR.")
ENDIF(ITK_FOUND)

FIND_PACKAGE(FLTK)
IF(FLTK_FOUND)
	INCLUDE_DIRECTORIES(${FLTK_INCLUDE_DIR})
ENDIF(FLTK_FOUND)

FIND_PACKAGE(VTK)
IF (VTK_FOUND)
	INCLUDE (${VTK_USE_FILE})
ENDIF (VTK_FOUND)

SET(InsightApplications_SOURCE_DIR "C:/Users/ltflores/Documents/CSC821/InsightApplications-3.20.0")
SET(InsightApplications_BINARY_DIR "C:/Users/ltflores/Documents/CSC821/InsightApplications-3.20.0/build")

INCLUDE_DIRECTORIES(
${InsightApplications_SOURCE_DIR}/Auxiliary/FltkImageViewer/
${InsightApplications_SOURCE_DIR}/Auxiliary/VtkFltk/
${InsightApplications_SOURCE_DIR}/Auxiliary/vtk/
${InsightApplications_BINARY_DIR}/Auxiliary/FltkImageViewer/Debug
${InsightApplications_BINARY_DIR}/Auxiliary/VtkFltk/Debug
${RegionGrowing_SOURCE_DIR}/includes
${RegionGrowing_SOURCE_DIR}
${RegionGrowing_BINARY_DIR}
)

LINK_DIRECTORIES(
${InsightApplications_BINARY_DIR}/Auxiliary/FltkImageViewer/Debug
${InsightApplications_BINARY_DIR}/Auxiliary/VtkFltk/Debug
${RegionGrowing_BINARY_DIR}
)

#Generates GUI .h and .cxx files
FLTK_WRAP_UI( RegionGrowing   RegionGrowingGUI.fl)

SET(RegionGrowing_SRCS
RegionGrowing.cxx
RegionGrowing.h
RegionGrowingBase.cxx
RegionGrowingBase.h
DICOMFileReader.cxx
DICOMFileReader.h
${RegionGrowing_FLTK_UI_SRCS}
)

ADD_EXECUTABLE(RegionGrowing ${RegionGrowing_SRCS})
TARGET_LINK_LIBRARIES (RegionGrowing
ITKCommon
ITKNumerics
ITKBasicFilters
ITKIO
ITKFltkImageViewer
ITKVtkFltk
vtkRendering
vtkVolumeRendering 
vtkGraphics
vtkHybrid
vtkImaging
vtkIO
vtkFiltering
vtkCommon
${FLTK_LIBRARIES} 
)

IF(CMAKE_COMPILER_IS_GNUCXX)
  SET_SOURCE_FILES_PROPERTIES (RegionGrowing.cxx PROPERTIES COMPILE_FLAGS -Wno-cast-qual)
ENDIF(CMAKE_COMPILER_IS_GNUCXX)