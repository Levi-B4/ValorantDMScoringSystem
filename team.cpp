#include "team.h"
#include "DSString/dsstring.h"

// constructor - params: DSString name
Team::Team(DSString name, int maxPlayers){
    this->name = name;
    this->maxPlayers = maxPlayers;

    players = new Player[maxPlayers];
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

// getter - int maxPlayers
int Team::getMaxPlayers(){
    return maxPlayers;
}

// setter - int maxPlayers
void Team::setMaxPlayers(int maxPlayers){
    this->maxPlayers = maxPlayers;
    delete[] players;

    players = new Player[maxPlayers];
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

// adds player to players - params: int id, DSString name
bool Team::addPlayer(int id, DSString name){
    if(numPlayers >= maxPlayers){
        return false;
    } else {
        players[numPlayers++] = Player(id, name, maxPlayers);
        return true;
    }
}

// sorts players by kills, then in alphabetical order
void Team::sortPlayers(){

}

// assignment operator=
Team& Team::operator=(const Team& other){
    if(this == &other){
        return *this;
    }

    delete[] players;
    players = new Player[other.maxPlayers];
    for(int i = 0; i < other.numPlayers; i++){
        players[i] = other.players[i];
    }

    name = other.name;
    numPlayers = other.numPlayers;
    maxPlayers = other.maxPlayers;
    totalPoints = other.totalPoints;

    return *this;
}

// default destructor
Team::~Team(){
    delete[] players;
}
