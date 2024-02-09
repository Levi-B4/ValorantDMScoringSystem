#ifndef PLAYER_H
#define PLAYER_H

#include "DSString/dsstring.h"

class Player
{
public:
    // default constructor
    Player();
    // constructor - params: int id, DSString name
    Player(int id, DSString name);

    // getter - int id
    int getId();
    // setter - int id
    void setId(int id);

    // getter - DSString name
    DSString getName();
    // setter - DSString name
    void setName(DSString name);

    // getter - int totalKills
    int getTotalKills();

    // getter - int totalPoints
    int getTotalPoints();

    // adds kill info to killsPerId and adds to kill and point totals - params: int targetId, int pointValue
    void addKill(int targetId, int pointValue);

    // returns number of kills on given id - params: int id
    int getKillsForId(int id);

    // default destructor
    ~Player();

private:
    int id;
    DSString name;
    int totalKills;
    int totalPoints;
    // int[numPlayers][2] - [{id1, timesKilled}, {id2, timesKilled}, ... ]
    int** killsPerId;


};

#endif // PLAYER_H
