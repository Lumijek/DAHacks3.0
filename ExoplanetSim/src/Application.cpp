// Application.cpp

#include "Application.h"
#include "InputHandler.h"
#include "Renderer.h"

#include <iostream>

Application::Application()
    : window(nullptr),
      camera(glm::vec3(0.0f, 5.0f, 15.0f)),
      deltaTime(0.0f),
      lastFrame(0.0f),
      lastX(SCR_WIDTH / 2.0f),
      lastY(SCR_HEIGHT / 2.0f),
      firstMouse(true),
      cursorEnabled(false), // Cursor is hidden by default
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
    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Cleanup GLFW
    glfwTerminate();

    // Delete dynamically allocated objects
    delete skybox;
    delete star;
    delete planet;
    delete starShader;
    delete planetShader;
    delete skyboxShader;
    delete orbitShader;
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
        std::cerr << "Error: GLFW initialization failed." << std::endl;
        return false;
    }

    // Configure GLFW
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

        if (ImGui::SliderFloat("Mass", &planetMass, 0.0001f, 0.1f, "%.5f")) {
            planet->setMass(planetMass);
        }
        if (ImGui::SliderFloat("Radius", &planetRadius, 0.1f, 2.0f, "%.2f")) {
            planet->setRadius(planetRadius);
        }
        if (ImGui::SliderFloat("Eccentricity", &planetEccentricity, 0.0f, 0.99f, "%.2f")) {
            planet->setEccentricity(planetEccentricity);
        }
        if (ImGui::SliderFloat("Orbital Distance", &planetOrbitalDistance, 1.0f, 20.0f, "%.2f AU")) {
            planet->setOrbitalDistance(planetOrbitalDistance);
        }
        if (ImGui::SliderFloat("Orbital Period", &planetOrbitalPeriod, 1.0f, 365.0f, "%.1f days")) {
            planet->setOrbitalPeriod(planetOrbitalPeriod);
        }

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
