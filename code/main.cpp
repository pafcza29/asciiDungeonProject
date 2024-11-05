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
    std::cout<< hp_potion->getLevel() << "\n";

    std::cout << player->getHealthCurr() << "\n";

    player->takeDamage(3);
    std::cout << player->getHealthCurr() << "\n";
    player->takeDamage(3);
    std::cout << player->getHealthCurr() << "\n";
    player->useConsumable(hp_potion);
    std::cout << player->getHealthCurr() << "\n";

    slime->attackPlayer(player);

    delete player;
    delete slime;

    return 0;
}
