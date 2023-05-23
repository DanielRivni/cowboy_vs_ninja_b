#include "SmartTeam.hpp"
using namespace std;
namespace ariel
{

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    // finds a victim that is alive and also the nearest to the attacker and with the minimum life left
    Character *SmartTeam::findVictim(SmartTeam *enemy, Character *attacker)
    {
        Character *victim = NULL;
        double minLocation = numeric_limits<double>::max();
        double maxHealth = numeric_limits<double>::max();

        for (Character *member : (*enemy->getMembers()))
        {
            double distance = attacker->distance(member);
            if (member->isAlive() && distance < minLocation && member->getHealth() < maxHealth)
            {
                minLocation = distance;
                maxHealth = member->getHealth();
                victim = member;
            }
        }

        return victim;
    }

    // finds a leader that is alive and  with the maximum life left
    Character *SmartTeam::findLeader(SmartTeam *enemy)
    {
        Character *newLeader = NULL;
        double minHealth = numeric_limits<double>::min();

        for (Character *member : (*this->getMembers()))
        {

            if (member->isAlive() && member->getHealth() > minHealth)
            {
                newLeader = member;
            }
        }
        if (newLeader != NULL)
        {
            return newLeader;
        }
        return newLeader;
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

        // instruct all alive members to attack the selected victim
        bool isMemberAlive = false;
        for (Character *member : (*this->getMembers()))
        {
            Character *victim = findVictim(enemy, member);
            if (victim == NULL)
            {
                // game over no more players alive
                return;
            }

            if (member->isAlive())
            {
                isMemberAlive = true;
                member->attack(victim);
            }
        }

        if (!isMemberAlive)
        {
            // if there are no alive members. finish attack;
            return;
        }
    }
}