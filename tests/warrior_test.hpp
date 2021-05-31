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
    delete warr1;
    delete warr2;
    delete aWarrior;
}

TEST(WarriorTest, GetHealth){
    Warrior* warr1 = new Warrior(1, 1, 6, 1);
    AttackWarrior* aWarrior = new AttackWarrior;
    warr1->setAttack(aWarrior);

    Warrior* warr2 = new Warrior(10, 1, 1, 1);

    warr1->attackHit(warr2);

    ASSERT_EQ(warr2->healthCheck(), true);
    delete warr1;
    delete warr2;
    delete aWarrior;
}

TEST(WarriorTest, IsDead){
    Warrior* warr1 = new Warrior(1, 1, 6, 1);
    AttackWarrior* aWarrior = new AttackWarrior;
    warr1->setAttack(aWarrior);

    Warrior* warr2 = new Warrior(6, 1, 1, 1);

    warr1->attackHit(warr2);

    ASSERT_EQ(warr2->isAlive(), false);
    delete warr1;
    delete warr2;
    delete aWarrior;
}

TEST(WarriorTest, GetSpeed){
    Warrior* warr1 = new Warrior(1, 1, 6, 11);
    AttackWarrior* aWarrior = new AttackWarrior;
    warr1->setAttack(aWarrior);

    EXPECT_DOUBLE_EQ(warr1->getSpeed(), 11);
    delete warr1;
    delete aWarrior;
}

TEST(WarriorTest, GetArmor){
    Warrior* warr1 = new Warrior(1, 3, 6, 11);
    AttackWarrior* aWarrior = new AttackWarrior;
    warr1->setAttack(aWarrior);

    EXPECT_DOUBLE_EQ(warr1->getArmor(), 3);
    delete warr1;
    delete aWarrior;
}


#endif
