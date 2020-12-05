/******************************************************************************
* Plushie_Express_Weapons.h
* CS 281-0798, Fall 2020
*
* Weapon class declaration
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_WEAPONS_H
#define PLUSHIE_EXPRESS_WEAPONS_H

#include <string>

// base class declaration
#include "Plushie_Express_CarryIt.h"

int constexpr WEAPON_POINTS = 100;
int constexpr WEAPON_USES = 1;

//----------------------------------------------------------
// Weapon class derived from base class for carried items
//----------------------------------------------------------
class Weapon : public CarryIt
{
private:
    int m_usesRemaining;

    static int m_wCount; // how many instances exist in game

public:
    Weapon();
    Weapon(const std::string& wName, int points);
    // Weapon persists for app lifetime
    // so destructor not needed
    //~Weapon();

    int setUsesRemaining(int uses);
    int getUsesRemaining() const;
    int addUsesRemaining(int uses);
    
    int getWeaponCount() const;
};

#endif

