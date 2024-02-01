//
//  Game.cpp
//  Zork
//
//  Created by MxC on 1/31/24.
//

#include "Game.hpp"
#include <iostream>

using namespace std;
// Constructor
Game::Game() : printRoomDescription(true) {
    // Create and setup rooms
    Room* livingRoom = new Room("You are in the living room. There's an exit to the north.");
    Room* kitchen = new Room("You are in the kitchen. There's an exit to the south.");
    Room* garden = new Room("You are in the garden. There's an exit to the south.");

    // Set exits for rooms
    livingRoom->setExit("north", kitchen);
    kitchen->setExit("south", livingRoom);
    
    kitchen->setExit("east", garden);
    garden->setExit("west", kitchen);

    // Add items to rooms
    Remote* livingRoomRemote = new Remote("Controls Living Room TV");
    livingRoom->addItem("remote", livingRoomRemote);

    // Set the initial current room
    currentRoom = livingRoom;
}

// Destructor
Game::~Game() {
    // TODO: Clean up dynamically allocated Room objects and other resources
}

void Game::run() {
    while (true) {
        std::string thisRM = currentRoom->description;
        
        // Display current room description
        if (printRoomDescription) {
            std::cout << currentRoom->description << std::endl;
            printRoomDescription = false; // Reset the flag
        }

        // Get command from the user
        std::string command;
        std::cout << "> ";
        getline(std::cin, command);

        // Process commands
        if (command == "quit") {
            std::cout << "Thank you for playing!" << std::endl;
            break; // Exit the game loop
        } else if (command == "search" || command == "look") {
            currentRoom->searchRoom();
        } else if (command == "where" || command == "lost") {
            cout << "*Sticks Finger In Air* \n" << thisRM << endl;
            continue;
        } else if (command.substr(0, 4) == "take") {
            if (command.size() <= 5) { // "take " is 5 characters
                cout << "Take what?" << endl;
                continue;
                }
            takeItem(command.substr(5)); // Pass the item name to takeItem
        } else {
            Room* nextRoom = currentRoom->getExit(command);
            if (nextRoom != nullptr) {
                currentRoom = nextRoom;
            } else {
                std::cout << "You can't go that way." << std::endl;
            }
        }
        printRoomDescription = true;
    }
}

void Game::takeItem(const std::string& itemName) {
    auto it = currentRoom->items.find(itemName);
    if (it != currentRoom->items.end()) {
        inventory.addItem(it->first, it->second->getDescription());

        delete it->second; // Free the memory allocated for Remote object
        currentRoom->items.erase(it);

        std::cout << "Taken: " << itemName << std::endl;
    } else {
        std::cout << "No item named '" << itemName << "' here." << std::endl;
    }
}
