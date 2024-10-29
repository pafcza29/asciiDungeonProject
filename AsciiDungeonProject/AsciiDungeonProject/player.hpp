#include <iostream>

class Player{
    private:
    std::string m_name;
    int m_hp;
    int m_def;
    
    public:
    Player(std::string name, int hp, int def);
    Player(std::string name);
    void takeDamage(int amount);
    void printInfo();
    
};