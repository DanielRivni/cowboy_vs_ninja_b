#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <limits>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> members;
        Character *leader;

        int lastCowboy;
        Character *findVictim(Team *enemy);

    public:
        Team(Character *leader);
        Team(const Team &) = default;
        Team &operator=(const Team &) = default;
        Team(Team &&) noexcept = default;
        Team &operator=(Team &&) noexcept = default;
        virtual ~Team();
        virtual void add(Character *character);
        void attack(Team *enemy);
        int stillAlive();
        void print();
        Character *getLeader();
        void setLeader(Character *leader);
        std::vector<Character *> *getMembers();

        // helpers
        Character *findNewLeader();
    };
}

#endif
