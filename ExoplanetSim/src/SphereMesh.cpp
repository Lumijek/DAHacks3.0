// src/SphereMesh.cpp

#include "SphereMesh.h"
#include <cmath>
#include <iostream>

// Constructor: Initializes and builds the sphere mesh
SphereMesh::SphereMesh(float radius, unsigned int sectorCount, unsigned int stackCount)
    : radius(radius), sectorCount(sectorCount), stackCount(stackCount)
{
    generateSphere();
    init();
}

// Destructor: Deletes the OpenGL buffers
SphereMesh::~SphereMesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

// Draws the sphere mesh
void SphereMesh::Draw() const
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indexCount), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

// Initializes OpenGL buffers and attribute pointers
void SphereMesh::init()
{
    // Generate and bind Vertex Array Object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind Vertex Buffer Object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    // Generate and bind Element Buffer Object
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Set vertex attribute pointers

    // Position attribute (location = 0)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,                  // Attribute location
        3,                  // Number of components (x, y, z)
        GL_FLOAT,           // Data type
        GL_FALSE,           // Normalize
        8 * sizeof(float),  // Stride
        (void*)0            // Offset
    );

    // Normal attribute (location = 1)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1,                                  // Attribute location
        3,                                  // Number of components (nx, ny, nz)
        GL_FLOAT,                           // Data type
        GL_FALSE,                           // Normalize
        8 * sizeof(float),                  // Stride
        (void*)(3 * sizeof(float))          // Offset
    );

    // Texture Coordinate attribute (location = 2)
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(
        2,                                  // Attribute location
        2,                                  // Number of components (s, t)
        GL_FLOAT,                           // Data type
        GL_FALSE,                           // Normalize
        8 * sizeof(float),                  // Stride
        (void*)(6 * sizeof(float))          // Offset
    );

    glBindVertexArray(0); // Unbind VAO
}

// Generates the sphere's vertex and index data
void SphereMesh::generateSphere()
{
    float x, y, z, xy;                              // Vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // Vertex normal
    float s, t;                                     // Texture coordinates

    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    float sectorAngle, stackAngle;

    for(unsigned int i = 0; i <= stackCount; ++i)
    {
        stackAngle = M_PI / 2 - i * stackStep;        // From pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // Add (sectorCount+1) vertices per stack
        for(unsigned int j = 0; j <= sectorCount; ++j)
        {
            sectorAngle = j * sectorStep;           // From 0 to 2pi

            // Vertex position
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            // Normalize the normal vector
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            // Texture coordinates
            s = (float)j / sectorCount;
            t = (float)i / stackCount;

            // Append vertex data: position (3), normal (3), texCoords (2)
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
            vertices.push_back(nx);
            vertices.push_back(ny);
            vertices.push_back(nz);
            vertices.push_back(s);
            vertices.push_back(t);
        }
    }

    // Generate indices
    unsigned int k1, k2;
    for(unsigned int i = 0; i < stackCount; ++i)
    {
        k1 = i * (sectorCount + 1);     // Beginning of current stack
        k2 = k1 + sectorCount + 1;      // Beginning of next stack

        for(unsigned int j = 0; j < sectorCount; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            if(i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            if(i != (stackCount-1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

    indexCount = static_cast<unsigned int>(indices.size());
}
