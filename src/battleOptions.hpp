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
		cout << "Not Implemented" << endl;
		}
	}

};

#endif //__BATTLEOPTIONS_HPP__
