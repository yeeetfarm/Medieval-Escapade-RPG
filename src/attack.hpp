#ifndef __ATTACK_HPP__
#define __ATTACK_HPP__

#include <iostream>
#include "character.hpp"

using namespace std;

class Character;

class AttackStrat{
public:
    AttackStrat(){}
    virtual ~AttackStrat();
    virtual void attack(Character* character_, Character* enemy) = 0;
};

class AttackWarrior : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
    ~AttackWarrior();
};

class AttackMage : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
    ~AttackMage();
};

class AttackAssassin : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
    ~AttackAssassin();
};

class AttackArcher : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
    ~AttackArcher();
};

class AttackEnemy : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
    ~AttackEnemy();
};

#endif //__ATTACK_HPP__


