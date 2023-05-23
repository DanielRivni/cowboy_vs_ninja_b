#include "Team2.hpp"
using namespace std;

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::add(Character *character)
    {
        if (getMembers()->size() == 10)
        {
            throw runtime_error("error: can't add character to team2. team is full.");
        }

        if (character->isInTeam())
        {
            throw runtime_error("error: can't add character to team2. character is in another team already");
        }

        character->setInTeam(true);
        getMembers()->push_back(character);
        setLeader(findNewLeader());
    }

}