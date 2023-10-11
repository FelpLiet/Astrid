#include "../include/asteroides.hpp"
namespace spc
{
    // vertices estrela
    float v1[3] = {-2.0f, 0.5f, 0.0f};
    float v2[3] = {-35.0f, -22.5f, 0.0f};
    float v3[3] = {0.0f, 42.5f, 0.0f};
    float v4[3] = {0.0f, -0.5f, 0.0f};
    float v5[3] = {2.0f, 0.5f, 0.0f};
    float v6[3] = {35.0f, -22.5f, 0.0f};

    float color1[3] = {1.0f, 0.0f, 0.0f}; // cor vermelha

    // centro da estrela
    float px = {250}, py = {100}; // Coordenadas do ponto de destino
    float center_s[3] = {0.0f, 0.0f, 0.0f};
    float center_d[3] = {px, py, 0.0f};

    float x = -10.0f, y = 500.0f; // Coordenadas da estrela
    float speed = 100.0f;         // Velocidade de movimento

    asteroide::~asteroide()
    {
    }

    void asteroide::draw_asteroide()
    {   
        glPushMatrix();
        glColor3fv(color1); // Define a cor do primeiro triângulo

        glBegin(GL_TRIANGLE_FAN); // Começa a definir um triângulo
        glVertex3fv(v1);
        glVertex3fv(v4);
        glVertex3fv(v5);
        glEnd();
        glPopMatrix();
    }
}