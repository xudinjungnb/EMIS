cmake_minimum_required(VERSION 3.0)
project(EMIS)
# set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib)
# link_directories(${LINK_DIR})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(emis ${SRC_LIST})
# target_link_libraries(emis libNetSocket)
