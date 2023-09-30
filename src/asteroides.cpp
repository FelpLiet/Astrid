#include "../include/asteroides.hpp"
namespace spc
{
    asteroide::~asteroide()
    {
    }

    void asteroide::draw_asteroide()
    {
        //glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f); // Cor vermelha
        glVertex2d(x, y);            // Centro da bola
        int numSegments = 100;
        for (int i = 0; i <= numSegments; ++i)
        {
            float theta = 2.0f * M_PI * float(i) / float(numSegments);
            float ballX = radius * cosf(theta);
            float ballY = radius * sinf(theta);
            glVertex2f(x + ballX, y + ballY);
        }
        glEnd();
    }
}