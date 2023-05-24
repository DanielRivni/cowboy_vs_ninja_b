#include "Character.hpp"
using namespace std;
namespace ariel
{

    Character::Character(string name, Point location, int health) : name(name), location(location), health(health) {}

    // for tidy to pass
    Character::Character(const Character &other)
    {
        name = other.name;
        location = other.location;
        health = other.health;
        inTeam = other.inTeam;
    }

    Character &Character::operator=(const Character &other)
    {
        if (this == &other)
        {
            return *this;
        }

        name = other.name;
        location = other.location;
        health = other.health;
        inTeam = other.inTeam;

        return *this;
    }

    Character::Character(Character &&other) noexcept
    {
        name = move(other.name);
        location = move(other.location);
        health = other.health;
        inTeam = other.inTeam;

        other.health = 0;
        other.inTeam = false;
    }

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        name = move(other.name);
        location = move(other.location);
        health = other.health;
        inTeam = other.inTeam;

        other.health = 0;
        other.inTeam = false;

        return *this;
    }

    Character::~Character() {}

    bool Character::isAlive() const
    {
        return health > 0;
    }
    double Character::distance(const Character *other) const
    {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damagePoint)
    {
        if (damagePoint < 0)
        {
            throw invalid_argument("error: Damage cant be negative");
        }
        if (!isAlive())
        {
            throw runtime_error("error: Character is allready dead");
        }
        health -= damagePoint;
    }

    string Character::print() const
    {
        return "";
    }

    string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }

    int Character::getHealth() const
    {
        return health;
    }

    bool Character::isInTeam() const
    {
        return inTeam;
    }

    void Character::setName(string name)
    {
        this->name = name;
    }

    void Character::setLocation(Point location)
    {
        this->location = location;
    }

    void Character::setHealth(int health)
    {
        this->health = health;
    }

    void Character::setInTeam(bool inTeam)
    {
        this->inTeam = inTeam;
    }
}