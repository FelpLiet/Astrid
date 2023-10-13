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
        float pontoInicialX, pontoInicialY;
        float pontoFinalX, pontoFinalY;
        float velocidade;
        float direcaoX, direcaoY;;
        int numAleatorioMax, numAleatorioMin;
        int timeLastFrame = 0;

    public:
        asteroide(float xInicial, float yInicial, float xFinal, float yFinal, float vel,
        float dirX, float dirY, int max, int min) : pontoInicialX(xInicial),
        pontoInicialY(yInicial), pontoFinalX(xFinal), pontoFinalY(yFinal),velocidade(vel),
        direcaoX(dirX), direcaoY(dirY), numAleatorioMax(max), numAleatorioMin(min) {} 
        ~asteroide();
        
        float getPontoInicialX() { return pontoInicialX; }
        float getPontoInicialY() { return pontoInicialY; }
        float getPontoFinalX() { return pontoFinalX; }
        float getPontoFinalY() { return pontoFinalY; }
        float getVelocidade() {return velocidade; }
        float getDirecaoX() {return direcaoX; }
        float getDirecaoY() {return direcaoY; }
        int getNumAleatorioMax() {return numAleatorioMax; }
        int getNumAleatorioMin() {return numAleatorioMin; }

        void setPontoInicialX(float xInicial) { pontoInicialX = xInicial; }
        void setPontoInicialY(float yInicial) { pontoInicialY = yInicial; }
        void setPontoFinalX(float xFinal) { pontoFinalX = xFinal; }
        void setPontoFinalY(float yFinal) { pontoFinalY = yFinal; }
        void setVelocidade(float vel) { velocidade = vel; }
        void setDirecaoX(float dirX) {direcaoX = dirX; }
        void setDirecaoY(float dirY) {direcaoY = dirY; }
        void setNumAleatorioMax(int max) {numAleatorioMax = max; }
        void setNumAleatorioMin(int min) {numAleatorioMin = min; }
        
        void draw_asteroide();
        void draw_lines();
        void calculo_trajetoria(GLFWwindow *window);
        //void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    };

}
