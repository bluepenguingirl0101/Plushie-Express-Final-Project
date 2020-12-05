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
#include <array>
#include <vector>

#include "Plushie_Express_Container.h"
#include "Plushie_Express_CarryIt.h"
#include "Plushie_Express_Treasure.h"
#include "Plushie_Express_Weapons.h"

int constexpr NPC_TEXT = 4;
int constexpr NPC_POINTS = 100;
int constexpr NPC_TALK = 1;

//----------------------------------------------------------
// NPC class: derived from CarryIt and Container classes
//----------------------------------------------------------
class NPC : public Container
{
    private:
        // how many instances exist in game
        static int m_nCount;

        // text to display for each direction in Room
        std::array <std::string, NPC_TEXT> m_NPCTextArray;

        // each Room* gives next Room in the given direction
        std::array<NPC*, NPC_TEXT> m_nextNPCPtrArray;

        // messages for display on Player entry and exit
        std::string m_NPCText;

    public:
        NPC();
        NPC(const std::string& name, int points);
        // NPC instances will persist for app lifetime
        // so destructor not needed
        //~NPC();

        int getNPCCount() const;

        void setNPCText(int npc, const std::string& str);
        std::string& getNPCText(int npc, std::string& str) const;

        // see direction constants above!
        void setNPCPtr(int npc, NPC* pNPC);
        NPC* getNPCPtr(int npc) const;
};

#endif
