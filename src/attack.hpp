#ifndef __ATTACK_HPP__
#define __ATTACK_HPP__

#include <iostream>
#include "character.hpp"

using namespace std;

class Character;

class AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy) = 0;
};

class AttackWarrior : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
};

class AttackMage : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
};

class AttackAssassin : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
};

class AttackArcher : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
};

class AttackEnemy : public AttackStrat{
public:
    virtual void attack(Character* character_, Character* enemy);
};

#endif //__ATTACK_HPP__


