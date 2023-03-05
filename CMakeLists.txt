cmake_minimum_required(VERSION 2.8.3)
project(using_cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/tools)

find_package(IMP REQUIRED)
include(${IMP_USE_FILE})

include_directories(SYSTEM ${IMP_INCLUDE_DIR})
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})
include_directories(SYSTEM ${Boost_INCLUDE_DIR})

add_executable(simple simple.cpp)
target_link_libraries(simple ${IMP_kernel_LIBRARY} ${IMP_core_LIBRARY} ${IMP_score_functor_LIBRARY})
