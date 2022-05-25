#pragma once
#include "GameObjects.h"
#include "Player.h"

class DungeonKeeper : public GameObjects
{
	Player* mpPlayer = nullptr;
public:
	DungeonKeeper();
	void Update() override;

	void SetPlayer(Player* pPlayer) { mpPlayer = pPlayer; }
	bool AllowExit() const;

};

