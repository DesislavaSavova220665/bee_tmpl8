#pragma once

#include "Bee.h"
#include "surface.h"
#include "flower.h"

namespace Tmpl8 {

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

	// Initialize the Bee and flowers at starting position (0, 0)
	Bee bee;
	Flower flower;

	int collectedRegularFlowers = 0;
	int collectedRareFlowers = 0;
	int collectedVeryRareFlowers = 0;
	int score = 0;  // Player's total score
};

}; // namespace Tmpl8