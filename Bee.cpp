#include "Bee.h"


namespace Tmpl8
{

	Bee::Bee()
	{
		width = 70;
		height = 70;
		beeSprite = new Sprite(new Surface("assets/beasset.png"), 1);
		score = 0;
	}

	void Bee::move(int dirX, int dirY, int screenHeight, int screenWidth)
	{

		// Defining the bee's current position
		float beeX = position.x;
		float beeY = position.y;

		//currently calculating bees' position after  the movement
		float newBeeX = beeX + dirX * moveSpeed;
		float newBeeY = beeY + dirY * moveSpeed;

		//adjusting the new position to prevent crossing the top and bottom borders
		if (newBeeY < 0) {
			newBeeY = 0; // Prevent crossing the top border
		}

		if (newBeeY > screenHeight - height) {
			newBeeY = screenHeight - height; // Prevent crossing the bottom border
		}

		if (newBeeX < 0) {
			newBeeX = 0; // Prevent crossing the right border
		}

		if (newBeeX > screenWidth - width) {
			newBeeX = screenWidth - width; // Prevent crossing the left border
		}

		position.x = newBeeX;
		position.y = newBeeY;
	}

	void Bee::draw(Surface* screen)
	{
		beeSprite->DrawScaled(position.x, position.y, width, height, screen);
	}

	void Bee::addScore()
	{
		score = score + 1;
	}
}