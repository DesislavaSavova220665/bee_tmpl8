#include "game.h"
#include "surface.h"
#include "timer.h"

#include <conio.h>
#include <string>
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
		timer.start(15.0f);
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

		auto remainingTime = std::to_string(timer.getRemainingTime());

		if (timer.hasExpired()) {
			screen->Print("Time's up! Game Over!", screen->GetWidth() / 2 -50, screen->GetHeight() / 2, 0x00ff0000);
			return;//terminating the program. everything after return; will not be executed.
		}
		screen->Print((char*)remainingTime.c_str(), 720, 15, 0x00ff0000);
	   // Move the bee with the adjusted position P.S. MAKE SURE TO ADD EVERY NEW THING YOU INCLUDE IN THE "BEE.H" HERE OTHERWISE THE CODE WON'T WORK
		bee.move(directionX, directionY, screen->GetHeight(), screen->GetWidth());
		flower.interactWithBee(bee, screen->GetWidth(), screen->GetHeight());
		bee.draw(screen);
		flower.draw(screen);

		auto addedScore = std::to_string(bee.score);
		screen->Print((char*)addedScore.c_str(), 700,15, 0x00ffffff);
		//score += collectFlowers(bee, flowers, collectedRegularFlowers, collectedRareFlowers, collectedVeryRareFlowers);

	}

}