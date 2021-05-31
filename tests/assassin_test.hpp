#ifndef __ASSASSIN_TEST_HPP__
#define __ASSASSIN_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/character.hpp"
#include "../src/attack.hpp"

TEST(AssassinTest, BasicTest1){
    Assassin* assa1 = new Assassin(1, 1, 1, 1);
    AttackAssassin* aAssa = new AttackAssassin;
    assa1->setAttack(aAssa);

    Assassin* assa2 = new Assassin(1, 1, 1, 1);

    assa1->attackHit(assa2);

    EXPECT_DOUBLE_EQ(assa2->getHealth(), 0);
    delete assa1;
    delete assa2;  
    delete aAssa;
}

TEST(AssassinTest, Bleeding){
    Assassin* assa1 = new Assassin(1, 1, 10, 1);
    AttackAssassin* aAssa = new AttackAssassin;
    assa1->setAttack(aAssa);

    Assassin* assa2 = new Assassin(100, 1, 1, 1);

    assa1->attackHit(assa2);
    assa1->attackHit(assa2);

    EXPECT_DOUBLE_EQ(assa2->getHealth(), 75);
    delete assa1;
    delete assa2;
    delete aAssa;
}

TEST(AssassinTest, Bleeding2){
    Assassin* assa1 = new Assassin(1, 1, 10, 1);
    AttackAssassin* aAssa = new AttackAssassin;
    assa1->setAttack(aAssa);

    Assassin* assa2 = new Assassin(100, 1, 1, 1);

    assa1->attackHit(assa2);

    EXPECT_DOUBLE_EQ(assa1->getBurning(), 5);
    delete assa1;
    delete assa2;
    delete aAssa;
}


#endif
