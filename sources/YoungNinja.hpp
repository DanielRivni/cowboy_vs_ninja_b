#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(std::string name, Point location);
        ~YoungNinja() override;
    };

}

#endif