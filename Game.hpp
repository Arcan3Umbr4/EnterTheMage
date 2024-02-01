//
//  Game.hpp
//  Zork
//
//  Created by MxC on 1/31/24.
//

#ifndef GAME_H
#define GAME_H

#include "Room.hpp"
#include "Inventory.hpp"

class Game {
private:
    Room* currentRoom;
    Inventory inventory;

public:
    Game();
    ~Game(); // Destructor for cleaning up Room objects if they are dynamically allocated
    void run();
    void takeItem(const std::string& itemName);
};

#endif // GAME_H
