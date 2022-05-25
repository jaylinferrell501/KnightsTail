#include "Enemy.h"

#include <cassert>
#include <conio.h>
#include <iostream>
#include <fstream>

void Enemy::Rewards() const
{
	DrawTextFile("Rewards.txt");
}

void Enemy::DrawTextFile(std::string newFile) const
{
	system("CLS");
	std::ifstream file(newFile, std::ios::in);
	assert(file.is_open());
	std::string word;
	getline(file, word);

	while (!file.eof())
	{
		std::cout << word << '\n';
		std::getline(file, word);
	}
}

Enemy::Enemy(int x, int y)
{
	mX = x;
	mY = y;
}

void Enemy::Attack()
{
	system("CLS");
	std::cout << "Your HP: " << mpPlayer->GetHealth() << " " << "VS" << " " << "Grunt HP " << mHealth << " Hp potion: " << mpPlayer->GetHpPotionCount() << " " << "Def Potion: " << mpPlayer->GetDefPotionCount() << "\n";
	std::ifstream gruntFile("Grunt.txt", std::ios::in);
	assert(gruntFile.is_open());
	std::string word;
	getline(gruntFile, word);

	while (!gruntFile.eof())
	{
		std::cout << word << '\n';
		std::getline(gruntFile, word);
	}

}

void Enemy::Battle()
{

	Attack();
	char input = _getch();

	while (mpPlayer->GetIsAlive() && mHealth > 0.f )
	{
		switch (input)
		{
		case 'a':
			mHealth -= mpPlayer->GetAttack();
			std::cout << "You Attack for " << mpPlayer->GetAttack() << "\n";
			mpPlayer->SetHealth(mpPlayer->GetHealth() + mpPlayer->GetDefense() - mAttack);
			std::cout << "Grunt Attacks you" << mAttack <<"\n";
			std::cout << "Press any key to continue" << "\n";
			break;
		case'i':
			std::cout << "Use Health Potion [h]\n";
			std::cout << "\n";
			std::cout << "Use Defense Potion [d]\n";

			char choice = _getch();
			if (choice == 'h')
			{
				if (mpPlayer->GetHpPotionCount() > 0)
				{
					mpPlayer->SetHealth(mpPlayer->GetHealth() + 10);
					mpPlayer->SetHpPotionCount(mpPlayer->GetHpPotionCount() - 1);
					std::cout << "You used a hp Potions";
					std::cout << "Press any key to continue" << "\n";

				}
				else
				{
					std::cout << "You Are OUT Of hp Potions";
					std::cout << "Press any key to continue" << "\n";

				}
				
			}
			else if (choice == 'd')
			{
				if (mpPlayer->GetDefPotionCount() > 0)
				{
					mpPlayer->SetDefense(mpPlayer->GetDefense() + 1);
					mpPlayer->SetDefPotionCount(mpPlayer->GetDefPotionCount() - 1);
					std::cout << "You used a def Potions";
					std::cout << "Press any key to continue" << "\n";

				}
				else
				{
					std::cout << "You Are OUT Of Def Potions";
					std::cout << "Press any key to continue" << "\n";

				}
			}
		}

		if (mpPlayer->GetHealth() <= 0.f)
		{
			mpPlayer->SetIsHeroExploring(false);
			DrawTextFile("GameOver.txt");
			mpPlayer->SetIsAlive(false);
		}
		else if(mHealth <= 0.f)
		{
			mpPlayer->SetX(mpPlayer->GetX() - 1);
			mpPlayer->SetGold(mpPlayer->GetGold() + 20);
			mpPlayer->SetEnemyKillCount(mpPlayer->GetEnemyKillCount() + 1);
			Rewards();
		}
		input = _getch();
		Attack();
	}
}

void Enemy::Update()
{
}
