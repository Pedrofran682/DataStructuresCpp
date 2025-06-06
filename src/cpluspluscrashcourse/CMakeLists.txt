cmake_minimum_required(VERSION 3.31)
message("Using CMake version ${CMAKE_VERSION}")

project(DataStructuresCpp VERSION 1.0.0)
message("  C: '${CMAKE_C_COMPILER}'")
message("  C++: '${CMAKE_CXX_COMPILER}'")
message("  Source: ${PROJECT_SOURCE_DIR}")
message("  Binary: ${PROJECT_BINARY_DIR}")
message("  Version (alt): ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

add_executable(cpluspluscrashcourse main.cpp)

add_subdirectory("chapter2")

target_link_libraries(cpluspluscrashcourse PUBLIC chapter2)

target_include_directories(cpluspluscrashcourse PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

