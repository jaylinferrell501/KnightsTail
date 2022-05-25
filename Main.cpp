// KnightsTail.cpp
// Jaylin Ferrell

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "ShopKeeper.h"
#include "Guide.h"

/**
 * \brief 
 * \ TOGGLE FULL SCREEN WHEN PLAYING GAME !?!?!?!?!!?!?!!?
 */
int main()
{
    Game game;
    Dungeon dungeon;
    Player player;
    BlackSmith blackSmith;
    ShopKeeper shopkeeper;
    Guide guide;
    DungeonKeeper dungeonkeeper;

    game.SetDungeon(&dungeon);
    game.SetPlayer(&player);
    game.SetBlackSmith(&blackSmith);
    game.SetShopKeeper(&shopkeeper);
    game.SetGuide(&guide);
    game.SetDungeonKeeper(&dungeonkeeper);

    game.SetGameObject();

    game.StartGame();

    return 0;
}

// ToDo
// Make Bosses
// Add Exit

