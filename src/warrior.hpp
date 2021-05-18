#ifndef __WARRIOR_HPP__
#define __WARRIOR_HPP__

#include <iostream>

#include "character.hpp"

using namespace std;

class Warrior : public Character{
private:
    int startingHealth;

public:
    Warrior(int health_, int armor_, int damage_, int speed_){
        this->health = health_;
        this->armor = armor_;
        this->damage = damage_;
        this->speed = speed_;
        startingHealth = health_;
    }
    bool healthCheck(){
        if(health < startingHealth/2){
                return true;
        }
        return false;
    }
};
#endif //__WARRIOR_HPP__
