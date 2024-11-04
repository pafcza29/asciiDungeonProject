#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "weapon.hpp"
#include "consumable.hpp"

class Player{
    private:
    std::string m_name;
    int m_healthCurrent;
    int m_healthMax;
    int m_attack;
    int m_criticalChance;
    float m_criticalDamage;
    Weapon* m_equippedWeapon;

    public:
    Player(std::string name);
    void takeDamage(int damage);
    void equipWeapon(Weapon* weapon);
};

#endif