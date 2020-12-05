/******************************************************************************
* Plushie_Express_NPC.cpp
*
* NPC class definition
* CS 281-0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
*******************************************************************************
*/
#include <iostream>
#include <vector>

#include "Plushie_Express_Treasure.h"
#include "Plushie_Express_Weapons.h"
#include "Plushie_Express_NPC.h"

int NPC::m_nCount = 0;

//***********************************************************
// NPC(std::string name)
//
// overload constructor
// 
// lrc changed for Week 6
//      name is now a call by value parameter
//      to allow NPC("NPC") call (see NPC() below)
//***********************************************************
NPC::NPC(const std::string& name, int points)
{
    m_nCount++;

    m_id = NPC_CONTAINER;
    m_name = name;
    m_points = points;


    // initialize NPC text to known values
    m_NPCTextArray[NPC_TALK] = "talking";

    // lrc added for Week 6
    // initialize NPC pointers
    m_nextNPCPtrArray[NPC_TALK] = nullptr;

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

//***********************************************************
// setNPCText()
//***********************************************************
void NPC::setNPCText(int npc, const std::string& str)
{
    m_NPCTextArray[npc] = str;
}

//***********************************************************
// getNPCNPCText()
//***********************************************************
std::string& NPC::getNPCText(int npc, std::string& str) const
{
    return str = m_NPCTextArray[npc];
}

//***********************************************************
// setNPCPtr()
//
// set the pointer to the next NPC in this npc
//***********************************************************
void NPC::setNPCPtr(int npc, NPC* pNPC)
{
    m_nextNPCPtrArray[npc] = pNPC;
}

//***********************************************************
// getNPCPtr()
//
// return pointer to the next NPC in given npc
//***********************************************************
NPC* NPC::getNPCPtr(int npc) const
{
    return m_nextNPCPtrArray[npc];
}




