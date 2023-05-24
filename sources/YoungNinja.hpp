#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include <iostream>
#include <stdexcept>
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(std::string name, Point location);
        // for tidy to work
        ~YoungNinja() override = default;
        YoungNinja(const YoungNinja &) = default;
        YoungNinja &operator=(const YoungNinja &) = default;
        YoungNinja(YoungNinja &&) noexcept = default;
        YoungNinja &operator=(YoungNinja &&) noexcept = default;
    };
}

#endif
