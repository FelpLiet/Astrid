#include "../include/space.hpp"

int main() {
    // Inicializa GLFW
    if (!glfwInit()) {
        std::cerr << "Erro ao inicializar o GLFW" << std::endl;
        return -1;
    }

    // Configuração do GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Cria uma janela GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Pirâmide OpenGL", NULL, NULL);
    if (!window) {
        std::cerr << "Erro ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Torna o contexto da janela atual
    glfwMakeContextCurrent(window);

    // Inicializa GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Erro ao inicializar o GLEW" << std::endl;
        return -1;
    }

    // Loop principal
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Desenha a pirâmide
        spc::pyramid();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Encerra o GLFW
    glfwTerminate();

    return 0;
}
