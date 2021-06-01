#ifndef __ARCHER_TEST_HPP__
#define __ARCHER_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/character.hpp"
#include "../src/attack.hpp"

TEST(ArcherTest, BasicTest1){
    Archer* arch1 = new Archer(1, 1, 1, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(1, 1, 1, 1);

    arch1->attackHit(arch2);

    EXPECT_DOUBLE_EQ(arch2->getHealth(), 0);
    delete arch1;
    delete arch2;
    delete aArcher;
}

TEST(ArcherTest, GetHolder){
    Archer* arch1 = new Archer(1, 1, 1, 1);

    arch1->setHolder(1);

    EXPECT_DOUBLE_EQ(arch1->getHolder(), 1);
    delete arch1;
}

TEST(ArcherTest, GetHolder2){
    Archer* arch1 = new Archer(1, 1, 1, 1);

    arch1->setHolder(1);
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();

    ASSERT_EQ(arch1->isArrow(), false);
    delete arch1;
}

TEST(ArcherTest, IsPoison){
    Archer* arch1 = new Archer(1, 1, 1, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setHolder(2);
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(100, 1, 1, 1);

    arch1->attackHit(arch2);

    EXPECT_DOUBLE_EQ(arch1->getBurning(), 2);
    delete arch1;
    delete arch2;
    delete aArcher;
}

TEST(ArcherTest, IsPoison2){
    Archer* arch1 = new Archer(1, 1, 10, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setHolder(2);
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(100, 1, 1, 1);

    arch1->attackHit(arch2);

    arch1->attackHit(arch2);

    EXPECT_DOUBLE_EQ(arch1->getBurning(), 4);
    delete arch1;
    delete arch2;
    delete aArcher;
}


TEST(ArcherTest, IsPoison3){
    Archer* arch1 = new Archer(1, 1, 10, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setHolder(2);
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(100, 1, 1, 1);

    arch1->attackHit(arch2);

    arch1->attackHit(arch2);

    EXPECT_DOUBLE_EQ(arch2->getHealth(), 78);
    delete arch1;
    delete arch2;
    delete aArcher;
}

TEST(ArcherTest, MultiShot){
    Archer* arch1 = new Archer(1, 1, 10, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setHolder(0);
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(100, 1, 1, 1);

    arch1->attackHit(arch2);

    EXPECT_DOUBLE_EQ(arch2->getHealth(), 70);
    delete arch1;
    delete arch2;
    delete aArcher;
}

TEST(ArcherTest, SlowShot){
    Archer* arch1 = new Archer(1, 1, 10, 1);
    AttackArcher* aArcher = new AttackArcher;
    arch1->setHolder(1);
    arch1->setAttack(aArcher);

    Archer* arch2 = new Archer(100, 1, 1, 11);

    arch1->attackHit(arch2);

    EXPECT_DOUBLE_EQ(arch2->getSpeed(), 1);
    delete arch1;
    delete arch2;
    delete aArcher;
}

TEST(ArcherTest, GetHolder3){
    Archer* arch1 = new Archer(1, 1, 1, 1);

    arch1->setHolder(1);
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->useArrow();
    arch1->resetBow();

    ASSERT_EQ(arch1->isArrow(), true);
    delete arch1;
}




#endif
