// Planet.cpp

#include "stb_image.h"
#include "Planet.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <cmath>

// Constructor
Planet::Planet(
    float mass,
    float radius,
    float temperature,
    float eccentricity,
    float orbitalDistance,
    float orbitalPeriod,
    float semiMajorAxis,
    const std::string& planetType,
    const glm::vec3& orbitCenter,
    const glm::vec3& planetColor,
    const char* texturePath
) : mass(mass),
    radius(radius),
    temperature(temperature),
    eccentricity(eccentricity),
    orbitalDistance(orbitalDistance),
    orbitalPeriod(orbitalPeriod),
    semiMajorAxis(semiMajorAxis),
    planetType(planetType),
    orbitCenter(orbitCenter),
    planetColor(planetColor),
    currentTime(0.0f),
    sphereMesh(1.0f, 72, 36), // Sphere of radius 1.0f
    maxOrbitPoints(360),
    currentOrbitIndex(0)
{
    // Initialize position
    position = calculateOrbitalPosition(currentTime);

    // Load texture
    textureID = loadTexture(texturePath);
    if (textureID == 0) {
        std::cerr << "Failed to load texture for the planet." << std::endl;
    }

    // Initialize orbit buffers
    initOrbitBuffers();

    // Generate the initial orbit path
    generateOrbitPath(static_cast<int>(maxOrbitPoints));
}

// Destructor
Planet::~Planet() {
    glDeleteVertexArrays(1, &orbitVAO);
    glDeleteBuffers(1, &orbitVBO);
    glDeleteTextures(1, &textureID);
}

// Initialize OpenGL buffers for orbit rendering
void Planet::initOrbitBuffers()
{
    glGenVertexArrays(1, &orbitVAO);
    glGenBuffers(1, &orbitVBO);

    glBindVertexArray(orbitVAO);
    glBindBuffer(GL_ARRAY_BUFFER, orbitVBO);
    glBufferData(GL_ARRAY_BUFFER, maxOrbitPoints * sizeof(glm::vec3), nullptr, GL_STATIC_DRAW);

    // Position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,                  // Attribute index
        3,                  // Number of components per vertex attribute
        GL_FLOAT,           // Data type
        GL_FALSE,           // Normalize
        sizeof(glm::vec3),  // Stride
        (void*)0            // Offset
    );

    glBindVertexArray(0);
}

// Generate the orbit path (precompute positions)
void Planet::generateOrbitPath(int segments)
{
    orbitPositions.clear();

    float deltaTime = orbitalPeriod / static_cast<float>(segments);
    for (int i = 0; i <= segments; ++i) {
        float time = i * deltaTime;
        glm::vec3 pos = calculateOrbitalPosition(time);
        orbitPositions.push_back(pos);
    }

    // Update the orbit buffer
    glBindBuffer(GL_ARRAY_BUFFER, orbitVBO);
    glBufferData(GL_ARRAY_BUFFER, orbitPositions.size() * sizeof(glm::vec3), orbitPositions.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Update the planet's position
void Planet::update(float deltaTime)
{
    // Update current time
    currentTime += deltaTime;

    // Keep currentTime within [0, orbitalPeriod]
    if (currentTime > orbitalPeriod)
        currentTime = fmod(currentTime, orbitalPeriod);

    // Calculate orbital position
    position = calculateOrbitalPosition(currentTime);

    // Update currentOrbitIndex
    currentOrbitIndex = static_cast<size_t>((currentTime / orbitalPeriod) * orbitPositions.size());
    if (currentOrbitIndex >= orbitPositions.size())
        currentOrbitIndex = orbitPositions.size() - 1;
}

// Render the planet
void Planet::render(const Shader& shader)
{
    if (textureID != 0) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
        shader.setInt("planetTexture", 0);
    }

    // Do not set the model matrix here; it's set in main.cpp

    // Bind the VAO and draw
    sphereMesh.Draw();

    glBindTexture(GL_TEXTURE_2D, 0);
}

// Render the orbit line
void Planet::renderOrbit(const Shader& shader, const glm::mat4& view, const glm::mat4& projection)
{
    if (orbitPositions.empty())
        return;

    shader.use();
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    glBindVertexArray(orbitVAO);

    // Enable point size
    glEnable(GL_PROGRAM_POINT_SIZE);

    // 1. Render the entire orbit as points (dotted white line)
    shader.setVec3("orbitColor", glm::vec3(1.0f)); // White color
    glPointSize(2.0f); // Set point size
    glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(orbitPositions.size()));

    // 2. Render the traveled path as a red line
    shader.setVec3("orbitColor", glm::vec3(1.0f, 0.0f, 0.0f)); // Red color
    glLineWidth(2.0f);

    if (currentOrbitIndex >= 1) {
        glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(currentOrbitIndex));
    }

    glBindVertexArray(0);

    glDisable(GL_PROGRAM_POINT_SIZE);
}

// Setters and Getters
void Planet::setMass(float mass) { this->mass = mass; }
float Planet::getMass() const { return mass; }

void Planet::setRadius(float radius) { this->radius = radius; }
float Planet::getRadius() const { return radius; }

void Planet::setTemperature(float temperature) { this->temperature = temperature; }
float Planet::getTemperature() const { return temperature; }

void Planet::setEccentricity(float eccentricity) {
    this->eccentricity = eccentricity;
    generateOrbitPath(static_cast<int>(maxOrbitPoints)); // Regenerate orbit path
}
float Planet::getEccentricity() const { return eccentricity; }

void Planet::setOrbitalDistance(float distance) {
    this->orbitalDistance = distance;
    generateOrbitPath(static_cast<int>(maxOrbitPoints)); // Regenerate orbit path
}
float Planet::getOrbitalDistance() const { return orbitalDistance; }

void Planet::setOrbitalPeriod(float period) {
    this->orbitalPeriod = period;
    generateOrbitPath(static_cast<int>(maxOrbitPoints)); // Regenerate orbit path
}
float Planet::getOrbitalPeriod() const { return orbitalPeriod; }

void Planet::setSemiMajorAxis(float sma) {
    this->semiMajorAxis = sma;
}
float Planet::getSemiMajorAxis() const {
    return semiMajorAxis;
}
void Planet::setPlanetType(const std::string& type) { this->planetType = type; }
std::string Planet::getPlanetType() const { return planetType; }

void Planet::setPlanetColor(const glm::vec3& color) { this->planetColor = color; }
glm::vec3 Planet::getPlanetColor() const { return planetColor; }

// Getter for current position
glm::vec3 Planet::getPosition() const {
    return position;
}

// Utility function to calculate orbital position
glm::vec3 Planet::calculateOrbitalPosition(float time)
{
    // Mean Anomaly (M)
    float meanAnomaly = (2.0f * glm::pi<float>() / orbitalPeriod) * time;

    // Solve Kepler's Equation for Eccentric Anomaly (E)
    float E = meanAnomaly;
    for (int i = 0; i < 5; ++i) {
        E = meanAnomaly + eccentricity * sin(E);
    }

    // True Anomaly (v)
    float sinV = sqrt(1.0f - eccentricity * eccentricity) * sin(E) / (1.0f - eccentricity * cos(E));
    float cosV = (cos(E) - eccentricity) / (1.0f - eccentricity * cos(E));
    float trueAnomaly = atan2(sinV, cosV);

    // Distance from focus to planet
    float r = orbitalDistance * (1.0f - eccentricity * eccentricity) / (1.0f + eccentricity * cos(trueAnomaly));

    // Position in orbital plane
    float x = r * cos(trueAnomaly);
    float z = r * sin(trueAnomaly);
    float y = 0.0f;

    return orbitCenter + glm::vec3(x, y, z);
}

// Utility function to load texture
unsigned int Planet::loadTexture(const char* path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true); // Flip texture vertically if needed
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if(nrComponents == 1)
            format = GL_RED;
        else if(nrComponents == 3)
            format = GL_RGB;
        else if(nrComponents == 4)
            format = GL_RGBA;
        else
            format = GL_RGB; // Default to RGB

        glBindTexture(GL_TEXTURE_2D, textureID);
        // Upload texture data
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Set texture wrapping/filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);

        std::cout << "Texture loaded successfully: " << path << " (" << width << "x" << height << ", " << nrComponents << " channels)" << std::endl;
    }
    else
    {
        std::cerr << "Failed to load texture at path: " << path << std::endl;
        stbi_image_free(data);
        return 0; // Return 0 to indicate failure
    }

    return textureID;
}
