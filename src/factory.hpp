#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


#include "character.hpp"
#include <string>
#include "attack.hpp"
using namespace std;


class factory{

        public:

        Character* createChar(string type, int one, int two, int three, int four){ //creates a character in a factory pattern manner, returns nullptr if invalid input
                if(type == "1"){
                        return new Warrior(one, two, three, four);
                }
                else if(type == "2"){
                        return new Archer(one, two, three, four);
                }
                else if(type == "3"){
                        return new Assassin(one, two, three, four);
                }
                else if(type == "4"){
                        return new Mage(one, two, three, four);
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
