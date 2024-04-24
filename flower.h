#pragma once
#include "Bee.h"

#include <cstdlib> // For rand() and srand()
#include <ctime>

namespace Tmpl8
{
	const int NUM_FLOWERS = 5;
	const int NUM_OBSTACLES = 3;
	const int TIME_LIMIT = 30;  // Time limit in seconds

	// Flower types and their corresponding point values
	enum FlowerType {
		REGULAR_FLOWER = 1,
		RARE_FLOWER = 2,
		VERY_RARE_FLOWER = 3
	};

	class Flower
	{
	public:

		Flower();

		void SpawnRandomly(int screenWidth, int screenHeight);

		//Method to draw the flower
		void draw(Surface* screen);

		void interactWithBee(const Bee& bee);

		bool shouldDisappear() const;

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
	//Method to draw the bee
	//void flower::draw(Surface* screen);
}