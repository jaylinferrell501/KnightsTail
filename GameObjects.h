#pragma once
#include "Dungeon.h"

class GameObjects
{
protected:
	char mSprite = '~';
	int mX = 0;
	int mY = 0;
	Dungeon* mpDungeon = nullptr;
public:
	virtual ~GameObjects() = default;
	virtual void Update() = 0;

	void Draw() const;
	void SetDungeon(Dungeon* pDungeon) { mpDungeon = pDungeon; }

	int GetX() const { return mX; }
	int GetY() const { return mY; }

	void SetX(int x) { mX = x; }
	void SetY(int y) { mY = y; }
	void SetSprite(char sprite) { mSprite = sprite; }
};

