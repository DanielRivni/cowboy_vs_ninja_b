#ifndef OLDNINJA_H
#define OLDNINJA_H

#include <iostream>
#include <stdexcept>
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(std::string name, Point location);
        // for tidy to work
        ~OldNinja() override = default;
        OldNinja(const OldNinja &) = default;
        OldNinja &operator=(const OldNinja &) = default;
        OldNinja(OldNinja &&) noexcept = default;
        OldNinja &operator=(OldNinja &&) noexcept = default;
    };
}

#endif
