#pragma once

#include "disparo.hpp"
#include "nave.hpp"
#include "space.hpp"
#include "asteroides.hpp"
#include <map>
#include <chrono>

struct key
{
    bool curr;
    bool prev;
};

int initWindow();
void runAstrid();
void input(GLFWwindow *window);
void drawScene(GLFWwindow *window);
void reshapeWindow(GLFWwindow *window, int width, int height);
void update(GLFWwindow *window);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
void aspecRatio(GLFWwindow *window);
bool isAsteroideInsideDisparo(spc::asteroide &asteroide, std::vector<spc::disparo> &disparos);
bool isAsteroideInsideTerra(spc::asteroide &asteroide, spc::space &space);