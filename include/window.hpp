#pragma once

#include "asteroides.hpp"
#include "disparo.hpp"
#include "nave.hpp"
#include "space.hpp"
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