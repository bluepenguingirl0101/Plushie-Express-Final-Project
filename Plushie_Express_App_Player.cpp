/******************************************************************************
* Plushie_Express_App_Player.cpp
* CS 281 - 0798, Fall 2020
*
* Player initialization and management functions
*******************************************************************************
*/
#include <sstream>
#include <vector>

#include "Plushie_Express_app.h"

// local function prototypes
bool interAct(Player* pP, Room* pR, std::vector<std::string>& msgQ);

/******************************************************************************
* grabTreasure()
*
* transfer Treasure from Room to Player
* fill caller's vector with messages for display
*******************************************************************************
*/
bool grabTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // Bogey present prevents Player from getting Treasure
    if (pR->getBogeyCount() > 0)
    {
        msgQ.push_back("As soon as you reach for the plushie...");

        // get current Bogey in Room
        std::vector<Bogey*> bV;
        pR->getBogeyInfo(bV);
        Bogey* pB = bV.back();

        // display Bogey text
        std::string str;
        pB->getText(str);
        msgQ.push_back("The creature yells " + str + " and you decide not to provoke further.");

        return false;
    }

    Treasure* pT = pR->removeTreasure();
    if (pT == nullptr)
    {
        msgQ.push_back("There's no more treasure here.");
        return false;
    }

    pP->addTreasure(pT);

    // build message string with string stream
    std::string str;
    std::stringstream ss;
    ss << "You got " << pT->getName(str) << " You got "
        << pT->getPoints() << " points!";

    // add completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* dropTreasure()
*
* transfer Treasure from Player to Room
* fill caller's vector with message strings for display
*******************************************************************************
*/
bool dropTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Treasure* pT = pP->removeTreasure();

    if (pT == nullptr)
    {
        msgQ.push_back("You have no treasure to drop!");
        return false;
    }

    // transfer Treasure from Player to Room
    pR->addTreasure(pT);

    // for queueing display message
    std::string str;
    msgQ.push_back("You dropped a " + pT->getName(str));

    return true;
}

/******************************************************************************
* grabWeapon()
*
* transfer Weapon from Room to Player
* add messages to caller's vector for display
*******************************************************************************
*/
bool grabWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Weapon* pW = pR->removeWeapon();

    if (pW == nullptr)
    {
        msgQ.push_back("There's no weapons here.");
        return false;
    }

    pP->addWeapon(pW);

    // build message string with string stream
    std::string str;
    std::stringstream ss;
    ss << "You now have a " << pW->getName(str) << ". you got "
        << pW->getPoints() << " points!";

    // copy completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* dropWeapon()
*
* transfer Weapon from Player to Room
* fill caller's vector with message strings for display
*******************************************************************************
*/
bool dropWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Weapon* pW = pP->removeWeapon();

    if (pW == nullptr)
    {
        msgQ.push_back("You have no weapon to drop!");
        return false;
    }

    // transfer Weapon from Player to Room
    pR->addWeapon(pW);

    // for queueing display message
    std::string str;
    msgQ.push_back("You dropped a " + pW->getName(str));

    return true;
}


/******************************************************************************
* interAct()
*
* use a Weapon on a Bogey
* add messages to caller's vector for display
*******************************************************************************
*/
bool interAct(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // check for Bogeys present
    if (pR->getBogeyCount() == 0)
    {
        msgQ.push_back("No unfriendlies here..");
        return true;
    }

    // get last Bogey stored in vector
    std::vector<Bogey*> bV;
    pR->getBogeyInfo(bV);
    Bogey* pB = bV.back();
    int bPower = pB->getPower();

    // #TODO check for Weapon in Player vector
    //if (pP->getWeaponCount() == 0)
    //{
        //if (!hasMagicWord())
        //{
            //msgQ.push_back("You don't know any secret words right now.");
            //return false;
         //}
        //else
        //{
            //msgQ.push_back("Awesome! You can get the plushies now!");

            // award points and add Bogey notch to Player's belt
            //pP->addPoints(pB->getPoints());
            //pR->removeBogey();
            //pP->addBogey(pB);

           //return true;
        //}
    //}

    // get last Weapon stored in vector
    std::vector<Weapon*> wV;
    pP->getWeaponInfo(wV);
    Weapon* pW = wV.back();
    int wPower = pW->getPower();

    // get Weapon and Bogey names
    std::string wName, bName;
    msgQ.push_back("You decide to use " + pW->getName(wName) +
        " on " + pB->getName(bName) + "!");

    // get text associated with this Weapon
    std::string str;
    msgQ.push_back(pW->getText(str));

    // get text associated with this Bogey
    msgQ.push_back(pB->getText(str));

    // if Weapon more powerful than Bogey award points
    if (wPower >= bPower)
    {
        int bPoints = pB->getPoints();

        std::stringstream ss;
        ss << bPoints << " points for defeating " << bName << "!";
        msgQ.push_back(ss.str());

        // award points and add Bogey notch to Player's belt
        pP->addPoints(bPoints);
        pR->removeBogey();
        pP->addBogey(pB);

        return true;
    }

    // Weapon weaker than Bogey lives to fight again
    if (wPower > 0)
    {
        msgQ.push_back("\nBut it doesn't work on " + bName);
        pB->setPower(bPower - wPower);
        return true;
    }

    return false;

}

/******************************************************************************
* lookAllDirections()
*
* add all direction text in current Room to caller's message vector
*******************************************************************************
*/
bool lookAllDirections(Room* pR, std::vector<std::string>& msgQ)
{
    // utility buffer gets stomped every time through loop
    std::string str;
    msgQ.push_back("You're in " + pR->getName(str) + "\n");

    // add text for all directions to caller's vector
    for (int i = 0; i < ROOM_NDIR; i++)
    {
        // only display text for diretions we're using 
        if (pR->getDirectionText(i, str) != "")
            msgQ.push_back(str);
    }

    // display things in Room
    getInventory(pR, msgQ);

    return true;
}

/******************************************************************************
* talkPerson()
*******************************************************************************
*/
bool talkPerson(NPC* pN, Room* pR, std::vector<std::string>& msgQ)
{
    // utility buffer gets stomped every time through loop
    std::string str;

    // add text for all directions to caller's vector
    for (int b = 0; b < NPC_TALK; b++)
    {
        // only display text for diretions we're using 
        if (pN->getNPCText(b, str) != "")
            msgQ.push_back(str);
    }

    return true;
}

/******************************************************************************
* movePlayer()
*
* look up pointer to next Room in given direction
* if there's a Room in that direction,
* display exit text in current Room
*
* return pointer to the new Room,
* or pointer to same Room if no Room in that direction
*
*******************************************************************************
*/
Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ)
{
    std::string str = "Dead end.";

    Room* pNextRoom = pR->getDirectionPtr(direction);
    if (pNextRoom != nullptr)
    {
        // "You are leaving" current Room
        msgQ.push_back(pR->getExitText(str));

        // update Player's Room visits
        visitRoom(pP, pNextRoom, msgQ);

        // display Room contents
        getInventory(pNextRoom, msgQ);

        return pNextRoom;
    }

    // nowhere to go in this direction, stay in current Room
    return pR;
}

/******************************************************************************
* visitRoom()
*
* award Room points to Player
* update Player's Rooms visited history
* queue messages for display
*******************************************************************************
*/
bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // award Room points to Player
    int points = pR->getPoints();
    pP->addPoints(points);

    // update Player Room visit history
    pP->addRoomVisit(pR);

    // build greeting messages and queue for display
    std::string str, roomName;
    msgQ.push_back("You're in " + pR->getName(roomName) + ".");
    msgQ.push_back(pR->getEntryText(str));

    // only award points for initial visit to each Room
    if (pR->getPoints() > 0)
    {
        std::stringstream ss;
        ss << points << " points for entering " << roomName << "!\n";

        msgQ.push_back(ss.str());
        pR->setPoints(0);
    }

    return true;
}

//***********************************************************
// hasMagicWord()
//
// returns true if the Player can provide the Magic Word,
// false otherwise
//***********************************************************
//bool hasMagicWord()
//{
    //std::string str;
    //std::cout << "\nUh-oh, you're in real trouble now-! Quick! What's the magic word? ";
    //std::cin >> str;

    //return !(str.compare("friendship"));
//}

//bool doMagicWord()
//{

//}