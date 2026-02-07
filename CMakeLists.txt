cmake_minimum_required(VERSION 3.10.0)
project(raylib-template VERSION 0.1.0 LANGUAGES C CXX)

if (EMSCRIPTEN)
    set(PLATFORM Web CACHE STRING "" FORCE)
endif()
add_subdirectory(external/raylib)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if (EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME "index"
        SUFFIX ".html"
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        "-sUSE_GLFW=3"
        "-sASYNCIFY"
    )
endif()
