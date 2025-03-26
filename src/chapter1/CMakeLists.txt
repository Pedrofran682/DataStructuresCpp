add_library(chapter1 main.cpp)


target_include_directories(chapter1
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )

add_subdirectory(Models)

target_link_libraries(chapter1 PUBLIC Models)


