#pragma once

#include "asteroides.hpp"
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
