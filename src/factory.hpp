#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


#include "character.hpp"
#include <string>
#include "attack.hpp"
using namespace std;


class factory{

        public:

        Character* createChar(string type){ //creates a character in a factory pattern manner, returns nullptr if invalid input
                if(type == "1"){
                        return new Warrior(100, 70, 70, 30);
                }
                else if(type == "2"){
                        return new Archer(70, 40, 60, 70);
                }
                else if(type == "3"){
                        return new Assassin(50, 50, 50, 100);
                }
                else if(type == "4"){
                        return new Mage(50, 40, 80, 50);
                }

                return nullptr; //accounts for invalid input

        }

        AttackStrat* createAttack(string type){
                if(type == "1"){
                        return new AttackWarrior;
                }
                else if(type == "2"){
                        return new AttackArcher;
                }
                else if(type == "3"){
                        return new AttackAssassin;
                }
                else if(type == "4"){
                        return new AttackMage;
                }

                return nullptr; //accounts for invalid input


        }


};
#endif //__FACTORY_HPP__
