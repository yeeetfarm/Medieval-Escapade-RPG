#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>

#include "attack.hpp"

using namespace std;

class AttackStrat;

class Character{
protected:
    int health;
    int armor;
    int damage;
    int speed;
    AttackStrat* attack_ = nullptr;

public:
    //Character(int health_, int armor_, int damage_, int speed_):health(health_), armor(armor_), damage(damage_), speed(speed_){}
    

    virtual ~Character();

    void setAttack(AttackStrat* attack);

    int getHealth() const;

    int getArmor() const;

    int getDamage() const;

    int getSpeed() const;

    void attackHit(Character* person);

    void expadd(int add);

    void damageHits(int damage_);

    void setHealth(int health_);

    void setArmor(int armor_);

    bool isAlive() const;

    void seeInventory();

    void usePotion();

    virtual bool healthCheck() = 0;

};
#endif //__CHARACTER_HPP__
