project(DataLib)
cmake_minimum_required(VERSION 3.10)
add_library(Data)

target_sources(Data
        PRIVATE
        Data.cpp
        DataType.cpp
        )
target_include_directories(Data
        PUBLIC
        include
)


set_target_properties(Data PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )
