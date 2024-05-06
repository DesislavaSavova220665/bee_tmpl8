#include "timer.h"

namespace Tmpl8 {

    //constuctor
    Timer::Timer()
    {
	    
    }

    //method to show how to start the timer
    void Timer::start(float durationInSeconds)
    {
        duration = durationInSeconds;



        startTime = std::chrono::steady_clock::now();
    }

    //method to show how the timer expires after a certain amount of time
    bool Timer::hasExpired() const
    {
        auto elapsed = std::chrono::steady_clock::now() - startTime;
        float elapsedSeconds = std::chrono::duration<float>(elapsed).count();
        return elapsedSeconds >= duration;
    }

    //method to show how to get the remaining time
    float Timer::getRemainingTime() const {

        auto elapsed = std::chrono::steady_clock::now() - startTime;

        float elapsedSeconds = std::chrono::duration<float>(elapsed).count();

        return duration - elapsedSeconds;
    }
}