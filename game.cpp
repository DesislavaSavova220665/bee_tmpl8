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
		bee.setPosition(200, 300);

		auto flowerSprite = new Sprite(new Surface("assets/flowerasset.png"), 1);
		auto rareFlowerSprite = new Sprite(new Surface("assets/pinkFlower.png"), 1);
		auto rareFlower2Sprite = new Sprite(new Surface("assets/greenFlower.png"), 1);

		for (int i = 0; i < NUM_FLOWERS; i++)
		{
			if(rand() % 100 < 5)
			{
				manyFlowers[i] = new Flower(rareFlowerSprite);

			}
			else if(rand()%100 < 10) //modulo
			{
				manyFlowers[i] = new Flower(rareFlower2Sprite);
			}

			else
			{
				manyFlowers[i] = new Flower(flowerSprite);
			}



			manyFlowers[i]->SpawnRandomly(screen->GetWidth(), screen->GetHeight());
		}


		timer.start(15.0f);
		ScreenBackground = new Sprite(new Surface("assets/grass.jpg"), 1);
		GameOver = new Sprite(new Surface("assets/gameover.png"), 1);
	}

	
	void Game::Shutdown()
	{
		
	}


	void Game::Tick(float deltaTime)
	{



		// clear the graphics window
		screen->Clear(0);
		ScreenBackground->DrawScaled(0, 0, screen->GetWidth(),screen->GetHeight(), screen);
		

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

		auto addedScore = std::to_string(bee.score);
		auto remainingTime = std::to_string(timer.getRemainingTime());

		if (timer.hasExpired()) {
			//screen->Print("Time's up! Game Over!", screen->GetWidth() / 2 -50, screen->GetHeight() / 2, 0x00ff0000);
			GameOver->DrawScaled(150, 25, 500, 500, screen);
			screen->Print((char*)addedScore.c_str(), screen->GetWidth() / 2, screen->GetHeight() / 2 + 50, 0x00ffffff);
			return;//terminating the program. everything after return; will not be executed.
		}


		// Drawing text
		screen->Print("Remaining Time:", 20, 20, 0);
		screen->Print((char*)remainingTime.c_str(), 115, 20, 0x00ff0000);
		screen->Print("SCORE:", 20, 30, 0);
		screen->Print((char*)addedScore.c_str(), 60, 30, 0x00ffffff);

		// Logic
		// Move the bee with the adjusted position P.S. MAKE SURE TO ADD EVERY NEW THING YOU INCLUDE IN THE "BEE.H" HERE OTHERWISE THE CODE WON'T WORK
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