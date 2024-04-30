#include "timer.h"

namespace Tmpl8 {

	Timer::Timer(float durationInSeconds): duration(durationInSeconds), startTime(std::chrono::steady_clock::now())
    {
        // Initialize the start time to the current time
    }

    void Timer::start()
    {
        startTime = std::chrono::steady_clock::now();
    }

    bool Timer::hasExpired() const
    {
        auto elapsed = std::chrono::steady_clock::now() - startTime;
        float elapsedSeconds = std::chrono::duration<float>(elapsed).count();
        return elapsedSeconds >= duration;
    }

    float Timer::getRemainingTime() const {

        auto elapsed = std::chrono::steady_clock::now() - startTime;

        float elapsedSeconds = std::chrono::duration<float>(elapsed).count();

        return duration - elapsedSeconds;
    }
}