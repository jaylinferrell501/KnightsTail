#pragma once
#include <string>

class Dungeon
{
	static constexpr int kWidth = 113;
	static constexpr int kHeight = 36;

	// This is a array of strings
	std::string mGrid[kHeight];

public:
	Dungeon();
	void Draw() const;

	bool IsWall(int x, int y) const;
};
