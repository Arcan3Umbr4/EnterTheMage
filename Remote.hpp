//
//  Remote.hpp
//  Zork
//
//  Created by MxC on 1/31/24.
//

#ifndef REMOTE_H
#define REMOTE_H

#include "Item.hpp"
#include <iostream>

class Remote : public Item {
private:
    std::string description;

public:
    Remote(const std::string& desc);
    std::string getDescription() const override;
    void use() override;
};

#endif // REMOTE_H


