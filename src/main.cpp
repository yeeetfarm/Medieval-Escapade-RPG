#include <iostream>
#include <vector>
#include <stdlib.h>

#include "character.hpp"
#include "attack.hpp"
#include "factory.hpp"
#include "battleOptions.hpp"

using namespace std;

int main(){
    //Warrior* warr1 = new Warrior(1, 1, 1, 1);
    //AttackWarrior* aWarrior = new AttackWarrior;
    //warr1->setAttack(aWarrior);
    

    //Warrior* warr2 = new Warrior(1, 1, 1, 1);

    //warr1->attackHit(warr2);
    
    //cout << warr2->getHealth() << endl;
    
    //delete warr1;
    //delete warr2;

    //Archer* arch1 = new Archer(1, 1, 1, 1);
    //AttackArcher* aArcher = new AttackArcher;
    //arch1->setAttack(aArcher);

    //Archer* arch2 = new Archer(1, 1, 1, 1);

    //arch1->attackHit(arch2);

    //delete arch1;
    //delete arch2;

    //ENEMIES
    //Dragon* drag = new Dragon(1, 1, 1, 1);
  //  if(drag->dodgeAttack() == true){
//	cout << "dodged" << endl;
    //}
  //  else if(drag->dodgeAttack() == false){
//	cout << "hit" << endl;
    //}

    //delete drag;

    //Ogre* og = new Ogre(1, 1, 1, 1);
    //delete og;

    //Slime* slim = new Slime(1, 1, 1, 1);
    //delete slim;

    //Skeleton* skel = new Skeleton(1, 1, 1, 1);
    //delete skel;

    //Spider* spid = new Spider(1, 1, 1, 1);
   // delete spid;

   // Zombies* zomb = new Zombies(1, 1, 1, 1);
   // delete zomb;

factory f; //factory object used to build user's character
string type; //string to identify type of character 1-warrior, 2-archer, 3-assassin, 4-mage
string userName; //string to keep track of the user defined character name
battleOptions battle; //battle options object to have access to all the battle options classes
string userChoice = "";


bool validType = false;
cout << "Welcome to PLACEHOLDER! Please enter a name for your character: ";
cin >> userName;

//write more preliminary dialogue for introduction to the story/dungeon

while(validType == false){
	cout << userName << ", please press the number of character you want to be, the options are warrior(1) , archer(2), assassin(3), or mage(4): ";
        cin >> type;

	if(type != "1" && type != "2" && type != "3" && type != "4"){
		cout << endl  <<"Invalid option, please try again" << endl;
	}
	else{
		validType = true;
	}
}
	//creation of character if proper criteria is met
       	Character* player1 = f.createChar(type, 1, 1, 1, 1);
       	AttackStrat* aPlayer = f.createAttack(type);
        
	player1->setAttack(aPlayer);

	Character* slim = new Slime(1, 1, 1, 1);	

//start of first battle against slime
while(slim->getHealth() > 0){

	battle.printOptions(type);	

	cin >> userChoice;	
	if(userChoice == "1"){ //attack option
		battle.attackSeq(type, player1, slim);		
	}
	else if (userChoice == "2"){ //heal option
		battle.healSeq(player1);	
	}
	else if (userChoice == "3"){ //give up option

	}
	else{
		cout << endl  <<"Invalid option, please try again" << endl;
	}
	
	cout << endl  << player1->getHealth() << endl;
}

cout << endl  << "You have defeated the slime" << endl;









    return 0;
}

