#include "attack.hpp"
AttackStrat::~AttackStrat(){
	
}

void AttackWarrior::attack(Character* character_, Character* enemy){
    int y = enemy->getHealth();
    if(character_->healthCheck()){
        enemy->setHealth(enemy->getHealth() - 2*character_->getDamage());
    cout << "Double Damage!" << endl;
    }
    else{
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
    }
    cout << "Thwomp! You dealt " << y - enemy->getHealth() << " damage" << endl;

}
AttackWarrior::~AttackWarrior(){
}
void AttackMage::attack(Character* character_, Character* enemy){
    int x = character_->getHolder();
    int y = enemy->getHealth();
    if (character_->getBurning() != 0){
        enemy->setHealth(enemy->getHealth() - character_->getBurning());
        cout << "Dealt " << character_->getBurning() << " points of burn damage" << endl;
    }
    if (x == 0){
        cout << "Fireball!" << endl;
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
        character_->burning();
    }
    else if (x == 1){
        cout << "Increasing Power!" << endl;
        character_->increasePower();
    }
    else if (x == 2){
        cout << "Lightning Bolt!" << endl;
        enemy->setHealth(enemy->getHealth() - character_->lightBolt());
    }
    else{
        enemy->setHealth(enemy->getHealth() - character_->getDamage());
    }
    cout << "Blast! You dealt " << y - enemy->getHealth() << " damage" << endl;
}
AttackMage::~AttackMage(){
        
}

void AttackAssassin::attack(Character* character_, Character* enemy){
    int y = enemy->getHealth();
    if (character_->getBurning() != 0){
        enemy->setHealth(enemy->getHealth() - character_->getBurning());
        cout << "Dealt " << character_->getBurning() << " points of poison damage" << endl;
    }
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    character_->burning();
    cout << "Stab! You dealt " << y - enemy->getHealth() << " damage" << endl;
}
AttackAssassin::~AttackAssassin(){
        
}


void AttackArcher::attack(Character* character_, Character* enemy){
    int x = character_->getHolder();
    int y = enemy->getHealth();
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
    cout << "Twang! You dealt " << y - enemy->getHealth() << " damage" << endl;
}
AttackArcher::~AttackArcher(){
        
}


void AttackEnemy::attack(Character* character_, Character* enemy){
    enemy->setHealth(enemy->getHealth() - character_->getDamage());
    cout << "Ouch! You were just dealt " << character_->getDamage() << " damage" << endl;
}
AttackEnemy::~AttackEnemy(){
	
}

