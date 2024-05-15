cmake_minimum_required(VERSION 3.22)
project(equalizer)
set(CMAKE_CXX_STANDARD 20)


set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
include(cmake/get_cpm.cmake)


CPMAddPackage(NAME JUCE
  GITHUB_REPOSITORY juce-framework/JUCE
  GIT_TAG 7.0.12
  VERSION 7.0.12
  SOURCE_DIR "${LIB_DIR}/juce"
  OPTIONS
    "JUCE_BUILD_EXAMPLES OFF"
)


if(MSVC)
  add_compile_options(/Wall /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(equalizer)