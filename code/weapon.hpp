#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
    std::string m_name;
    int m_damage;
    int m_durabilityCurrent;
    int m_durabilityMax;
    int m_critrate_bonus;

    public:
    Weapon(std::string name, int damage, int durability, int critrate_bonus);
    std::string getName();
    int getDamage();
    int getDurabilityCurrent();
    int getDurabilityMax();
    int getCritRate();
};

#endif