#pragma once
#include "Bee.h"

namespace Tmpl8
{

	// Flower types and their corresponding point values
	enum FlowerType {
		REGULAR_FLOWER = 3,
		RARE_FLOWER = 2
	};

	class Flower
	{
	public:
		//public members
		Flower() = delete;
		Flower(Sprite* sprite);

		//method to spawn randomly
		void SpawnRandomly(int screenWidth, int screenHeight);

		//method to interact with the bee
		void interactWithBee(Bee& bee, int screenWidth, int screenHeight);

		//Method to draw the flower
		void draw(Surface* screen);

		//getting and setting position
		Point getPosition() const { return position; }

		void setPosition(Point p) { position = p; }
		void setPosition(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

		// Setters for flower position
		void setPosX(float x) { position.x = x; }
		void setPosY(float y) { position.y = y; }
		void setScale(int scale) { m_height = scale; m_width = scale; }
		int points;
	private:
		//private members
		Point position;
		int m_height;
		int m_width;

		int m_CurrentHeight;
		int m_CurrentWidth;

		bool visible;
		Sprite* flowerSprite;
	};
}