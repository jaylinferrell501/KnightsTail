#include "Npc.h"

#include <cassert>
#include <iostream>
#include <fstream>


void Npc::DrawNpc(const std::string fileName) const
{
	std::ifstream file(fileName, std::ios::in);
	assert(file.is_open());
	std::string word;
	getline(file, word);

	while (!file.eof())
	{
		std::cout << word << '\n';
		std::getline(file, word);
	}
}

void Npc::DrawNpcMenu(const std::string menuName) const
{
	std::ifstream menuFile(menuName, std::ios::in);
	assert(menuFile.is_open());
	std::string word;
	getline(menuFile, word);

	while (!menuFile.eof())
	{
		std::cout << word << '\n';
		std::getline(menuFile, word);
	}
}

void Npc::DrawNpcShop(const std::string shopName) const
{
	std::ifstream shopFile(shopName, std::ios::in);
	assert(shopFile.is_open());
	std::string word;
	getline(shopFile, word);

	while (!shopFile.eof())
	{
		std::cout << word << '\n';
		std::getline(shopFile, word);
	}
}

void Npc::DrawNpcUpgradeOptions(const std::string UpgradeOptionsFile) const
{
	std::ifstream upgradeFile(UpgradeOptionsFile, std::ios::in);
	assert(upgradeFile.is_open());
	std::string word;
	getline(upgradeFile, word);

	while (!upgradeFile.eof())
	{
		std::cout << word << '\n';
		std::getline(upgradeFile, word);
	}
}

void Npc::Update()
{
	//
}
