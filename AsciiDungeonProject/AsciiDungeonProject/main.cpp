#include <iostream>
#include "player.hpp"

int main()
{
    Player* player = new Player("Pavel");
    player->printInfo();
    delete player;
}
