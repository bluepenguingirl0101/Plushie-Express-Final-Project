/******************************************************************************
* Plushie_Express_Bogie.h
* CS 281-0798, Fall 2020
*
* Bogie class declaration
*******************************************************************************
*/
#ifndef PLUSHIE_EXPRESS_BOGIE_H
#define PLUSHIE_EXPRESS_BOGIE_H

#include <string>

#include "Plushie_Express_Element.h"
#include "Plushie_Express_CarryIt.h"

//----------------------------------------------------------
// Bogie class: derived from CarryIt and Container classes
//----------------------------------------------------------
class Bogie : public CarryIt
{

public:
    Bogie();
    Bogie(std::string name);
    // Bogie instances will persist for app lifetime
    // so destructor not needed
    //~Bogie();

};

#endif