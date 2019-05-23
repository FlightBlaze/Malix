cmake_minimum_required(VERSION 3.14)
project(malix)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.h)

add_executable(malix ${SOURCE} src/lib/functions/Functions)