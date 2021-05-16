#include "attack.hpp"

void AttackWarrior::attack(Character* character_, Character* enemy){
    cout << "Ah!" << endl;
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Thwomp!" << endl;
}

void AttackMage::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Blast!" << endl;
}

void AttackAssassin::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Stab!" << endl;
}

void AttackArcher::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Twang!" << endl;
}

void AttackEnemy::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Ouch!" << endl;
}

