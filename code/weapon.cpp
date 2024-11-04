#include <iostream>
#include "weapon.hpp"

Weapon::Weapon(std::string name, int damage, int durability, int critrate_bonus){
    m_name = name;
    m_damage = damage;
    m_durabilityMax = durability;
    m_durabilityCurrent = durability;
    m_critrate_bonus = critrate_bonus;
}

std::string Weapon::getName(){
    return m_name;
}

int Weapon::getDamage(){
    return m_damage;
}

int Weapon::getDurabilityCurrent(){
    return m_durabilityCurrent;
}

int Weapon::getDurabilityMax(){
    return m_durabilityMax;
}

int Weapon::getCritRate(){
    return m_critrate_bonus;
}