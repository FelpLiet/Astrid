#pragma once

#include "space.hpp" //
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

namespace spc
{
    class nave
    {
    private:
        float vertices[9];
        float rotationAngle;
        float rotationSpeed;
        double xpos, ypos;

        std::chrono::time_point<std::chrono::steady_clock> pointTimerStart;

    public:
        nave();
        nave(double x, double y)
        {
            this->xpos = x;
            this->ypos = y;
        }
        // Métodos getters para os atributos privados
        float *getVertices() { return vertices; }
        float getRotationAngle() const { return rotationAngle; }
        float getRotationSpeed() const { return rotationSpeed; }
        double getPosX() const { return xpos; }
        double getPosY() const { return ypos; }

        // Métodos setters para os atributos privados
        void setRotationAngle(float angle) { rotationAngle = angle; }
        void setRotationSpeed(float speed) { rotationSpeed = speed; }

        void draw();
        void updatePosition(GLFWwindow *window);
        void disparoPosition(double drawPoint, double mouseX, double mouseY);
        std::chrono::time_point<std::chrono::steady_clock> getPointTimerStart() const
        {
            return pointTimerStart;
        }
    };
}
