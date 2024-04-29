#include "game.h"
#include "surface.h"

#include <conio.h>
#include <windows.h>

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		bee.setPosition(200, 200);
		flower.SpawnRandomly(screen->GetWidth(), screen->GetHeight());

		//int randomX = rand() % screenWidth;
		//int randomY = rand() % screenHeight;


		//flower.setPosX();
		//flower.setPosY();

	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}


	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{



		// clear the graphics window
		screen->Clear(0);

		//displayGrid(bee, flowers, obstacles);  // Display the grid

		// Display time remaining and current score
		//std::cout << "Time remaining: " << TIME_LIMIT - (std::time(nullptr) - startTime) << " seconds\n";
		//std::cout << "Score: " << score << "\n";

		int directionX = 0, directionY = 0;
		if (GetAsyncKeyState(VK_LEFT))
		{
			directionX = -1;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			directionX = 1;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			directionY = -1;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			directionY = 1;
		}

		//move
		/// int dirX -> 1, 0, -1,
		/// int dirY -> 1, 0, -1,
		/// int screenHeight -> 512 ,
		/// int screenWidth -> 800,
	   // Move the bee with the adjusted position P.S. MAKE SURE TO ADD EVERY NEW THING YOU INCLUDE IN THE "BEE.H" HERE OTHERWISE THE CODE WON'T WORK
		bee.move(directionX, directionY, screen->GetHeight(), screen->GetWidth());
		flower.interactWithBee(bee, screen->GetWidth(), screen->GetHeight());
		bee.draw(screen);
		flower.draw(screen);
		// Collect flowers and calculate score
		//score += collectFlowers(bee, flowers, collectedRegularFlowers, collectedRareFlowers, collectedVeryRareFlowers);

	}

}