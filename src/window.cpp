#include "../include/window.hpp"

bool running = true, fullscreen;
spc::nave ship;
GLFWwindow *window;
GLFWmonitor *monitor;
std::map<int, key> keyMap;

int initWindow()
{
    if (!glfwInit())
    {
        std::cerr << "Erro ao inicializar o GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "ASTRID", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Erro ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    monitor = glfwGetPrimaryMonitor();
    running = true;
    fullscreen = false;
    glfwSetWindowSizeCallback(window, reshapeWindow);

    // Inicializa GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Erro ao inicializar o GLEW" << std::endl;
        return -1;
    }

    return 0;
}

void input(GLFWwindow *window)
{
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        running = false;
        glfwWindowShouldClose(window);
    }

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && keyMap[GLFW_KEY_F].prev)
    {
        glfwWaitEventsTimeout(0.7);
        if (!fullscreen)
            glfwSetWindowMonitor(window, monitor, 0, 0, WIDTH, HEIGHT, 0);
        if (fullscreen)
            glfwSetWindowMonitor(window, NULL, 0, 0, WIDTH, HEIGHT, 0);
        fullscreen = !fullscreen;
    }
    keyMap[GLFW_KEY_F].prev = glfwGetKey(window, GLFW_KEY_F);
}

void drawScene(GLFWwindow *window)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Desenha a nave
    ship.updatePosition(window);
    ship.draw();
    glfwSwapBuffers(window);
}

void reshapeWindow(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void runAstrid()
{
    initWindow();
    double lastTime = 0;
    double deltaTime = 0.0;
    const double FPS = 60.0;
    const double targetFrameTime = 1.0 / FPS;
    while (running)
    {
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        while (deltaTime >= targetFrameTime)
        {
            input(window);
            update(window);
            std::cout << "FPS: " << 1.0 / deltaTime << std::endl;
            deltaTime -= targetFrameTime;
        }
        drawScene(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

void update(GLFWwindow *window)
{
}