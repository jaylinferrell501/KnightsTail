#pragma once
#include <vector>

#include "BlackSmith.h"
#include "Door.h"
#include "GameObjects.h"
#include "Guide.h"
#include "LootBox.h"
#include "ShopKeeper.h"

class Player : public GameObjects
{
	bool isHeroExploring = true; // Check to see if the hero is still exploring
	bool mHasSword = false; 
	bool mHasArmor = false;
	bool mHasShield = false;
	bool mIsAlive = true;

	std::vector<Door*> doors;
	std::vector<LootBox*> mpLoot;

	BlackSmith* mpBlackSmith = nullptr;
	ShopKeeper* mpShopKeeper = nullptr;
	Guide* mpGuide = nullptr;

	float mHealth = 100.f;
	int mLockPicks = 1;
	int mGold = 20;
	int mAttack = 5;
	int mDefense = 4;
	int mHealthPotionCount = 0;
	int mDefensePotionCount = 0;
	std::string mArmor = "none";

	int mEnemyKillCount = 10;
	int mLootCollected = 20;

public:
	Player();
	bool GetIsHeroExploring() const { return isHeroExploring; }

	void SetIsHeroExploring(bool isExploring) { isHeroExploring = isExploring; }
	void Update() override;
	void SetLoot(std::vector<LootBox*> pLoot) { mpLoot = pLoot; }
	void SetDoor(std::vector<Door*> a_doors) { doors = a_doors; }
	void SetBlackSmith(BlackSmith* pBlackSmith) { mpBlackSmith = pBlackSmith; }
	void SetShopKeeper(ShopKeeper* pShopKeeper) { mpShopKeeper = pShopKeeper; }
	void SetGuide(Guide* pGuide) { mpGuide = pGuide; }

	bool GetIsAlive() const { return mIsAlive; }
	void SetIsAlive(bool alive) { mIsAlive = alive; }

	void HeroStatsAndInventory() const;

	int GetGold() const { return mGold; }
	void SetGold(int newGold) { mGold = newGold; }

	int GetAttack() const { return mAttack; }

	int GetDefense() const { return mDefense; }
	void SetDefense(int newDefense) { mDefense = newDefense; }

	float GetHealth() const { return mHealth; }
	void SetHealth(float newHealth) { mHealth = newHealth; }

	int GetHpPotionCount() const { return mHealthPotionCount; }
	int GetDefPotionCount() const { return mDefensePotionCount; }

	void SetHpPotionCount(int newCount) { mHealthPotionCount = newCount; }
	void SetDefPotionCount(int newCount) { mDefensePotionCount = newCount; }

	int GetEnemyKillCount() const { return mEnemyKillCount; }
	void SetEnemyKillCount(int newCount) {mEnemyKillCount = newCount; }

	int GetLootCollected() const { return mLootCollected; }

	void looted();
};

