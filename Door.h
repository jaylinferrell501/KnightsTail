#pragma once
#include "GameObjects.h"

class Door : public GameObjects
{
	bool mIsUnlocked = false;
public:
	Door(int x, int y);
	void Update() override;
	bool GetIsUnlocked() const { return mIsUnlocked; }
	void SetUnlocked(bool unlocked) { mIsUnlocked = unlocked; }
};

