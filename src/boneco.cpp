#include "../include/space.hpp"

void Pyramid() {
    glBegin(GL_TRIANGLE_STRIP);

    // Base da pirâmide
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, -0.5f, 0.5f);

    // Faces laterais
    glVertex3f(0.0f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.5f, 0.0f);

    glVertex3f(0.0f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.5f, 0.0f);

    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.5f, 0.0f);

    glEnd();
}
