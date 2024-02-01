//
//  Inventory.hpp
//  Zork
//
//  Created by MxC on 1/31/24.
//
#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>

class Inventory {
public:
    std::map<std::string, std::string> items; // Key: item name, Value: description

    void addItem(const std::string& itemName, const std::string& itemDescription);
    void removeItem(const std::string& itemName);
    void displayItems();
};

#endif // INVENTORY_H
