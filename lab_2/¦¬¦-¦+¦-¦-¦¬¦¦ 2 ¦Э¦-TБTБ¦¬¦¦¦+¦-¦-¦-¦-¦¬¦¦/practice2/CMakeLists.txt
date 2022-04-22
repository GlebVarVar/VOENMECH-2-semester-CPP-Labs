cmake_minimum_required(VERSION 3.20)
project(practice2)

set(CMAKE_CXX_STANDARD 14)

add_executable(practice2 main.cpp String.cpp String.h IdentifiedString.cpp IdentifiedString.h HexString.cpp HexString.h)
