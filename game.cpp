#include "game.h"
#include "surface.h"
#include "timer.h"

#include <conio.h>
#include <string>
#include <windows.h>

namespace Tmpl8
{
	void Game::Init()
	{

		//setting the position pf the bee
		bee.setPosition(200, 300);

		//adding the sprites of the 3 flower types
		auto flowerSprite = new Sprite(new Surface("assets/flowerasset.png"), 1);
		auto rareFlowerSprite = new Sprite(new Surface("assets/pinkFlower.png"), 1);
		auto rareFlower2Sprite = new Sprite(new Surface("assets/greenFlower.png"), 1);

		//maing one global code so it is more clear and less messy with logic for all 3 types of flowers with arrays "for" loop
		for (int i = 0; i < NUM_FLOWERS; i++)
		{
			if (rand() % 100 < 5)//modulo
			{
				manyFlowers[i] = new Flower(rareFlowerSprite);
				manyFlowers[i]->setScale(50);
				manyFlowers[i]->points = 2;

			}
			else if (rand() % 100 < 10) //modulo
			{
				manyFlowers[i] = new Flower(rareFlower2Sprite);
				manyFlowers[i]->setScale(35);
				manyFlowers[i]->points = 3;

			}

			else
			{
				manyFlowers[i] = new Flower(flowerSprite);
				//manyFlowers[i]->setScale(25);
				manyFlowers[i]->points = 1;
			}



			manyFlowers[i]->SpawnRandomly(screen->GetWidth(), screen->GetHeight());
		}

		//adding the background with "game over" sprites
		ScreenBackground = new Sprite(new Surface("assets/grass.jpg"), 1);
		GameOver = new Sprite(new Surface("assets/gameover.png"), 1);
		MainMenu = new Sprite(new Surface("assets/PurpleDaisyLogo.png"), 1);
	}


	void Game::Shutdown()
	{
		// if i have time i will do this one also
	}


	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);
		//drawing the background
		ScreenBackground->DrawScaled(0, 0, screen->GetWidth(), screen->GetHeight(), screen);

		//main menu creation and logic
		if (IsInMainMenu)
		{
			MainMenu->DrawScaled(140, 80, 500, 300, screen);
			screen->Print("Press SPACE to start the game!!!", 230, 380, 0);

			if (GetAsyncKeyState( VK_SPACE) < 0)
			{

				if (!previousSpaceState) 
				{
					previousSpaceState = true;
					timer.start(15.0f);
					IsInMainMenu = false;
					bee.score = 0;
				}
			}
			else previousSpaceState = false;

			return;//everything after return will be executed.
		}


		//controls for the bee
		//left arrow
		float directionX = 0, directionY = 0;
		if (GetAsyncKeyState(VK_LEFT))
		{
			directionX = -1;
		}

		//right arrow
		if (GetAsyncKeyState(VK_RIGHT))
		{
			directionX = 1;
		}

		//UP arrow
		if (GetAsyncKeyState(VK_UP))
		{
			directionY = -1;
		}

		//DOWN arrow
		if (GetAsyncKeyState(VK_DOWN))
		{
			directionY = 1;
		}

		// Bug: This doesn't work as expected because i tried to calculate how fast it goes diagonal and what is the distance between x and y vector(i cannot realy explain what i am doing i just know i made a mistake and now i dont see a difference...)
		if (abs(directionX) + abs(directionY) > 1)
		{
			float scalar = sqrt(directionX * directionX + directionY * directionY);
			directionX = scalar/ directionX;
			directionY = scalar/ directionY;
		}

		//adding the score and the remaining time 
		auto addedScore = std::to_string(bee.score);
		auto remainingTime = std::to_string(timer.getRemainingTime());

		//logic of the end screen
		if (timer.hasExpired()) {
			GameOver->DrawScaled(150, 25, 500, 500, screen);
			screen->Print((char*)addedScore.c_str(), screen->GetWidth() / 2, screen->GetHeight() / 2 + 150, 0x00ffffff);

			if (GetKeyState(VK_SPACE) < 0) 
            {
				if (!previousSpaceState) {
					previousSpaceState = true;
					//Key pressed
					IsInMainMenu = true;
				}
			}
			else previousSpaceState = false;
			return;//everything after return; will not be executed
		}


		// Drawing text
		screen->Print("Remaining Time:", 20, 20, 0);
		screen->Print((char*)remainingTime.c_str(), 190, 20, 0x00ff0000);
		screen->Print("SCORE:", 20, 40, 0);
		screen->Print((char*)addedScore.c_str(), 90, 40, 0x00ffffff);

		// Logic
		bee.move(directionX, directionY, screen->GetHeight(), screen->GetWidth());

		for (int i = 0; i < NUM_FLOWERS; i++)
		{
			manyFlowers[i]->interactWithBee(bee, screen->GetWidth(), screen->GetHeight());
		}


		//Drawing
		bee.draw(screen);

		for (int i = 0; i < NUM_FLOWERS; i++)
		{
			manyFlowers[i]->draw(screen);
		}

	}

}