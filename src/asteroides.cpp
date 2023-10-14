#include "../include/asteroides.hpp"
namespace spc
{
    asteroide::asteroide()
    {
        x = 0.0f;
        y = 0.0f;
        velocidade = 10.0f;
        timeLastFrame = 0;
        pontoFinalX = 0.0f;
        pontoFinalY = -5.0f;
    }

    asteroide::~asteroide()
    {
    }

    void asteroide::draw_asteroide()
    {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glColor3fv(color1); // Define a cor do primeiro triângulo

        glBegin(GL_TRIANGLE_FAN); // Começa a definir o triângulo 1
        glVertex3fv(v1);
        glVertex3fv(v4);
        glVertex3fv(v5);
        glEnd();

        glBegin(GL_TRIANGLE_FAN); // Começa a definir o triângulo 2
        glVertex3fv(v2);
        glVertex3fv(v3);
        glVertex3fv(v6);
        glEnd();
        glPopMatrix();
    }

    void asteroide::draw_lines()
    {
        glPushMatrix();
        glColor3fv(color2); // Define a cor do ponto da trajetoria

        glPointSize(5.0f);
        glBegin(GL_POINTS); // Define o ponto da trajetoria
        glVertex2f(pontoFinalX, pontoFinalY);
        glEnd();

        glLineWidth(1.0f);
        glBegin(GL_LINES);                    // Define a linha da trajetoria
        glVertex2f(x, y);                     // Define o ponto de origem da linha
        glVertex2f(pontoFinalX, pontoFinalY); // Define o ponto de destino da linha
        glEnd();
        glPopMatrix();
    }

    void asteroide::calculo_trajetoria(GLFWwindow *window)
    {
        static double lastFrameTime = 0.0;
        double timeNow = glfwGetTime();
        float delta = (float)(timeNow - lastFrameTime);
        lastFrameTime = timeNow;

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        float direcaoX = pontoFinalX - x;
        float direcaoY = pontoFinalY - y;

        float length = sqrt((direcaoX * direcaoX) + (direcaoY * direcaoY));

        direcaoX /= length;
        direcaoY /= length;

        if (length > 1.0f)
        {
            x += direcaoX * velocidade * delta;
            y += direcaoY * velocidade * delta;
        }
        if (length < 1.0f)
        {
            std::random_device rd;
            std::mt19937 gen(rd());

            int numAleatorioMax = width / 55;
            int numAleatorioMin = -width / 55;

            std::uniform_int_distribution<int> dis(numAleatorioMin, numAleatorioMax);
            x = dis(gen);
            y = height / 50;

            if (x < -17 || x > 17)
            {
                numAleatorioMax = height / 50 / 2;
                numAleatorioMin = 0;

                std::uniform_int_distribution<int> dis(numAleatorioMin, numAleatorioMax);
                y = dis(gen);
            }
        }
    }

}
