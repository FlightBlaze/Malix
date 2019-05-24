cmake_minimum_required(VERSION 3.8)
project(malix CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCLUDES ${PROJECT_SOURCE_DIR}/src/*.h*)

if(MALIX_LIBRARY)
    add_library(malix SHARED ${INCLUDES} ${SOURCES} src/lib/functions/Functions)
else()
    add_executable(malix ${INCLUDES} ${SOURCES} src/lib/functions/Functions)
endif()

target_link_libraries(malix ${CMAKE_DL_LIBS})


if(MALIX_LIBRARY)
    INSTALL (
            DIRECTORY ${CMAKE_SOURCE_DIR}/src/
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include
            FILES_MATCHING PATTERN "*.h*")
endif()