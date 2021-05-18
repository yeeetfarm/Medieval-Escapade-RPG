#include "character.hpp"
#include "warrior.hpp"

Character::~Character(){

}

void Character::setAttack(AttackStrat* attack){
    this->attack_ = attack;
}

int Character::getHealth() const{
    return health;
}

int Character::getArmor() const{
    return armor;
}

int Character::getDamage() const{
    return damage;
}

int Character::getSpeed() const{
    return speed;
}

void Character::attackHit(Character* person){
    this->attack_->attack(this, person);
}

void Character::expadd(int add){

}

void Character::damageHits(int damage_){

}

void Character::setHealth(int health_){
    this->health = health_;
}

void Character::setArmor(int armor_){
    this->armor = armor_;
}

bool Character::isAlive() const{

    return false;
}

void Character::seeInventory(){

}

void Character::usePotion(){

}

bool healthCheck(){
    return true;
}
