#pragma once

#include "Bee.h"
#include "surface.h"
#include "flower.h"
#include "timer.h"

namespace Tmpl8 {

	constexpr int NUM_FLOWERS = 100;

class Surface;

class Game
{
public:
	Game() = default;

	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
private:
	Surface* screen;
	Bee bee;
	Flower* manyFlowers[NUM_FLOWERS];
	Timer timer;
	Sprite* ScreenBackground;
	Sprite* GameOver;
	Sprite* MainMenu;
	bool IsInMainMenu = true; 
	bool previousSpaceState = false;
};

}; // namespace Tmpl8