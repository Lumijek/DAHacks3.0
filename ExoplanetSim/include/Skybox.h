#ifndef SKYBOX_H
#define SKYBOX_H

#include <glad/glad.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>

class Skybox {
public:
    Skybox(const std::vector<std::string>& faces);
    ~Skybox();
    void render();

private:
    GLuint cubemapTexture;
    GLuint VAO, VBO;
    void loadCubemap(const std::vector<std::string>& faces);
    void setupMesh();
};

#endif // SKYBOX_H
