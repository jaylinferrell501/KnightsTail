#include "ShopKeeper.h"

#include <conio.h>

ShopKeeper::ShopKeeper()
{
	mSprite = 'S';
	mX = 5;
	mY = 5;
}

void ShopKeeper::NpcScreen()
{
	DrawNpc("ShopKeeper.txt");
	DrawNpcMenu("ShopKeeperMenu.txt");
	NpcMenuInput();
}

void ShopKeeper::NpcMenuInput()
{
	char input = _getch();

	if (input == 'y')
	{
		system("CLS");
		mIsOnShopScreen = true;
		mIsOnUpgrageScreen = false;
		DrawNpcShop("ShopKeeperShop.txt");
	}
	else if (input == 'b')
	{
		system("CLS");
		NpcScreen();
	}
}

void ShopKeeper::Update()
{
	// If a First boss is beaten update Shop Keeprs Shop (If i have time)
}
