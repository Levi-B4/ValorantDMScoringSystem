#include "player.h"

// defaulst constructor
Player::Player(){

}

// constructor - params: int id, DSString name
Player::Player(int id, DSString name){

}

// getter - int id
int Player::getId(){
    return id;
}

// setter - int id
void Player::setId(int id){
    this->id = id;
}

// getter - DSString name
DSString Player::getName(){
    return name;
}

// setter - DSString name
void Player::setName(DSString name){
    this->name = name;
}

// getter - int totalKills
int Player::getTotalKills(){
    return totalKills;
}

// getter - int totalPoints
int Player::getTotalPoints(){
    return totalPoints;
}

// adds kill info to killsPerId and adds to kill and point totals - params: int targetId, int pointValue
void Player::addKill(int targetId, int pointValue){

}

// returns number of kills on given id - params: int id
int Player::getKillsForId(int id){
    return -1;
}

// default destructor
Player::~Player(){

}
