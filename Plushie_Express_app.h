/******************************************************************************
* Plushie_Express_app.h
*
* Common include file for test driver
* CS 281 - 0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_H
#define PLUSHIE_EXPRESS_H

constexpr int PLAYER_DEFEATED = -1;

#include "Plushie_Express_Rooms.h"
#include "Plushie_Express_Bogey.h"
#include "Plushie_Express_Player.h"
#include "Plushie_Express_Treasure.h"
#include "Plushie_Express_Weapons.h"
#include "Plushie_Express_MagicWord.h"
#include "Plushie_Express_NPC.h"

// global variables
extern Room* g_pPassenger;
extern Room* g_pHallway;
extern Room* g_pDinning;
extern Room* g_pKitchen;
extern Room* g_pEngine;

// custom room initialization functions
Room* initPassenger();
Room* initHallway();
Room* initDinning();
Room* initKitchen();
Room* initEngine();

// app_init_map.cpp: custom Room map initialization functions
void initRoomMap();

// app_player.cpp: Player initialization and management functions
bool grabTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool dropTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool grabWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool dropWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ);
char defendSelf(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool lookAllDirections(Room* pR, std::vector<std::string>& msgQ);
bool talkPerson(Player* pP, Room* pR, std::vector<std::string>& msgQ);
Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ);
bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ);
//bool hasMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool doMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ);
// app_util.cpp: Room initialization and management functions
int getInventory(Container* pR, std::vector<std::string>& msgQ);
// for app exit message display
bool getInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ);
// for handling I)nfo command
bool getAllInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ);

#endif