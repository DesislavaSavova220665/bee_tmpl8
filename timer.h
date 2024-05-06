#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <chrono>
namespace Tmpl8 {

    class Timer {

    public:

        Timer();

        //method to start the timer
        void start(float durationInSeconds);

        //method to check if the timer has expired
        bool hasExpired() const;

        //method to get the remaining time (in seconds)
        float getRemainingTime() const;

    private:
        float duration;
        std::chrono::time_point<std::chrono::steady_clock> startTime;
    }; 
#endif // TIMER_H

}
