#include <iostream>
#include <vector>

#include "character.hpp"
#include "attack.hpp"

using namespace std;

int main(){
    Warrior* warr1 = new Warrior(1, 1, 1, 1);
    AttackWarrior* aWarrior = new AttackWarrior;
    warr1->setAttack(aWarrior);

    Warrior* warr2 = new Warrior(1, 1, 1, 1);

    warr1->attackHit(warr2);
    
    cout << warr2->getHealth() << endl;

    Archer* arch1 = new Archer(1, 1, 1, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(1, 1, 1, 1);

    arch1->attackHit(arch2);
	return 0;
}

