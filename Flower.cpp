#include "flower.h"
#include "Bee.h"
#include "cmath"


namespace Tmpl8
{

	Flower::Flower(Sprite* sprite)
	{
		m_width = 25;
		m_height = 25;
		position.x = 0;
		position.y = 0;
		flowerSprite = sprite;

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

		m_CurrentWidth = 0;
		m_CurrentHeight = 0;
	}
	void Flower::draw(Surface* screen)
	{
		if (m_CurrentWidth < m_width)
		{
			m_CurrentWidth++;
		}
		if (m_CurrentHeight < m_height)
		{
			m_CurrentHeight++;
		}

		flowerSprite->DrawScaled(position.x, position.y, m_CurrentWidth, m_CurrentHeight, screen);
		//flowerSprite->Draw(screen, position.x, position.y);

	}

	void Flower::interactWithBee(Bee& bee, int screenWidth, int screenHeight)
	{
		//you can only collect the flower if its fully grown
		if (!(m_CurrentWidth >= m_width && m_CurrentHeight >= m_height))
			return;


		//centering the position of the bee from top left
		float BeeCenterPositionX = bee.getPosition().x + (bee.getWidth() / 2);
		float BeeCenterPositionY = bee.getPosition().y + (bee.getHeight() / 2);

		//centering the position of the flower from top left
		float FlowerCenterPositionY = position.y + (m_height / 2);
		float FlowerCenterPositionX = position.x + (m_width / 2);

		// distance between bee and flower
		float dx = BeeCenterPositionX - FlowerCenterPositionX;
		float dy = BeeCenterPositionY - FlowerCenterPositionY;
		float distance = std::sqrt(dx * dx + dy * dy);

		float BeeRadius = bee.getHeight() / 2;
		float FlowerRadius = m_height / 2;

		//defining the distance threshold for interaction
		float interactionDistance = BeeRadius + FlowerRadius - 10;

		//checkiing if the distance between the bee and the flower is within the interaction distance:
		if (distance < interactionDistance) {



			SpawnRandomly(screenWidth, screenHeight);

			bee.addScore(points);
			std::cout << bee.score << std::endl;

		}
	}
}
