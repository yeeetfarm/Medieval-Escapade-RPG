#include "attack.hpp"

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
void AttackMage::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Blast!" << endl;
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

void AttackArcher::attack(Character* character_, Character* enemy){
    int x = character_->getHolder();
    if (character_->getBurning() != 0){
        //Check if poison
        enemy->setHealth(enemy->getHealth() - character_->getBurning());
        cout << "Dealt " << character_->getBurning() << " points of poison damage" << endl;
    }

    if (x == 0){
        //Multishot
        enemy->setHealth(enemy->getHealth() - 3*character_->getDamage());
    }
    else if (x == 1){
        //Slowshot
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
        enemy->setSpeed(enemy->getSpeed() - 10);
    }
    else if (x == 2){
        //Poisonshot
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
        character_->burning();
    }
    else{
        //Normalshot
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
    }
    character_->useArrow();
    cout << "Twang!" << endl;
}

void AttackEnemy::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Ouch!" << endl;
}

