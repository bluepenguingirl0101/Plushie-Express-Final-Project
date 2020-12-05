/******************************************************************************
* Plushie_Express_CarryIt.h
* CS 281-0798, Fall 2020
*
* CarryIt pure abstract class declaration
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_CARRYIT_H
#define PLUSHIE_EXPRESS_CARRYIT_H

// needed for overloading insertion operator <<
#include <iostream>

#include "Plushie_Express_Element.h"

int constexpr TREASURE_CARRYIT = 't';
int constexpr WEAPON_CARRYIT = 'w';
int constexpr BOGIE_CARRYIT = 'b';
int constexpr BOGEY_CARRYIT = 'd';
int constexpr GENERIC_CARRYIT = 'c';
int constexpr MAGIC_CARRYIT = 'm';
int constexpr NPC_CARRYIT = 'n';

//----------------------------------------------------------
// CarryIt class: abstract base class for carried items
//----------------------------------------------------------
class CarryIt : public Element
{
protected:
    int m_power;
    int m_roomInfo;
    int m_playerInfo;

public:
    CarryIt();
    // CarryIt instances will persist for app lifetime
    // so destructor not needed
    //~CarryIt();

    void setPower(int power);
    int getPower() const;
    int addPower(int morePower);

    // insertion operator overloading function must either
    //      1) be declared as a friend, or
    //      2) be defined inside the class

    friend std::ostream& operator<< (std::ostream& os, const CarryIt& item);
};

#endif