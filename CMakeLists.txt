cmake_minimum_required(VERSION 3.9)
project(malix CXX)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DMALIX_VERSION="0.0.1 -pthread")

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCLUDES ${PROJECT_SOURCE_DIR}/src/*.h*)

find_package(Boost COMPONENTS program_options filesystem thread REQUIRED)

if(MALIX_LIBRARY)
    add_library(malix SHARED ${INCLUDES} ${SOURCES})
else()
    add_executable(malix ${INCLUDES} ${SOURCES})
endif()

include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(malix ${CMAKE_DL_LIBS} ${Boost_LIBRARIES} stdc++fs)

if(MALIX_LIBRARY)
    INSTALL (
            DIRECTORY ${CMAKE_SOURCE_DIR}/src/
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include
            FILES_MATCHING PATTERN "*.h*")
endif()