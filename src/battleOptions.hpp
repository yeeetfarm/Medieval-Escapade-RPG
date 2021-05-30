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

	void attackSeq(string type, Character* user, Character* enemy){
		if(type == "1"){
			user->attackHit(enemy);
		}
		else{
		cout << "Not implemented yet" << endl;
		}
	}

	void healSeq(Character* user){
		if(user->getPotion() > 0){	
			user->usePotion();
			cout << endl  <<"You consume a healing potion to regain 30 health!" << endl;
		}
		else{
		cout << endl  <<"Oh no! You don't have any more potions left to use!" << endl;
		}
	}


};

#endif //__BATTLEOPTIONS_HPP__
