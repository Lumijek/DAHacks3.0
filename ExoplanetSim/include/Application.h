// Application.h

#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Skybox.h"
#include "Star.h"
#include "Planet.h"
#include "Shader.h"
#include "HabitableZone.h" // Include HabitableZone

// ImGui includes
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

// Include stb_image
#include "stb_image.h"

#include <cstdint> // For uintptr_t

class Application {
public:
    Application();
    ~Application();

    bool initialize();
    void run();

    // Public members needed by other classes
    GLFWwindow* window;
    Camera camera;
    float deltaTime;

    // Screen settings
    const unsigned int SCR_WIDTH = 1280;
    const unsigned int SCR_HEIGHT = 720;

    // Input handling variables
    float lastX;
    float lastY;
    bool firstMouse;
    bool cursorEnabled; // True if cursor is visible

    // State variable for the separate window
    bool showSeparateWindow;

private:
    // Timing variables
    float lastFrame;

    // Objects
    Skybox* skybox;
    Star* star;
    Planet* planet;
    HabitableZone* habitableZone; // Add HabitableZone

    // Shaders
    Shader* starShader;
    Shader* planetShader;
    Shader* skyboxShader;
    Shader* orbitShader;
    Shader* habitableZoneShader; // Shader for HabitableZone

    // ImGui
    ImGuiIO* io;

    // Initialization functions
    bool initWindow();
    bool initOpenGL();
    void initObjects();
    bool initImGui();

    // Main loop functions
    void update();

    // Camera adjustment methods
    void adjustCameraPosition();    // View entire solar system
    void adjustCameraToPlanet();    // Focus on planet
    void adjustCameraToStar();      // Focus on star

    // Function to load a texture from file
    GLuint loadTexture(const char* path);

    // Texture IDs for images
    GLuint imageTexture1;
    GLuint imageTexture2;
    GLuint imageTexture3;

    // State variables for image windows
    bool showImage1;
    bool showImage2;
    bool showImage3;

    // Friend classes and functions for access
    friend class InputHandler;
    friend class Renderer;
};

#endif // APPLICATION_H
