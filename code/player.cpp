#include <iostream>
#include <algorithm>
#include "player.hpp"

int getHealAmount(Player* player, int level){
    int amount = level * 5;
    int diff = player->getHealthCurr() + amount - player->getHealthMax();
    if (diff < 0){
        amount = player->getHealthMax() - player->getHealthCurr();
    }
    return amount;
}

Player::Player(std::string name){
    m_name = name;
    m_healthMax = 50;
    m_healthCurrent = m_healthMax;
    m_attack = 5;
    m_criticalChance = 5;
    m_criticalDamage = 1.5f;
    m_consumables = {};

}

void Player::takeDamage(int damage){
    m_healthCurrent -= damage;
    std::cout << "Took " << damage << " damage!\n";
}

void Player::equipWeapon(Weapon* weapon){
    m_equippedWeapon = weapon;
}

void Player::addConsumable(Consumable* consumable){
    if (m_consumables.size() <= 5){
        m_consumables.push_back(consumable);
    }
}

void Player::useConsumable(Consumable* consumable){
    ConsumableType type = consumable->getType();
    switch(type){
        case ConsumableType::HEALTH:
            if (m_healthCurrent < m_healthMax){
                int healAmount = getHealAmount(this, consumable->getLevel());
                m_healthCurrent += healAmount;
                std::cout << "Player healed " << healAmount << " HP!\n";

                // Remove the first HEALTH potion from the vector
                auto it = std::find(m_consumables.begin(), m_consumables.end(), consumable);
                if (it != m_consumables.end()) {
                    // Remove the consumable from the vector and delete it
                    m_consumables.erase(it);
                    delete consumable; // Clean up the memory
                    std::cout << "Health potion consumed and removed from inventory.\n";
                }
            }
        break;
        case ConsumableType::DMG_BOOST:
        break;
        case ConsumableType::CRITRATE_BOOST:
        break;
        case ConsumableType::CRITDAMAGE_BOOST:
        break;
    }
}

int Player::getHealthCurr(){
    return m_healthCurrent;
}
int Player::getHealthMax(){
    return m_healthMax;
}