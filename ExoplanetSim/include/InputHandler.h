// InputHandler.h

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"

class Application; // Forward declaration

class InputHandler {
public:
    InputHandler(Application* app);

    void processInput(GLFWwindow* window);

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void char_callback(GLFWwindow* window, unsigned int c);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

private:
    Application* app;
    static InputHandler* instance;
};

#endif // INPUTHANDLER_H
