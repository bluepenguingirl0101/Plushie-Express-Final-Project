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
    pRoom->setDirectionText(ROOM_LEFT, "There is a beautiful view to the right of you. The sceneary is too fast to take in all the details.");
    pRoom->setDirectionText(ROOM_BACK, "There's a note on the table under the window that says, 'enjoy the ride~'.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("a plush guinea pig with a collar that has the name 'Daniel' written on it.", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    MagicWord* pMagicWord = new MagicWord("plushies", 300);
    pMagicWord->setText("All of a sudden 3 plushies land in front of you:"
        "\n" "a lion with the name 'Jared', "
        "\n" "a leopard with the name 'Connor'," 
        "\n" "and an owl with the name 'Garrett'");
    pRoom->addMagicWord(pMagicWord);

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
    pRoom->setDirectionText(ROOM_LEFT, "To the left of you is your passenger car, but on the floor of the passenger car you see a two small wolf plushies.");
    pRoom->setDirectionText(ROOM_BACK, "On the floor you see a pencil that has some teeth marks. Seems someone likes to chew their pencil.");
    pRoom->setDirectionText(ROOM_RIGHT, "To the right of you, you see a girl with a blonde ponytail, wearing a white t-shirt and blue shorts."
       "\n" "Her blue eyes look at you as if she has something she wants to tell you.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("two plush wolfs with a collar on each:" 
        "\n" "one with the name 'Carlos'" 
        "\n" "and one with the name 'Alex'.", 200);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("pencil with non-human teeth marks", 100);
    pWeapon->setText("You try using the pencil");

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    //create and initalize NPC instance
    NPC* pNPC = new NPC("the blonde girl to ask her about information..."
        "\n" "'Oh hi! My name's Kylie!'"
        "\n" "'No, sorry, I don't remember how or when on got on this train either...'"
        "\n" "'Buuut, I DO remember seeing the word 'plushies' on a card in my room.'"
        "\n" "'I tried saying it in my room, but nothing happened for me...'", 100);
    // install NPC pointer in Room's NPC vector
    pRoom->addNPC(pNPC);

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
    pRoom->setDirectionText(ROOM_RIGHT, "You look around once more and notice a plush tiger sitting on one of the tables." 
        "\n" "Along with a spool of thread and a sewing needle.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("a plush tiger with a collar that has the name 'Morgan' written on it", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("needle and some thread", 100);
    pWeapon->setText("you try and use the needle and thread.");

    // install Treasure pointer in Room's Treasure vector
    pRoom->addWeapon(pWeapon);

    //create and initalize NPC instance
    NPC* pNPC = new NPC("the frantic orange rabbit..."
        "\n" "'ACK-! I don't got time to talk right now-!'"
        "\n" "'I'm sorry- but I'm looking for my pencil right now!'"
        "\n" "'I just got this great idea for a sketch-!'", 100);
    // install NPC pointer in Room's NPC vector
    pRoom->addNPC(pNPC);

    // create and initialize Bogie instance
    Bogey* pBogey = new Bogey("Sketch the rabbit", 100);
    pBogey->setText("'H-hey! That's mine! Thank you so much!'"
    "\n" "'I don't know much, but I overheard the conductor the chef talking.'"
    "\n" "'I guess the name 'liz' means something 'cause the conductor told the chef not to say it.'");

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogey(pBogey);

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
    pRoom->setDirectionText(ROOM_BACK, "Looks like the a sweet dessert is being made right now by a cute couple- a blonde and a man with glasses.");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("A plush sea lion with a collar that has the name 'Emily' written on it", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogey* pBogey = new Bogey("the grumpy plush chef", 100);
    pBogey->setText("You sew up the chef's fabric arm so it's good as new. It's a bit difficult since he does squirm a bit."
    "\n" "'Ah... thanks kid... name's Damon, uh... as thanks you can... you can take the stuffed sea lion on the counter.'"
    "\n" "'Also uh... boss lady in the next room, don't be so hard on her okay?'");

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogey(pBogey);

    //create and initalize NPC instance
    NPC* pNPC = new NPC("the grummy plush chef..."
        "\n" "'What do you want kid? Get out of here. I'm kinda busy since my arm is kinda busted.'"
        "\n" "'Dang arm ripped on me and now my stuffing's gonna get everywhere if I don't sew it back up.'", 100);
    // install NPC pointer in Room's NPC vector
    pRoom->addNPC(pNPC);

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
    pBogey->setText("'Huh, didn't expect that..'"
        "\n" "'Well, um, here have some points so I can go back to work driving the train!'");

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogey(pBogey);

    //create and initalize NPC instance
    NPC* pNPC = new NPC("the ragdoll conductor..."
        "\n" "'Ah, you're the new passenger aren't you? How are you enjoying the ride? I hope you like it because it'll be a long...'"
        "\n" "LONG time before we stop.'", 100);
    // install NPC pointer in Room's NPC vector
    pRoom->addNPC(pNPC);

    MagicWord* pMagicWord = new MagicWord("liz", 300);
    pMagicWord->setText("The second you say it, the conductor looks at you with an slightly agap mouth."
        "\n" "'You... how... that name... it's the... nickname my family gave me..."
        "\n" "The plushies you've found they... they're my family... we were turned into stuffed toys."
        "\n" "I was the only one who was given speech next to chef Damon.'"
        "\n" "The conductor that was so upset before, gives a small smile."
        "\n" "'I'm so sorry, I just... didn't want to be alone anymore."
        "\n" "I hope you and the rest of the passengers forgive me. But for now, please enjoy the rest of your ride!" 
        "\n" "We'll all be home soon!'"
        "\n"
        "\n" "You Won!"
        "\n"
        "\n" "This game is deticated to both of my familes."
        "\n" "Blood and friend.");
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

