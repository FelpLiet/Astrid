#include "../include/nave.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

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

        int width, height, channels;
        unsigned char *image = stbi_load("../assets/Nave/Falcon.png", &width, &height, &channels, 0);

        if (image == NULL)
        {
            // Handle error
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        stbi_image_free(image);

        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        //glTranslatef(getX(), getY(), 0.0f);
        //glScalef(0.1f, 0.1f, 0.1f);
        glRotatef(getRotationAngle(), 0.0f, 0.0f, 1.0f);

        glEnable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(vertices[0], vertices[1], vertices[2]);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(vertices[3], vertices[4], vertices[5]);
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(vertices[6], vertices[7], vertices[8]);
        glEnd();
        glDisable(GL_TEXTURE_2D);
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
