#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords; // Received from vertex shader

// Texture sampler
uniform sampler2D starTexture;

void main()
{
    // Sample the texture color
    vec3 texColor = texture(starTexture, TexCoords).rgb;
    
    // Output the texture color directly
    FragColor = vec4(texColor, 1.0);
}
