#include <iostream>
#include <vector>

#include "character.hpp"
#include "attack.hpp"

using namespace std;

int main(){
    Character* warrior = new Character(1, 1, 1, 1);
    AttackWarrior* aWarrior = new AttackWarrior;
    warrior->setAttack(aWarrior);

    Character* zombie = new Character(10, 10, 0, 0);

    warrior->attackHit(zombie);

    return 0;
}

