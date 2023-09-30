#include "../include/space.hpp"
#include <thread>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

double mouseX = 0.0;
double mouseY = 0.0;
bool drawPoint = false;
double shipX = 0.0;
double shipY = 0.0;
std::chrono::time_point<std::chrono::steady_clock> pointTimerStart;

spc::nave ship;

// Função para atualizar o status do ponto
void updatePointStatus()
{
    auto currentTime = std::chrono::steady_clock::now();
    if (drawPoint && std::chrono::duration_cast<std::chrono::seconds>(currentTime - pointTimerStart).count() >= 1)
    {
        drawPoint = false;
    }
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        mouseX = xpos;
        mouseY = ypos;
        drawPoint = true;
        pointTimerStart = std::chrono::steady_clock::now();
    }
}

void drawScene(GLFWwindow *window)
{
    glClear(GL_COLOR_BUFFER_BIT);

    ship.updatePosition(window);

    // Desenha a nave
    glPushMatrix();
    glTranslatef(shipX, shipY, 0.0);
    glRotatef(ship.getRotationAngle(), 0.0f, 0.0f, 1.0f);
    ship.draw();
    glPopMatrix();

    updatePointStatus();

    // Desenha o disparo
    ship.disparoPosition(drawPoint, mouseX, mouseY);
}

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Erro ao inicializar o GLFW" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(1080, 1080, "Desenhar Cena", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Erro ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Erro ao inicializar o GLEW" << std::endl;
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Cor de fundo preta

    while (!glfwWindowShouldClose(window))
    {
        drawScene(window); // Passa a janela como argumento para a função drawScene
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
