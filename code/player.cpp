#include <iostream>
#include "player.hpp"

Player::Player(std::string name){
    m_name = name;
    m_healthMax = 50;
    m_healthCurrent = m_healthMax;
    m_attack = 5;
    m_criticalChance = 5;
    m_criticalDamage = 1.5f;

}

void Player::takeDamage(int damage){
    m_healthCurrent -= damage;
}
