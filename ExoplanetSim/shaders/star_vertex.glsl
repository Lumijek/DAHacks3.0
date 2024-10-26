#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords; // New attribute for texture coordinates

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords; // Pass to fragment shader

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    TexCoords = aTexCoords; // Assign texture coordinates

    gl_Position = projection * view * vec4(FragPos, 1.0);
}
