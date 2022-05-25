#include "LootBox.h"

LootBox::LootBox(int x, int y)
{
	mSprite = '+';
	mX = x;
	mY = y;
}

void LootBox::Update()
{
	if (mIsLooted)
	{
		mSprite = '.';
	}
}
