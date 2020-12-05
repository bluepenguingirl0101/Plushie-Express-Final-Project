/******************************************************************************
* Plushie_Express_MagicWord.h
* CS 281-0798, Fall 2020
*
* MagicWord class declaration
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_MAGICWORD_H
#define PLUSHIE_EXPRESS_MAGICWORD_H

#include <string>

#include "Plushie_Express_CarryIt.h"

int constexpr MAGIC_POINTS = 300;

//----------------------------------------------------------
// MagicWord class
//----------------------------------------------------------
class MagicWord : public CarryIt
{
private:
    int m_usesRemaining;

    static int m_wCount; // how many instances exist in game

public:
    MagicWord();
    MagicWord(const std::string& wName, int points);
    // MagicWord persists for app lifetime
    // so destructor not needed
    //~MagicWord();

    int getMagicWordCount() const;

};

#endif