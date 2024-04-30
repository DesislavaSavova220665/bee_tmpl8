#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <chrono>
namespace Tmpl8 {

    class Timer {

    public:

        Timer();

        // Constructor to initialize the timer with a specific duration (in seconds)
        Timer(float durationInSeconds);

        // Method to start the timer
        void start();

        // Method to check if the timer has expired
        bool hasExpired() const;

        // Method to get the remaining time (in seconds)
        float getRemainingTime() const;

    private:
        float duration;
        std::chrono::time_point<std::chrono::steady_clock> startTime;
    }; 
#endif // TIMER_H

}
