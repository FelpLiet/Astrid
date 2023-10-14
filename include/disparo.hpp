#pragma once 

#include "space.hpp"
#include <glm/glm.hpp>
#include <chrono>
#include <vector>
#include <algorithm>


namespace spc
{
    class disparo
    {
    private:
        glm::vec2 center;
        float radius = 1.0;
        std::chrono::time_point<std::chrono::steady_clock> timeCreated;
        std::chrono::time_point<std::chrono::steady_clock> pointTimerStart;
        bool drawPoint;
    public:
        disparo( glm::vec2 centerXY, std::chrono::time_point<std::chrono::steady_clock> timeCreated) : center(centerXY), timeCreated(timeCreated), pointTimerStart(timeCreated), drawPoint(true) {}
        ~disparo() {}

        // getters
        glm::vec2 getCenter() const { return center; }
        float getRadius() const { return radius; }
        std::chrono::time_point<std::chrono::steady_clock> getTimeCreated() const { return timeCreated; }
        std::chrono::time_point<std::chrono::steady_clock> getPointTimerStart() const { return pointTimerStart; }
        bool getDrawPoint() const { return drawPoint; }

        // setters
        void setCenter(glm::vec2 center) { this->center = center; }
        void setRadius(float radius) { this->radius = radius; }
        void setTimeCreated(std::chrono::time_point<std::chrono::steady_clock> timeCreated) { this->timeCreated = timeCreated; }
        void setPointTimerStart(std::chrono::time_point<std::chrono::steady_clock> pointTimerStart) { this->pointTimerStart = pointTimerStart; }
        
        // methods
        void draw(GLFWwindow *window);
        void updatePointStatus();
    };

    void verificaDisparos(std::vector<disparo> &disparos);
}