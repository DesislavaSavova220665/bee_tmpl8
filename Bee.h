#pragma once
#include <cassert>
#include <iostream>

#include "surface.h"
#include "template.h"

namespace Tmpl8
{
	
	const int GRID_SIZE = 10;  // Size of the grid (10x10)
	const int NUM_FLOWERS = 5;  // Number of flowers on the grid
	const int NUM_OBSTACLES = 3;  // Number of obstacles on the grid
	const int TIME_LIMIT = 30;  // Time limit in seconds

	// Flower types and their corresponding point values
	enum FlowerType {
		REGULAR_FLOWER = 1,
		RARE_FLOWER = 2,
		VERY_RARE_FLOWER = 3
	};

	// Represents a point in the grid
	struct Point {
		float x = 0;
		float y = 0;
		FlowerType type = REGULAR_FLOWER;  // Type of flower (or none)
	};

	// Represents the Bee player
	class Bee {
	public:
		float moveSpeed = 7;

		Bee();

		//Constructing tje customizable width and height
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

	// Function to initialize flowers on the grid
	inline void initializeFlowers(Point flowers[]) {
		std::srand(std::time(0));
		for (int i = 0; i < NUM_FLOWERS; i++) {
			flowers[i].x = std::rand() % GRID_SIZE;
			flowers[i].y = std::rand() % GRID_SIZE;
			// Randomly assign flower type
			flowers[i].type = static_cast<FlowerType>((std::rand() % 3) + 1);
		}
	}

	// Function to initialize obstacles on the grid
	inline void initializeObstacles(Point obstacles[]) {
		std::srand(std::time(0));
		for (int i = 0; i < NUM_OBSTACLES; i++) {
			obstacles[i].x = std::rand() % GRID_SIZE;
			obstacles[i].y = std::rand() % GRID_SIZE;
		}
	}

	// Function to display the grid
	inline void displayGrid(const Bee& bee, const Point flowers[], const Point obstacles[]) {

		Point beePosition = bee.getPosition();
		for (int y = 0; y < GRID_SIZE; y++) {
			for (int x = 0; x < GRID_SIZE; x++) {
				// Check if it's the Bee's position
				if (beePosition.x == x && beePosition.y == y) {
					std::cout << 'B';  // Bee
				}
				// Check if there is an obstacle at this position
				else {
					bool isObstacle = false;
					for (int i = 0; i < NUM_OBSTACLES; i++) {
						if (obstacles[i].x == x && obstacles[i].y == y) {
							std::cout << 'O';  // Obstacle
							isObstacle = true;
							break;
						}
					}
					if (isObstacle) continue;  // Skip checking for flowers if obstacle

					// Check if there is a flower at this position
					bool isFlower = false;
					for (int i = 0; i < NUM_FLOWERS; i++) {
						if (flowers[i].x == x && flowers[i].y == y) {
							// Display flower based on its type
							switch (flowers[i].type) {
							case REGULAR_FLOWER:
								std::cout << 'f';  // Regular flower
								break;
							case RARE_FLOWER:
								std::cout << 'r';  // Rare flower
								break;
							case VERY_RARE_FLOWER:
								std::cout << 'v';  // Very rare flower
								break;
							}
							isFlower = true;
							break;
						}
					}
					if (!isFlower) {
						std::cout << '.';  // Empty space
					}
				}
			}
			std::cout << std::endl;
		}
	}

	// Function to collect flowers and calculate score
	inline int collectFlowers(Bee& bee, Point flowers[], int& collectedRegularFlowers, int& collectedRareFlowers, int& collectedVeryRareFlowers) {
		Point beePosition = bee.getPosition();
		int score = 0;

		for (int i = 0; i < NUM_FLOWERS; i++) {
			if (flowers[i].x == beePosition.x && flowers[i].y == beePosition.y) {
				// Calculate score based on flower type
				switch (flowers[i].type) {
				case REGULAR_FLOWER:
					score += REGULAR_FLOWER;
					collectedRegularFlowers++;
					break;
				case RARE_FLOWER:
					score += RARE_FLOWER;
					collectedRareFlowers++;
					break;
				case VERY_RARE_FLOWER:
					score += VERY_RARE_FLOWER;
					collectedVeryRareFlowers++;
					break;
				}
				// Move the collected flower out of the grid to mark it as collected
				flowers[i].x = -1;
				flowers[i].y = -1;
				flowers[i].type = static_cast<FlowerType>(0);  // Remove the flower
			}
		}
		return score;
	}

}
