#include "BlackSmith.h"

#include <conio.h>

std::string gShopFile = "BlackSmithsShop.txt";

void BlackSmith::NpcScreen()
{
	DrawNpc("BlackSmiths.txt");
	DrawNpcMenu("BlackSmithsMenu.txt");
	NpcMenuInput();
}

void BlackSmith::NpcMenuInput()
{
	char input = _getch();

	if (input == 's')
	{
		system("CLS");
		mIsOnShopScreen = true;
		mIsOnUpgrageScreen = false;
		DrawNpcShop(gShopFile);
	}
	else if(input == 'u')
	{
		system("CLS");
		mIsOnUpgrageScreen = true;
		mIsOnShopScreen = false;
		DrawNpcUpgradeOptions("BlackSmithUpgradeOptions.txt");
	}

}

BlackSmith::BlackSmith()
{
	mSprite = 'B';
	mX = 10;
	mY = 3;
}

void BlackSmith::Update()
{
	if (!mHasShield && !mHasSword && !mHasArmor)
	{
		gShopFile = "BlackSmithsSoldOut.txt";
	}
	else if (!mHasShield && !mHasSword)
	{
		gShopFile = "BlackSmithsShopV4.txt";
	}
	else if(!mHasShield && !mHasArmor)
	{
		gShopFile = "BlackSmithsShopV5.txt";
	}
	else if (!mHasSword && !mHasArmor)
	{
		gShopFile = "BlackSmithsShopV6.txt";
	}
	else if (!mHasSword)
	{
		gShopFile = "BlackSmithsShopV2.txt";
	}
	else if (!mHasShield)
	{
		gShopFile = "BlackSmithsShopV3.txt";
	}
	
}
// fix armor posibillty
