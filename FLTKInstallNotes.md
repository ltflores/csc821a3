#FLTK installation notes

# Tutorial Pages #
Here's a link to the ITK tutorial page (contains pdfs for itk related tasks):
http://www.itk.org/ITK/help/tutorials.html

Here's the ITK+FLTK tutorial:
http://www.itk.org/CourseWare/Training/GettingStarted-IV.pdf

# FLTK Cmake compiler options #

When running the project through CMake, I find that the
following options must be set (I left my definitions for reference):

```
//ITK directory (folder with ITKConfig.cmake)
ITK_DIR:PATH=/home/ltflores/ITK-build/debug/

//Path to a library.
FLTK_BASE_LIBRARY:FILEPATH=/home/ltflores/FLTK-build/lib/libfltk.a

//Path to a program.
FLTK_CONFIG_SCRIPT:FILEPATH=/home/ltflores/FLTK-build/fltk-config

//The directory containing FLTKConfig.cmake.  This is either the
// root of the build tree, or PREFIX/lib/fltk for an installation.
FLTK_DIR:PATH=/home/ltflores/FLTK-build/

//Path to a program.
FLTK_FLUID_EXECUTABLE:FILEPATH=/home/ltflores/FLTK-build/bin/fluid

//Path to a library.
FLTK_FORMS_LIBRARY:FILEPATH=/home/ltflores/FLTK-build/lib/libfltk_forms.a

//Path to a library.
FLTK_GL_LIBRARY:FILEPATH=/home/ltflores/FLTK-build/lib/libfltk_gl.a

//Path to a library.
FLTK_IMAGES_LIBRARY:FILEPATH=/home/ltflores/FLTK-build/lib/libfltk_images.a

//Path to a file. (path to original source, if not set you won't see
errors till you try importing into eclipse)
FLTK_INCLUDE_DIR:PATH=/home/ltflores/Downloads/fltk-1.3.x-r8441
```
