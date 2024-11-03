#include <iostream>
#include "enemy.hpp"
#include "player.hpp"

int main()
{
    Player* player = new Player("player");
    Enemy* slime = new Enemy("Slime", 20, 10);

    slime->attackPlayer(player);

    return 0;
}
