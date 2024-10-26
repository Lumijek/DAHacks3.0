#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 lightPos;           // Position of the light source (star)
uniform vec3 lightColor;         // Color of the light emitted by the star
uniform vec3 viewPos;            // Camera position
uniform sampler2D planetTexture; // Texture sampler

void main()
{
    // Texture Sampling
    vec3 texColor = texture(planetTexture, TexCoords).rgb;

    // Normalize vectors
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 viewDir = normalize(viewPos - FragPos);

    // Calculate diffuse component
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor * texColor;

    // Calculate ambient component scaled by diffuse
    float ambientStrength = 0.1; // Base ambient strength
    float scaledAmbientStrength = ambientStrength * diff; // Scale ambient by diffuse factor
    vec3 ambient = scaledAmbientStrength * texColor;

    // Calculate specular component
    float specularStrength = 0.5;
    vec3 reflectDir = reflect(-lightDir, norm);
    float shininess = 32.0;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * lightColor;

    // Combine lighting components
    vec3 result = ambient + diffuse + specular;

    // Optional: Gamma Correction
    // float gamma = 2.2;
    // result = pow(result, vec3(1.0 / gamma));

    // Clamp the result to [0,1]
    result = clamp(result, 0.0, 1.0);

    FragColor = vec4(result, 1.0);
}
