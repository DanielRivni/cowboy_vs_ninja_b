#ifndef OLDNINJA_H
#define OLDNINJA_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Ninja.hpp"

namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(std::string name, Point location);
        ~OldNinja() override;
    };

}

#endif