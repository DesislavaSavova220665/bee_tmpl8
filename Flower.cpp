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

        // Manually enforcing screen bounds by ensuring new flower coordinates remain within the screen
        if (randomX < 0) {
            randomX = 0;
        }
        else if (randomX > screenWidth - m_width) {
            randomX = screenWidth - m_width;
        }

        if (randomY < 0) {
            randomY = 0;
        }
        else if (randomY > screenHeight - m_height) {
            randomY = screenHeight - m_height; // Ensure y doesn't go off the bottom side
        }
    
        position.x = randomX;
        position.y = randomY;

    }
	void Flower::draw(Surface* screen)
	{
		// flowerSprite->DrawScaled(position.x, position.y, m_width, m_height, screen);
		flowerSprite->Draw(screen, position.x, position.y);

	}

    void Flower::interactWithBee(Bee& bee, int screenWidth, int screenHeight)
	{

        // distance between bee and flower
        float dx = bee.getPosition().x - position.x;
        float dy = bee.getPosition().y - position.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        // Define a distance threshold for interaction
        float interactionDistance = 30.0f; // Adjust the distance as needed

        // Check if the distance between the bee and the flower is within the interaction distance
        if (distance < interactionDistance) {

            SpawnRandomly(screenWidth, screenHeight);

            bee.addScore();
            std::cout << bee.score << std::endl;
        }
    }
}
