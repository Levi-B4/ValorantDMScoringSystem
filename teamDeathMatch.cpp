#include "teamDeathMatch.h"
#include "team.h"

#include "DSString/dsstring.h"

#include <fstream>
#include <iostream>

// default constructor
TeamDeathMatch::TeamDeathMatch(){}

// constructor - params: int numFiles, char** fileList, char* verbosity
TeamDeathMatch::TeamDeathMatch(char** fileList, char* verbosity){
    readTeamFile(fileList[0], &teamA);
    readTeamFile(fileList[1], &teamB);

    readMatchFile(fileList[2]);

    char* outputPath= fileList[3];

    if(verbosity == "vlow"){
        printLowVerbosity(outputPath);
    }

    if(verbosity == "vmed"){
        printMediumVerbosity(outputPath);
    }

    if(verbosity == "vhigh"){
        printHighVerbosity(outputPath);
    }
}

// reads team file and creates team object from it - params: DSString filePath, int teamNumber
void TeamDeathMatch::readTeamFile(char* filePath, Team* team){

    std::ifstream teamFile(filePath);
    DSString line;

    teamFile >> line;
    int numPlayers;
    teamFile >> numPlayers;
    // clear white space
    teamFile.get();


    team->setName(line);
    team->setMaxPlayers(numPlayers);


    int playerId;
    for(int i = 0; i < numPlayers; i++){
        teamFile >> playerId;
        // clear white space
        teamFile.get();
        teamFile >> line;
        Player here(playerId, line);
        here;

        team->addPlayer(playerId, line);
    }
    teamFile.close();
}

// reads match file and adds stats to teams - params: DSString filePath
void TeamDeathMatch::readMatchFile(char* filePath){

}

// prints to output file with minimum verbosity
void TeamDeathMatch::printLowVerbosity(char* outputPath){

}

// prints to output file with medium verbosity
void TeamDeathMatch::printMediumVerbosity(char* outputPath){

}

// prints to output file with highest verbosity
void TeamDeathMatch::printHighVerbosity(char* outputPath){

}

//default destructor
TeamDeathMatch::~TeamDeathMatch(){
}
