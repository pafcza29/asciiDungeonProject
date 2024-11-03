#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "player.hpp"

class Enemy{
    private:
    std::string m_name;
    int m_healthCurrent;
    int m_healthMax;
    int m_attack;
    int m_criticalChance;
    float m_criticalDamage;

    public:
    Enemy(std::string name, int health, int attack);
    void attackPlayer(Player* player);

};

#endif