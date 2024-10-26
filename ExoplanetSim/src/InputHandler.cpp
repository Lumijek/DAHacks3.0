// InputHandler.cpp

#include "InputHandler.h"
#include "Application.h"
#include <iostream>

// Initialize the static instance pointer
InputHandler* InputHandler::instance = nullptr;

InputHandler::InputHandler(Application* app)
    : app(app)
{
    instance = this;
}

void InputHandler::processInput(GLFWwindow* window)
{
    ImGuiIO& io = ImGui::GetIO();

    // Toggle cursor visibility with 'M' key
    static bool mKeyPressed = false;

    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && !mKeyPressed)
    {
        mKeyPressed = true;

        // Toggle cursor enabled state
        app->cursorEnabled = !app->cursorEnabled;

        if (app->cursorEnabled)
        {
            // Enable the cursor
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            app->firstMouse = true; // Reset firstMouse to avoid sudden camera jump
        }
        else
        {
            // Disable the cursor
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_RELEASE)
    {
        mKeyPressed = false;
    }

    // Process keyboard input only if ImGui is not capturing it
    if (!io.WantCaptureKeyboard)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            app->camera.ProcessKeyboard(FORWARD, app->deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            app->camera.ProcessKeyboard(BACKWARD, app->deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            app->camera.ProcessKeyboard(LEFT, app->deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            app->camera.ProcessKeyboard(RIGHT, app->deltaTime);
    }
}

void InputHandler::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void InputHandler::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    // Forward mouse movement to ImGui
    ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);

    if (!instance)
        return;

    Application* app = instance->app;

    if (app->cursorEnabled)
        return; // Do not process mouse movement when cursor is visible

    if (app->firstMouse)
    {
        app->lastX = static_cast<float>(xpos);
        app->lastY = static_cast<float>(ypos);
        app->firstMouse = false;
        return; // Prevent sudden camera jump
    }

    float xoffset = static_cast<float>(xpos) - app->lastX;
    float yoffset = app->lastY - static_cast<float>(ypos);

    app->lastX = static_cast<float>(xpos);
    app->lastY = static_cast<float>(ypos);

    app->camera.ProcessMouseMovement(xoffset, yoffset);
}

void InputHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    // Forward scroll to ImGui
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);

    if (!instance)
        return;

    Application* app = instance->app;

    if (app->cursorEnabled)
        return; // Do not process scroll when cursor is visible

    app->camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Forward key events to ImGui
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
}

void InputHandler::char_callback(GLFWwindow* window, unsigned int c)
{
    // Forward character input to ImGui
    ImGui_ImplGlfw_CharCallback(window, c);
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    // Forward mouse button events to ImGui
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
}
