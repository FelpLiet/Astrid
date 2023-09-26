#pragma once

#include "space.hpp"//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

namespace spc
{
    class nave
    {
    private:
        float x, y;          // Posição
        float width, height; // Tamanho
        float rotation;      // Ângulo de rotação

    public:
        nave(float x, float y, float width, float height) : x(x), y(y), width(width), height(height), rotation(0.0f) {}

        void draw()
        {
            glPushMatrix();
            glTranslatef(x + width / 2, y + height / 2, 0.0f);
            glRotatef(rotation, 0.0f, 0.0f, 1.0f); // Aplica a rotação em torno do centro da nave
            glTranslatef(-width / 2, -height / 2, 0.0f);

            glColor3f(1.0f, 1.0f, 1.0f); // Cor branca
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + width, y);
            glVertex2f(x + width, y + height);
            glVertex2f(x, y + height);
            glEnd();

            glPopMatrix();
        }

        void updateRotation(float mouseX, float mouseY)
        {
            // Calcula o ângulo de rotação em relação à posição do mouse
            float dx = mouseX - (x + width / 2);
            float dy = mouseY - (y + height / 2);
            rotation = atan2(dy, dx) * 180.0f / 3.14159265f;
        }
    };
}