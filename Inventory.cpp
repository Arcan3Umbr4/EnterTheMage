//
//  Inventory.cpp
//  Zork
//
//  Created by MxC on 1/31/24.
//

#include "Inventory.hpp"
#include <iostream>

void Inventory::addItem(const std::string& itemName, const std::string& itemDescription) {
    items[itemName] = itemDescription;
}

void Inventory::removeItem(const std::string& itemName) {
    items.erase(itemName);
}

void Inventory::displayItems() {
    if (items.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    } else {
        std::cout << "You have the following items:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item.first << ": " << item.second << std::endl;
        }
    }
}
