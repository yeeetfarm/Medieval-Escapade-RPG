#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

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
string userChoice = ""; //keeps track of the choice user makes in battle
string giveUp = "bruh"; //indicates if the user has decided to give up
bool skipEnemyDamage = false; //indicates if the user should skip taking damage from enemy, used when player should not use their turn.
srand(time(0)); //rand value to be used for enemy abilites



bool validType = false;
cout << "Welcome to PLACEHOLDER! Please enter a name for your character: ";
cin >> userName;

//write more preliminary dialogue for introduction to the story/dungeon

while(validType == false){
	cout << userName << ", please press the number of character you want to be, the options are warrior(1) , archer(2), assassin(3), or mage(4): ";
        cin >> type;

	system("clear"); //command to clear terminal so only the important text is on the screen		

	if(type != "1" && type != "2" && type != "3" && type != "4"){
		cout << endl  <<"Invalid option, please try again" << endl;
	}
	else{
		validType = true;
	}
}
	//creation of character if proper criteria is met
       	Character* player1 = f.createChar(type);
       	AttackStrat* aPlayer = f.createAttack(type);
       
	player1->setAttack(aPlayer);

	Character* slim = new Slime(150, 40, 20, 40);	
	AttackStrat* slimy = new AttackEnemy; 

	slim->setAttack(slimy);

//start of first battle against slime

cout << endl << "In starting your adventure you stumble across a lone slime blocking you path on the road, how should you proceed?" << endl;

while(slim->getHealth() > 0){
	

	if((skipEnemyDamage == false) && (slim->getHealth() > 0) && (slim->getSpeed() > player1->getSpeed())){ //enemy attack or ability if it is faster
                if((rand() % 2) == 0){  
                        cout << endl  << "The slime jumps and bounces off of you!" << endl;
			battle.enemyAttackSeq(type, player1, slim);
                }
                else{
                        slim->reduceSpeed(player1);
                        cout << endl << "The slime covers you in goo, making it tougher to move " << endl;
                }

        }
        if((slim->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


	cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
	cout << endl << "Slime's current health : " << slim->getHealth() << endl;

	battle.printOptions(type);	

	cin >> userChoice;

	system("clear");
	if(userChoice == "1"){ //attack option
		battle.attackSeq(type, player1, slim);		
	}
	else if (userChoice == "2"){ //heal option
		if(player1->getPotion() <= 0){
			skipEnemyDamage = true;
		}
		battle.healSeq(player1);	
	}
	else if (userChoice == "3"){ //give up option
		cout << endl <<"You have selected the give up option, are you sure you want to give up?" << endl << "press 1 to give up and 2 to return to battle" << endl;
		giveUp = "6";
		while(giveUp != "1" && giveUp != "2")
		cin >> giveUp;
	
		if(giveUp == "1"){
		 cout << endl << "And so you give up and return home to fight another day, better luck next time!" << endl;
		return 0;	
		}
		else if(giveUp == "2"){
			
			skipEnemyDamage = true;		
		}
		else if(giveUp != "1" && giveUp != "2"){
			cout << endl  << "Invalid Option please try again" << endl;
		}
	}
	else{
		cout << endl  <<"Invalid option, please try again" << endl;
		skipEnemyDamage = true;
	}
	
	if((skipEnemyDamage == false) && (slim->getHealth() > 0) && (slim->getSpeed() <= player1->getSpeed())){ //enemy attack if it is slower, or use its ability
	
		if((rand() % 2) == 0){	
			cout << endl  << "The slime jumps and bounces off of you!" << endl;
			battle.enemyAttackSeq(type, player1, slim);
		}
		else{
			slim->reduceSpeed(player1);
			cout << endl << "The slime covers you in goo, making it tougher to move " << endl; 
		}

	}
	

	if(player1->getHealth() <= 0){ //check if player has died
		cout << endl << "Gamer over, You died!" << endl;
		return 0;
	}	
	if((slim->getSpeed() < player1->getSpeed())){
		skipEnemyDamage = false;
	}

}

cout << endl  << "You have defeated the slime, and it dropped a potion" << endl;


	battle.resetStats(type, player1); //reset characters stats
	player1->addPotion();
	
delete slim;
delete slimy;

delete player1;
delete aPlayer; 

    return 0;
}

