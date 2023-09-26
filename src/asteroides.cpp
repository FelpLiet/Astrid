#include "../include/asteroides.hpp"
namespace spc
{

    std::vector<asteroide> asteroide_vec;

    void draw_asteroide()
    {
        // glBegin(GL_TRIANGLE_FAN);
        // glColor3f(1.0f, 0.0f, 0.0f); // Cor vermelha
        // glVertex2d(x, y);            // Centro da bola
        // int numSegments = 100;
        // for (int i = 0; i <= numSegments; ++i)
        // {
        //     float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        //     float ballX = radius * cosf(theta);
        //     float ballY = radius * sinf(theta);
        //     glVertex2f(x + ballX, y + ballY);
        // }
        // glEnd();
    }

    // Função de callback para quando um clique do mouse ocorre
    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);

            // Adicione uma nova bola nas coordenadas do clique do mouse
            spc::asteroide newBall(xpos, ypos, 20.0f); // Raio da bola é 20.0f
            asteroide_vec.push_back(newBall);
        }
    }

}