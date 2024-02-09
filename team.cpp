#include "team.h"
#include "DSString/dsstring.h"

// default constructor
Team::Team(){

}

// constructor - params: DSString name
Team::Team(DSString name){

}

// getter - Player* players
Player* Team::getPlayers(){
    return players;
}

// getter - DSString name
DSString Team::getName(){
    return name;
}

// setter - DSString name
void Team::setName(DSString name){
    this->name = name;
}

// getter - int numPlayers
int Team::getNumPlayers(){
    return numPlayers;
}

// getter - int totalPoints
int Team::getTotalPoints(){
    return totalPoints;
}

// returns topPlayer
Player Team::getTopPlayer(){
    return players[1];
}

// processes a kill by adding values to players and to team - params: int shooterId, int targetId, int pointValue
void Team::processKill(int shooterId, int targetId, int pointValue){

}

// adds player to players
void Team::addPlayer(int id, DSString name){

}

// sorts players by kills, then in alphabetical order
void Team::sortPlayers(){

}

// default destructor
Team::~Team(){

}
