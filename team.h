#ifndef TEAM_H
#define TEAM_H

#include "DSString/dsstring.h"
#include "player.h"

class Team
{
public:
    // constructor - params: DSString name
    Team(DSString name = "", int maxPlayers = 0);


    // getter - Player* players
    Player* getPlayers();

    // getter - DSString name
    DSString getName();
    // setter - DSString name
    void setName(DSString name);

    // getter - int numPlayers
    int getNumPlayers();

    // getter - int maxPlayers
    int getMaxPlayers();
    // setter - int maxPlayers
    void setMaxPlayers(int maxPlayers);

    // getter - int totalPoints
    int getTotalPoints();


    // returns topPlayer
    Player getTopPlayer();

    // processes a kill by adding values to players and to team - params: int shooterId, int targetId, int pointValue
    void processKill(int shooterId, int targetId, int pointValue);

    // adds player to players, returns false if at maxPlayers - params: int id, DSString name
    bool addPlayer(int id, DSString name);

    // sorts players by kills, then in alphabetical order
    void sortPlayers();


    // assignment operator=
    Team& operator=(const Team& other);


    // default destructor
    ~Team();

private:
    DSString name = "";
    Player* players;
    int numPlayers = 0;
    int maxPlayers;
    int totalPoints;
};

#endif // TEAM_H
