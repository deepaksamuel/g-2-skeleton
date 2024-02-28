# create a cmake file for compiling readfile.cpp with ROOT
# NVCCOPTIONS=--gpu-architecture sm_60
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


project(g-2-skeleton)
# include ( FindCUDAToolkit )
# find_package(Threads REQUIRED)
find_package(ROOT 6.26 REQUIRED)

if (NOT ROOT_FOUND)
    message(FATAL_ERROR "ROOT not found")
else()
    message(STATUS "ROOT version found: ${ROOT_VERSION}")
endif()

message(STATUS "ROOT include dir: ${ROOT_INCLUDE_DIRS}")
message(STATUS "CUDA include dir: ${CUDAToolkit_INCLUDE_DIRS}")
# file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/analysis" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )
include_directories("${ROOT_INCLUDE_DIRS}")
include_directories("g2esoft-root-libs/include")

add_subdirectory(g2esoft-root-libs)
add_executable(g-2-skeleton main.cpp)

target_link_libraries(g-2-skeleton  g2esoftCommon ${ROOT_LIBRARIES})