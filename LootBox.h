#pragma once
#include "GameObjects.h"

class LootBox : public GameObjects
{
	bool mIsLooted = false;
public:
	LootBox(int x, int y);
	void Update() override;

	void SetIsLooted(bool looted) { mIsLooted = looted; }
};

