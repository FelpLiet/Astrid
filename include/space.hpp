#pragma once

#include "nave.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

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

    class estrela
    {
    private:
        glm::vec2 xy;

        float esVec1[3] = {-0.5f, -0.5f, 0.0f};
        float esVec4[3] = {0.5f, -0.5f, 0.0f};
        float esVec5[3] = {0.0f, 0.5f, 0.0f};
        float esVec2[3] = {-0.5f, 0.1f, 0.0f};
        float esVec3[3] = {0.5f, 0.1f, 0.0f};
        float esVec6[3] = {0.0f, -0.8, 0.0f};

        float colorB[3] = {1.0f, 1.0f, 1.0f};

    public:
        estrela(/* args */);
        ~estrela();

        void draw();
    };


    class space
    {
    private:
        terra spaceTerra;
        estrela spaceEstrela;
        std::vector<estrela> estrelas;

    public:
        space(/* args */);
        ~space();
        void draw(GLFWwindow *window);
        terra getTerra() const { return spaceTerra; }
        estrela getEstrela() const { return spaceEstrela; }
        std::vector<estrela> getEstrelas() const { return estrelas; }
        


        void drawEstrelas();

    };

}