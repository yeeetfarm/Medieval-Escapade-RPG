#ifndef __BATTLEOPTIONS_HPP__
#define __BATTLEOPTIONS_HPP__

#include <iostream>
#include "character.hpp"
#include "attack.hpp"
using namespace std;

class battleOptions{

	public:
	void printOptions(string type){
		if(type == "1" || type == "3"){
			cout << "Attack with melee weapon (1)" << endl << "Heal with potion (2)" << endl << "Give up your Adventure (3)" << endl;
		}
		else if(type == "2"){
			cout << "Attack with an arrow of your choice (1)" << endl << "Heal with potion (2)" << endl << "Give up your Adventure (3)" << endl;
		}
		else if(type == "4"){
			cout << "Use a spell of your choice (1)" << endl << "Heal with potion (2)" << endl << "Give up your Adventure (3)" << endl;
		}
	}

	void attackSeq(string type, Character* player, Character* enemy){
		if(type == "1" || type == "3"){
			player->attackHit(enemy);
		}
		else if(type == "2"){
			int arrowType;


			while(arrowType != 1 && arrowType != 2 && arrowType != 3 && arrowType != 4){
				cout << endl  << "Normal Shot (1)" << endl << "Multi-shot (2)" << endl << "Slow Shot (3)" << endl << "Poison Shot (4)" << endl;
				cin >> arrowType;

				if(arrowType == 1){
					player->setHolder(-1);
					player->attackHit(enemy);
				}
				else if(arrowType == 2){
					player->setHolder(0);
                                        player->attackHit(enemy);
				}
				else if(arrowType == 3){
					player->setHolder(1);
                                        player->attackHit(enemy);
				}
				else if(arrowType == 4){
					player->setHolder(2);
                                        player->attackHit(enemy);
				}
				else{
					cout << endl  << "Invalid option, please try again." << endl;
				}
 			}
		}
		else if(type == "4"){
			int spellType;


                        while(spellType != 1 && spellType != 2 && spellType != 3){
                                cout << endl  << "Fireball (1)" << endl << "Increase power (2)" << endl << "Lightning Bolt (3)" << endl;
                                cin >> spellType;

                                if(spellType == 1){
                                        player->setHolder(0);
                                        player->attackHit(enemy);
                                }
                                else if(spellType == 2){
                                        player->setHolder(1);
                                        player->attackHit(enemy);
                                }
                                else if(spellType == 3){
                                        player->setHolder(2);
                                        player->attackHit(enemy);
                                } 
                                else{
                                        cout << endl  << "Invalid option, please try again." << endl;
                                }
                        }

		}
	}

	void healSeq(Character* player){
		if(player->getPotion() > 0){	
			player->usePotion();
			cout << endl  <<"You consume a healing potion to regain 40 health!" << endl;
		}
		else{
		cout << endl  <<"Oh no! You don't have any more potions left to use!" << endl;
		}
	}

	void enemyAttackSeq(string type, Character* player, Character* enemy){
		enemy->attackHit(player); //work in progress, needs to be adjusted with actual attack function
	}

	void resetStats(string type, Character* player){
		if(type == "1"){
			player->setHealth(120);
			player->setSpeed(30);
		}
		else if(type == "2"){
			player->setHealth(90);
                        player->setSpeed(70);
			player->resetBurning();
		}
		else if(type == "3"){
                        player->setHealth(70);
                        player->setSpeed(110);
                }
		else if(type == "4"){
                        player->setHealth(70);
                        player->setDamage(80);
                        player->setSpeed(50);
			player->resetBurning();
			player->resetCounter();
                }

	}

};

#endif //__BATTLEOPTIONS_HPP__
