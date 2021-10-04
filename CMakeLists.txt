cmake_minimum_required(VERSION 3.15)

set(project_name PP-CNN)
project(${project_name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SEAL 3.6 REQUIRED)
find_package(OpenMP REQUIRED)
find_package(HDF5 REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}/ppcnn
  ${PROJECT_SOURCE_DIR}/stdsc
  ${SEAL_INCLUDE_DIR}
  PRIVATE ${HDF5_INCLUDE_DIRS})

set(COMMON_LIBS
  stdsc
  ppcnn_share
  SEAL::seal
  ${HDF5_LIBRARIES}
  hdf5
  hdf5_cpp)

add_subdirectory(stdsc)
add_subdirectory(ppcnn)
add_subdirectory(demo)
