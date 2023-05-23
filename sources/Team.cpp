#include "Team.hpp"
using namespace std;
namespace ariel
{

    Team::Team(Character *leader) : leader(leader)
    {
        if (leader->isInTeam())
        {
            throw runtime_error("error: member is already in another team");
        }
        members.push_back(leader);
        leader->setInTeam(true);
        lastCowboy = 0;
    }

    Team::~Team()
    {
        for (Character *member : members)
        {
            delete member;
        }

        // delete leader;
    }

    void Team::add(Character *character)
    {
        if (members.size() == 10)
        {
            throw runtime_error("error: can't add character to team. team is full.");
        }

        if (character->isInTeam())
        {
            throw runtime_error("error: can't add character to team. character is in another team already");
        }

        if (character->getType() == COWBOY)
        {
            // if cowboy, insert after the last cowboy
            members.insert(members.begin() + lastCowboy, character);
            lastCowboy++;
        }
        else
        {
            // if ninja, insert at the end
            members.push_back(character);
        }

        character->setInTeam(true);
        leader = findNewLeader();
    }

    void Team::print()
    {
        for (Character *member : members)
        {
            member->print();
        }
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (Character *member : members)
        {
            if (member->isAlive())
            {
                count++;
            }
        }

        return count;
    }

    Character *Team::findNewLeader()
    {
        Character *newLeader = NULL;
        double minLocation = numeric_limits<double>::max();

        for (Character *member : members)
        {
            if (member->isAlive())
            {
                double distance = leader->distance(member);
                if (distance < minLocation && member != leader)
                {
                    minLocation = distance;
                    newLeader = member;
                }
            }
        }

        return newLeader;
    }

    Character *Team::findVictim(Team *enemy)
    {
        Character *victim = NULL;
        double minLocation = numeric_limits<double>::max();

        for (Character *member : (*enemy->getMembers()))
        {
            double distance = leader->distance(member);
            if (member->isAlive() && distance < minLocation)
            {
                minLocation = distance;
                victim = member;
            }
        }

        return victim;
    }

    void Team::attack(Team *enemy)
    {
        if (enemy == NULL)
        {
            throw invalid_argument("error: failed to attack. enemy team is null.");
        }
        if (stillAlive() == 0)
        {
            // we lost the game..
            return;
        }

        if (!leader->isAlive())
        {
            // elect a new leader since current leader is dead.
            Character *newLeader = findNewLeader();
            if (newLeader == NULL)
            {
                throw runtime_error("error: failed to find a new leader from team.");
            }
            leader = newLeader;
        }

        Character *victim = findVictim(enemy);
        if (victim == NULL)
        {
            throw runtime_error("failed to find a victim, all members are dead.");
        }

        // instruct all alive members to attack the selected victim
        bool isMemberAlive = false;
        for (Character *member : members)
        {
            if (member->isAlive())
            {
                isMemberAlive = true;
                member->attack(victim);
            }

            if (!victim->isAlive())
            {
                victim = findVictim(enemy);
            }

            if (victim == NULL)
            {
                // no more alive members in enemy team
                return;
            }
        }

        if (!isMemberAlive)
        {
            // if there are no alive members. finish attack;
            return;
        }
    }

    Character *Team::getLeader()
    {
        return leader;
    }

    void Team::setLeader(Character *leader)
    {
        this->leader = leader;
    }

    std::vector<Character *> *Team::getMembers()
    {
        return &members;
    }
}