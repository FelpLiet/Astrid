#include "../include/disparo.hpp"

namespace spc
{
    void disparo::draw(GLFWwindow *window)
    {
        int WIDTH, HEIGHT;
        glfwGetWindowSize(window, &WIDTH, &HEIGHT);

        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.5f, 0.0f);
        // glVertex2f(x,y);

        // int numSegments = 50;
        // for (int i = 0; i <= numSegments; ++i)
        // {
        //     double theta = 2.0 * M_PI * static_cast<double>(i) / static_cast<double>(numSegments);
        //     double disX = x + 1.0 * std::cos(theta);
        //     double disY = y + 1.0 * std::sin(theta);
        //     glVertex2f(disX, disY);
        // }

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

        glEnd();
        glPopMatrix();
    }

    void disparo::updatePointStatus()
    {
        auto currentTime = std::chrono::steady_clock::now();
        if (drawPoint && std::chrono::duration_cast<std::chrono::seconds>(currentTime - pointTimerStart).count() >= 1)
        {
            drawPoint = false;
        }
    }

    void verificaDisparos(std::vector<disparo> &disparos)
    {
        auto currentTime = std::chrono::steady_clock::now();
        for (int i = 0; i < disparos.size(); i++)
        {
            if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - disparos[i].getTimeCreated()).count() >= 1)
            {
                // O disparo está ativo por mais de 1 segundo, remova-o
                disparos.erase(disparos.begin() + i);
            }
            else
            {
                // O disparo ainda está ativo, desenhe-o
                disparos[i].updatePointStatus();
            }
        }
    }

}