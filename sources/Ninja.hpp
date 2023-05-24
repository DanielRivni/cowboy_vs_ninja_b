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
        // for tidy to pass
        Ninja(const Ninja &other);
        Ninja &operator=(const Ninja &other);
        Ninja(Ninja &&other) noexcept;
        Ninja &operator=(Ninja &&other) noexcept;

        ~Ninja() override;
        virtual void move(Character *enemy);
        virtual void slash(Character *enemy);
        int getSpeed() const;
        void attack(Character *enemy) override;
        type getType() override;
    };
}

#endif
