#include "DungeonKeeper.h"

#include <cassert>
#include <conio.h>
#include <iostream>
#include <fstream>

DungeonKeeper::DungeonKeeper()
{
	mSprite = 'D';
	mX = 107;
	mY = 25;
}

void DungeonKeeper::Update()
{
	if(mpPlayer->GetX() + 1 == GetX() && mpPlayer->GetY() == GetY())
	{
		if (AllowExit())
		{
			system("CLS");
			std::ifstream winFile("WinScreen.txt", std::ios::in);
			assert(winFile.is_open());
			std::string word;
			getline(winFile, word);

			while (!winFile.eof())
			{
				std::cout << word << '\n';
				std::getline(winFile, word);
			}

			mpPlayer->SetIsHeroExploring(false);
		}
		else if (!AllowExit())
		{
			system("CLS");
			std::cout << "Enemies killed: " << mpPlayer->GetEnemyKillCount() << "/ " << "10\n";
			std::cout << "LootCollected: " << mpPlayer->GetLootCollected() << "/ " << "20\n";
			mpPlayer->SetX(GetX() - 2);
			std::cout << "Press any Key to Continue";
			_getch();
		}
	}
}

bool DungeonKeeper::AllowExit() const
{
	if(mpPlayer->GetEnemyKillCount() >= 10 && mpPlayer->GetLootCollected() == 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}

