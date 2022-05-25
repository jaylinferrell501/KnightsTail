#pragma once
#include "Npc.h"

class BlackSmith : public Npc
{
	bool mHasSword = true;
	bool mHasShield = true;
	bool mHasArmor = true;
public:
	BlackSmith();
	void NpcMenuInput() override;
	void NpcScreen() override;
	void Update() override;

	bool HasSword() const { return mHasSword; }
	bool HasShield() const { return mHasShield; }
	bool HasArmor() const { return mHasArmor; }

	void SetHasSword(bool hasSword) { mHasSword = hasSword; }
	void SetHasShield(bool hasShield) { mHasShield = hasShield; }
	void SetHasArmor(bool hasArmor) { mHasArmor = hasArmor; }
};

