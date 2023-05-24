#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H
#include <iostream>
#include <stdexcept>
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(std::string name, Point location);
        // for tidy to work
        ~TrainedNinja() override = default;
        TrainedNinja(const TrainedNinja &) = default;
        TrainedNinja &operator=(const TrainedNinja &) = default;
        TrainedNinja(TrainedNinja &&) noexcept = default;
        TrainedNinja &operator=(TrainedNinja &&) noexcept = default;
    };
}

#endif
