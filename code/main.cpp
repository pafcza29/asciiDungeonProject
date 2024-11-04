#include <iostream>
#include "player.hpp"
#include "enemy.hpp"
#include "weapon.hpp"

int main()
{
    Player* player = new Player("player");
    Enemy* slime = new Enemy("Slime", 20, 10);

    slime->attackPlayer(player);

    delete player;
    delete slime;

    return 0;
}
