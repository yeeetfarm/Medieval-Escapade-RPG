#include <iostream>
#include <vector>
#include <stdlib.h>

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
	

	//ENEMIES
    Dragon* drag = new Dragon(1, 1, 1, 1);
    if(drag->dodgeAttack() == true){
	cout << "dodged" << endl;
    }
    else if(drag->dodgeAttack() == false){
	cout << "hit" << endl;
    }

    Ogre* og = new Ogre(1, 1, 1, 1);

    Slime* slim = new Slime(1, 1, 1, 1);

    Skeleton* skel = new Skeleton(1, 1, 1, 1);

    Spider* spid = new Spider(1, 1, 1, 1);

    Zombies* zomb = new Zombies(1, 1, 1, 1);

    return 0;
}

