#include "player.h"

// constructor - params: int id, DSString name
Player::Player(int id, DSString name, int playersPerTeam){
    this->id = id;
    this->name = name;

    enemyIds = new int[playersPerTeam];
    enemyKills = new int[playersPerTeam];

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

// getter - int totalPoints
int Player::getTotalPoints() const{
    return totalPoints;
}

// adds kill info to killsPerId and adds to kill and point totals - params: int targetId, int pointValue
void Player::addKill(int targetId, int pointValue){

}

// returns number of kills on given id - params: int id
int Player::getKillsForId(int id) const{
    return -1;
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
}
