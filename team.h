#ifndef TEAM_H
#define TEAM_H

#include "DSString/dsstring.h"
#include "player.h"

class Team
{
public:
    // default constructor
    Team();
    // constructor - params: DSString name
    Team(DSString name);


    // getter - Player* players
    Player* getPlayers();

    // getter - DSString name
    DSString getName();
    // setter - DSString name
    void setName(DSString name);

    // getter - int numPlayers
    int getNumPlayers();

    // getter - int totalPoints
    int getTotalPoints();


    // returns topPlayer
    Player getTopPlayer();

    // processes a kill by adding values to players and to team - params: int shooterId, int targetId, int pointValue
    void processKill(int shooterId, int targetId, int pointValue);

    // adds player to players
    void addPlayer(int id, DSString name);

    // sorts players by kills, then in alphabetical order
    void sortPlayers();


    // default destructor
    ~Team();

private:
    DSString name;
    Player* players;
    int numPlayers;
    int totalPoints;
};

#endif // TEAM_H
