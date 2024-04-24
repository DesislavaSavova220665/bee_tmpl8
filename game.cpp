#include "game.h"
#include "surface.h"

#include <conio.h>
#include <windows.h>


namespace Tmpl8
{
	Sprite beeSprite(new Surface("assets/beasset.png"), 1);

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		bee.setPosition(200, 200);

		initializeFlowers(flowers);  // Initialize the flowers
		initializeObstacles(obstacles);  // Initialize the obstacles


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

		// print something in the graphics window
		screen->Print("hello world", 2, 2, 0xffffff);

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

		if (GetAsyncKeyState('Z'))
		{
			bee.moveSpeed = 8;
		}

		if (GetAsyncKeyState('X'))
		{
			bee.moveSpeed = 2;
		}

		if (GetAsyncKeyState('R'))
		{
			bee.setPosition(200, 200);
		}

		if (GetAsyncKeyState('W'))
		{
			int newHeight = bee.getHeight();
			int targetHeight = 300;
			if (newHeight < targetHeight)
			{
				newHeight = newHeight + 1;
				bee.setHeight(newHeight);

			}
		}

		if (GetAsyncKeyState('S'))
		{
			int newWidth = bee.getWidth();
			int targetWidth = 300;
			if (newWidth < targetWidth)
			{
				 newWidth = newWidth + 1;
				bee.setWidth(newWidth);

			}
		}


		// [-1 ; 1]
	   // Move the bee with the adjusted position P.S. MAKE SURE TO ADD EVERY NEW THING YOU INCLUDE IN THE "BEE.H" HERE OTHERWISE THE CODE WON'T WORK
		bee.move(directionX, directionY, screen->GetHeight(), screen->GetWidth());

		bee.draw(screen);

		// move this lower thing into bee.draw()
		// Make width and height customizable

		// Collect flowers and calculate score
		score += collectFlowers(bee, flowers, collectedRegularFlowers, collectedRareFlowers, collectedVeryRareFlowers);

	}

}