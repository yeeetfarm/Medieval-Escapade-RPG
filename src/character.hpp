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
  
  //Dragon
    virtual bool dodgeAttack();
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
    ~Archer(){}
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
    ~Assassin(){}
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
    ~Mage(){}
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
/*
  //ENEMIES
class Dragon : public Character{
    public:
        Dragon(int health_, int armor_, int damage_, int speed_){
		health = health_;
        	armor = armor_;
        	damage = damage_;
        	speed = speed_;
	}
	~Dragon(){}
	bool dodgeAttack(){
		int percentage = rand() % 100 + 1;
		if(percentage <= 40){
			return true;
		}
		return false;
	}
};

class Ogre : public Character{
	public:
		Ogre(int health_, int armor_, int damage_, int speed_){
                	health = health_;
                	armor = armor_;
                	damage = damage_;
                	speed = speed_;
        	}
		~Ogre(){}
};

class Slime : public Character{
	public:
		Slime(int health_, int armor_, int damage_, int speed_){
                        health = health_;
                        armor = armor_;
                        damage = damage_;
                        speed = speed_;
                }
		~Slime(){}
		void reduceSpeed(Character* char_){
			int newSpeed = char_->getSpeed() - 5;
			char_->setSpeed(newSpeed);
		}
};

class Skeleton : public Character{
	private:
		int surviveFatal;
	public:
		Skeleton(int health_, int armor_, int damage_, int speed_){
                        health = health_;
                        armor = armor_;
                        damage = damage_;
                        speed = speed_;
			surviveFatal = 1;
                }
		~Skeleton(){}
		void checkFatal(){
			if(surviveFatal == 1){
				health = 1;
				surviveFatal = 0;		
			}
		}
};

class Spider : public Character{
	private:
		int web_; //1 = web function used, 0 = not in use
	public:
		Spider(int health_, int armor_, int damage_, int speed_){
                        health = health_;
                        armor = armor_;
                        damage = damage_;
                        speed = speed_;
			web_ = 0;
                }
		~Spider(){}
		bool webon(Character *char_){
			web_ = 1;		
		}
		bool weboff(Character *char_){
			web_ = 0;
		} 	
};

class Zombies : public Character{
	public:
		Zombies(int health_, int armor_, int damage_, int speed_){
                        health = health_;
                        armor = armor_;
                        damage = damage_;
                        speed = speed_;
                }
		~Zombies(){}
		void leech(Character *char_){
			int newHealth = char_->getHealth() - 5;
			char_->setHealth(newHealth);
			this->health += 5;
		}
};
*/
#endif //__CHARACTER_HPP__
