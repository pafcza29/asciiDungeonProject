#include <iostream>

#include "player.hpp"
#include "enemy.hpp"
#include "weapon.hpp"
#include "consumable.hpp"

int main()
{
    Player* player = new Player("player");
    Enemy* slime = new Enemy("Slime", 20, 10);
    Consumable* hp_potion = new Consumable(ConsumableType::HEALTH, 1);
    player->addConsumable(hp_potion);

    player->takeDamage(40);
    player->useConsumable(hp_potion);

    slime->attackPlayer(player);

    delete player;
    delete slime;

    return 0;
}
