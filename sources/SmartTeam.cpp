#include "SmartTeam.hpp"
using namespace std;
namespace ariel
{

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    Character *SmartTeam::findVictim(SmartTeam *enemy)
    {
        Character *victim = NULL;
        double minLocation = numeric_limits<double>::max();
        double minLife = numeric_limits<double>::max();

        for (Character *member : (*enemy->getMembers()))
        {
            double distance = getLeader()->distance(member);
            if (member->isAlive() && distance < minLocation && member->getHealth() < minLife)
            {
                minLocation = distance;
                minLife = member->getHealth();
                victim = member;
            }
        }

        return victim;
    }

    void *SmartTeam::findLeader(SmartTeam *enemy)
    {
        Character *attacker = NULL;
        double minLocation = numeric_limits<double>::max();
        double health = numeric_limits<double>::min();

        for (Character *member : (*this->getMembers()))
        {
            double distance = member->distance(findVictim(enemy));

            if (member->isAlive() && distance < 1 && member->getType() == NINJA)
            {
                attacker = member;
            }
        }
        if (attacker != NULL)
        {
            setLeader(attacker);
            return;
        }

        for (Character *member : (*this->getMembers()))
        {
            double distance = member->distance(findVictim(enemy));

            if (member->isAlive() && distance < 1 && member->getType() == COWBOY)
            {
                attacker = member;
            }
        }
        if (attacker != NULL)
        {
            setLeader(attacker);
            return;
        }
        for (Character *member : (*this->getMembers()))
        {
            double distance = member->distance(findVictim(enemy));

            if (member->isAlive() && distance < minLocation)
            {
                minLocation = distance;
                attacker = member;
            }
        }
        if (attacker != NULL)
        {
            setLeader(attacker);
            return;
        }
        for (Character *member : (*this->getMembers()))
        {

            if (member->isAlive() && member->getHealth() > health)
            {
                health = member->getHealth();
                attacker = member;
            }
        }
        if (attacker != NULL)
        {
            setLeader(attacker);
            return;
        }
    }
    void SmartTeam::attack(SmartTeam *enemy)
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

        if (!getLeader()->isAlive())
        {
            // elect a new leader since current leader is dead.
            Character *newLeader = findNewLeader();
            if (newLeader == NULL)
            {
                throw runtime_error("error: failed to find a new leader from team.");
            }
            setLeader(newLeader);
        }

        Character *victim = findVictim(enemy);
        if (victim == NULL)
        {
            throw runtime_error("failed to find a victim, all members are dead.");
        }

        // instruct all alive members to attack the selected victim
        bool isMemberAlive = false;
        for (Character *member : (*enemy->getMembers()))
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
}