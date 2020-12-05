/******************************************************************************
* Plushie_Express_Room.cpp
*
* Room class definition
* CS 281-0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
*******************************************************************************
*/
#include <iostream>
#include <vector>

#include "Plushie_Express_Rooms.h"
#include "Plushie_Express_Treasure.h"
#include "Plushie_Express_Weapons.h"
#include "Plushie_Express_NPC.h"

int Room::m_rCount = 0;

//***********************************************************
// Room(std::string name)
//
// overload constructor
// 
// lrc changed for Week 6
//      name is now a call by value parameter
//      to allow Room("room") call (see Room() below)
//***********************************************************
Room::Room(const std::string& name, int points)
{
    m_rCount++;

    m_id = ROOM_CONTAINER;
    m_name = name;
    m_points = points;
    m_entryText = "entering " + m_name;
    m_exitText = "exiting " + m_name;


    // initialize room text to known values
    m_roomTextArray[ROOM_FORWARD] = "looking forward";
    m_roomTextArray[ROOM_BACK] = "looking back";
    m_roomTextArray[ROOM_RIGHT] = "looking right";
    m_roomTextArray[ROOM_LEFT] = "looking left";

    // initialize custom direction text to "" to
    // simplify client (app) code display logic
    m_roomTextArray[ROOM_UX1] = "";
    m_roomTextArray[ROOM_UX2] = "";
    m_roomTextArray[ROOM_UX3] = "";
    m_roomTextArray[ROOM_UX4] = "";
    m_roomTextArray[ROOM_UX5] = "";
    m_roomTextArray[ROOM_UX6] = "";
    m_roomTextArray[ROOM_UX7] = "";
    m_roomTextArray[ROOM_UX8] = "";
    m_roomTextArray[ROOM_UX9] = "";
    m_roomTextArray[ROOM_UXX] = "";

    // lrc added for Week 6
    // initialize room pointers
    m_nextRoomPtrArray[ROOM_FORWARD] = nullptr;
    m_nextRoomPtrArray[ROOM_BACK] = nullptr;
    m_nextRoomPtrArray[ROOM_RIGHT] = nullptr;
    m_nextRoomPtrArray[ROOM_LEFT] = nullptr;

    // support for user defined directions
    // client code should add global const (before main())
    // like this: const int ROOM_YOUR_CUSTOM_DIRECTION = ROOM_UX1;

    m_nextRoomPtrArray[ROOM_UX1] = nullptr;
    m_nextRoomPtrArray[ROOM_UX2] = nullptr;
    m_nextRoomPtrArray[ROOM_UX3] = nullptr;
    m_nextRoomPtrArray[ROOM_UX4] = nullptr;
    m_nextRoomPtrArray[ROOM_UX5] = nullptr;
    m_nextRoomPtrArray[ROOM_UX6] = nullptr;
    m_nextRoomPtrArray[ROOM_UX7] = nullptr;
    m_nextRoomPtrArray[ROOM_UX8] = nullptr;
    m_nextRoomPtrArray[ROOM_UX9] = nullptr;
    m_nextRoomPtrArray[ROOM_UXX] = nullptr;

}

//***********************************************************
// Room()
//
// constructor
//***********************************************************
Room::Room() : Room("room", ROOM_POINTS) 
{ 

}

//***********************************************************
// getRoomCount() : return static instance count 
//***********************************************************
int Room::getRoomCount() const
{
    return m_rCount;
}

//***********************************************************
// setEntryText()
//***********************************************************
void Room::setEntryText(const std::string& entryText)
{
    m_entryText = entryText;
}

//***********************************************************
// getEntryText()
//***********************************************************
std::string& Room::getEntryText(std::string& str) const
{
    return str = m_entryText;
}

//***********************************************************
// setExitText()
//***********************************************************
void Room::setExitText(const std::string& exitText)
{
    m_exitText = exitText;
}

//***********************************************************
// getExitText()
//***********************************************************
std::string& Room::getExitText(std::string& str) const
{
    return str = m_exitText;
}

//***********************************************************
// setDirectionText()
//***********************************************************
void Room::setDirectionText(int direction, const std::string& str)
{
    m_roomTextArray[direction] = str;
}

//***********************************************************
// getRoomDirectionText()
//***********************************************************
std::string& Room::getDirectionText(int direction, std::string& str) const
{
    return str = m_roomTextArray[direction];
}

//***********************************************************
// setDirectionPtr()
//
// set the pointer to the next Room in this direction
//***********************************************************
void Room::setDirectionPtr(int direction, Room* pRoom)
{
    m_nextRoomPtrArray[direction] = pRoom;
}

//***********************************************************
// getDirectionPtr()
//
// return pointer to the next Room in given direction
//***********************************************************
Room* Room::getDirectionPtr(int direction) const
{
    return m_nextRoomPtrArray[direction];
}


