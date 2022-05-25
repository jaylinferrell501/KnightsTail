#pragma once
#include "Npc.h"

class Guide : public Npc
{
	void Controls() const;
	void WhatToDo() const;
	void Info() const;
public:
	Guide();
	void NpcScreen() override;
	void NpcMenuInput() override;
	void Update() override;
};

