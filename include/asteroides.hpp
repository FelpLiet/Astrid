#pragma once

#include "space.hpp"

namespace spc
{
    class asteroide
    {
    private:
        float x, y;
        float radius;

    public:
        asteroide(float x, float y) : x(x), y(y) {}
        ~asteroide();
        
        float get_radius() { return radius; }
        float get_x() { return x; }
        float get_y() { return y; }

        void set_x(float x) { this->x = x; }
        void set_y(float y) { this->y = y; }
        void set_radius(float radius) { this->radius = radius; }
        
        void draw_asteroide();
        //void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    };
    
}