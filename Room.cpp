//
//  Room.cpp
//  Zork
//
//  Created by MxC on 1/31/24.
//
#include "Room.hpp"
#include <iostream>

Room::Room(std::string desc) : description(desc) {}

Room::~Room() {
    for (auto& pair : items) {
        delete pair.second; // Free the memory allocated for Remote objects
    }
}

void Room::setExit(std::string direction, Room* room) {
    exits[direction] = room;
}

Room* Room::getExit(std::string direction) {
    auto it = exits.find(direction);
    return it != exits.end() ? it->second : nullptr;
}

void Room::addItem(std::string itemName, Remote* remote) {
    items[itemName] = remote;
}

void Room::searchRoom() {
    if (items.empty()) {
        std::cout << "There's nothing of interest here." << std::endl;
    } else {
        std::cout << "You find the following:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item.first << ": " << item.second->getDescription() << std::endl;
        }
    }
}
