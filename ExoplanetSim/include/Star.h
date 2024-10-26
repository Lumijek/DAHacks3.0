// include/Star.h

#ifndef STAR_H
#define STAR_H

#include "Shader.h"
#include "SphereMesh.h"
#include <glm/glm.hpp>
#include <string>
#include <glad/glad.h> // Include for GLuint

class Star {
public:
    // Constructor
    Star(
        float mass,
        float radius,
        float effectiveTemperature,
        float luminosity,
        float surfaceGravity,
        float metallicity,
        const glm::vec3& position,
        const glm::vec3& velocity,
        const std::string& chemicalComposition,
        const std::string& texturePath // Texture path
    );

    // Destructor to clean up texture
    ~Star();

    // Render the star
    void render(const Shader& shader, const glm::mat4& model);

    // Update the star's position based on motion
    void update(float deltaTime);

    // Setters and Getters for hyperparameters
    void setMass(float mass);
    float getMass() const;

    void setRadius(float radius);
    float getRadius() const;

    void setEffectiveTemperature(float temperature);
    float getEffectiveTemperature() const;

    void setLuminosity(float luminosity);
    float getLuminosity() const;

    void setSurfaceGravity(float gravity);
    float getSurfaceGravity() const;

    void setMetallicity(float metallicity);
    float getMetallicity() const;

    void setPosition(const glm::vec3& position);
    glm::vec3 getPosition() const;

    void setVelocity(const glm::vec3& velocity);
    glm::vec3 getVelocity() const;

    void setChemicalComposition(const std::string& composition);
    std::string getChemicalComposition() const;

    glm::vec3 getColor() const;

private:
    // Fundamental parameters
    float mass;
    float radius;
    float effectiveTemperature;
    float luminosity;
    float surfaceGravity;
    float metallicity;
    std::string chemicalComposition;

    // Position and motion
    glm::vec3 position;
    glm::vec3 velocity;

    // Sphere mesh for rendering
    SphereMesh sphereMesh;

    // Texture
    GLuint textureID;

    // Utility function to convert temperature to color (keep it private)
    glm::vec3 temperatureToColor(float temperature) const;

    // Utility function to load texture
    GLuint loadTexture(const std::string& path);
};

#endif // STAR_H
