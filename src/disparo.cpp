#include "../include/disparo.hpp"

namespace spc
{
    void disparo::draw(GLFWwindow *window)
    {
        int WIDTH, HEIGHT;
        glfwGetWindowSize(window, &WIDTH, &HEIGHT);
        WIDTH /= 2;
        HEIGHT /= 2;
        glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        float size = 0.09;
        float newX = (x - WIDTH) / WIDTH;
        float newY = (HEIGHT - y) / HEIGHT;
        glBegin(GL_POLYGON);
        for (int i = 0; i < 36; i++)
        {
            float angle = 2.0 * M_PI * i / 36.0;
            float xOffset = size * cos(angle);
            float yOffset = size * sin(angle);
            glVertex2f(newX + xOffset, newY + yOffset);
        }
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