#ifndef __WARRIOR_TEST_HPP__
#define __WARRIOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/character.hpp"
#include "../src/attack.hpp"

TEST(WarriorTest, BasicTest1){
    Warrior* warr1 = new Warrior(1, 1, 1, 1);
    AttackWarrior* aWarrior = new AttackWarrior;
    warr1->setAttack(aWarrior);

    Warrior* warr2 = new Warrior(1, 1, 1, 1);

    warr1->attackHit(warr2);

    EXPECT_DOUBLE_EQ(warr2->getHealth(), 0);
}


#endif
