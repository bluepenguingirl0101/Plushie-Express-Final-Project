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
        msgQ.push_back("As soon as you reach for the plushie,");

        // get current Bogey in Room
        std::vector<Bogey*> bV;
        pR->getBogeyInfo(bV);
        Bogey* pB = bV.back();

        // display Bogey text
        std::string str;
        std::stringstream ss;
        pB->getName(str);
        msgQ.push_back("You notice that " + str + " looking at you. \nSomething tells you that it's a bad idea to get the plush toy at this moment.");

        ss << "You got " << pB->getName(str) << "\nYou got ";

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
    ss << "You got " << pT->getName(str) << "\nYou got "
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
    ss << "You now have a " << pW->getName(str) << ". \nYou got "
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
* defendSelf()
*
* use a Weapon on a Bogey
* add messages to caller's vector for display
*
* returns 'q' when Player is defeated and all lives are gone, or 'f'
* return value 'q' forces main loop to terminate
*******************************************************************************
*/
char defendSelf(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    if (!interAct(pP, pR, msgQ))
    {
        // get Player name
        std::string str;
        msgQ.push_back(pP->getName(str) + ", that didn't work!");

        // check for all Player lives used up
        int nLivesLeft = pP->loseLife();
        if (nLivesLeft <= 0)
        {
            msgQ.push_back("And you're out of lives :-((");

            // force q)uit in main app loop
            return 'q';
        }

        std::stringstream ss;
        ss << "You have " << nLivesLeft << "  chances left.";
        msgQ.push_back(ss.str());
    }

    // #TODO return same command to main loop
    return 'f';
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

    // check for Weapon in Player vector
    if (pP->getWeaponCount() == 0)
    {
        //if (!doMagicWord(pP, pR, msgQ))
        //{
           // msgQ.push_back("You don't know any secret words right now.");
           // return false;
        // }

       // else
       // {
            //msgQ.push_back("Awesome! You can get the plushies now!");

            // award points and add Bogey notch to Player's belt
           // pP->addPoints(pB->getPoints());
            //pR->removeBogey();
           // pP->addBogey(pB);

           //return true;
        //}
    }

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
    if (wPower == bPower)
    {
        int bPoints = pB->getPoints();

        std::stringstream ss;
        ss <<  "You gained " << bPoints << " points!" ;
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
bool talkPerson(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    int points = pR->getPoints();
    pP->addPoints(points);
    NPC* pN = pR->removeNPC();

    if (pN == nullptr)
    {
        msgQ.push_back("There's no one to talk to...");
        return false;
    }

    // build message string with string stream

    int tPoints = pN->getPoints();

    std::string str;
    std::stringstream ss;
    ss << "You decide to talk to " << pN->getName(str) << ". "
        "\n" << "You got " << tPoints << " points!";

    // copy completed message string to caller's vector
    msgQ.push_back(ss.str());

   //try that works-ish
   //std::string str;
   //msgQ.push_back("You're in " + pR->getNPCInfo(str) + "\n");

    //if (pR->getNPCCount() == 1)
    //{ 
       //msgQ.push_back(pR->getText(str));
    //}

    //else if (pR->getNPCCount() == 0)
    //{
        //msgQ.push_back("There's no one to talk to..");
        //return true;
    //}

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
    std::string str = "Oof-! You ran into a dead end";

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

    //if (pNextRoom == nullptr)
    //{
        msgQ.push_back("Oof-! You ran into a wall. Guess you won't be going that way.");
        return pR;
    //}

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
bool doMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{    
    std::cout << "What's the mystery word you'd like to use?" "\n";
    std::string str; 
    std::cin >> str; 

    if (str == "plushies")
    {
        MagicWord* pM = pR->removeMagicWord();
        int points = pR->getPoints();
        pP->addPoints(points);

        pP->addMagicWord(pM);

        // build greeting messages and queue for display
        std::string str, magicText;
        msgQ.push_back("You say the mystery word 'plushies'." "\n" + pM->getText(magicText) + ".");

        int mPoints = pM->getPoints();

        std::stringstream ss;
        ss << "You gained " << mPoints << " points!";
        msgQ.push_back(ss.str());

            //std::stringstream ss;
            //ss << points << " points for saying the secret " << magicText << "!\n";

        return true;
    }

    else if (str == "liz")
    {
        MagicWord* pM = pR->removeMagicWord();
        int points = pR->getPoints();
        pP->addPoints(points);

        // update Player Room visit history
        pP->addMagicWord(pM);

        // build greeting messages and queue for display
        std::string str, magicText;
        msgQ.push_back("You say the mystery word 'liz'." "\n" + pM->getText(magicText));

        // get last Bogey stored in vector
        std::vector<Bogey*> bV;
        pR->getBogeyInfo(bV);
        Bogey* pB = bV.back();
        int bPower = pB->getPower();

        // get text associated with this Bogey
        //msgQ.push_back(pB->getText(str));

        //if (bPower)
        //{
            int mPoints = pM->getPoints();

            std::stringstream ss;
            ss << "You gained " << mPoints << " points!";
            msgQ.push_back(ss.str());

            pP->addPoints(mPoints);
            pR->removeBogey();
            pP->addBogey(pB);

            return true;
        //}

    }

    else
    {
       std::cout << "You say that, but nothing happens.";
    }

    return true;
}