#include "../include/nave.hpp"

namespace spc
{
    nave::nave() : rotationAngle(0.0f), rotationSpeed(0.5f)
    {
        // Inicializa as coordenadas do triângulo
        vertices[0] = -0.5f;
        vertices[1] = -0.5f;
        vertices[2] = 0.0f;
        vertices[3] = 0.5f;
        vertices[4] = -0.5f;
        vertices[5] = 0.0f;
        vertices[6] = 0.0f;
        vertices[7] = 0.5f;
        vertices[8] = 0.0f;
    }

    void nave::draw()
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f); // Cor azul
        glVertex2f(-0.025f, -0.025f);
        glVertex2f(0.025f, -0.025f);
        glVertex2f(0.0f, 0.025f);
        glEnd();
    }

    void nave::updatePosition(GLFWwindow *window)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        // Calcula a rotação com base na posição do mouse
        float centerX = static_cast<float>(width) / 2.0f;
        float centerY = static_cast<float>(height) / 2.0f;

        float deltaX = static_cast<float>(xpos) - centerX;
        float deltaY = centerY - static_cast<float>(ypos);

        setRotationAngle(540.0f + atan2(deltaY, deltaX) * (360.0f / static_cast<float>(M_PI)));

        // Ajusta a velocidade de rotação
        rotationAngle *= rotationSpeed;
    }

    void nave::disparoPosition(double drawSquare, double mouseX, double mouseY)
    {
        if (drawSquare)
        {
            float size = 0.09; 
            float x = (mouseX - 540.0) / 540.0;
            float y = (540.0 - mouseY) / 540.0;
            glColor3f(1.0f, 0.0f, 0.0f); 
            glBegin(GL_POLYGON);        
            for (int i = 0; i < 36; i++) 
            {
                float angle = 2.0 * M_PI * i / 36.0; 
                float xOffset = size * cos(angle);
                float yOffset = size * sin(angle);
                glVertex2f(x + xOffset, y + yOffset); 
            }
            glEnd();
        }
    }
}
