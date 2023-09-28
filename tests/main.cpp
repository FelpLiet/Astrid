#include "../include/space.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>

// Crie uma nave com posição (400, 300) e tamanho (0.1, 0.1)
spc::nave ship;
spc::asteroide newBall(20, 20, 10.0f);

// Função de callback para quando um clique do mouse ocorre
void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    std::cout << "Mouse: (" << xpos << ", " << ypos << ")" << std::endl;
    ship.updatePosition(window);
}

// Função de callback para quando um clique do mouse ocorre
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        newBall.set_x(xpos);
        newBall.set_y(ypos);
        // Adicione uma nova bola nas coordenadas do clique do mouse
        std::cout << newBall.get_x() << std::endl;
        std::cout << newBall.get_y() << std::endl;
        std::cout << newBall.get_radius() << std::endl;
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Desenha a nave
    ship.draw();
    newBall.draw_asteroide();
}

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Erro ao inicializar o GLFW" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(1080, 1080, "Desenhar Bolas", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Erro ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // Inicializa GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Erro ao inicializar o GLEW" << std::endl;
        return -1;
    }

    // Configuração da taxa de quadros por segundo
    // glfwSwapInterval(1000); // Define a taxa de VSync para 1 (60 FPS)

    // Loop principal
    while (!glfwWindowShouldClose(window))
    {
        drawScene();
        glfwSwapBuffers(window);
        glfwPollEvents();
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Espera por aproximadamente 16 ms (60 FPS)
    }

    // Encerra o GLFW
    glfwTerminate();

    return 0;
}
