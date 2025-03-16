# CMakeLists.txt

cmake_minimum_required(VERSION 3.31)
message("Using CMake version ${CMAKE_VERSION}")

project(DataStructuresCpp VERSION 1.0.0)
message("  C: '${CMAKE_C_COMPILER}'")
message("  C++: '${CMAKE_CXX_COMPILER}'")
message("  Source: ${PROJECT_SOURCE_DIR}")
message("  Binary: ${PROJECT_BINARY_DIR}")
message("  Version (alt): ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

add_subdirectory(test)
add_subdirectory(chapter1)

message("Processing CMakeLists.txt")
