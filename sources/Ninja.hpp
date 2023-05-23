#ifndef NINJA_H
#define NINJA_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(std::string name, Point location, int health, int speed);
        virtual ~Ninja() override;
        virtual void move(Character *enemy);
        virtual void slash(Character *enemy);
        int getSpeed() const;
        void attack(Character *enemy) override;
        type getType() override;
    };
}

#endif
