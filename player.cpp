#include "player.h"

// constructor - params: int id, DSString name
Player::Player(int id, DSString name, int playersPerTeam){
    this->id = id;
    this->name = name;

    enemyIds = new int[playersPerTeam];
    enemyKills = new int[playersPerTeam];
    for(int i = 0; i < playersPerTeam; i++){
        enemyIds[i] = 0;
        enemyKills[i] = 0;
    }

    this->playersPerTeam = playersPerTeam;
}

// getter - int id
int Player::getId() const{
    return id;
}

// setter - int id
void Player::setId(int id){
    this->id = id;
}

// getter - DSString name
DSString Player::getName() const{
    return name;

}

// setter - DSString name
void Player::setName(DSString name){
    this->name = name;
}

// getter - int totalKills
int Player::getTotalKills() const{
    return totalKills;
}

// setter - int totalKills
void Player::setTotalKills(int totalKills){
    this->totalKills = totalKills;
}

// getter - int totalPoints
int Player::getTotalPoints() const{
    return totalPoints;
}

// getter - int* enemyIds
int* Player::getEnemyIds() const{
    return enemyIds;
}

// adds kill info to killsPerId and adds to kill and point totals - params: int targetId, int pointValue
void Player::addKill(int targetId, int pointValue){
    for(int i = 0; i < playersPerTeam; i++){
        if(enemyIds[i] == targetId){
            enemyKills[i]++;
        }
    }
    totalKills++;
    totalPoints += pointValue;
}

// returns number of kills on given id - params: int id
int Player::getKillsOnPlayer(int id) const{
    for(int i = 0; i < playersPerTeam; i++){
        if(enemyIds[i] == id){
            return enemyKills[i];
        }
    }

    return 0;
}

// adds enemie ids to enemyIds
void Player::addEnemies(const Player* enemies){
    for(int i = 0; i < playersPerTeam; i++){
        enemyIds[i] = enemies[i].getId();
    }
}

// assignment operator=
Player& Player::operator=(const Player& other){
    if(this == &other){
        return *this;
    }

    delete[] enemyIds;
    delete[] enemyKills;

    enemyIds = new int[other.playersPerTeam];
    enemyKills = new int[other.playersPerTeam];

    for(int i = 0; i < other.playersPerTeam; i++){
        enemyIds[i] = other.enemyIds[i];
        enemyKills[i] = other.enemyKills[i];
    }

    id = other.id;
    name = other.name;
    playersPerTeam = other.playersPerTeam;
    totalKills = other.totalKills;
    totalPoints = other.totalPoints;

    return *this;
}

// default destructor
Player::~Player(){
    delete[] enemyIds;
    delete[] enemyKills;
}
