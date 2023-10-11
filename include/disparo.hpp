#pragma once 

#include "space.hpp"
#include <chrono>
#include <vector>
#include <algorithm>


namespace spc
{
    class disparo
    {
    private:
        float x, y;
        std::chrono::time_point<std::chrono::steady_clock> timeCreated;
        std::chrono::time_point<std::chrono::steady_clock> pointTimerStart;
        bool drawPoint;
    public:
        disparo(float x, float y, std::chrono::time_point<std::chrono::steady_clock> timeCreated) : x(x), y(y), timeCreated(timeCreated), pointTimerStart(timeCreated), drawPoint(true) {}
        ~disparo() {}

        float getX() const { return x; }
        float getY() const { return y; }
        std::chrono::time_point<std::chrono::steady_clock> getTimeCreated() const { return timeCreated; }
        std::chrono::time_point<std::chrono::steady_clock> getPointTimerStart() const { return pointTimerStart; }
        bool getDrawPoint() const { return drawPoint; }

        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
        void setTimeCreated(std::chrono::time_point<std::chrono::steady_clock> timeCreated) { this->timeCreated = timeCreated; }
        void setPointTimerStart(std::chrono::time_point<std::chrono::steady_clock> pointTimerStart) { this->pointTimerStart = pointTimerStart; }
        
        void disparoPosition(double mouseX, double mouseY);
        void updatePointStatus();
    };
}