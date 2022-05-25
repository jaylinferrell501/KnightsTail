#pragma once
#include "Enemy.h"

class GuardPatrolUpAndDown : public Enemy
{
public:
	GuardPatrolUpAndDown( int x, int y);
	void Patrol() override;
	void Update() override;
};

