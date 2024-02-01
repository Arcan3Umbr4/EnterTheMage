//
//  Remote.cpp
//  Zork
//
//  Created by MxC on 1/31/24.
//

#include "Remote.hpp"

Remote::Remote(const std::string& desc) : description(desc) {}

std::string Remote::getDescription() const {
    return description;
}

void Remote::use() {
    std::cout << "Using the remote: " << description << std::endl;
}
