#ifndef COWBOY_H
#define COWBOY_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(std::string name, Point location);
        ~Cowboy() override;
        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        int getBullets() const;
        void attack(Character *enemy) override;
        type getType() override;
    };
}

#endif
