#include "game.h"
#include "surface.h"
#include "timer.h"

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
		Timer myTimer(60.0f);
		myTimer.start();
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

		if (timer.hasExpired()) {
			// Handle game over scenario when the timer has run out
			std::cout << "Time's up! Game Over!" << std::endl;

			exit(0); // This will terminate the program; you can use other actions such as stopping the loop
			return;
		}

	   // Move the bee with the adjusted position P.S. MAKE SURE TO ADD EVERY NEW THING YOU INCLUDE IN THE "BEE.H" HERE OTHERWISE THE CODE WON'T WORK
		bee.move(directionX, directionY, screen->GetHeight(), screen->GetWidth());
		flower.interactWithBee(bee, screen->GetWidth(), screen->GetHeight());
		bee.draw(screen);
		flower.draw(screen);

		// Collect flowers and calculate score
		//score += collectFlowers(bee, flowers, collectedRegularFlowers, collectedRareFlowers, collectedVeryRareFlowers);

	}

}