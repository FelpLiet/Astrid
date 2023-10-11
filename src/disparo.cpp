#include "../include/disparo.hpp"

namespace spc
{
    void disparo::disparoPosition(double mouseX, double mouseY)
    {
        glPushMatrix();
        float size = 0.09;
        float x = (mouseX - 540.0) / 540.0;
        float y = (540.0 - mouseY) / 540.0;
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 36; i++)
        {
            float angle = 2.0 * M_PI * i / 36.0;
            float xOffset = size * cos(angle);
            float yOffset = size * sin(angle);
            glVertex2f(x + xOffset, y + yOffset);
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

}