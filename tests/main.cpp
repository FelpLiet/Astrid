#include "../include/space.hpp"

// Crie uma nave com posição (400, 300) e tamanho (0.1, 0.1)
spc::nave ship(400.0f, 300.0f, 0.1f, 0.1f);

// Função de callback para quando um clique do mouse ocorre
void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    // Atualiza a rotação da nave com base na posição do mouse
    ship.updateRotation((float)xpos, (float)ypos);
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

    // Inicializa GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Erro ao inicializar o GLEW" << std::endl;
        return -1;
    }

    // Loop principal
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Ball ball(0.0f, 0.0f, 1.0f);
        // ball.draw();
        ship.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Encerra o GLFW
    glfwTerminate();

    return 0;
}
