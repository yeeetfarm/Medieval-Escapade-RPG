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
cout << "Welcome to Medieval Escapade! Please enter a name for your character: ";
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

	Character* slim = new Slime(150, 40, 10, 40);	
	AttackStrat* slimy = new AttackEnemy; 

	slim->setAttack(slimy);

//start of first battle against slime

cout << endl << "In starting your adventure you stumble across a lone slime blocking your path on the road, how should you proceed?" << endl;

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
	if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((slim->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


	cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
	cout << endl << "Slime's current health : " << slim->getHealth() << endl << endl;

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
	else if(userChoice == "cheat"){
		slim->setHealth(0);
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
//end of slime fight

	battle.resetStats(type, player1); //reset characters stats
	player1->addPotion();
	
delete slim;
delete slimy;


//start of second battle against skeleton

	Character* skele = new Skeleton(180, 40, 20, 100);
        AttackStrat* skull = new AttackEnemy;

        skele->setAttack(skull);

cout << endl << "In following the road you come across an abandoned cabin and a skeleton emerges and comes running at you! how should you proceed?" << endl;

while(skele->getHealth() > 0){

        if((skipEnemyDamage == false) && (skele->getHealth() > 0) && (skele->getSpeed() > player1->getSpeed())){ //enemy attack or ability if it is faster
                        cout << endl  << "The skelton swings his rusty sword at you!" << endl;
                        battle.enemyAttackSeq(type, player1, skele);
        }
        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
	if((skele->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


        cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
        cout << endl << "Skeleton's current health : " << skele->getHealth() << endl << endl;

        battle.printOptions(type);

        cin >> userChoice;

        system("clear");
        if(userChoice == "1"){ //attack option
                battle.attackSeq(type, player1, skele);
		if(skele->getHealth() <= 0){
			skele->checkFatal();
		}
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
        else if(userChoice == "cheat"){
                skele->setHealth(0);
        }
        else{
                cout << endl  <<"Invalid option, please try again" << endl;
                skipEnemyDamage = true;
        }

        if((skipEnemyDamage == false) && (skele->getHealth() > 0) && (skele->getSpeed() <= player1->getSpeed())){ //enemy attack if it is slower, or use its ability
                        cout << endl  << "The skelton swings his rusty sword at you!" << endl;
                        battle.enemyAttackSeq(type, player1, skele);
        }


        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((skele->getSpeed() < player1->getSpeed())){
                skipEnemyDamage = false;
        }
}

cout << endl  << "You have defeated the skeleton, it crumbles to pieces and drops two potion" << endl;
//end of skeleton fight

        battle.resetStats(type, player1); //reset characters stats
                player1->addPotion();
		player1->addPotion();

                delete skele;
                delete skull;
                
//start of the third fight against giant spider

        Character* spider = new Spider(120, 40, 10, 60);
        AttackStrat* aSpider = new AttackEnemy;

        spider->setAttack(aSpider);

	cout << endl << "Passing by the log cabin and into the forest, you come across a giant spider in its web, how should you proceed?" << endl;

while(spider->getHealth() > 0){


        if((skipEnemyDamage == false) && (spider->getHealth() > 0) && (spider->getSpeed() > player1->getSpeed())){ //enemy attack or ability if it is faster
                if((rand() % 2) == 0){
                        cout << endl  << "The spider pounces forward and bites you!" << endl;
                        battle.enemyAttackSeq(type, player1, spider);
                }
                else{
                    cout << endl << "The spider shoots its web at you, causing you to get stuck!" << endl;
			spider->webOn();
                }

        }
        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((spider->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


        cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
        cout << endl << "Giant Spider's current health : " << spider->getHealth() << endl << endl;

        battle.printOptions(type);

        cin >> userChoice;

        system("clear");
        if(userChoice == "1"){ //attack option
        	if(spider->getWeb() == 0){        
		battle.attackSeq(type, player1, spider);
        	}
		else{
		cout << endl << "Oh no! You are caught in some spider web and are unable to move!" << endl;
		spider->webOff();
		}
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
        else if(userChoice == "cheat"){
                spider->setHealth(0);
        }
        else{
                cout << endl  <<"Invalid option, please try again" << endl;
                skipEnemyDamage = true;
        }

        if((skipEnemyDamage == false) && (spider->getHealth() > 0) && (spider->getSpeed() <= player1->getSpeed())){ //enemy attack if it is slower, or use its ability

                if((rand() % 2) == 0){
                        cout << endl  << "The spider pounces forward and bites you!" << endl;
                        battle.enemyAttackSeq(type, player1, spider);
                }
                else{
			cout << endl << "The spider shoots its web at you, causing you to get stuck!" << endl;
                        spider->webOn();
                }

        }


        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((spider->getSpeed() < player1->getSpeed())){
                skipEnemyDamage = false;
        }
}

cout << endl << "You have vanquished the Giant spider, and for your efforts you recieve three more potions"  << endl;

//end of spider fight 
		battle.resetStats(type, player1); //reset characters stats
                player1->addPotion();
                player1->addPotion();
		player1->addPotion();

                delete spider;
                delete aSpider;

//start of fourth fight against zombie

 	Character* zombie = new Zombies(150, 60, 20, 70);
        AttackStrat* aZombie = new AttackEnemy;

        zombie->setAttack(aZombie);




cout << endl << "Through wondering the forest you come accross a large castle, but in order to get to the gate you must pass through the graveyard" << endl;
cout << "While treading through the graveyard a zombie grabs you leg and begins its attack! how will you proceed? " << endl;

while(zombie->getHealth() > 0){


        if((skipEnemyDamage == false) && (zombie->getHealth() > 0) && (zombie->getSpeed() > player1->getSpeed())){ //enemy attack or ability if it is faster
                        cout << endl  << "The zombie bites a chunk of your flesh dealing 5 dmg and regains 5 hp as well as scratching you!" << endl;
                        battle.enemyAttackSeq(type, player1, zombie);
			zombie->leech(player1);
        }
        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((zombie->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


        cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
        cout << endl << "Zombie's current health : " << zombie->getHealth() << endl << endl;

        battle.printOptions(type);

        cin >> userChoice;

        system("clear");
        if(userChoice == "1"){ //attack option
                battle.attackSeq(type, player1, zombie);
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
        else if(userChoice == "cheat"){
                zombie->setHealth(0);
        }
        else{
                cout << endl  <<"Invalid option, please try again" << endl;
                skipEnemyDamage = true;
        }

        if((skipEnemyDamage == false) && (zombie->getHealth() > 0) && (zombie->getSpeed() <= player1->getSpeed())){ //enemy attack if it is slower, or use its ability
                        cout << endl  << "The zombie bites a chunk of your flesh dealing 5 dmg and regains 5 hp as well as scratching you!" << endl;
                        battle.enemyAttackSeq(type, player1, zombie);
			zombie->leech(player1);
        }


        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((zombie->getSpeed() < player1->getSpeed())){
                skipEnemyDamage = false;
        }

}

cout << endl << "You have sent the zombie to his second death, and for your reward you recieve three more potions"  << endl;

//end of zombie fight  
                battle.resetStats(type, player1); //reset characters stats
                player1->addPotion();
                player1->addPotion();
                player1->addPotion();

                delete zombie;
                delete aZombie;

//start of fifth fight against ogre

	Character* ogre = new Ogre(200, 60, 25, 10);
        AttackStrat* anOgre = new AttackEnemy;

        ogre->setAttack(anOgre);

cout << endl << "Past the graveyard there is a lone Ogre standing at the entrance to the castle, how should you proceed?" << endl;

while(ogre->getHealth() > 0){


        if((skipEnemyDamage == false) && (ogre->getHealth() > 0) && (ogre->getSpeed() > player1->getSpeed())){ //enemy attack or ability if it is faster
                        cout << endl  << "The ogre stomps on you with tremendous force!" << endl;
                        battle.enemyAttackSeq(type, player1, ogre);
        }
        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((ogre->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


        cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
        cout << endl << "Ogre's current health : " << ogre->getHealth() << endl << endl;

        battle.printOptions(type);

        cin >> userChoice;

        system("clear");
        if(userChoice == "1"){ //attack option
                battle.attackSeq(type, player1, ogre);
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
        else if(userChoice == "cheat"){
                ogre->setHealth(0);
        }
        else{
                cout << endl  <<"Invalid option, please try again" << endl;
                skipEnemyDamage = true;
        }

        if((skipEnemyDamage == false) && (ogre->getHealth() > 0) && (ogre->getSpeed() <= player1->getSpeed())){ //enemy attack if it is slower, or use its ability
                        cout << endl  << "The ogre stomps on you with tremendous force!" << endl;
                        battle.enemyAttackSeq(type, player1, ogre);
        }


        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((ogre->getSpeed() < player1->getSpeed())){
                skipEnemyDamage = false;
        }

}

cout << endl << "You have defeated the mighty Ogre and gained entrance into the castle, good job!" << endl;
cout << endl << "You also find three more potions! Hurray " << endl;

//end of zombie fight   
                battle.resetStats(type, player1); //reset characters stats
                player1->addPotion();
                player1->addPotion();
                player1->addPotion();

                delete ogre;
                delete anOgre;

//start of final fight against the dragon

	Character* dragon = new Dragon(220, 60, 25, 80);
        AttackStrat* aDragon = new AttackEnemy;

        dragon->setAttack(aDragon);

cout << endl << "Ascending the castle steps, you encounter an enormous dragon lying on a large pile of treasure, how should you proceed?" << endl;

while(dragon->getHealth() > 0){

	dragon->dodgeAttack();

        if((skipEnemyDamage == false) && (dragon->getHealth() > 0) && (dragon->getSpeed() > player1->getSpeed())){ //enemy attack or ability if it is faster
                        cout << endl  << "The dragon spits a ball of fire at you!" << endl;
                        battle.enemyAttackSeq(type, player1, dragon);
        }
        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((dragon->getSpeed() > player1->getSpeed())){
                skipEnemyDamage = false;
        }


        cout << endl << userName << "'s current health : " << player1->getHealth() << endl;
        cout << endl << "Dragon's current health : " << dragon->getHealth() << endl << endl;

        battle.printOptions(type);

        cin >> userChoice;

        system("clear");
        if(userChoice == "1"){ //attack option
         	if(dragon->getDodge() == 0){       
			battle.attackSeq(type, player1, dragon);
        	}
		else{
			cout << endl << "The dragon has dodged your attack by flying away!" << endl;
		}
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
        else if(userChoice == "cheat"){
                dragon->setHealth(0);
        }
        else{
                cout << endl  <<"Invalid option, please try again" << endl;
                skipEnemyDamage = true;
        }

        if((skipEnemyDamage == false) && (dragon->getHealth() > 0) && (dragon->getSpeed() <= player1->getSpeed())){ //enemy attack if it is slower, or use its ability
                        cout << endl  << "The dragon spits a ball of fire at you!" << endl;
                        battle.enemyAttackSeq(type, player1, dragon);
        }


        if(player1->getHealth() <= 0){ //check if player has died
                cout << endl << "Gamer over, You died!" << endl;
                return 0;
        }
        if((dragon->getSpeed() < player1->getSpeed())){
                skipEnemyDamage = false;
        }

}	

cout << endl << "Congratulations! You have slain the almighty dragon!!!" << endl;
cout << endl << "All the treasure is now yours to keep!!! " << endl;
cout << endl << endl << "Thanks for Playing! Until your next adventure ..." << endl;

delete dragon;
delete aDragon;



//save this for the end
delete player1;
delete aPlayer; 

    return 0;
}

