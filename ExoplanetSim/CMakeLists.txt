cmake_minimum_required(VERSION 3.15)
project(ExoplanetSimulation)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES
    src/main.cpp
    src/Application.cpp
    src/InputHandler.cpp
    src/Renderer.cpp
    src/glad.c
    src/Camera.cpp
    src/Skybox.cpp
    src/Shader.cpp
    src/stb_image.cpp
    src/Star.cpp
    src/Planet.cpp
    src/SphereMesh.cpp
)

# Find GLFW using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# Include directories
include_directories(
    include
    /opt/homebrew/include    # Include GLM headers from Homebrew
    ${GLFW_INCLUDE_DIRS}
)

link_directories(${GLFW_LIBRARY_DIRS})

# Find OpenGL
find_package(OpenGL REQUIRED)

# Include OpenGL headers
include_directories(${OPENGL_INCLUDE_DIR})

# Set macOS frameworks
set(MACOSX_FRAMEWORKS
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

# Common libraries
set(COMMON_LIBRARIES
    ${GLFW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${MACOSX_FRAMEWORKS}
)

# ImGui directory
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/third_party/imgui)

# ImGui sources
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Add ImGui library
add_library(imgui STATIC ${IMGUI_SOURCES})

# Include directories for ImGui
target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends ${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})

# Define IMGUI_IMPL_OPENGL_LOADER_GLAD
target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)

# Link libraries for ImGui
target_link_libraries(imgui PUBLIC ${COMMON_LIBRARIES})

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    imgui
    ${COMMON_LIBRARIES}
)
