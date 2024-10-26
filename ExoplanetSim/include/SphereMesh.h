// include/SphereMesh.h

#ifndef SPHEREMESH_H
#define SPHEREMESH_H

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

class SphereMesh {
public:
    // Constructor: Initializes the sphere mesh with given parameters
    SphereMesh(float radius, unsigned int sectorCount, unsigned int stackCount);
    
    // Destructor: Cleans up the allocated OpenGL resources
    ~SphereMesh();

    // Draws the sphere mesh
    void Draw() const;

private:
    // OpenGL Object IDs
    unsigned int VAO, VBO, EBO;
    
    // Number of indices to draw
    unsigned int indexCount;

    // Sphere parameters
    float radius;
    unsigned int sectorCount;
    unsigned int stackCount;

    // Vertex and index data
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    // Initializes the sphere mesh by generating vertex and index data and setting up buffers
    void init();

    // Generates the sphere's vertex and index data
    void generateSphere();
};

#endif // SPHEREMESH_H
