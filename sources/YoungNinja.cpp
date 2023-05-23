
#include <stdexcept>
#include <cmath>

#include "Ninja.hpp"
#include "YoungNinja.hpp"

using namespace std;
namespace ariel
{
    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {}

    YoungNinja::~YoungNinja() {}
}