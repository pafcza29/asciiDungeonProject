#include "consumable.hpp"
#include <iostream>
#include "player.hpp"

Consumable::Consumable(std::string name, ConsumableType type, int count){
    m_name = name;
    m_type = type;
    m_count = count;
}

void Consumable::useConsumable(Player* player){
    ConsumableType type = Consumable::getType();
    switch(type){
        case ConsumableType::HEALTH:
        break;
        case ConsumableType::DMG_BOOST:
        break;
        case ConsumableType::CRITRATE_BOOST:
        break;
        case ConsumableType::CRITDAMAGE_BOOST:
        break;
    }
}

std::string Consumable::getName(){
    return m_name;
}

ConsumableType Consumable::getType(){
    return m_type;
}

int Consumable::getCount(){
    return m_count;
}