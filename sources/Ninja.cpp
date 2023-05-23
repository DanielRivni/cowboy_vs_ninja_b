#include "Ninja.hpp"
using namespace std;
namespace ariel
{
    // Constructors
    Ninja::Ninja(string name, Point location, int HealthPoints, int speed) : Character(name, location, HealthPoints), speed(speed) {}

    Ninja::~Ninja() {}
    // Functions
    void Ninja::move(Character *enemy)
    {
        if (!isAlive())
        {
            throw runtime_error("error: Character is dead (can't move)");
        }
        double enemyDist = getLocation().distance(enemy->getLocation());
        double moveDist = (speed < enemyDist) ? speed : enemyDist;
        Point newLocation = getLocation().moveTowards(getLocation(), enemy->getLocation(), moveDist);
        setLocation(newLocation);
    }

    void Ninja::slash(Character *enemy)
    {
        if (enemy == this)
        {
            throw runtime_error("error: Can't slash yourself");
        }
        if (!isAlive())
        {
            throw runtime_error("error: you're dead");
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("error: Target is allready dead");
        }
        if (getLocation().distance(enemy->getLocation()) > 1)
        {
            return;
        }
        enemy->hit(40);
    }

    int Ninja::getSpeed() const
    {
        return speed;
    }

    void Ninja::attack(Character *enemy)
    {
        if (getLocation().distance(enemy->getLocation()) > 1)
        {
            move(enemy);
            return;
        }
        slash(enemy);
    }

    type Ninja::getType()
    {
        return NINJA;
    }
}