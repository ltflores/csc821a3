PROJECT(ApplyMaskImageTest)

# Find ITK.
FIND_PACKAGE(ITK REQUIRED)
IF(ITK_FOUND)
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

ADD_EXECUTABLE(ApplyMaskImageTest
               ApplyMaskImageTest.cxx )

TARGET_LINK_LIBRARIES(ApplyMaskImageTest
                      ITKCommon 
                      ITKBasicFilters
                      ITKIO)

ADD_EXECUTABLE(ApplyMaskImage
               ApplyMaskImage.cxx )

TARGET_LINK_LIBRARIES(ApplyMaskImage
                      ITKCommon 
                      ITKBasicFilters
                      ITKIO)


# Configure Dart testing support.  This should be done before any
# MESSAGE(FATAL_ERROR ...) commands are invoked.
INCLUDE(${CMAKE_ROOT}/Modules/Dart.cmake)
ENABLE_TESTING()
ADD_TEST(ApplyMaskImageTest_Test1 
        ${CXX_TEST_PATH}/ApplyMaskImageTest
              ${ApplyMaskImageTest_SOURCE_DIR}/Data/cthead1.jpg
              ${ApplyMaskImageTest_SOURCE_DIR}/Data/ctheadmask.jpg 
              0 test1.jpg)
ADD_TEST(ApplyMaskImageTest_Test2 
        ${CXX_TEST_PATH}/ApplyMaskImageTest 
              ${ApplyMaskImageTest_SOURCE_DIR}/Data/cthead1.jpg 
              ${ApplyMaskImageTest_SOURCE_DIR}/Data/ctheadmask.jpg 
              1 test2.jpg)
 

# Dashboard is opened for submissions for a 24 hour period starting at
# the specified NIGHLY_START_TIME. Time is specified in 24 hour format.
SET (NIGHTLY_START_TIME "1:00:00 EDT")

# Dart server to submit results (used by client)
SET (SITE "hjohnson")
#SET (BUILDNAME "NewTest")

# Dart server to submit results (used by client)
SET (DROP_METHOD "xmlrpc")
SET (DROP_SITE "testing.psychiatry.uiowa.edu:8081")
SET (DROP_LOCATION "ITKShortCourse")