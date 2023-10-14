#include "../include/space.hpp"

namespace spc
{
    space::space(/* args */)
    {
    }

    space::~space()
    {
    }

    void space::draw(GLFWwindow *window)
    {
        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.5f, 1.0f); // Blue color for the Earth
        glVertex2f(0, -9);           // Center of the Earth

        int numSegments = 50;
        for (int i = 0; i <= numSegments; ++i)
        {
            double theta = 2.0 * M_PI * static_cast<double>(i) / static_cast<double>(numSegments);
            double terraX = 5.0 * std::cos(theta);
            double terraY = -9 + 5.0 * std::sin(theta);
            glVertex2f(terraX, terraY);
        }

        glEnd();
        glPopMatrix();
    }

    void terra::draw()
    {
        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(center.x, center.y);
        for (int i = 0; i <= 360; ++i)
        {
            float angle = glm::radians(static_cast<float>(i));
            float x = center.x + radius * std::cos(angle);
            float y = center.y + radius * std::sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
    }

}
