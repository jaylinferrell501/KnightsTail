#pragma once
#include "GameObjects.h"
#include "Player.h"

class Enemy :public GameObjects
{
protected:
	Player* mpPlayer = nullptr;
	bool mTouchedWall = false;
	float mHealth = 100;
	int mAttack = 15;
	void Rewards() const;
	void DrawTextFile(std::string newFile) const;
	bool mIsAlive = true;

public:
	Enemy(int x, int y);
	virtual void Patrol() = 0;
	void Attack();
	void Battle();
	void Update() override;
	void SetPlayer(Player* pPlayer) { mpPlayer = pPlayer; }
};

