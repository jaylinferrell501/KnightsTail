#pragma once
#include "Enemy.h"

class GuardPatrolLeftAndRight : public Enemy
{
public:
	GuardPatrolLeftAndRight(int x, int y);
	void Patrol() override;
	void Update() override;
};

