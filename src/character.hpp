#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>

#include "attack.hpp"

using namespace std;

class Character : public attackStrat{
protected:
    int health;
    int armor;
    int damage;
    int speed;

public:
    Character(int health_, int armor_, int damage_, int speed_):health(health_), armor(armor_), damage(damage_), speed(speed_){}

    int getHealth() const{
        return health;
    }

    int getArmor() const{
        return armor;
    }

    int getDamage() const{
        return damage;
    }

    int getSpeed() const{
        return speed;
    }

    void expadd(int add){

    }

    void damageHits(int damage_){

    }

    void setHealth(int health_){
        this->health = health_;
    }

    void setArmor(int armor_){
        this->armor = armor_;
    }

    bool isAlive() const{
        
    }

    void seeInventory(){
        
    }

    void usePotion(){
        
    }


};
#endif //__CHARACTER_HPP__
