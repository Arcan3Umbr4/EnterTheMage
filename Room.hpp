//
//  Room.hpp
//  Zork
//
//  Created by MxC on 1/31/24.
//

// Room.hpp

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include "Remote.hpp" // Include Remote.h if you want to store Remote* in the Room

class Room {
public:
    std::string description;
    std::map<std::string, Room*> exits;
    std::map<std::string, Remote*> items; // Key: item name, Value: Remote*

    Room(std::string desc);
    ~Room(); // Destructor to clean up dynamically allocated Remote objects
    void setExit(std::string direction, Room* room);
    Room* getExit(std::string direction);
    void addItem(std::string itemName, Remote* remote);
    void searchRoom();
};

#endif // ROOM_H


