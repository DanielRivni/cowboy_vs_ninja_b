#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(std::string name, Point location);
        ~TrainedNinja() override;
    };

}

#endif