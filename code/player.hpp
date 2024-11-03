#include <iostream>

class Player{
    private:
    std::string m_name;
    int m_healthCurrent;
    int m_healthMax;
    int m_attack;
    int m_criticalChance;
    float m_criticalDamage;

    public:
    Player(std::string name);
    void takeDamage(int damage);
};