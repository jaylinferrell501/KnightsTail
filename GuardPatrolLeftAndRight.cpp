#include "GuardPatrolLeftAndRight.h"

GuardPatrolLeftAndRight::GuardPatrolLeftAndRight(int x, int y)
	:Enemy(x, y)
{
	mHealth = 100;
	mSprite = '>';
	mIsAlive = true;
}

void GuardPatrolLeftAndRight::Patrol()
{
	int newX = mX;
	const int newY = mY;

	if (mpDungeon->IsWall(newX + 1, newY))
	{
		mTouchedWall = true;
		mSprite = '<';
	}
	else if (mpDungeon->IsWall(newX - 1, newY))
	{
		mTouchedWall = false;
		mSprite = '>';

	}
	if (mTouchedWall)
	{
		mX = --newX;
		mY = newY;
	}
	else
	{
		mX = ++newX;
		mY = newY;
	}

	if (mHealth <= 0)
	{
		mIsAlive = false;
	}

	if (mIsAlive)
	{
		if ((mpPlayer->GetX() - 1 == GetX() && mpPlayer->GetY() == GetY()) || (mpPlayer->GetX() == GetX() && mpPlayer->GetY() == GetY()))
		{
			Battle();
		}
		else if (mpPlayer->GetX() + 1 == GetX() && mpPlayer->GetY() == GetY())
		{
			Battle();
		}
	}
	else if (!mIsAlive)
	{
		mSprite = '.';
	}
}

void GuardPatrolLeftAndRight::Update()
{
	Patrol();
}
