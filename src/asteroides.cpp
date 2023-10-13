#include "../include/asteroides.hpp"
namespace spc
{
    // vertices estrela
    float v1[3] = {-0.5f, -0.5f, 0.0f};
    float v4[3] = {0.5f, -0.5f, 0.0f};
    float v5[3] = {0.0f, 0.5f, 0.0f};

    float v2[3] = {-0.5f, 0.1f, 0.0f};
    float v3[3] = {0.5f, 0.1f, 0.0f};
    float v6[3] = {0.0f, -0.8, 0.0f};

    float color1[3] = {1.0f, 1.0f, 1.0f}; // cor branca
    float color2[3] = {1.0f, 0.0f, 0.0f}; // cor vermelha

    // float x = -10.0f, y = 500.0f; // Coordenadas da estrela
    // float speed = 100.0f;         // Velocidade de movimento

    asteroide::~asteroide()
    {
    }

    void asteroide::draw_asteroide()
    {
        glPushMatrix();
        glTranslatef(pontoInicialX, pontoInicialY, 0.0f);
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

        // centro da estrela
        float center_s[3] = {0.0f, 0.0f, 0.0f};
        float center_d[3] = {pontoFinalX, pontoFinalY, 0.0f};
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
        glBegin(GL_LINES);                      // Define a linha da trajetoria
        glVertex2f(pontoInicialX, pontoFinalY); // Define o ponto de origem da linha
        glVertex2f(pontoFinalX, pontoFinalY);   // Define o ponto de destino da linha
        glEnd();
        glPopMatrix();
    }
    
    void asteroide::calculo_trajetoria(GLFWwindow *window)
    {
        int timeNow = glfwGetTime();
        float dt = (float)(timeNow - timeLastFrame) / 1000.0f;
        timeLastFrame = timeNow;

        int width, height;
        glfwGetWindowSize(window, &width, &height);
        
        direcaoX = pontoFinalX - pontoInicialX;
        direcaoY = pontoFinalY - pontoInicialY;

        float comprimento = sqrt((direcaoX * direcaoX) + (direcaoY * direcaoY));

        direcaoX /= comprimento;
        direcaoY /= comprimento;

        if (comprimento > 1.0f)
        {
            pontoInicialX += direcaoX * velocidade * dt;
            pontoInicialY += direcaoY * velocidade * dt;
        }
        if (comprimento < 1.0f)
        {
            std::random_device rd;
            std::mt19937 gen(rd());

            numAleatorioMax = width + 100;
            numAleatorioMin = width - numAleatorioMax;

            std::uniform_int_distribution<int> dis(numAleatorioMin, numAleatorioMax);
            pontoInicialX = dis(gen);
            pontoInicialY = 550;

            if (pontoInicialX < 0)
            {
                numAleatorioMax = width + 10;
                numAleatorioMin = width / 2;

                std::uniform_int_distribution<int> dis(numAleatorioMin, numAleatorioMax);
                pontoInicialY = dis(gen);
            }
        }
    }

}
