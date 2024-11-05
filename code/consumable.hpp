#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP

#include <iostream>
#include "player.hpp"

enum class ConsumableType{
    HEALTH, DMG_BOOST, CRITRATE_BOOST, CRITDAMAGE_BOOST
};

class Consumable{
    private:
    ConsumableType m_type;
    int m_level;

    public:
    Consumable(ConsumableType type, int level);
    ConsumableType getType();
    int getLevel();
};

#endif