
#include <stdexcept>
#include <cmath>

#include "Ninja.hpp"
#include "OldNinja.hpp"

using namespace std;
namespace ariel
{

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {}

    OldNinja::~OldNinja() {}

}