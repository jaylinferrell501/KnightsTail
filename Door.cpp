#include "Door.h"

#include <conio.h>
#include <iostream>

Door::Door(int x, int y)
{
	mSprite = '[';
	mX = x;
	mY = y;
}

void Door::Update()
{
	if (mIsUnlocked == true)
	{
		mSprite = '/';
	}
}
