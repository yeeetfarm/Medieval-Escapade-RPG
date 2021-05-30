#include "attack.hpp"
AttackStrat::~AttackStrat(){
	cout << "Deleting..." << endl;
}

void AttackWarrior::attack(Character* character_, Character* enemy){
    if(character_->healthCheck()){
        enemy->setHealth(enemy->getHealth() - 2*character_->getDamage());
    cout << "Double Damage!" << endl;
    }
    else{
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
    }
    cout << "Thwomp!" << endl;


}
AttackWarrior::~AttackWarrior(){
}
void AttackMage::attack(Character* character_, Character* enemy){
    int x = character_->getHolder();
    if (character_->getBurning() != 0){
        enemy->setHealth(enemy->getHealth() - character_->getBurning());
        cout << "Dealt " << character_->getBurning() << " points of burn damage" << endl;
    }
    if (x == 0){
        //Fireball
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
        character_->burning();
    }
    else if (x == 1){
        //IncreasePower
        character_->increasePower();
    }
    else if (x == 2){
        //Lightbolt
        enemy->setHealth(enemy->getHealth() - character_->lightBolt());
    }
    else{
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
    }
    cout << "Blast!" << endl;

}
AttackMage::~AttackMage(){
        delete this;
}

void AttackAssassin::attack(Character* character_, Character* enemy){
    if (character_->getBurning() != 0){
        enemy->setHealth(enemy->getHealth() - character_->getBurning());
        cout << "Dealt " << character_->getBurning() << " points of poison damage" << endl;
    }
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    character_->burning();
    cout << "Stab!" << endl;
}
AttackAssassin::~AttackAssassin(){
        delete this;
}


void AttackArcher::attack(Character* character_, Character* enemy){
    int x = character_->getHolder();
    if (character_->getBurning() != 0){
        //Check if poison
        enemy->setHealth(enemy->getHealth() - character_->getBurning());
        cout << "Dealt " << character_->getBurning() << " points of poison damage" << endl;
    }

    if (x == 0){
        cout << "Multishot" << endl;
        enemy->setHealth(enemy->getHealth() - 3*character_->getDamage());
    }
    else if (x == 1){
        cout << "Slowshot" << endl;
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
        enemy->setSpeed(enemy->getSpeed() - 10);
    }
    else if (x == 2){
        cout << "Poisonshot" << endl;
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
        character_->burning();
    }
    else{
        cout << "Normalshot" << endl;
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
    }
    character_->useArrow();
    cout << "Twang!" << endl;
}
AttackArcher::~AttackArcher(){
        delete this;
}


void AttackEnemy::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Ouch!" << endl;
}
AttackEnemy::~AttackEnemy(){
	delete this;
}

