#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP

#include <iostream>
#include "player.hpp"

enum class ConsumableType{
    HEALTH, DMG_BOOST, CRITRATE_BOOST, CRITDAMAGE_BOOST
};

class Consumable{
    private:
    std::string m_name;
    ConsumableType m_type;
    int m_count;

    public:
    Consumable(std::string name, ConsumableType type, int count);
    void useConsumable(Player* player);
    std::string getName();
    ConsumableType getType();
    int getCount();
};

#endif