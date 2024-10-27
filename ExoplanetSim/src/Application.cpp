// Application.cpp

#include "Application.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "stb_image.h"
#include "Charts.h"

#include <iostream>

Application::Application()
    : window(nullptr),
      camera(glm::vec3(0.0f, 5.0f, 15.0f)),
      deltaTime(0.0f),
      lastFrame(0.0f),
      lastX(SCR_WIDTH / 2.0f),
      lastY(SCR_HEIGHT / 2.0f),
      firstMouse(true),
      cursorEnabled(false),
      skybox(nullptr),
      star(nullptr),
      planet(nullptr),
      starShader(nullptr),
      planetShader(nullptr),
      skyboxShader(nullptr),
      orbitShader(nullptr),
      io(nullptr)
{
}

Application::~Application()
{
    // Cleanup
    delete skybox;
    delete star;
    delete planet;

    delete starShader;
    delete planetShader;
    delete skyboxShader;
    delete orbitShader;

    // Shutdown ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Terminate GLFW
    glfwTerminate();
}

bool Application::initialize()
{
    if (!initWindow())
        return false;
    if (!initOpenGL())
        return false;
    initObjects();
    if (!initImGui())
        return false;
    return true;
}

bool Application::initWindow()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Error: Failed to initialize GLFW." << std::endl;
        return false;
    }

    // Set OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Exoplanet Simulation", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Error: Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // Set input callbacks
    glfwSetFramebufferSizeCallback(window, InputHandler::framebuffer_size_callback);
    glfwSetCursorPosCallback(window, InputHandler::mouse_callback);
    glfwSetScrollCallback(window, InputHandler::scroll_callback);
    glfwSetKeyCallback(window, InputHandler::key_callback);
    glfwSetCharCallback(window, InputHandler::char_callback);
    glfwSetMouseButtonCallback(window, InputHandler::mouse_button_callback);

    // Capture mouse cursor (hidden by default)
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    return true;
}

bool Application::initOpenGL()
{
    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error: Failed to initialize GLAD." << std::endl;
        return false;
    }

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Enable program point size
    glEnable(GL_PROGRAM_POINT_SIZE);

    return true;
}

void Application::initObjects()
{
    // Build and compile shaders
    starShader = new Shader("../shaders/star_vertex.glsl", "../shaders/star_fragment.glsl");
    planetShader = new Shader("../shaders/object_vertex.glsl", "../shaders/planet_fragment.glsl");
    skyboxShader = new Shader("../shaders/skybox_vertex.glsl", "../shaders/skybox_fragment.glsl");
    orbitShader = new Shader("../shaders/orbit_vertex.glsl", "../shaders/orbit_fragment.glsl");

    // Configure the planet shader's texture sampler uniform
    planetShader->use();
    planetShader->setInt("planetTexture", 0); // Texture unit 0

    // Load the skybox textures
    std::vector<std::string> faces{
        "../textures/skybox/right.jpg",
        "../textures/skybox/left.jpg",
        "../textures/skybox/top.jpg",
        "../textures/skybox/bottom.jpg",
        "../textures/skybox/front.jpg",
        "../textures/skybox/back.jpg"
    };
    skybox = new Skybox(faces);

    // Instantiate the star
    star = new Star(
        1.0f,                // Mass (in solar masses)
        1.0f,                // Radius (in arbitrary units)
        5800.0f,             // Effective Temperature (Kelvin)
        1.0f,                // Luminosity (in solar luminosities)
        4.44f,               // Surface Gravity (log g in cgs units)
        0.0f,                // Metallicity ([Fe/H])
        glm::vec3(0.0f),     // Position
        glm::vec3(0.0f),     // Velocity
        "Hydrogen, Helium",  // Chemical Composition
        "../textures/star.jpg" // Texture Path
    );

    // Instantiate the planet
    planet = new Planet(
        0.00315f,                      // Mass (relative to solar mass)
        0.9f,                          // Radius (arbitrary units)
        288.0f,                        // Temperature (Kelvin)
        0.0167f,                       // Eccentricity
        5.0f,                          // Orbital Distance (arbitrary units)
        65.25f,                        // Orbital Period (days)
        "Terrestrial",                 // Planet Type
        star->getPosition(),           // Orbit Center (star position)
        glm::vec3(0.2f, 0.5f, 0.8f),   // Planet Color
        "../textures/planet.jpg"       // Texture Path
    );

    // Adjust the camera position based on initial orbital parameters
    adjustCameraPosition();
}

void Application::generatePlots() {
    // Clear existing image paths and generate updated plots
    imagePaths.clear();

    Charts::gvmass(star->getRadius(), "gvmass");
    imagePaths.push_back("temp_images/gvmass.png");

    Charts::radvmass(star->getMass(), "radvmass");
    imagePaths.push_back("temp_images/radvmass.png");

    Charts::luminosityvrad(star->getRadius(), star->getEffectiveTemperature(), "luminosityvrad");
    imagePaths.push_back("temp_images/luminosityvrad.png");

    Charts::tempvrad(star->getMass(), "tempvrad");
    imagePaths.push_back("temp_images/tempvrad.png");

    Charts::metalvmass(star->getMass(), "metalvmass");
    imagePaths.push_back("temp_images/metalvmass.png");
}

void Application::loadImages() {
    std::vector<std::string> imagePaths = {
        "../textures/image1.png",
        "../textures/image2.png",
        "../textures/image3.png" // Add more images here
    };

    for (const auto& path : imagePaths) {
        int width, height, channels;
        unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 4);
        if (!data) {
            std::cerr << "Failed to load texture: " << path << std::endl;
            continue;
        }

        GLuint textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data); // Free the image memory

        imageTextures.push_back(textureID);
        imageSizes.push_back(ImVec2(width, height));
    }
}

void Application::loadImage(const std::string& path) {
    int width, height, channels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 4);
    if (!data) {
        std::cerr << "Failed to load texture: " << path << std::endl;
        return;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data); // Free the image memory

    // Add to the vector
    imageTextures.push_back(textureID);
    imageSizes.push_back(ImVec2(width, height));
    imagePaths.push_back(path); // Track the loaded image path
}

bool Application::initImGui()
{
    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO(); (void)io;

    // Enable keyboard controls
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    // Setup ImGui style
    ImGui::StyleColorsDark();
    // Initialize ImGui backends
    ImGui_ImplGlfw_InitForOpenGL(window, false); // Install callbacks manually
    ImGui_ImplOpenGL3_Init("#version 330 core");

    loadImages()

    return true;
}

void Application::run()
{
    InputHandler inputHandler(this);
    Renderer renderer(this);

    while (!glfwWindowShouldClose(window))
    {
        // Per-frame time logic
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Process input
        inputHandler.processInput(window);

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Build ImGui UI

        // Star Parameters Window
        ImGui::Begin("Star Parameters");

        static float starMass = star->getMass();
        static float starRadius = star->getRadius();
        static float starTemperature = star->getEffectiveTemperature();

        if (ImGui::SliderFloat("Mass", &starMass, 0.1f, 10.0f, "%.2f")) {
            star->setMass(starMass);
        }
        if (ImGui::SliderFloat("Radius", &starRadius, 0.1f, 5.0f, "%.2f")) {
            star->setRadius(starRadius);
            adjustCameraPosition(); // Adjust camera if star size changes
        }
        if (ImGui::SliderFloat("Temperature", &starTemperature, 1000.0f, 40000.0f, "%.0f K")) {
            star->setEffectiveTemperature(starTemperature);
        }

        ImGui::End();

        // Planet Parameters Window
        ImGui::Begin("Planet Parameters");

        static float planetMass = planet->getMass();
        static float planetRadius = planet->getRadius();
        static float planetEccentricity = planet->getEccentricity();
        static float planetOrbitalDistance = planet->getOrbitalDistance();
        static float planetOrbitalPeriod = planet->getOrbitalPeriod();

        bool orbitalParametersChanged = false;

        if (ImGui::SliderFloat("Mass", &planetMass, 0.0001f, 0.1f, "%.5f")) {
            planet->setMass(planetMass);
        }
        if (ImGui::SliderFloat("Radius", &planetRadius, 0.1f, 2.0f, "%.2f")) {
            planet->setRadius(planetRadius);
        }
        if (ImGui::SliderFloat("Eccentricity", &planetEccentricity, 0.0f, 0.99f, "%.2f")) {
            planet->setEccentricity(planetEccentricity);
            orbitalParametersChanged = true;
        }
        if (ImGui::SliderFloat("Orbital Distance", &planetOrbitalDistance, 1.0f, 1000.0f, "%.2f AU")) {
            planet->setOrbitalDistance(planetOrbitalDistance);
            orbitalParametersChanged = true;
        }
        if (ImGui::SliderFloat("Orbital Period", &planetOrbitalPeriod, 1.0f, 1000.0f, "%.1f days")) {
            planet->setOrbitalPeriod(planetOrbitalPeriod);
            // If orbital period affects distance, set orbitalParametersChanged = true
            // orbitalParametersChanged = true;
        }

        ImGui::End();

        generatePlots();

        // Graphical Analysis Window with Image Pagination
        ImGui::Begin("Graphical Analysis");

        // Check if there are images to display
        if (!imageTextures.empty()) {
            // Navigation buttons
            if (ImGui::ArrowButton("##left", ImGuiDir_Left)) {
                currentImageIndex = (currentImageIndex - 1 + imageTextures.size()) % imageTextures.size();
            }
            ImGui::SameLine();
            ImGui::Text("Image %d/%d", currentImageIndex + 1, static_cast<int>(imageTextures.size()));
            ImGui::SameLine();
            if (ImGui::ArrowButton("##right", ImGuiDir_Right)) {
                currentImageIndex = (currentImageIndex + 1) % imageTextures.size();
            }

            // Display the current image
            GLuint currentTexture = imageTextures[currentImageIndex];
            ImVec2 currentSize = imageSizes[currentImageIndex];
            ImGui::Image((ImTextureID)(intptr_t)currentTexture, currentSize);
        } else {
            ImGui::Text("No images loaded.");
        }

        ImGui::End();

        // Adjust camera position if orbital parameters have changed
        if (orbitalParametersChanged) {
            adjustCameraPosition();
        }

        // Camera Controls at the bottom
        ImGuiIO& io = ImGui::GetIO();

        // Create a new ImGui window at the bottom of the screen
        ImGui::SetNextWindowPos(ImVec2(0, io.DisplaySize.y - 50));
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, 50));

        ImGui::Begin("Camera Controls", nullptr,
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoBackground);

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0)); // Transparent background
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1, 1, 1, 0.1f)); // Slight highlight on hover
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1, 1, 1, 0.2f)); // Slight highlight when pressed

        // Center the buttons
        float buttonWidth = 120.0f; // Adjust as needed
        float totalButtonWidth = buttonWidth * 3 + ImGui::GetStyle().ItemSpacing.x * 2;
        float windowWidth = io.DisplaySize.x;
        float startX = (windowWidth - totalButtonWidth) / 2.0f;

        ImGui::SetCursorPosX(startX);

        if (ImGui::Button("Planet View", ImVec2(buttonWidth, 0)))
        {
            adjustCameraToPlanet();
        }
        ImGui::SameLine();
        if (ImGui::Button("Star View", ImVec2(buttonWidth, 0)))
        {
            adjustCameraToStar();
        }
        ImGui::SameLine();
        if (ImGui::Button("System View", ImVec2(buttonWidth, 0)))
        {
            adjustCameraPosition();
        }

        ImGui::PopStyleColor(3);

        ImGui::End();

        // Rendering ImGui
        ImGui::Render();

        // Clear the color and depth buffers
        glClearColor(0.01f, 0.01f, 0.01f, 1.0f); // Dark background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update and render
        update();
        renderer.renderScene(deltaTime);

        // Render ImGui on top of the scene
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::update()
{
    // Update objects
    planet->update(deltaTime);
    star->update(deltaTime);
}

void Application::adjustCameraPosition()
{
    // Calculate the maximum distance the planet can be from the star
    float maxDistance = planet->getOrbitalDistance() * (1.0f + planet->getEccentricity());

    // Include the star's radius in the calculation
    float starRadius = star->getRadius();

    // Calculate a suitable camera distance
    float distanceFactor = 2.5f; // Adjust this factor as needed
    float cameraDistance = (maxDistance + starRadius) * distanceFactor;

    // Position the camera along a suitable vector
    glm::vec3 newPosition = glm::vec3(0.0f, cameraDistance, cameraDistance);

    // Calculate the new front vector
    glm::vec3 newFront = star->getPosition() - newPosition;

    // Set the camera's position and front vectors using the Camera method
    camera.setPositionAndFront(newPosition, newFront);
}

void Application::adjustCameraToPlanet()
{
    // Position the camera directly in front of the planet
    float offsetDistance = planet->getRadius() * 3.0f; // Adjust multiplier as needed

    // Calculate direction from the planet to the star (or any other point)
    glm::vec3 direction = glm::normalize(planet->getPosition() - star->getPosition());

    // Calculate new camera position behind the planet
    glm::vec3 newPosition = planet->getPosition() + direction * offsetDistance;

    // Calculate new front vector
    glm::vec3 newFront = planet->getPosition() - newPosition;

    // Set the camera's position and front vectors using the Camera method
    camera.setPositionAndFront(newPosition, newFront);
}

void Application::adjustCameraToStar()
{
    // Position the camera directly in front of the star
    float offsetDistance = star->getRadius() * 3.0f; // Adjust multiplier as needed

    // Calculate direction to position the camera
    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 1.0f); // Adjust if needed

    // Calculate new camera position
    glm::vec3 newPosition = star->getPosition() + direction * offsetDistance;

    // Calculate new front vector
    glm::vec3 newFront = star->getPosition() - newPosition;

    // Set the camera's position and front vectors using the Camera method
    camera.setPositionAndFront(newPosition, newFront);
}
