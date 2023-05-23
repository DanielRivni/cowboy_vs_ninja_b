#ifndef SMART_TEAM_H
#define SMART_TEAM_H
#include <iostream>
#include <sstream>
#include <list>
#include <stdexcept>
#include <cmath>
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
        Character *findVictim(SmartTeam *enemy, Character *attacker);
        Character *findLeader(SmartTeam *enemy);
        void attack(SmartTeam *enemy);
    };
}

#endif
