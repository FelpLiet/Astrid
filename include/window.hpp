#pragma once

#include "asteroides.hpp"
#include "nave.hpp"
#include "space.hpp"
#include <map>
#include <chrono>

#define WIDTH 1280
#define HEIGHT 720

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
