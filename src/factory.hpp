#include "character.hpp"
#include <string>
#include "attack.hpp"
using namespace std;


class factory{

        public:

        Character* createChar(string type, int one, int two, int three, int four){ //creates a character in a factory pattern manner, returns nullptr if invalid input
                if(type == "warrior"){
                        return new Warrior(one, two, three, four);
                }
                else if(type == "archer"){
                        return new Archer(one, two, three, four);
                }
                else if(type == "assassin"){
                        return new Assassin(one, two, three, four);
                }
                else if(type == "mage"){
                        return new Mage(one, two, three, four);
                }

                return nullptr; //accounts for invalid input

        }

        AttackStrat* createAttack(string type){
                if(type == "warrior"){
                        return new AttackWarrior;
                }
                else if(type == "archer"){
                        return new AttackArcher;
                }
                else if(type == "assassin"){
                        return new AttackAssassin;
                }
                else if(type == "mage"){
                        return new AttackMage;
                }

                return nullptr; //accounts for invalid input


        }


};
