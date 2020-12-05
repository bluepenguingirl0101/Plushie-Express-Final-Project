/******************************************************************************
* Plushie_Express_Bogey.h
* CS 281-0798, Fall 2020
*
* Bogey class declaration
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_BOGEY_H
#define PLUSHIE_EXPRESS_BOGEY_H

#include <string>

#include "Plushie_Express_Element.h"
#include "Plushie_Express_CarryIt.h"

int constexpr BOGEY_POINTS = 100;

//----------------------------------------------------------
// Bogey class: derived from CarryIt and Container classes
//----------------------------------------------------------
class Bogey : public CarryIt
{
private:
    static int m_bCount;

public:
    Bogey();
    Bogey(std::string name);
    Bogey(std::string name, int points);
    // Bogey instances will persist for app lifetime
    // so destructor not needed
    //~Bogey();

    int getBogeyCount() const;

};

#endif
