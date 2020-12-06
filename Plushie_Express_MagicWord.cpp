/******************************************************************************
* Plushie_Express_MagicWord.cpp
*
* MagicWord class definition
* CS 281-0798, Fall 2020
*
* >>> Week 7 STARTER FILE <<<
*
*******************************************************************************
*/
#include <string>

#include "Plushie_Express_MagicWord.h"
#include "Plushie_Express_CarryIt.h"

int MagicWord::m_mCount = 0;

//***********************************************************
// MagicWord(string tName)
//
// overload constructor
//
// tName is a call by value string parameter
// to allow passing string literals
//***********************************************************
MagicWord::MagicWord(const std::string& mName, int points)
{
    // track instance count
    m_mCount++;

    m_id = MAGICWORD_CARRYIT;
    m_name = mName;
    m_points = points;
}

//***********************************************************
// MagicWord()
//
// constructor
//***********************************************************
MagicWord::MagicWord() : MagicWord("magicword", MAGICWORD_POINTS)
{ 

}

//***********************************************************
// getMagicWordCount() : return static instance count 
//***********************************************************
int MagicWord::getMagicWordCount() const
{
    return m_mCount;
}