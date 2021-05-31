#include "character.hpp"
#include "attack.hpp"

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

void Character::setSpeed(int speed_){
    this->speed = speed_;
}

void Character::setDamage(int damage_){
    this->damage = damage_;
}

bool Character::isAlive() const{
    if (this->health <= 0){
	return false;
    }
    return true;
}

void Character::seeInventory(){

}

void Character::usePotion(){
	potion -= 1;
	this->health += 40;
}

void Character::addPotion(){
	potion += 1;
}

int Character::getPotion(){
	return this->potion;
}

void Character::burning(){

}

int Character::getBurning(){
    return 0;
}

//Warrior
bool Character::healthCheck(){
    return true;
}


//Archer
void Character::useArrow(){

}
int Character::getHolder(){
    return 0;
}

void Character::setHolder(int num){

}

//Mage
void Character::increasePower(){

}

int Character::lightBolt(){
    return 0;
}
