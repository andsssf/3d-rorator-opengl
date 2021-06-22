cmake_minimum_required(VERSION 3.0.0)
project(3DRotator VERSION 0.1.0)

include_directories(include src)
link_directories(lib)
link_libraries("libfreeglut.a" "glew32s.lib" "opengl32.lib" "glu32.lib")

aux_source_directory(src SOURCE_LIST)
aux_source_directory(src/Rotator SOURCE_LIST)


add_executable(3DRotator "${SOURCE_LIST}")

