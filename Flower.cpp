#include "flower.h"

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
}
