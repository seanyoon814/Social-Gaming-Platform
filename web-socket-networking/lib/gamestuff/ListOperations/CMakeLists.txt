#cmake_minimum_required(VERSION 3.10)
#project(ListOps)
#set(CMAX_CXX_STANDARD 17)

add_library(ListOperations)
target_sources(ListOperations
    PRIVATE
        ListOps.cpp
)
target_include_directories(ListOperations
        PUBLIC
        /include)

set_target_properties(ListOperations PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)

add_subdirectory(test)