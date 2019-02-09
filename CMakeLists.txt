cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinaryTree.cpp BinaryTree.h AVLTree.cpp AVLTree.h TextAnalysis.cpp TextAnalysis.h testMain.cpp)
add_executable(untitled ${SOURCE_FILES})