cmake_minimum_required(VERSION 3.10)
project(ListOpsLib)
set(CMAX_CXX_STANDARD 17)

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
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)

target_link_libraries(ListOperations PUBLIC Data)
#include_directories(Data PUBLIC include)

add_subdirectory(test)