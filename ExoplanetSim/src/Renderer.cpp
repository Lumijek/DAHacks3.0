// Renderer.cpp

#include "Renderer.h"
#include "Application.h"

Renderer::Renderer(Application* app)
    : app(app)
{
}

void Renderer::renderScene(float deltaTime)
{
    // Clear the color and depth buffers
    glClearColor(0.01f, 0.01f, 0.01f, 1.0f); // Dark background
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set view and projection matrices
    glm::mat4 view = app->camera.GetViewMatrix();
    int width, height;
    glfwGetFramebufferSize(app->window, &width, &height);
    glm::mat4 projection = glm::perspective(
        glm::radians(app->camera.Zoom),
        static_cast<float>(width) / static_cast<float>(height),
        0.1f,
        100.0f
    );

    // Render the star
    app->starShader->use();
    app->starShader->setMat4("view", view);
    app->starShader->setMat4("projection", projection);
    glm::mat4 starModel = glm::mat4(1.0f);
    starModel = glm::translate(starModel, app->star->getPosition());
    starModel = glm::scale(starModel, glm::vec3(app->star->getRadius()));
    app->starShader->setMat4("model", starModel);
    app->star->render(*app->starShader);

    // Render the planet
    app->planetShader->use();
    app->planetShader->setMat4("view", view);
    app->planetShader->setMat4("projection", projection);
    glm::mat4 planetModel = glm::mat4(1.0f);
    planetModel = glm::translate(planetModel, app->planet->getPosition());
    planetModel = glm::scale(planetModel, glm::vec3(app->planet->getRadius()));
    app->planetShader->setMat4("model", planetModel);
    app->planetShader->setVec3("lightPos", app->star->getPosition());
    app->planetShader->setVec3("lightColor", app->star->getColor());
    app->planetShader->setVec3("viewPos", app->camera.Position);
    app->planet->render(*app->planetShader);

    // Render the orbit line
    app->orbitShader->use();
    app->orbitShader->setMat4("view", view);
    app->orbitShader->setMat4("projection", projection);
    app->planet->renderOrbit(*app->orbitShader, view, projection);

    // Render the skybox last
    glDepthFunc(GL_LEQUAL);
    app->skyboxShader->use();
    glm::mat4 skyboxView = glm::mat4(glm::mat3(view));
    app->skyboxShader->setMat4("view", skyboxView);
    app->skyboxShader->setMat4("projection", projection);
    app->skybox->render();
    glDepthFunc(GL_LESS);
}
