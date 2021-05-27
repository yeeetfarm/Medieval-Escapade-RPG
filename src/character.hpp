#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>
#include <vector>

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

    void setSpeed(int speed_);

    void setDamage(int damage_);

    bool isAlive() const;

    void seeInventory();

    void usePotion();

    virtual void burning();

    virtual int getBurning();

    //Warrior
    virtual bool healthCheck();

    //Archer
    virtual void useArrow();

    virtual int getHolder();

    virtual bool isArrow();

    virtual void setHolder(int num);

    //Mage
    virtual void increasePower();

    virtual int lightBolt();
};

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

class Archer : public Character{
private:
    vector<int> arrows;
    int holder;
    int burn;
public:
    Archer(int health_, int armor_, int damage_, int speed_){
        health = health_;
        armor = armor_;
        damage = damage_;
        speed = speed_;
        for(int i = 0; i < 3; i++){
            arrows.push_back(5);
        }
        holder = -1;
        burn = 0;
    }
    int getHolder(){
        return holder;
    }
    void useArrow(){
        if (holder != -1){
            --arrows[holder];
        }
    }
    bool isArrow(){
        if (holder == -1){
            return true;
        }
        if (arrows[holder] == 0){
            return false;
        }
        return true;
    }
    void setHolder(int num){
        holder = num;
    }
    void burning(){
        burn += 2;
    }
    int getBurning(){
        return burn;
    }
};

class Assassin : public Character{
private:
    int burn;

public:
    Assassin(int health_, int armor_, int damage_, int speed_){
        health = health_;
        armor = armor_;
        damage = damage_;
        speed = speed_;
        burn = 0;
    }
    void burning(){
        burn += 5;
    }
    int getBurning(){
        return burn;
    }
};

class Mage : public Character{
private:
    int counter;
    int holder;
    int burn;

public:
    Mage(int health_, int armor_, int damage_, int speed_){
        health = health_;
        armor = armor_;
        damage = damage_;
        speed = speed_;
        holder = 0;
        counter = 0;
        burn = 0;
    }
    void setHolder(int num){
        holder = num;
    }
    int getHolder(){
        return holder;
    }
    void increasePower(){
        setDamage(damage + 20);
    }

    int lightBolt(){
        return damage + (10 * counter++);
    }
    void burning(){
        burn += 1;
    }
    int getBurning(){
        return burn;
    }
};
#endif //__CHARACTER_HPP__
