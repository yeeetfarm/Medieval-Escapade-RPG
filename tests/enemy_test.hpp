#ifndef __ENEMY_TEST_HPP__
#define __ENEMY_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/character.hpp"
#include "../src/attack.hpp"

TEST(DragonTest, Health){
	Dragon* drag = new Dragon(1, 2, 3, 4);
	EXPECT_EQ(drag->getHealth(), 1);
	delete drag;
}

TEST(DragonTest, Armor){
        Dragon* drag = new Dragon(1, 2, 3, 4);
        EXPECT_EQ(drag->getArmor(), 2);
        delete drag;
}

TEST(DragonTest, Damage){
        Dragon* drag = new Dragon(1, 2, 3, 4);
        EXPECT_EQ(drag->getDamage(), 3);
        delete drag;
}

TEST(DragonTest, Speed){
        Dragon* drag = new Dragon(1, 2, 3, 4);
        EXPECT_EQ(drag->getSpeed(), 4);
        delete drag;
}

TEST(DragonTest, DodgeGE){
	Dragon* drag = new Dragon(1, 2, 3, 4);
	drag->dodgeAttack();
	EXPECT_GE(drag->getDodge(), 0);
	delete drag;
}

TEST(DragonTest, DodgeLE){
	Dragon* drag = new Dragon(1, 2, 3, 4);
        drag->dodgeAttack();
        EXPECT_LE(drag->getDodge(), 1);
        delete drag;
}

TEST(OgreTest, Health){
        Ogre* og = new Ogre(5, 6, 7, 8);
        EXPECT_EQ(og->getHealth(), 5);
        delete og;
}

TEST(OgreTest, Armor){
        Ogre* og = new Ogre(5, 6, 7, 8);
        EXPECT_EQ(og->getArmor(), 6);
        delete og;
}

TEST(OgreTest, Damage){
        Ogre* og = new Ogre(5, 6, 7, 8);
        EXPECT_EQ(og->getDamage(), 7);
        delete og;
}

TEST(OgreTest, Speed){
        Ogre* og = new Ogre(5, 6, 7, 8);
        EXPECT_EQ(og->getSpeed(), 8);
        delete og;
}

TEST(SlimeTest, Health){
       	Slime* slim = new Slime(9, 10, 11, 12);
        EXPECT_EQ(slim->getHealth(), 9);
        delete slim;
}

TEST(SlimeTest, Armor){
        Slime* slim = new Slime(9, 10, 11, 12);
        EXPECT_EQ(slim->getArmor(), 10);
        delete slim;
}

TEST(SlimeTest, Damage){
        Slime* slim = new Slime(9, 10, 11, 12);
        EXPECT_EQ(slim->getDamage(), 11);
        delete slim;
}

TEST(SlimeTest, Speed){
        Slime* slim = new Slime(9, 10, 11, 12);
        EXPECT_EQ(slim->getSpeed(), 12);
        delete slim;
}

TEST(SlimeTest, reduceSpeed){
	Slime* slim = new Slime(9, 10, 11, 12);
	Warrior* war = new Warrior(30, 30, 30, 30);
	slim->reduceSpeed(war);
	EXPECT_EQ(war->getSpeed(), 10);
	delete slim;
	delete war;
}

TEST(SkeletonTest, Health){
        Skeleton* skel = new Skeleton(13, 14, 15, 16);
        EXPECT_EQ(skel->getHealth(), 13);
        delete skel;
}

TEST(SkeletonTest, Armor){
        Skeleton* skel = new Skeleton(13, 14, 15, 16);
        EXPECT_EQ(skel->getArmor(), 14);
        delete skel;
}

TEST(SkeletonTest, Damage){
        Skeleton* skel = new Skeleton(13, 14, 15, 16);
        EXPECT_EQ(skel->getDamage(), 15);
        delete skel;
}

TEST(SkeletonTest, Speed){
        Skeleton* skel = new Skeleton(13, 14, 15, 16);
        EXPECT_EQ(skel->getSpeed(), 16);
        delete skel;
}

TEST(SkeletonTest, checkFatal){
	Skeleton* skel = new Skeleton(4, 0, 15, 16);
	Warrior* war = new Warrior(20, 20, 20, 20);
	AttackWarrior* aWarrior = new AttackWarrior;
	war->setAttack(aWarrior);
	war->attackHit(skel);
	skel->checkFatal();
	EXPECT_EQ(skel->getHealth(), 1);
	delete skel;
	delete war;
	delete aWarrior;
}

TEST(SpiderTest, Health){
        Spider* spid = new Spider(17, 18, 19, 20);
        EXPECT_EQ(spid->getHealth(), 17);
        delete spid;
}

TEST(SpiderTest, Armor){
        Spider* spid = new Spider(17, 18, 19, 20);
        EXPECT_EQ(spid->getArmor(), 18);
        delete spid;
}

TEST(SpiderTest, Damage){
        Spider* spid = new Spider(17, 18, 19, 20);
        EXPECT_EQ(spid->getDamage(), 19);
        delete spid;
}

TEST(SpiderTest, Speed){
        Spider* spid = new Spider(17, 18, 19, 20);
        EXPECT_EQ(spid->getSpeed(), 20);
        delete spid;
}

TEST(SpiderTest, Web){
	Spider* spid = new Spider(17, 18, 19, 20);
	spid->webOn();
	EXPECT_EQ(spid->getWeb(), 1);
	delete spid;
}

TEST(ZombiesTest, Health){
        Zombies* zomb = new Zombies(21, 22, 23, 24);
        EXPECT_EQ(zomb->getHealth(), 21);
        delete zomb;
}

TEST(ZombiesTest, Armor){
        Zombies* zomb = new Zombies(21, 22, 23, 24);
        EXPECT_EQ(zomb->getArmor(), 22);
        delete zomb;
}

TEST(ZombiesTest, Damage){
        Zombies* zomb = new Zombies(21, 22, 23, 24);
        EXPECT_EQ(zomb->getDamage(), 23);
        delete zomb;
}

TEST(ZombiesTest, Speed){
        Zombies* zomb = new Zombies(21, 22, 23, 24);
        EXPECT_EQ(zomb->getSpeed(), 24);
        delete zomb;
}

TEST(ZombiesTest, LeechZombHealth){
	Zombies* zomb = new Zombies(21, 22, 23, 24);
	Warrior* war = new Warrior(20, 20, 20, 20);
        zomb->leech(war);
	EXPECT_EQ(zomb->getHealth(), 26);
	delete zomb;
	delete war;	
}

TEST(ZombiesTest, LeechWarHealth){
	Zombies* zomb = new Zombies(21, 22, 23, 24);
        Warrior* war = new Warrior(20, 20, 20, 20);
        zomb->leech(war);
        EXPECT_EQ(war->getHealth(), 15);
        delete zomb;
        delete war;
}

#endif //ENEMY_TEST_HPP__
