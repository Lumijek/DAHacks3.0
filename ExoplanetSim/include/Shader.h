// Shader.h

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <glm/glm.hpp>  // Include GLM types

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    // Program ID
    unsigned int ID;

    // Constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // Use/activate the shader program
    void use() const;

    // Utility functions to set uniform variables
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const float* value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;

    // Overloaded functions for setting uniforms with glm types
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;

    // Add the setVec4 method
    void setVec4(const std::string &name, const glm::vec4 &value) const;
};

#endif // SHADER_H
