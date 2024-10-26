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

class Application; // Forward declaration

class Renderer {
public:
    Renderer(Application* app);

    void renderScene(float deltaTime);

private:
    Application* app;
};

#endif // RENDERER_H
