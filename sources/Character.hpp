#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Point.hpp"
#include "Type.hpp"

namespace ariel
{
    class Character
    {
    private:
        std::string name;
        Point location;
        int health;
        bool inTeam = false;

    public:
        Character(std::string name, Point location, int health);
        // for tidy to pass
        Character(const Character &other);
        Character &operator=(const Character &other);
        Character(Character &&other) noexcept;
        Character &operator=(Character &&other) noexcept;

        virtual ~Character();
        virtual bool isAlive() const;
        virtual double distance(const Character *other) const;
        virtual void hit(int health);
        virtual std::string print() const;
        virtual void attack(Character *enemy) = 0; // define abstract function
        virtual type getType() = 0;

        // Getters and Setters
        std::string getName() const;
        Point getLocation() const;
        int getHealth() const;
        void setName(std::string name);
        void setLocation(Point location);
        void setHealth(int health);
        bool isInTeam() const;
        void setInTeam(bool inTeam);
    };

}

#endif
