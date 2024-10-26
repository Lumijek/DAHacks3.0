// src/Star.cpp

#include "stb_image.h"

#include "Star.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <iostream>

Star::Star(
    float mass,
    float radius,
    float effectiveTemperature,
    float luminosity,
    float surfaceGravity,
    float metallicity,
    const glm::vec3& position,
    const glm::vec3& velocity,
    const std::string& chemicalComposition,
    const std::string& texturePath // New parameter for texture path
)
    : mass(mass),
      radius(radius),
      effectiveTemperature(effectiveTemperature),
      luminosity(luminosity),
      surfaceGravity(surfaceGravity),
      metallicity(metallicity),
      chemicalComposition(chemicalComposition),
      position(position),
      velocity(velocity),
      sphereMesh(1.0f, 36, 18) // Initialize SphereMesh with unit radius and desired resolution
{
    // Load texture
    textureID = loadTexture(texturePath);
    if (textureID == 0) {
        std::cerr << "Failed to load texture: " << texturePath << std::endl;
    }
}

Star::~Star() {
    // Delete the texture when the Star object is destroyed
    glDeleteTextures(1, &textureID);
}

void Star::render(const Shader& shader) {
    // Bind the texture
    glActiveTexture(GL_TEXTURE0); // Activate texture unit 0
    glBindTexture(GL_TEXTURE_2D, textureID);
    shader.setInt("starTexture", 0); // Set the sampler to texture unit 0

    // Set model matrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, glm::vec3(radius)); // Scale based on the star's radius
    shader.setMat4("model", model);

    // Calculate color from temperature
    glm::vec3 color = temperatureToColor(effectiveTemperature);
    shader.setVec3("starColor", color);

    // Render the star using SphereMesh
    sphereMesh.Draw();

    // Unbind the texture for cleanliness
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Star::update(float deltaTime) {
    // Update position based on velocity
    position += velocity * deltaTime;
}

GLuint Star::loadTexture(const std::string& path) {
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    // Flip the image vertically during loading
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;
        else {
            std::cerr << "Unknown number of texture components: " << nrComponents << std::endl;
            stbi_image_free(data);
            return 0;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        // Create the texture
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Set texture wrapping/filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // Use linear filtering for minification and magnification
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
        std::cout << "Texture loaded successfully: " << path << " (" << width << "x" << height << ", " << nrComponents << " channels)" << std::endl;

    }
    else
    {
        std::cerr << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
        return 0;
    }

    return textureID;
}

// Utility function to convert temperature to RGB color
glm::vec3 Star::temperatureToColor(float temperature) const{
    // Clamp temperature to range [1000K, 40000K]
    temperature = glm::clamp(temperature, 1000.0f, 40000.0f) / 100.0f;

    float red, green, blue;

    // Red
    if (temperature <= 66.0f) {
        red = 255.0f;
    } else {
        red = temperature - 60.0f;
        red = 329.698727446f * powf(red, -0.1332047592f);
        red = glm::clamp(red, 0.0f, 255.0f);
    }

    // Green
    if (temperature <= 66.0f) {
        green = temperature;
        green = 99.4708025861f * logf(green) - 161.1195681661f;
        green = glm::clamp(green, 0.0f, 255.0f);
    } else {
        green = temperature - 60.0f;
        green = 288.1221695283f * powf(green, -0.0755148492f);
        green = glm::clamp(green, 0.0f, 255.0f);
    }

    // Blue
    if (temperature >= 66.0f) {
        blue = 255.0f;
    } else if (temperature <= 19.0f) {
        blue = 0.0f;
    } else {
        blue = temperature - 10.0f;
        blue = 138.5177312231f * logf(blue) - 305.0447927307f;
        blue = glm::clamp(blue, 0.0f, 255.0f);
    }

    return glm::vec3(red, green, blue) / 255.0f;
}


// Setters and Getters
void Star::setMass(float newMass) {
    mass = newMass;
}

float Star::getMass() const {
    return mass;
}

void Star::setRadius(float newRadius) {
    radius = newRadius;
}

float Star::getRadius() const {
    return radius;
}

void Star::setEffectiveTemperature(float temperature) {
    effectiveTemperature = temperature;
}

float Star::getEffectiveTemperature() const {
    return effectiveTemperature;
}

void Star::setLuminosity(float newLuminosity) {
    luminosity = newLuminosity;
}

float Star::getLuminosity() const {
    return luminosity;
}

void Star::setSurfaceGravity(float gravity) {
    surfaceGravity = gravity;
}

float Star::getSurfaceGravity() const {
    return surfaceGravity;
}

void Star::setMetallicity(float newMetallicity) {
    metallicity = newMetallicity;
}

float Star::getMetallicity() const {
    return metallicity;
}

void Star::setPosition(const glm::vec3& newPosition) {
    position = newPosition;
}

glm::vec3 Star::getPosition() const {
    return position;
}

void Star::setVelocity(const glm::vec3& newVelocity) {
    velocity = newVelocity;
}

glm::vec3 Star::getVelocity() const {
    return velocity;
}

void Star::setChemicalComposition(const std::string& composition) {
    chemicalComposition = composition;
}

std::string Star::getChemicalComposition() const {
    return chemicalComposition;
}

glm::vec3 Star::getColor() const {
    return temperatureToColor(effectiveTemperature);
}
