#cmake_minimum_required(VERSION 3.10)
#project(ForEach-When-Messages-Test)
#
#set(CMAX_CXX_STANDARD 17)
#
#add_library(vineshTest)
#target_sources(vineshTest
#  PRIVATE
#    src/Foreach.cpp
#    src/when.cpp
#    src/Rules.cpp
#    src/Messages.cpp
#    src/PerPlayer.cpp
#
#)
#target_include_directories(vineshTest
#  PUBLIC
#    include/
#
#)
#set_target_properties(vineshTest PROPERTIES
#  LINKER_LANGUAGE CXX
#  CXX_STANDARD 17
#)
#
#add_subdirectory(src/tempTesting)


#CMAKE FOR DATA/LISTOPS
cmake_minimum_required(VERSION 3.10)
project(Data_ListOps)
set(CMAX_CXX_STANDARD 17)


add_subdirectory(Data)
add_subdirectory(ListOperations)

