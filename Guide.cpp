#include "Guide.h"

#include <cassert>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>


void Guide::Controls() const
{
	std::ifstream controlFile("Controls.txt", std::ios::in);
	assert(controlFile.is_open());
	std::string word;
	getline(controlFile, word);

	while (!controlFile.eof())
	{
		std::cout << word << '\n';
		std::getline(controlFile, word);
	}
	_getch();

}

void Guide::WhatToDo() const
{
	std::ifstream WhatToDoFile("WhatToDo.txt", std::ios::in);
	assert(WhatToDoFile.is_open());
	std::string word;
	getline(WhatToDoFile, word);

	while (!WhatToDoFile.eof())
	{
		std::cout << word << '\n';
		std::getline(WhatToDoFile, word);
	}

	_getch();
}

void Guide::Info() const
{
	std::ifstream InfoFile("Info.txt", std::ios::in);
	assert(InfoFile.is_open());
	std::string word;
	getline(InfoFile, word);

	while (!InfoFile.eof())
	{
		std::cout << word << '\n';
		std::getline(InfoFile, word);
	}
	_getch();
}

Guide::Guide()
{
	mSprite = '!';
	mX = 10;
	mY = 7;
}

void Guide::NpcScreen()
{
	DrawNpc("Guide.txt");
	DrawNpcMenu("GuideMenu.txt");
	NpcMenuInput();
}

void Guide::NpcMenuInput()
{
	char input = _getch();

	if (input == 'c')
	{
		system("CLS");
		Controls();
	}
	else if (input == 'w')
	{
		system("CLS");
		WhatToDo();
	}
	else if (input == 'i')
	{
		system("CLS");
		Info();
	}
}

void Guide::Update()
{

}
