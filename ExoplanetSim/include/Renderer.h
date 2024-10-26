// Renderer.h

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Star.h"
#include "Planet.h"
#include "Skybox.h"
#include "Shader.h"
#include "HabitableZone.h" // Include HabitableZone

class Application; // Forward declaration

class Renderer {
public:
    Renderer(Application* app);
    void renderScene(float deltaTime);

private:
    Application* app;
    HabitableZone* habitableZone; // Add HabitableZone pointer
};

#endif // RENDERER_H
