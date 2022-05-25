#include "GuardPatrolUpAndDown.h"

GuardPatrolUpAndDown::GuardPatrolUpAndDown(int x, int y)
	:Enemy(x, y)
{
	mHealth = 100;
	mSprite = '^';
	mIsAlive = true;
}

void GuardPatrolUpAndDown::Patrol()
{
	/// <summary>
	/// Checks to see id enemy has touched a wall and if so,
	///	the enemy will walk the other way on the Y - axis.
	/// </summary>
	const int newX = mX;
	int newY = mY;

	if (mpDungeon->IsWall(newX, newY + 1))
	{
		mTouchedWall = true;
		mSprite = '^';
	}
	else if (mpDungeon->IsWall(newX, newY - 1))
	{
		mTouchedWall = false;
		mSprite = 'v';

	}
	if (mTouchedWall)
	{
		mX = newX;
		mY = --newY;
	}
	else
	{
		mX = newX;
		mY = ++newY;
	}

	if (mHealth <= 0)
	{
		mIsAlive = false;
	}

	if (mIsAlive)
	{
		if ((mpPlayer->GetX() == GetX() && mpPlayer->GetY() - 1 == GetY()) || (mpPlayer->GetX() == GetX() && mpPlayer->GetY() == GetY()))
		{
			Battle();
		}
		else if (mpPlayer->GetX() == GetX() && mpPlayer->GetY() + 1 == GetY())
		{
			Battle();
		}
	}
	else if(!mIsAlive)
	{
		mSprite = '.';
	}
	
}

void GuardPatrolUpAndDown::Update()
{
	Patrol();
}

