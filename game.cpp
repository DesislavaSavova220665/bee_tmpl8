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

			}
			else if (rand() % 100 < 10) //modulo
			{
				manyFlowers[i] = new Flower(rareFlower2Sprite);
				manyFlowers[i]->setScale(30);
			}

			else
			{
				manyFlowers[i] = new Flower(flowerSprite);
				//manyFlowers[i]->setScale(25);
			}



			manyFlowers[i]->SpawnRandomly(screen->GetWidth(), screen->GetHeight());
		}

		//making the timer and adding the background with "game over" sprites
		timer.start(15.0f);
		ScreenBackground = new Sprite(new Surface("assets/grass.jpg"), 1);
		GameOver = new Sprite(new Surface("assets/gameover.png"), 1);
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


		float directionX = 0, directionY = 0;
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
			return;//terminating the program. everything after return; will not be executed.
		}


		// Drawing text
		screen->Print("Remaining Time:", 20, 20, 0);
		screen->Print((char*)remainingTime.c_str(), 115, 20, 0x00ff0000);
		screen->Print("SCORE:", 20, 30, 0);
		screen->Print((char*)addedScore.c_str(), 60, 30, 0x00ffffff);

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