/******************************************************************************
* Plushie_Express_App_Init_Map.cpp
* CS 281 - 0798, Fall 2020
*
* Room map initialization functions
*
* The Room map is an array of Room pointers in each Room.
* Each Room knows which Room can be accessed in each direction.
* There is no overall map of the Rooms.
*******************************************************************************
*/

#include "Plushie_Express_app.h"

/******************************************************************************
* void initRoomMap()
*******************************************************************************
*/
void initRoomMap()
{
    g_pHallway->setDirectionPtr(ROOM_FORWARD, g_pDinning);
    g_pDinning->setDirectionPtr(ROOM_FORWARD, g_pKitchen);
    g_pKitchen->setDirectionPtr(ROOM_FORWARD, g_pEngine);

    g_pDinning->setDirectionPtr(ROOM_BACK, g_pHallway);
    g_pKitchen->setDirectionPtr(ROOM_BACK, g_pDinning);
    g_pEngine->setDirectionPtr(ROOM_BACK, g_pKitchen);

    g_pPassenger->setDirectionPtr(ROOM_RIGHT, g_pHallway);

    g_pHallway->setDirectionPtr(ROOM_LEFT, g_pPassenger);

}
