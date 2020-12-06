/******************************************************************************
* Plushie_Express_Treasure.cpp
*
* Treasure class definition
* CS 281-0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
*******************************************************************************
*/
#include <string>

#include "Plushie_Express_Treasure.h"
#include "Plushie_Express_CarryIt.h"

int Treasure::m_tCount = 0;

//***********************************************************
// Treasure(string tName)
//
// overload constructor
//
// tName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Treasure::Treasure(const std::string& tName, int points)
{
    // track instance count
    m_tCount++;

    m_id = TREASURE_CARRYIT;
    m_name = tName;
    m_points = points;
}

//***********************************************************
// Treasure()
//
// constructor
//***********************************************************
Treasure::Treasure() : Treasure("treasure", TREASURE_POINTS)
{ }


//***********************************************************
// getTreasureCount() : return static instance count 
//***********************************************************
int Treasure::getTreasureCount() const 
{ 
    return m_tCount; 
}



