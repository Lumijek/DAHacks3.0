// Planet.h

#ifndef PLANET_H
#define PLANET_H

#include "Shader.h"
#include "SphereMesh.h"
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Planet {
public:
    // Constructor and Destructor
    Planet(
        float mass,
        float radius,
        float temperature,
        float eccentricity,
        float orbitalDistance,
        float orbitalPeriod,
        const std::string& planetType,
        const glm::vec3& orbitCenter,
        const glm::vec3& planetColor,
        const char* texturePath
    );
    ~Planet();

    // Update the planet's position
    void update(float deltaTime);

    // Render functions
    void render(const Shader& shader);
    void renderOrbit(const Shader& shader, const glm::mat4& view, const glm::mat4& projection);

    // Setters and Getters
    void setMass(float mass);
    float getMass() const;

    void setRadius(float radius);
    float getRadius() const;

    void setTemperature(float temperature);
    float getTemperature() const;

    void setEccentricity(float eccentricity);
    float getEccentricity() const;

    void setOrbitalDistance(float distance);
    float getOrbitalDistance() const;

    void setOrbitalPeriod(float period);
    float getOrbitalPeriod() const;

    void setPlanetType(const std::string& type);
    std::string getPlanetType() const;

    void setPlanetColor(const glm::vec3& color);
    glm::vec3 getPlanetColor() const;

    // Generate the orbit path
    void generateOrbitPath(int segments);

    // Getter for current position
    glm::vec3 getPosition() const;

private:
    // Fundamental parameters
    float mass;
    float radius;
    float temperature;
    float eccentricity;
    float orbitalDistance;
    float orbitalPeriod;
    std::string planetType;

    glm::vec3 orbitCenter;
    glm::vec3 position;
    float currentTime;

    glm::vec3 planetColor;  // Planet color

    SphereMesh sphereMesh; // Sphere mesh for rendering

    // Texture
    unsigned int textureID; // Texture ID

    // Orbit path data
    std::vector<glm::vec3> orbitPositions;
    unsigned int orbitVAO, orbitVBO;
    size_t maxOrbitPoints; // Maximum number of points to store

    // Current index in the orbit path
    size_t currentOrbitIndex;

    // Utility functions
    glm::vec3 calculateOrbitalPosition(float time);
    unsigned int loadTexture(const char* path);
    void initOrbitBuffers();
};

#endif // PLANET_H
