/******************************************************************************
* Final Project C++
* Plushie_Express_app.cpp
*
* Elizabeth Dennison
* CS 281 - 0798, Fall 2020
*
* Still need to:
*  -impliment Secret Words (aka Magic Words)
*  -impliment ending scene / detication 
* 
*******************************************************************************
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <cstdlib>
#include <time.h>

#include "Plushie_Express_app.h"

// local function prototypes
void displayMessageQueue(std::vector<std::string>& msgQueue);
int mapMoveCommand(char cmd);
char menuOption();

// global variables
Room* g_pPassenger = nullptr;
Room* g_pHallway = nullptr;
Room* g_pDinning = nullptr;
Room* g_pKitchen = nullptr;
Room* g_pEngine = nullptr;

/******************************************************************************
* int main()
* entry point
*******************************************************************************
*/
int main()
{
    time_t t;
    srand(static_cast<unsigned int>(time(&t)));

    std::vector<std::string> messageQueue;

    g_pPassenger = initPassenger();
    g_pHallway = initHallway();
    g_pDinning = initDinning();
    g_pKitchen = initKitchen();
    g_pEngine = initEngine();

    initRoomMap();

    // #TODO for Week 7: set the room map initialization pointers
    // by calling g_pNexus->setRoomDirectionPtr()
    // and g_pRoom2->setRoomDirectionPtr() 
    // #TODO test copy constructor and overloaded comparison operator ==
    //Room pTest = *g_pPassenger;
    //if (pTest == *g_pPassenger)
        //std::cout << "pTest and g_pPassenger are the same!\n";

    // put player in starting room of your choice
    Room* pRoom = g_pPassenger;

    // all-purpose string + message buff
    std::string str;
    std::string playerName;

    std::cout << "\nThe Plushie Express: A 281 Fall 2020 Game Project\n";
        std::cout << "What's your name? ";
        std::cin >> playerName;

    // display app version
    messageQueue.push_back("Why hello there " + playerName + "!\n");
    messageQueue.push_back("Are you ready for your tale on the plushie express?\n");
    messageQueue.push_back("Well, ready or not- here we go!\n");
    messageQueue.push_back("You wake up on the seat of a cozy little passenger room of a train.");
    messageQueue.push_back("You don't remember how or even when you got on this train,");
    messageQueue.push_back("but you decide you should take a look around to see if anyone else knows anything.");

    Player* pPlayer = new Player(playerName, PLAYER_LIVES);
    visitRoom(pPlayer, pRoom, messageQueue);

    getInventory(pRoom, messageQueue);
    displayMessageQueue(messageQueue);

    char userCmd = 'x';
    int direction = ROOM_DEAD_END;

    Room* pNextRoom = nullptr;

    // play the game!
    do
    {
        userCmd = menuOption();

        // handle move commands first
        // translate char command to int direction constant
        direction = mapMoveCommand(userCmd);
        if (direction != ROOM_DEAD_END)
            pRoom = movePlayer(pPlayer, pRoom, direction, messageQueue);
        // O)bserve command
        else if (userCmd == 'o')
            lookAllDirections(pRoom, messageQueue);
        // S)peak command
        else if (userCmd == 's')
            talkPerson(pRoom, messageQueue);
        // G)et treasure command
        else if (userCmd == 'g')
            grabTreasure(pPlayer, pRoom, messageQueue);
        // T)ake weapon command  
        else if (userCmd == 't')
            grabWeapon(pPlayer, pRoom, messageQueue);
        // D)rop treasure command
        else if (userCmd == 'd')
            dropTreasure(pPlayer, pRoom, messageQueue);
        // dR)op weapon command
        else if (userCmd == 'r')
            dropWeapon(pPlayer, pRoom, messageQueue);
        // I)nfo command
        else if (userCmd == 'i')
            getAllInfo(pPlayer, pRoom, messageQueue);
        // M)agic command
        else if (userCmd == 'm')
            doMagicWord(pPlayer, pRoom, messageQueue);
        // U)se command 
        else if (userCmd == 'u')
            userCmd = defendSelf(pPlayer, pRoom, messageQueue);
        // Q)uit command 
        else if (userCmd == 'q')
            messageQueue.push_back("Leaving so soon?");
        // handle bad input
        else
            messageQueue.push_back("\aI don't think doing that is a good idea");

        displayMessageQueue(messageQueue);

    } while (userCmd != 'q');
    // end main input loop

        // status display and farewell to Player
    getInfo(pPlayer, pRoom, messageQueue);
    messageQueue.push_back("\nGoodbye " + playerName + "!\n");
    displayMessageQueue(messageQueue);

    system("pause");

    return 0;
}

/******************************************************************************
* displayMessageQueue()
*
* display queued messages and clear queue
*
*******************************************************************************
*/
void displayMessageQueue(std::vector<std::string>& msgQ)
{
    std::cout << std::endl;

    // add a newline after each queued message 
    for (std::string msg : msgQ)
        std::cout << msg << "\n";

    // reset queue for next iteration
    msgQ.clear();
}

/******************************************************************************
* mapMoveCommand()
*
* assumes parameter is lower case
*
* if passed command char is a move command,
* return the direction constant
*
* otherwise return ROOM_DEAD_END
*******************************************************************************
*/
int mapMoveCommand(char cmd)
{
    if (cmd == 'f')         // n)orth
        return ROOM_FORWARD;
    if (cmd == 'b')         // s)outh
        return ROOM_BACK;
    if (cmd == 'r')         // e)ast
        return ROOM_RIGHT;
    if (cmd == 'l')         // w)est
        return ROOM_LEFT;

    // this is not a move command!
    return ROOM_DEAD_END; 
}

/******************************************************************************
* char menuOption()
*
* display menu and prompt
*
* return lower case user command
*
*******************************************************************************
*/
char menuOption()
{
    char cmd;

    // display game menu
    std::cout << std::endl;
    std::cout << "What would you like to do? \n";
    std::cout << "F)orward, B)ack, R)ight, L)eft, O)bserve,\n";
    std::cout << "G)et item, D)rop item, T)ake weapon dR)op weapon\n";
    std::cout << "S)peak, U)se M)agic\n";
    std::cout << "I)nfo, Q)uit ? ";

    // get user command
    std::cin >> cmd;

    // lower case simplifies command handling
    cmd = tolower(cmd);

    return cmd;
}
