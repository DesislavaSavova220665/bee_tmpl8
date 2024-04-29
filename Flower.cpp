#include "flower.h"
#include "Bee.h"
#include "cmath"
namespace Tmpl8
{

	Flower::Flower()
	{
		m_width = 100;
		m_height = 100;
		position.x = 0;
		position.y = 0;

		flowerSprite = new Sprite(new Surface("assets/flowerasset.png"), 1);
	}


	void Flower::SpawnRandomly(int screenWidth, int screenHeight)
	{
		float randomX = static_cast<float>(rand() % screenWidth);
		float randomY = static_cast<float>(rand() % screenHeight);

		position.x = randomX;
		position.y = randomY;
	}

	void Flower::draw(Surface* screen)
	{
		// flowerSprite->DrawScaled(position.x, position.y, m_width, m_height, screen);
		flowerSprite->Draw(screen, position.x, position.y);

	}

    void Flower::interactWithBee(const Bee& bee, int screenWidth, int screenHeight) {
        // Calculate the distance between the bee and the flower
        float dx = bee.getPosition().x - position.x;
        float dy = bee.getPosition().y - position.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        // Define a distance threshold for interaction
        float interactionDistance = 30.0f; // Adjust the distance as needed

        // Check if the distance between the bee and the flower is within the interaction distance
        if (distance < interactionDistance) {
            // Generate new random coordinates for the flower
            float newRandomX = static_cast<float>(rand() % screenWidth);
            float newRandomY = static_cast<float>(rand() % screenHeight);

            // Manually enforce bounds checking for x and y coordinates
            if (newRandomX < 0) {
                newRandomX = 0;
            }
            else if (newRandomX > screenWidth) {
                newRandomX = static_cast<float>(screenWidth);
            }

            if (newRandomY < 0) {
                newRandomY = 0;
            }
            else if (newRandomY > screenHeight) {
                newRandomY = static_cast<float>(screenHeight);
            }

            // Set the flower's position to the calculated random coordinates
            position.x = newRandomX;
            position.y = newRandomY;
        }
    }
}
