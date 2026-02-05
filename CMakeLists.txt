cmake_minimum_required(VERSION 3.16)

project(operations_lib VERSION 1.0.0 LANGUAGES C CXX)

add_library(operations_lib STATIC
    src/operations.cpp
)

target_include_directories(operations_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(operations_lib PUBLIC cxx_std_17)

install(TARGETS operations_lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
)
