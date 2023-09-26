#pragma once

#include "space.hpp"

namespace spc
{
    class asteroide
    {
    private:
        double x, y;
        float radius;

    public:
        asteroide(double x, double y, float radius) : x(x), y(y), radius(radius) {}
        ~asteroide();
        
        float get_radius() { return radius; }
        float get_x() { return x; }
        float get_y() { return y; }
        
        void draw_asteroide();
        //void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    };
    
}