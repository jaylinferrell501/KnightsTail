#pragma once
#include <vector>

#include "BlackSmith.h"
#include "Door.h"
#include "Dungeon.h"
#include "DungeonKeeper.h"
#include "GuardPatrolLeftAndRight.h"
#include "GuardPatrolUpAndDown.h"
#include "LootBox.h"
#include "Player.h"
#include "ShopKeeper.h"
#include "Guide.h";

class Game
{
	Player* mpPlayer = nullptr;
	Dungeon* mpDungeon = nullptr;
	BlackSmith* mpBlackSmith = nullptr;
	ShopKeeper* mpShopKeeper = nullptr;
	Guide* mpGuide = nullptr;
	DungeonKeeper* mpDungeonKeeper = nullptr;

	void MenuInput();

	// Enemies
	using PatrolUpAndDown = GuardPatrolUpAndDown;
	PatrolUpAndDown enemy1{ 11, 15 };
	PatrolUpAndDown enemy2{ 15, 30 };
	PatrolUpAndDown enemy3{ 35, 5 };
	PatrolUpAndDown enemy4{ 39, 7 };
	PatrolUpAndDown enemy5{ 43, 8 };
	PatrolUpAndDown enemy6{ 37, 3 };
	PatrolUpAndDown enemy7{ 51, 9 };
	PatrolUpAndDown enemy8{ 55, 10 };
	PatrolUpAndDown enemy9{ 9, 30 };
	PatrolUpAndDown enemy10{ 77, 10 };
	PatrolUpAndDown enemy11{ 88, 10 };
	PatrolUpAndDown enemy12{ 10, 30 };
	PatrolUpAndDown enemy13{ 51, 10 };
	PatrolUpAndDown enemy14{ 54, 7 };
	PatrolUpAndDown enemy15{ 57, 6 };
	std::vector<PatrolUpAndDown> enemies{ enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, enemy9, enemy10, enemy11, enemy12, enemy13, enemy14, enemy15};

	using PatrolLeftAndRight = GuardPatrolLeftAndRight;
	PatrolLeftAndRight enemy16{ 31, 4 };
	PatrolLeftAndRight enemy17{ 35, 10 };
	PatrolLeftAndRight enemy18{ 25, 6 };
	PatrolLeftAndRight enemy19{ 40, 12 };
	PatrolLeftAndRight enemy20{ 50, 10 };
	PatrolLeftAndRight enemy21{ 15, 18 };
	PatrolLeftAndRight enemy22{ 20, 22 };
	PatrolLeftAndRight enemy23{ 28, 15 };
	PatrolLeftAndRight enemy24{ 90, 3 };
	PatrolLeftAndRight enemy25{ 55, 20 };
	PatrolLeftAndRight enemy26{ 50, 30 };
	PatrolLeftAndRight enemy27{ 55, 33 };
	PatrolLeftAndRight enemy28{ 55, 26 };
	PatrolLeftAndRight enemy29{ 88, 10 };
	PatrolLeftAndRight enemy30{ 50, 10 };
	std::vector<PatrolLeftAndRight> enemies2ndSet{ enemy16, enemy17, enemy18, enemy19, enemy20, enemy21 , enemy22 , enemy23 , enemy24 , enemy25 , enemy25 , enemy26 , enemy27 , enemy28, enemy29, enemy30 };

	// LootBoxes
	LootBox* lootbox1 = new LootBox{ 19, 8 };
	LootBox* lootbox2 = new LootBox{ 82, 3 };
	LootBox* lootbox3 = new LootBox{ 21, 3 };
	LootBox* lootbox4 = new LootBox{ 21, 8 };
	LootBox* lootbox5 = new LootBox{ 82, 15 };
	LootBox* lootbox6 = new LootBox{ 29, 15 };
	LootBox* lootbox7 = new LootBox{ 108, 3 };
	LootBox* lootbox8 = new LootBox{ 108, 15 };
	LootBox* lootbox9 = new LootBox{ 108, 15 };
	LootBox* lootbox10 = new LootBox{ 12, 15 };
	LootBox* lootbox11 = new LootBox{ 18, 18 };
	LootBox* lootbox12 = new LootBox{ 55, 31 };
	LootBox* lootbox13 = new LootBox{ 88, 10 };
	LootBox* lootbox14 = new LootBox{ 90, 3 };
	LootBox* lootbox15 = new LootBox{ 55, 20 };
	LootBox* lootbox16 = new LootBox{ 31, 4 };
	LootBox* lootbox17 = new LootBox{ 55, 15 };
	LootBox* lootbox18 = new LootBox{ 55, 29 };
	LootBox* lootbox19 = new LootBox{ 15, 15 };
	LootBox* lootbox20 = new LootBox{ 56, 32 };
	std::vector<LootBox*> mpLootBoxs{ lootbox1, lootbox2, lootbox3, lootbox4, lootbox5, lootbox6, lootbox7, lootbox8, lootbox9, lootbox10, lootbox11, lootbox12, lootbox13, lootbox14, lootbox15, lootbox16, lootbox17 , lootbox18, lootbox19, lootbox20 };

	//Door
	Door* door1 = new Door{ 83, 11 };
	Door* door2 = new Door{ 20, 5 };
	Door* door3 = new Door{ 10, 20 };
	Door* door4 = new Door{ 37, 25 };
	std::vector<Door*> doors{ door1, door2, door3, door4 };


public:

	~Game() = default;
	void PlayGame();

	void SetGameObject();
	void DrawGameObject() const;
	void UpdateGameObject();

	void SetPlayer(Player* pPlayer) { mpPlayer = pPlayer; }
	void SetDungeon(Dungeon* pDungeon) { mpDungeon = pDungeon; }
	void SetLoot(std::vector<LootBox*> loots) { mpLootBoxs = loots; }

	// Npcs
	void SetBlackSmith(BlackSmith* pBlackSmith) { mpBlackSmith = pBlackSmith; }
	void SetShopKeeper(ShopKeeper* pShopKeeper) { mpShopKeeper = pShopKeeper; }
	void SetGuide(Guide* pGuide) { mpGuide = pGuide; }
	void SetDungeonKeeper(DungeonKeeper* pDungeonKeeper) { mpDungeonKeeper = pDungeonKeeper; }


	void StartGame();
};

