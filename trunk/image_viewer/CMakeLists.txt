PROJECT(myITKgui)

# All the Mac Specific Stuff
IF(APPLE)
  SET(MYITKGUI_REQUIRED_CXX_FLAGS "${MYITKGUI_REQUIRED_CXX_FLAGS}")
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flat_namespace -framework Carbon -framework Cocoa -noprebind")
ENDIF(APPLE)

# Look for FLTK 
INCLUDE (${CMAKE_ROOT}/Modules/FindFLTK.cmake)  
# and ITK 
INCLUDE (${CMAKE_ROOT}/Modules/FindITK.cmake) 
IF (USE_ITK_FILE)   
  INCLUDE(${USE_ITK_FILE}) 
ENDIF(USE_ITK_FILE)  
# We need VTK to build this... 
INCLUDE (${CMAKE_ROOT}/Modules/FindVTK.cmake) 
IF (USE_VTK_FILE)   
  INCLUDE(${USE_VTK_FILE}) 
ENDIF(USE_VTK_FILE)  
# ... and finally GL 
INCLUDE (${CMAKE_ROOT}/Modules/FindOpenGL.cmake) 
INCLUDE (${CMAKE_ROOT}/Modules/FindGLU.cmake)  
INCLUDE_DIRECTORIES( ${myITKgui_SOURCE_DIR} ${FLTK_INCLUDE_PATH} )  

LINK_LIBRARIES(

  # FLTK libraries
  ${FLTK_BASE_LIBRARY}
  ${FLTK_GL_LIBRARY} 
  ${FLTK_FORMS_LIBRARY}
  ${FLTK_IMAGES_LIBRARY}
  ${FLTK_PLATFORM_DEPENDENT_LIBS}

  # OpenGL stuff that CMake finds
  ${OPENGL_LIBRARY}
  ${GLU_LIBRARY}
  
  ITKBasicFilters
  ITKCommon
  ITKIO
  ITKNumerics
  ITKMetaIO

  vtkRendering
  vtkGraphics
  vtkHybrid
  vtkImaging
  vtkIO
  vtkFiltering
  vtkCommon
  vtkWidgets )  

SET(
    myITKgui_VTK_SRCS     
    vtkFlRenderWindowInteractor  )  

SET(
    myITKgui_App_SRCS
    imViewBase
    imViewGUI
    imView     
    imViewWindowBase     
    imViewWindowGUI     
    imViewWindow  )  

ADD_EXECUTABLE(
    myITKgui
    MACOSX_BUNDLE
    main                
    ${myITKgui_VTK_SRCS}                
    ${myITKgui_App_SRCS}  )

#IF(APPLE)
#  FIND_PROGRAM(MYITKGUI_APPLE_RESOURCE Rez /Developer/Tools)
#
#  IF(MYITKGUI_BINARY_DIR)
#	SET(DUMMY NOTHING)
#  ELSE(MYITKGUI_BINARY_DIR)
#    SET(MYITKGUI_BINARY_DIR .)
#  ENDIF(MYITKGUI_BINARY_DIR)
#	
#  ADD_CUSTOM_COMMAND(
#	SOURCE myITKgui
#	COMMAND ${MYITKGUI_APPLE_RESOURCE}
#	ARGS Carbon.r -o ${MYITKGUI_BINARY_DIR}/myITKgui
#	TARGET myITKgui
#	)
#ENDIF(APPLE)

# Final tag for using the Apple stuff
#SET(MYITKGUI_USE_CARBON "@MYITKGUI_USE_CARBON@")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MYITKGUI_REQUIRED_CXX_FLAGS}") 
