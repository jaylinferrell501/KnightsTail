#include "GameObjects.h"

#include <iostream>

void GameObjects::Draw() const
{
	// Moves the cursor to the hero position.
	// The ANSI code is \033[Y;XH.

	// The grid array starts at indices 0,0.
	// The ANSI cursor starts at position 1,1.
	// So we have to add 1 to the mX and mY to get them to match up.
	std::cout << "\033[" << mY + 1 << ";" << mX + 1 << "H";
	std::cout << mSprite;
}
