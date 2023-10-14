#pragma once

#include "nave.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <cmath>

namespace spc
{
    class terra
    {
    private:
        glm::vec2 center;
        float radius = 6.0;
    public:
        terra() : center(glm::vec2(0.0f, -10.0f)) {}
        ~terra() {}

        // getters
        glm::vec2 getCenter() const { return center; }
        float getRadius() const { return radius; }

        // setters
        void setCenter(glm::vec2 center) { this->center = center; }
        void setRadius(float radius) { this->radius = radius; }
        
        // methods
        void draw();
    };
    
     class space
    {
    private:
        terra spaceTerra;
    public:
        space(/* args */);
        ~space();
        void draw(GLFWwindow *window);
        terra getTerra() const { return spaceTerra; }
    };
}