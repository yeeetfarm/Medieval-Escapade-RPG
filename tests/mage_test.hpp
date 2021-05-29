#ifndef __MAGE_TEST_HPP__
#define __MAGE_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/character.hpp"
#include "../src/attack.hpp"

TEST(MageTest, BasicTest1){
    Mage* mage1 = new Mage(1, 1, 1, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(1, 1, 1, 1);

    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage2->getHealth(), 0);
}

TEST(MageTest, IsBurning){
    Mage* mage1 = new Mage(1, 1, 1, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(1, 1, 1, 1);

    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage1->getBurning(), 1);
}

TEST(MageTest, IsBurning2){
    Mage* mage1 = new Mage(1, 1, 10, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(100, 1, 1, 1);

    mage1->attackHit(mage2);
    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage2->getHealth(), 79);
}

TEST(MageTest, IncreasePower){
    Mage* mage1 = new Mage(1, 1, 10, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(100, 1, 1, 1);
    mage1->setHolder(1);

    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage2->getHealth(), 100);
}

TEST(MageTest, IncreasePower2){
    Mage* mage1 = new Mage(1, 1, 10, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(100, 1, 1, 1);
    mage1->setHolder(1);

    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage1->getDamage(), 30);
}

TEST(MageTest, LightBolt){
    Mage* mage1 = new Mage(1, 1, 10, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(100, 1, 1, 1);
    mage1->setHolder(2);

    mage1->attackHit(mage2);
    mage1->attackHit(mage2);
    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage2->getHealth(), 40);
}

TEST(MageTest, LightBolt2){
    Mage* mage1 = new Mage(1, 1, 10, 1);
    AttackMage* aMage = new AttackMage;
    mage1->setAttack(aMage);

    Mage* mage2 = new Mage(100, 1, 1, 1);
    mage1->setHolder(2);

    mage1->attackHit(mage2);

    EXPECT_DOUBLE_EQ(mage2->getHealth(), 90);
}


#endif
