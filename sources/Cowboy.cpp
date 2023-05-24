#include "Cowboy.hpp"
using namespace std;
namespace ariel
{
    // Constructors
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bullets(6) {}

    // for the tidy to pass
    Cowboy::Cowboy(const Cowboy &other) : Character(other), bullets(other.bullets) {}

    Cowboy &Cowboy::operator=(const Cowboy &other)
    {
        if (this != &other)
        {
            Character::operator=(other);
            bullets = other.bullets;
        }
        return *this;
    }

    Cowboy::Cowboy(Cowboy &&other) noexcept : Character(move(other)), bullets(move(other.bullets)) {}

    Cowboy &Cowboy::operator=(Cowboy &&other) noexcept
    {
        if (this != &other)
        {
            Character::operator=(move(other));
            bullets = move(other.bullets);
        }
        return *this;
    }

    Cowboy::~Cowboy() {}

    // Functions
    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == this)
        {
            throw runtime_error("error: You can't shoot yourself");
        }
        if (!hasboolets())
        {
            reload();
            return;
        }
        if (!isAlive())
        {
            throw runtime_error("error: You're dead");
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("error: Target is allready dead");
        }
        enemy->hit(10);
        this->bullets--;
    }

    bool Cowboy::hasboolets() const
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw runtime_error("error: Character is dead");
        }
        this->bullets = 6;
    }

    // Getters and Setters
    int Cowboy::getBullets() const
    {
        return bullets;
    }
    void Cowboy::attack(Character *enemy)
    {
        shoot(enemy);
    }

    type Cowboy::getType()
    {
        return COWBOY;
    }
}