#include "../include/nave.hpp"

namespace spc
{
    nave::nave() : rotationAngle(0.0f), rotationSpeed(0.5f) {
        // Inicializa as coordenadas do triângulo
        vertices[0] = -0.5f; vertices[1] = -0.5f; vertices[2] = 0.0f;
        vertices[3] = 0.5f;  vertices[4] = -0.5f; vertices[5] = 0.0f;
        vertices[6] = 0.0f;  vertices[7] = 0.5f;  vertices[8] = 0.0f;
    }
    
    void nave::draw()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(getX(), getY(), 0.0f);
        glScalef(0.1f, 0.1f, 0.1f);
        glRotatef(getRotationAngle(), 0.0f, 0.0f, 1.0f);

        // Desenha o triângulo
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_VERTEX_ARRAY);
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
}