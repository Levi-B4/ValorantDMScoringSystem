#ifndef PLAYER_H
#define PLAYER_H

#include "DSString/dsstring.h"

class Player
{
public:
    // constructor - params: int id, DSString name
    Player(int id = -1, DSString name = "", int PlayersPerTeam = 1);


    // getter - int id
    int getId() const;
    // setter - int id
    void setId(int id);

    // getter - DSString name
    DSString getName() const;
    // setter - DSString name
    void setName(DSString name);

    // getter - int totalKills
    int getTotalKills() const;

    // getter - int totalPoints
    int getTotalPoints() const;

    // getter - int* enemyIds
    int* getEnemyIds() const;


    // adds kill info to killsPerId and adds to kill and point totals - params: int targetId, int pointValue
    void addKill(int targetId, int pointValue);

    // returns number of kills on given id - params: int id
    int getKillsForId(int id) const;


    // assignment operator=
    Player& operator=(const Player& other);


    // default destructor
    ~Player();

private:
    int id;
    DSString name = "";
    int playersPerTeam = 0;
    int totalKills = 0;
    int totalPoints = 0;

    int* enemyIds;
    int* enemyKills;
};

#endif // PLAYER_H
