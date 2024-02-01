//
//  Item.hpp
//  Zork
//
//  Created by MxC on 1/31/24.
//
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    virtual ~Item() = default; // Virtual destructor for a proper cleanup of derived classes
    virtual std::string getDescription() const = 0;
    virtual void use() = 0;
};

#endif // ITEM_H


