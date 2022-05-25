#include "Game.h"

#include <cassert>
#include <conio.h>
#include <iostream>
#include <fstream>


void Game::StartGame()
{
	std::ifstream menuFile("TitleScreen.txt", std::ios::in);
	assert(menuFile.is_open());

	std::string word;

	getline(menuFile, word);              // need to #include <string>

	// loop until you hit the end-of-file (EOF) character
	while (!menuFile.eof())   // returns true if and when the end of the file was reached on the previous read attempt
	{
		std::cout << word << '\n';   // print that line
		std::getline(menuFile, word);         // try to grab another
	}

	MenuInput();
}

void Game::MenuInput()
{
	const char input = _getch();
	while (mpPlayer->GetIsHeroExploring())
	{
		if (input == 'p')
		{
			PlayGame();
		}
		else if (input == 'q')
		{
			mpPlayer->SetIsHeroExploring(false);
		}
		else
		{
			std::cout << "Invalid input\n";
			MenuInput();
		}
	}
	return;
}

void Game::PlayGame()
{

	while (mpPlayer->GetIsHeroExploring())
	{
		std::cout << "\033[1H"; // Tell cursor to reset

		DrawGameObject();

		UpdateGameObject();

	}
}

void Game::SetGameObject()
{
	mpPlayer->SetDungeon(mpDungeon);

	for (auto& enemy : enemies)
	{
		enemy.SetPlayer(mpPlayer);
		enemy.SetDungeon(mpDungeon);
	}

	for (auto& enemy2ndSet : enemies2ndSet)
	{
		enemy2ndSet.SetPlayer(mpPlayer);
		enemy2ndSet.SetDungeon(mpDungeon);
	}

	for (auto& loot : mpLootBoxs)
	{
		loot->SetDungeon(mpDungeon);
	}
	mpPlayer->SetLoot(mpLootBoxs);

	for (auto& door : doors)
	{
		door->SetDungeon(mpDungeon);
	}
	mpPlayer->SetDoor(doors);

	mpBlackSmith->SetDungeon(mpDungeon);
	mpPlayer->SetBlackSmith(mpBlackSmith);

	mpShopKeeper->SetDungeon(mpDungeon);
	mpPlayer->SetShopKeeper(mpShopKeeper);

	mpGuide->SetDungeon(mpDungeon);
	mpPlayer->SetGuide(mpGuide);

	mpDungeonKeeper->SetDungeon(mpDungeon);
	mpDungeonKeeper->SetPlayer(mpPlayer);

}

void Game::DrawGameObject() const
{
	mpDungeon->Draw();

	for (auto& enemie : enemies)
	{
		enemie.Draw();
	}

	for (auto& enemy2ndSet : enemies2ndSet)
	{
		enemy2ndSet.Draw();
	}

	for (auto& loot : mpLootBoxs)
	{
		loot->Draw();
	}

	for (auto door : doors)
	{
		door->Draw();
	}

	mpBlackSmith->Draw();
	mpShopKeeper->Draw();
	mpGuide->Draw();
	mpDungeonKeeper->Draw();

	mpPlayer->Draw();
}

void Game::UpdateGameObject()
{
	for (auto& enemie : enemies)
	{
		enemie.Update();
	}

	for (auto& enemy2ndSet : enemies2ndSet)
	{
		enemy2ndSet.Update();
	}

	for (auto& loot : mpLootBoxs)
	{
		loot->Update();
	}

	for (auto& door : doors)
	{
		door->Update();
	}

	mpBlackSmith->Update();
	mpShopKeeper->Update();
	mpGuide->Update();

	mpPlayer->Update();
	mpDungeonKeeper->Update();
}