#include "../include/space.hpp"

namespace spc
{
    space::space(/* args */)
    {
        for(int i = 0; i < 100; i++){
            estrela estrelaNova;
            estrelas.push_back(estrelaNova);
        }
    }

    space::~space()
    {
    }

    void space::draw(GLFWwindow *window)
    {
        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.5f, 1.0f); // Blue color for the Earth
        glVertex2f(0, -9);           // Center of the Earth

        int numSegments = 50;
        for (int i = 0; i <= numSegments; ++i)
        {
            double theta = 2.0 * M_PI * static_cast<double>(i) / static_cast<double>(numSegments);
            double terraX = 5.0 * std::cos(theta);
            double terraY = -9 + 5.0 * std::sin(theta);
            glVertex2f(terraX, terraY);
        }

        glEnd();
        glPopMatrix();
    }

    void space::drawEstrelas(){
        for(auto estrela : estrelas){
            estrela.draw();
        }
    }

    void terra::draw()
    {
        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(center.x, center.y);
        for (int i = 0; i <= 360; ++i)
        {
            float angle = glm::radians(static_cast<float>(i));
            float x = center.x + radius * std::cos(angle);
            float y = center.y + radius * std::sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
    }

    estrela::estrela(/* args */)
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> dis(-18, 18);
        xy.x = dis(gen);
        xy.y = dis(gen);
    }

    estrela::~estrela()
    {
    }

    void estrela::draw()
    {
        glPushMatrix();
        glTranslatef(xy.x, xy.y, 0.0f);
        glScalef(0.1f, 0.1f, 0.0f);
        glColor3fv(colorB);

        glBegin(GL_TRIANGLE_FAN);
        glVertex3fv(esVec1);
        glVertex3fv(esVec4);
        glVertex3fv(esVec5);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glVertex3fv(esVec2);
        glVertex3fv(esVec3);
        glVertex3fv(esVec6);
        glEnd();
        glPopMatrix();
    }

}
