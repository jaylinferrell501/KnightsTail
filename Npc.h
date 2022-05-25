#pragma once
#include "GameObjects.h"

class Npc : public GameObjects
{
protected:
	void DrawNpc(std::string fileName) const;
	void DrawNpcMenu(std::string menuName) const;
	void DrawNpcShop(std::string shopName) const;
	void DrawNpcUpgradeOptions(std::string UpgradeOptionsFile) const;

	bool mIsOnShopScreen = false;
	bool mIsOnUpgrageScreen = false;
public:
	virtual void NpcScreen() = 0;
	virtual void NpcMenuInput() = 0;

	bool IsOnShopScreen() const { return mIsOnShopScreen; }
	bool IsOnUpgradeScreen() const { return mIsOnUpgrageScreen; }
	
	
	void Update() override;
};

