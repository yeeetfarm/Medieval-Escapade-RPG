#ifndef __ATTACK_HPP__
#define __ATTACK_HPP__

#include <iostream>

using namespace std;

class attackStrat{
public:
    virtual double attack() = 0;
};

//FIXME Finish all of the attacks

class attackWarrior : public attackStrat{
public:
    virtual double attack(){

        return 0;
    }
};

class attackMage : public attackStrat{
public:
    virtual double attack(){

        return 0;
    }
};

class attackAssassin : public attackStrat{
public:
    virtual double attack(){

        return 0;
    }
};

class attackArcher : public attackStrat{
public:
    virtual double attack(){

        return 0;
    }
};

#endif //__ATTACK_HPP__
