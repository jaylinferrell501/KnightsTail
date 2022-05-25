#include "Player.h"

#include <cassert>
#include <iostream>
#include "conio.h"
#include "string"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <time.h>

std::string gInventoryFile = "EmptyBackpack.txt";

Player::Player()
	:GameObjects()
{
	mSprite = '@';
	mX = 10;
	mY = 5;
}

void Player::Update()
{
	/// <summary>
	/// Don't move the hero, instead,
	///	find out where they want to go,
	///	what is thier new position.
	/// </summary>
	int newX = mX;
	int newY = mY;

	const char aKey = _getch();

	switch (aKey)
	{
	case 'a':
		--newX;
		break;
	case 'd':
		++newX;
		for (size_t door = 0; door < doors.size(); door++)
		{
			if (GetX() + 1 == doors[door]->GetX() && GetY() == doors[door]->GetY())
			{
				if (!doors[door]->GetIsUnlocked())
				{
					--newX;
				}
			}
		}
		break;
	case 's':
		++newY;
		break;
	case 'w':
		--newY;
		break;
	case 'q':
		system("CLS");
		SetIsHeroExploring(false);
		break;
	case 'i':
		system("CLS");
		HeroStatsAndInventory();
		break;
	case 'e':
		// loot InterAction
		srand(time(nullptr));
		for (size_t i = 0; i < mpLoot.size(); i++)
		{
			if (GetX() == mpLoot[i]->GetX() && GetY() == mpLoot[i]->GetY())
			{
				mGold += 1 + rand() % 50;
				mLockPicks += rand() % 2;
				mLootCollected += 1;
				mpLoot[i]->SetIsLooted(true);
				mpLoot.erase(mpLoot.begin() + i);
				looted();
			}
		}
		// Door InterAction
		for (size_t door = 0; door < doors.size(); door++)
		{
			if (doors[door]->GetX() == GetX() + 1 && doors[door]->GetY() == GetY())
			{
				if (mLockPicks > 0)
				{
					mLockPicks -= 1;
					doors[door]->SetUnlocked(true);
				}
			}
		}
		// Black Smith InterAction
		if(mpBlackSmith->GetX() == GetX() && mpBlackSmith->GetY() == GetY() - 1)
		{
			system("CLS");
			std::cout << "Gold: " << mGold << "   " << "Attack: " << mAttack << "   " << "Defense: " << mDefense << "\n";
			std::cout << "\n";
			mpBlackSmith->NpcScreen();

			if (mpBlackSmith->IsOnShopScreen())
			{
				char input = _getch();
				if (input == 's')
				{
					if (mpBlackSmith->HasSword())
					{
						if (mGold >= 20)
						{
							mHasSword = true;
							mAttack += 10;
							mGold -= 20;
							mpBlackSmith->SetHasSword(false);
						}
					}
				}
				else if (input == 'h')
				{
					if (mpBlackSmith->HasShield())
					{
						if (mGold >= 40)
						{
							mHasShield = true;
							mDefense += 4;
							mGold -= 40;
							mpBlackSmith->SetHasShield(false);

						}

					}
				}
				else if (input == 'a')
				{
					if (mpBlackSmith->HasArmor())
					{
						if (mGold >= 60)
						{
							mHasArmor = true;
							mHealth += 50;
							mGold -= 60;
							mpBlackSmith->SetHasArmor(false);

						}

					}
				}
				else if (input == 'b')
				{
					system("CLS");
					mpBlackSmith->NpcScreen();

				}
			}
			else if (mpBlackSmith->IsOnUpgradeScreen())
			{
				char input = _getch();

				if (input == 's' && mHasSword)
				{
					if (mGold >= 20)
					{
						mAttack += 5;
						mGold -= 20;
					}
				}
				else if (input == 'h' && mHasShield)
				{
					if (mGold >= 20)
					{
						mDefense += 3;
						mGold -= 20;
					}
				}
				else if (input == 'a' && mHasArmor)
				{
					if (mGold >= 20)
					{
						mHealth += 10;
						mGold -= 20;
					}
				}
				else if (input == 'b')
				{
					system("CLS");
					mpBlackSmith->NpcScreen();
				}
			}
		}
		// ShopKeeper
		else if(mpShopKeeper->GetX() == GetX() - 1 && mpShopKeeper->GetY() == GetY())
		{
			system("CLS");
			std::cout << "Gold: " << mGold;
			std::cout << "\n";
			mpShopKeeper->NpcScreen();

			if (mpShopKeeper->IsOnShopScreen())
			{
				char input = _getch();
				if (input == 's')
				{
					if (mGold >= 20)
					{
						mHealthPotionCount += 1;
						mGold -= 20;
					}
				}
				else if (input == 'h')
				{
					if (mGold >= 20)
					{
						mDefensePotionCount += 1;
						mGold -= 20;
					}
				}
			}
		}
		// Guide
		else if (mpGuide->GetX() == GetX() && mpGuide->GetY() == GetY() + 1)
		{
			system("CLS");
			mpGuide->NpcScreen();
		}
		break;
	default:;
	}

	// Once we know where they want to go,
	// if there's no wall, then go there.
	if (!mpDungeon->IsWall(newX, newY))
	{
		mX = newX;
		mY = newY;
	}

	if (mHasArmor)
	{
		mArmor = "Armor";
	}

	// Updates inventory
	if (mHasSword && mHasShield)
	{
		gInventoryFile = "BackPackWithSwordAndShield.txt";
	}
	else if(mHasSword)
	{
		gInventoryFile = "BackPackWithSword.txt";
	}
	else if(mHasShield)
	{
		gInventoryFile = "BlackPackWithShield.txt";
	}
}

void Player::HeroStatsAndInventory() const
{
	std::ifstream menuFile(gInventoryFile, std::ios::in);
	assert(menuFile.is_open());
	std::string word;
	getline(menuFile, word);

	while (!menuFile.eof())
	{
		std::cout << word << '\n';
		std::getline(menuFile, word);
	}
	std::cout << "\n";
	std::cout << "Health: " << mHealth << "\n";
	std::cout << "\n";
	std::cout << "Lock picks: " << mLockPicks << "\n";
	std::cout << "\n";
	std::cout << "Gold: " << mGold << "\n";
	std::cout << "\n";
	std::cout << "Attack: " << mAttack << "\n";
	std::cout << "\n";
	std::cout << "Defense: " << mDefense << "\n";
	std::cout << "\n";
	std::cout << "Enemies Killed: " << mEnemyKillCount << "\n";
	std::cout << "\n";
	std::cout << "Loot Collected: " << mLootCollected << "\n";
	std::cout << "\n";
	std::cout << "Armor: " << mArmor << "\n";
	std::cout << "\n";
	std::cout << "Health Potion: " << mHealthPotionCount << "\n";
	std::cout << "\n";
	std::cout << "Defense Potion: " << mDefensePotionCount << "\n";
	std::cout << "\n";
	std::cout << "Press any key to go back";

	_getch();
}

void Player::looted()
{
	system("CLS");
	std::cout << "You now have " << mGold << " Gold\n";
	std::cout << "You now have " << mLockPicks << " lock picks\n";
	std::cout << "\n";
	std::cout << "Press any key to continue";
	_getch();
}
