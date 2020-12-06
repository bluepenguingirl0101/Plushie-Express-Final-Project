/******************************************************************************
* Plushie_Express_NPC.h
* CS 281-0798, Fall 2020
*
* NPC class declaration
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_NPC_H
#define PLUSHIE_EXPRESS_NPC_H

#include <string>

#include "Plushie_Express_Element.h"
#include "Plushie_Express_CarryIt.h"

int constexpr NPC_POINTS = 100;

//----------------------------------------------------------
// Bogey class: derived from CarryIt and Container classes
//----------------------------------------------------------
class NPC : public CarryIt
{
private:
    static int m_nCount;

public:
    NPC();
    NPC(std::string name);
    NPC(std::string name, int points);
    // Bogey instances will persist for app lifetime
    // so destructor not needed
    //~NPC();

    int getNPCCount() const;

};
#endif
