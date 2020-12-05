/******************************************************************************
* Plushie_Express_Bogie.cpp
* CS 281-0798, Fall 2020
*
* Bogie derived class definition
*******************************************************************************
*/
#include <string>

#include "Plushie_Express_Bogie.h"


//***********************************************************
// Bogie()
//
// overload constructor
//***********************************************************
Bogie::Bogie(std::string name)
{
    m_id = static_cast<int>(BOGIE_CARRYIT);
    m_name = name;
}

//***********************************************************
// Bogie()
//
// constructor
//***********************************************************
Bogie::Bogie() : Bogie("bogie") { }
