#include <iostream>

#include "consumable.hpp"

Consumable::Consumable(ConsumableType type, int level){
    m_type = type;
    m_level = level;
}

ConsumableType Consumable::getType(){
    return m_type;
}

int Consumable::getLevel(){
    return m_level;
}