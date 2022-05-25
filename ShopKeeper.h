#pragma once
#include "Npc.h"

class ShopKeeper :public Npc
{
public:
	ShopKeeper();
	void NpcScreen() override;
	void NpcMenuInput() override;
	void Update() override;
};

