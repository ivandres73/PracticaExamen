cmake_minimum_required(VERSION 3.8)
project(PracticaExamen)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataFile.cpp DataFile.h Registro.cpp Registro.h Registro2.cpp Registro2.h Registro3.cpp Registro3.h)
add_executable(PracticaExamen ${SOURCE_FILES})