#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "weapon.hpp"
#include "consumable.hpp"

class Consumable;

class Player{
    private:
    std::string m_name;
    int m_healthCurrent;
    int m_healthMax;
    int m_attack;
    int m_criticalChance;
    float m_criticalDamage;
    Weapon* m_equippedWeapon;
    std::vector<Consumable*> m_consumables;

    public:
    Player(std::string name);
    void takeDamage(int damage);
    void equipWeapon(Weapon* weapon);
    void addConsumable(Consumable* consumable);
    void useConsumable(Consumable* consumable);

    int getHealthCurr();
    int getHealthMax();
};

#endif