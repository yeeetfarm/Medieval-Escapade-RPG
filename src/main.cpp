#include <iostream>
#include <vector>

#include "character.hpp"
#include "attack.hpp"
#include "warrior.hpp"

using namespace std;

int main(){
    Warrior* temp = new Warrior(1, 1, 1, 1);
    AttackWarrior* aWarrior = new AttackWarrior;
    temp->setAttack(aWarrior);

    Warrior* temp2 = new Warrior(1, 1, 1, 1);

    temp->attackHit(temp2);

	return 0;
}

