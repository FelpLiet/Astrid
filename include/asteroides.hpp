#pragma once

#include "space.hpp"
#include <time.h>
#include <random>
#include <math.h>

namespace spc
{
    class asteroide
    {
    private:
        float x, y;
        float pontoFinalX, pontoFinalY;

        float v1[3] = {-0.5f, -0.5f, 0.0f};
        float v4[3] = {0.5f, -0.5f, 0.0f};
        float v5[3] = {0.0f, 0.5f, 0.0f};
        float v2[3] = {-0.5f, 0.1f, 0.0f};
        float v3[3] = {0.5f, 0.1f, 0.0f};
        float v6[3] = {0.0f, -0.8, 0.0f};

        float color1[3] = {1.0f, 1.0f, 1.0f}; // cor branca
        float color2[3] = {1.0f, 0.0f, 0.0f}; // cor vermelha

        float velocidade;

    public:
        asteroide();
        ~asteroide();

        float getX() { return x; }
        float getY() { return y; }
        float getPontoFinalX() { return pontoFinalX; }
        float getPontoFinalY() { return pontoFinalY; }
        float getVelocidade() { return velocidade; }

        void setPontoInicialX(float xInicial) { x = xInicial; }
        void setPontoInicialY(float yInicial) { y = yInicial; }
        void setPontoFinalX(float xFinal) { pontoFinalX = xFinal; }
        void setPontoFinalY(float yFinal) { pontoFinalY = yFinal; }
        void setVelocidade(float vel) { velocidade = vel; }

        void draw_asteroide();
        void draw_lines();
        void calculo_trajetoria(GLFWwindow *window);
        void reset();
        // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    };

}
