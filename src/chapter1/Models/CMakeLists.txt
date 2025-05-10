add_library(Models IntCell.cpp Rectangle.cpp Matrix.cpp)


target_include_directories(Models
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )

add_subdirectory(Utils)

