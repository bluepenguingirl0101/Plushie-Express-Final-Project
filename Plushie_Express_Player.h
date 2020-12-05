/******************************************************************************
* Plushie_Express_Player.h
*
* Player class declaration
* CS 281-0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
* Students' code must compile and build with this file.
* Don't edit this file.
*
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_PLAYER_H
#define PLUSHIE_EXPRESS_PLAYER_H

#include <string>
#include <vector>

#include "Plushie_Express_Treasure.h"
#include "Plushie_Express_Weapons.h"
#include "Plushie_Express_Container.h"

//----------------------------------------------------------
// Player class derived from base class for containers
//----------------------------------------------------------
class Player : public Container
{
private:
    static int m_pCount; // how many instances exist in game

    std::vector<Room*> m_pRoomsVisitedV;

public:
    Player();
    Player(std::string& name);
    Player(const std::string& name);
    // players will persist for app lifetime
    // so destructor not needed
    //~Player();

    int getPlayerCount() const;

    // Room visit tracking support
    int addRoomVisit(Room* pR);
    void clearRoomVisits();
    int getRoomVisits(std::vector<Room*>& pRV);

    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();

    int addWeapon(Weapon* pW);
    Weapon* removeWeapon();
};

#endif