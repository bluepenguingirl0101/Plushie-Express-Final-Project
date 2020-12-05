/******************************************************************************
* Plushie_Express_App_Init_Rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
*   - install magic words in Room MagicWord vector
*******************************************************************************
*/
#include "Plushie_Express_app.h"

/******************************************************************************
* Room* initPassenger()
*******************************************************************************
*/
Room* initPassenger()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the Passenger Car", 100);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("\n""You're now in your passenger car of the train.");
    pRoom->setExitText("You walk out into the hallway of the train.");
    pRoom->setDirectionText(ROOM_FORWARD, "There is a nice comfy seat in front of you. On the seat is a plush guinea pig that looks directly at you.");
    pRoom->setDirectionText(ROOM_RIGHT, "There is a door to your right that leads out into a narrow hallway.");
    pRoom->setDirectionText(ROOM_LEFT, "There is a beautiful view to the right of you of sceneary that is too fast to take in all the details");
    pRoom->setDirectionText(ROOM_BACK, "There's a note on the table under the window that says, 'enjoy the ride~'.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("a plush guinea pig with a collar that has the name 'Daniel' written on it.", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    return pRoom;
}

/******************************************************************************
* Room* initHallway()
*******************************************************************************
*/
Room* initHallway()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the Hallway", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("You walk into the hallway where there seems to be only one person in it looking out the window.");
    pRoom->setExitText("You leave the hallway and into the next room");
    pRoom->setDirectionText(ROOM_FORWARD, "In front of you, you see a door that leads into what seems to be the dinning room of the train.");
    pRoom->setDirectionText(ROOM_LEFT, "To the left of you is your passenger car, but on the floor of the passenger car you see a small wolf plushie.");
    pRoom->setDirectionText(ROOM_BACK, "On the floor you see a pencil that has some teeth marks. Seems someone likes to chew their pencil.");
    pRoom->setDirectionText(ROOM_RIGHT, "To the right of you, you see a girl with a blonde ponytail, wearing a white t-shirt and blue shorts."
       "\n" "Her blue eyes look at you as if she has something she wants to tell you.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("two plush wolfs with a collar on each:" 
        "\n" "one with the name 'Carlos' and one with the name 'Alex'.", 200);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("a pencil with non-human teeth marks", 100);
    pWeapon->setText("You decide to try using the pencil");

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    //create and initalize NPC instance
    NPC* pNPC = new NPC("Kylie", 100);
    pNPC->setNPCText(NPC_TALK, "You decide to talk to the blonde girl to ask her about information..." 
        "\n" "'No, sorry, I don't remember how or when on got on this train either...'"
        "\n" "'Buuut, I DO remember seeing the word 'plush' on the car in my room'"
        "\n" "'I tried saying it in my room, but nothing happened for me...'" );
    // install NPC pointer in Room's NPC vector
    //pRoom->addNPC(pNPC);

    return pRoom;
}

/******************************************************************************
* Room* initDinning()
*******************************************************************************
*/
Room* initDinning()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the Dinning Car", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("You enter the dinning car to be greated by different characters and creatures of different varities.");
    pRoom->setExitText("You exit the dinning car to get away from all the noise.");
    pRoom->setDirectionText(ROOM_BACK, "To your right there is a counter where a little sign that says 'Be back, ran out of chocolate milk'.");
    pRoom->setDirectionText(ROOM_LEFT, "To your left you see an orange bunny with a blue shirt and long white sleeve franticly looking for something.");
    pRoom->setDirectionText(ROOM_FORWARD, "In front of you is the enterance to the kitchen. You assume this because of the sign that says 'kitchen'.");
    pRoom->setDirectionText(ROOM_RIGHT, "You look around once more and notice a plush tiger sitting on one of the tables. Along with a spool of thread and a sewing needle.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("a plush tiger with a collar that has the name 'Morgan' written on it", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("needle and some thread", 100);
    pWeapon->setText("you decide to try and use the needle and thread.");

    // install Treasure pointer in Room's Treasure vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initKitchen()
*******************************************************************************
*/
Room* initKitchen()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the Kitchen Car", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("The smell of yummy food comes in contact with your nose as you enter the kitchen.");
    pRoom->setExitText("You leave the kitchen, much to your stomach's dismay.");
    pRoom->setDirectionText(ROOM_FORWARD, "Looks like in front of you is the enterance to the engine room.");
    pRoom->setDirectionText(ROOM_RIGHT, "You see just to the side of the door a grummpy looking plush that glare at you. Doesn't seem to be too friendly.");
    pRoom->setDirectionText(ROOM_LEFT, "On one of the kitchen counters is a sea lion plushie that looks at you with it's small pleading eyes.");
    pRoom->setDirectionText(ROOM_BACK, "Looks like the a sweet dessert is being made right now!");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("A plush sea lion with a collar that has the name 'Emily' written on it", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogey* pBogey = new Bogey("grumpy plush chef", 100);
    pBogey->setText("OH NO YOU DON'T!");

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogey(pBogey);

    return pRoom;
}

/******************************************************************************
* Room* initEngine()
*******************************************************************************
*/
Room* initEngine()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the Engine Room", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("You enter the engine room; it has a much heavier atomsophere than any of the pervious rooms.");
    pRoom->setExitText("You leave the engine room, hoping not to upset the conductor in the process.");
    pRoom->setDirectionText(ROOM_FORWARD, "There is the conductor. She's not human it seems- more of a doll than anything. A rag doll more specifically.");
    pRoom->setDirectionText(ROOM_BACK, "You can always go back the way you came to not infurate the doll conductor.");
    pRoom->setDirectionText(ROOM_RIGHT, "To the right of you is another plushie like the ones before, except this time it's a chameleon.");
    pRoom->setDirectionText(ROOM_LEFT, "To the left of you is another plushie like the ones before, but this time it's a dragon.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("A plush chameleon with a collar that has the name 'Sam' written on it and another plush, this one a dragon with a collar that has the name 'Captain' written on it", 200);
    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogey* pBogey = new Bogey("the ragdoll conductor", 100);
    pBogey->setText("'GET AWAY FROM THAT!'");

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogey(pBogey);

    return pRoom;
}

