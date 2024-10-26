#version 330 core

out vec4 FragColor;

uniform vec3 orbitColor;

void main()
{
    FragColor = vec4(orbitColor, 1.0);
}
