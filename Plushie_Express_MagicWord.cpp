/******************************************************************************
* MagicWord.cpp
* Elizabeth Dennison
* CS 281-0798, Fall 2020
* November 15, 2020
*
*******************************************************************************
*/

#include <string>

#include "Plushie_Express_MagicWord.h"


/*******************************************************************************
* MagicWord(string mName)
*
* overload constructor
********************************************************************************
*/
MagicWord::MagicWord(std::string mName)
{
	m_name = mName;
	m_magicWordText = "After you utter the magic word...";
	m_points = 300;

}

/*******************************************************************************
* MagicWord()
*
* constructor
********************************************************************************
*/
MagicWord::MagicWord() {}

/*******************************************************************************
* bool setMagicWordName(string mName)
********************************************************************************
*/
bool MagicWord::setMagicWordName(std::string& mName)
{
	m_name = mName;
	return true;
}
/*******************************************************************************
* bool getMagicWordName(string& mName) const
********************************************************************************
*/
bool MagicWord::getMagicWordName(std::string& mName) const
{
	mName = m_name;
	return true;
}
/*******************************************************************************
* bool setMagicWordPoints(int mPoints)
********************************************************************************
*/
bool MagicWord::setMagicWordPoints(int mPoints)
{
	m_points = mPoints;
	return true;
}
/*******************************************************************************
* int getMagicWordPoints() const
********************************************************************************
*/
int MagicWord::getMagicWordPoints() const
{
	return m_points;
}
/*******************************************************************************
* bool setMagicWordText(string& mText)
********************************************************************************
*/
bool MagicWord::setMagicWordText(std::string& mText)
{
	m_magicWordText = mText;
	return true;
}
/*******************************************************************************
* bool getMagicWordText(string& mText)
********************************************************************************
*/
bool MagicWord::getMagicWordText(std::string& mText) const
{
	mText = m_magicWordText;
	return true;
}