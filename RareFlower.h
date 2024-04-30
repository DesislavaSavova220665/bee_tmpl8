#pragma once
#include "flower.h"

namespace Tmpl8
{
    class RareFlower : public Flower {
    public:
        // Constructor
        RareFlower();

        // Method to spawn a rare flower at a random location
        void spawnRarely(int screenWidth, int screenHeight);

        // Method to interact with the bee
        void interactWithBee(const Bee& bee, int screenWidth, int screenHeight);

    private:

        float spawnProbability;
    };
}

