#include "../include/window.hpp"

GLFWmonitor *monitor;
GLFWwindow *window;

spc::nave ship;
std::vector<spc::disparo> disparos;
std::map<int, key> keyMap;

bool running = true, fullscreen;
int WIDTH = 1280, HEIGHT = 720;

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

    glfwSetMouseButtonCallback(window, mouse_button_callback);

    monitor = glfwGetPrimaryMonitor();
    running = true;
    fullscreen = false;

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
    // Set up the viewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = (float)width / (float)height;
    float size = 10.0f;
    if (aspectRatio > 1.0f)
    {
        glOrtho(-size * aspectRatio, size * aspectRatio, -size, size, -1.0f, 1.0f);
    }
    else
    {
        glOrtho(-size, size, -size / aspectRatio, size / aspectRatio, -1.0f, 1.0f);
    }

    // Switch back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);


    glClear(GL_COLOR_BUFFER_BIT);

    ship.updatePosition(window);
    ship.draw();
    glfwSwapBuffers(window);
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
    // Desenha e verifica os disparos
    auto currentTime = std::chrono::steady_clock::now();
    // for (spc::disparo it = disparos.begin(); it != disparos.end();)
     for (int i = 0; i < disparos.size(); i++)
    {
        if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - disparos[i].getTimeCreated()).count() >= 1)
        {
            // O disparo está ativo por mais de 1 segundo, remova-o
            disparos.erase(disparos.begin() + i);
        }
        else
        {
            // O disparo ainda está ativo, desenhe-o
            disparos[i].updatePointStatus();
            disparos[i].disparoPosition(disparos[i].getX(), disparos[i].getY());
        }
    }
}

void mouse_button_callback(GLFWwindow *window , int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        spc::disparo newDisparo(xpos, ypos, std::chrono::steady_clock::now());
        
        disparos.push_back(newDisparo);
    }
}