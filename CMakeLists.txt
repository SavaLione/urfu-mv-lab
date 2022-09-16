#################################################################################
# Copyright (c) 2022, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# Project Lyssa
set(LYSSA_PROJECT "lyssa")
set(LYSSA_PROJECT_VERSION "0.0.1")

project(${LYSSA_PROJECT}
    VERSION ${LYSSA_PROJECT_VERSION}
    LANGUAGES CXX
)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")               # default
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")           # debug

#################################################################################
#                               Macros and functions                            #
#################################################################################
# Output directory
function(function_output_directory arg_project)
    set_target_properties(${arg_project}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endfunction(function_output_directory)

#################################################################################
#                                    Libraries                                  #
#################################################################################
# OpenGL
find_package(OpenGL REQUIRED)

# OpenCV
find_package(OpenCV REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

set(GLFW_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/glfw/include" CACHE PATH "GLFW lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)

# imgui
set(IMGUI_BUILD_BACKEND_OPENGL3 ON CACHE BOOL "" FORCE)
set(IMGUI_BUILD_BACKEND_GLFW ON CACHE BOOL "" FORCE)

set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/imgui/include" CACHE PATH "imgui lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/imgui)

# spdlog
set(SPDLOG_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/spdlog/include" CACHE PATH "spdlog lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/spdlog)

# tinyfiledialogs
set(TFD_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/tinyfiledialogs/include" CACHE PATH "tinyfiledialogs lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/tinyfiledialogs)

#################################################################################
#                                     Sources                                   #
#################################################################################
# core
set(LYSSA_CORE_SRC
    src/core/compiler_version.h
    src/core/compiler_version.cpp
    src/core/lyssa.h
    src/core/lyssa.cpp
    src/core/platform.h
    src/core/platform.cpp
    src/core/settings.h
    src/core/settings.cpp
    src/core/variable.h
    src/core/variable.cpp
    src/core/version.h
    src/core/version.cpp
)

# io
set(LYSSA_IO_SRC
    src/io/logger.h
    src/io/logger.cpp
)

# time
set(LYSSA_TIME_SRC
    src/time/current_time.h
    src/time/current_time.cpp
    src/time/execution_time.h
    src/time/execution_time.cpp
    src/time/wait_time.h
    src/time/wait_time.cpp
)

# gui
set(LYSSA_GUI_SRC
    src/gui/gui.h
    src/gui/gui.cpp
    src/gui/window_about.h
    src/gui/window_about.cpp
    src/gui/window_imgui_features.h
    src/gui/window_imgui_features.cpp
    src/gui/window_settings.h
    src/gui/window_settings.cpp
    src/gui/window.h
    src/gui/window.cpp
)

# Lyssa application
set(LYSSA_SRC
    ${LYSSA_CORE_SRC}
    ${LYSSA_IO_SRC}
    ${LYSSA_TIME_SRC}
    ${LYSSA_GUI_SRC}
)

#################################################################################
#                                     Executable                                #
#################################################################################
add_executable(${LYSSA_PROJECT} ${LYSSA_SRC})
target_include_directories(${LYSSA_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# C++ features
target_compile_features(${LYSSA_PROJECT} PRIVATE cxx_auto_type)

#################################################################################
#                                Libraries include                              #
#################################################################################
# OpenGL
target_link_libraries(${LYSSA_PROJECT} ${OPENGL_gl_LIBRARY})
target_include_directories(${LYSSA_PROJECT} PUBLIC ${OPENGL_INCLUDE_DIR})

# OpenCV
target_link_libraries(${LYSSA_PROJECT} ${OpenCV_LIBS})
target_include_directories(${LYSSA_PROJECT} PUBLIC ${OpenCV_INCLUDE_DIRS})

# GLFW
target_link_libraries(${LYSSA_PROJECT} glfw)
target_include_directories(${LYSSA_PROJECT} PUBLIC ${GLFW_INCLUDE_DIR})

# imgui
target_link_libraries(${LYSSA_PROJECT} imgui imgui_glfw imgui_opengl3)
target_include_directories(${LYSSA_PROJECT} PUBLIC ${IMGUI_INCLUDE_DIR})

# spdlog
target_link_libraries(${LYSSA_PROJECT} spdlog::spdlog)
target_include_directories(${LYSSA_PROJECT} PUBLIC ${SPDLOG_INCLUDE_DIR})

# tinyfiledialogs
target_link_libraries(${LYSSA_PROJECT} tfd)
target_include_directories(${LYSSA_PROJECT} PUBLIC ${TFD_INCLUDE_DIR})

#################################################################################
#                                 Output directory                              #
#################################################################################
function_output_directory(glfw)                 # Library glfw output directory
function_output_directory(imgui)                # Library imgui output directory
function_output_directory(imgui_glfw)           # Library imgui_glfw output directory
function_output_directory(imgui_opengl3)        # Library imgui_opengl3 output directory
function_output_directory(spdlog)               # Library spdlog output directory
function_output_directory(tfd)                  # Library tinyfiledialogs output directory
function_output_directory(${LYSSA_PROJECT})     # Lyssa application