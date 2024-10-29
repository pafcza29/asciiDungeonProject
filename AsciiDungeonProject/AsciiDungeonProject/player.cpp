#include <iostream>
#include "player.hpp"

Player::Player(std::string name, int hp, int def){
    m_name = name;
    m_hp = hp;
    m_def = def;
}

Player::Player(std::string name): Player::Player(name, 100, 20){}

void Player::takeDamage(int amount){
    m_hp -= amount;
}

void Player::printInfo(){
    std::cout << "Player name: " << m_name << "\nHP: " << m_hp << "\nDEF: " << m_def << "\n";
}