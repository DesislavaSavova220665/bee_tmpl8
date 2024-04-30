#pragma once
#include <cassert>
#include <iostream>

#include "surface.h"
#include "template.h"

namespace Tmpl8
{
	
	const int GRID_SIZE = 10;  // Size of the grid (10x10)

	// Represents a point in the grid
	struct Point {
		float x = 0;
		float y = 0;

	};

	// Represents the Bee player
	class Bee {
	public:
		float moveSpeed = 7;

		Bee();

		//Constructing the customizable width and height
		Bee(float startX, float startY, int width = 20, int height = 20);

		// Method to move the Bee based on the input direction
		void move(int dirX, int dirY,int screenHeight, int screenWidth);

		//Method to draw the bee
		void Bee::draw(Surface* screen);


		// Method to get the Bee's current position
		Point getPosition() const {
			return position;
		}

		void setPosition(float posX, float posY)
		{
			position.x = posX;
			position.y = posY;
		}

		int getHeight() const {
			return height;
		}

		void setHeight(int newHeight) {
			//verifying that the new height is non-negative
			assert(newHeight >= 0, "Height must be above 0");

			// If the assertion passes, set the new height
			height = newHeight;
		}
		
		int getWidth() const {
			return width;
		}

		void setWidth(int newWidth) {
			//verifying that the new width is non-negative
			assert(newWidth >= 0 , "Width must be above 0");

			// If the assertion passes, set the new width
			width = newWidth;
		}
	private:
		Point position;  // Current position of the Bee
		Sprite* beeSprite;
		int height;
		int width;
	};
}
