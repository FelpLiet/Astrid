#pragma once

#include "space.hpp" //
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
        float vertices[9];  
        float rotationAngle;
        float rotationSpeed;

    public:
        nave();
        // Métodos getters para os atributos privados
        float *getVertices() { return vertices; }
        float getRotationAngle() const { return rotationAngle; }
        float getRotationSpeed() const { return rotationSpeed; }

        // Métodos setters para os atributos privados
        void setRotationAngle(float angle) { rotationAngle = angle; }
        void setRotationSpeed(float speed) { rotationSpeed = speed; }
        
        void draw();
        void updatePosition(GLFWwindow *window);
   
};
}