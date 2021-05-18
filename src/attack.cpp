#include "attack.hpp"
#include "warrior.hpp"

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

