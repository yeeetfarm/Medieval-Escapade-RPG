#ifndef __BATTLEOPTIONS_HPP__
#define __BATTLEOPTIONS_HPP__

#include <iostream>
#include "character.hpp"
#include "attack.hpp"
using namespace std;

class battleOptions{

	public:
	void printOptions(string type){
		if(type == "1"){
		cout << "Attack with melee weapon (1)" << endl << "Heal with potion (2)" << endl << "Give up and try again (3)" << endl;
		}
		else{
		cout << "Not Implemented yet" << endl;
		}
	}

	void attackSeq(string type, Character* player, Character* enemy){
		if(type == "1"){
			player->attackHit(enemy);
		}
		else{
		cout << "Not implemented yet" << endl;
		}
	}

	void healSeq(Character* player){
		if(player->getPotion() > 0){	
			player->usePotion();
			cout << endl  <<"You consume a healing potion to regain 30 health!" << endl;
		}
		else{
		cout << endl  <<"Oh no! You don't have any more potions left to use!" << endl;
		}
	}

	void enemyAttackSeq(string type, Character* player, Character* enemy){
		enemy->attackHit(player); //work in progress, needs to be adjusted with actual attack function
	}

};

#endif //__BATTLEOPTIONS_HPP__
