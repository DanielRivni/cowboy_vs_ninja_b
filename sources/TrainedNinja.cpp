#include <stdexcept>
#include <cmath>

#include "Ninja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel
{

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {}

    TrainedNinja::~TrainedNinja() {}

}