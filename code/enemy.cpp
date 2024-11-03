#include <iostream>
#include "enemy.hpp"
#include "player.hpp"

Enemy::Enemy(std::string name, int health, int attack){
    m_name = name;
    m_healthMax = health;
    m_healthCurrent = m_healthMax;
    m_attack = attack;
    m_criticalChance = 5;
    m_criticalDamage = 1.5f;

}

void Enemy::attackPlayer(Player* player){
    player->takeDamage(m_attack);
}
