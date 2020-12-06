/******************************************************************************
* Plushie_Express_Treasure.cpp
*
* NPC class definition
* CS 281-0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
*******************************************************************************
*/
#include <string>

#include "Plushie_Express_NPC.h"
#include "Plushie_Express_CarryIt.h"

int NPC::m_nCount = 0;

//***********************************************************
// NPC(string tName)
//
// overload constructor
//
// tName is a call by value string parameter
// to allow passing string literals
//***********************************************************
NPC::NPC(std::string name, int points)
{
    // track instance count
    m_nCount++;

    m_id = NPC_CARRYIT;
    m_name = name;
    m_points = points;
}

//***********************************************************
// NPC()
//
// overload constructor 2 of 2
//***********************************************************
NPC::NPC(std::string name) : NPC(name, NPC_POINTS)
{

}

//***********************************************************
// NPC()
//
// constructor
//***********************************************************
NPC::NPC() : NPC("npc", NPC_POINTS)
{

}

//***********************************************************
// getNPCCount() : return static instance count 
//***********************************************************
int NPC::getNPCCount() const
{
    return m_nCount;
}


