#pragma once
#include "Bee.h"

#include <cstdlib> // For rand() and srand()
#include <ctime>

namespace Tmpl8
{
	const int NUM_FLOWERS = 5;
	const int NUM_OBSTACLES = 3;
	const int TIME_LIMIT = 15;  // Time limit in seconds

	// Flower types and their corresponding point values
	enum FlowerType {
		REGULAR_FLOWER = 3,
		RARE_FLOWER = 2
	};

	class Flower
	{
	public:

		Flower() = delete;
		Flower(Sprite* sprite);

		void SpawnRandomly(int screenWidth, int screenHeight);

		void interactWithBee(Bee& bee, int screenWidth, int screenHeight);

		//Method to draw the flower
		void draw(Surface* screen);

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

	private:
		// Private members
		Point position;
		int m_height;
		int m_width;
		bool visible;
		Sprite* flowerSprite;
	};
	//void flower::draw(Surface* screen);
}