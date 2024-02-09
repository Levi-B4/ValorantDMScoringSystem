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


    std::ofstream outputFile(fileList[3]);

    if(DSString(verbosity) == "vlow"){
        printLowVerbosity(outputFile);
    }

    if(DSString(verbosity) == "vmed"){
        printMediumVerbosity(outputFile);
    }

    if(DSString(verbosity) == "vhigh"){
        printHighVerbosity(outputFile);
    }

    outputFile.close();

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
    std::ifstream matchFile(filePath);
    int shooter = 0;
    int target = 0;
    int value = 0;

    int numKills;

    matchFile >> numKills;

    for(int i = 0; i < numKills; i++){
        matchFile >> shooter;
        matchFile >> target;
        // skip time entry
        matchFile >> value;
        matchFile >> value;
        teamA.hasPlayer(shooter) ?
            teamA.processKill(shooter, target, value):
            teamB.processKill(shooter, target, value);
    }
}

// prints to output file with minimum verbosity
void TeamDeathMatch::printLowVerbosity(std::ofstream& outputFile){

    int tAPoints = teamA.getTotalPoints();
    int tBPoints = teamB.getTotalPoints();

    outputFile << teamA.getName() << ": " << tAPoints << " points" << '\n';
    outputFile << teamB.getName() << ": " << tBPoints << " points" << '\n';

    outputFile << "Overall Winners: ";

    if(tAPoints == tBPoints){
        outputFile << "tie";
    } else{
        tAPoints > tBPoints ?
            outputFile << teamA.getName() : outputFile << teamB.getName();
    }

    outputFile << std::endl;
}

// prints to output file with medium verbosity
void TeamDeathMatch::printMediumVerbosity(std::ofstream& outputFile){
    outputFile << teamA.getName() << std::endl;

    Player player;
    for(int i = 0; i < teamA.getMaxPlayers(); i++){
        player = teamA.getPlayers()[i];
        outputFile << '\t' << player.getName() << " had a total of " << player.getTotalKills() << " kills\n";
    }

    outputFile << teamB.getName() << std::endl;

    for(int i = 0; i < teamB.getMaxPlayers(); i++){
        player = teamB.getPlayers()[i];
        outputFile << '\t' << player.getName() << " had a total of " << player.getTotalKills() << " kills\n";
    }

    Player topPlayer = teamA.getTopPlayer();
    outputFile << "Best score from " << teamA.getName() << " : " << topPlayer.getName() << " (" << topPlayer.getTotalPoints() << " points)\n";

    topPlayer = teamB.getTopPlayer();
    outputFile << "Best score from " << teamB.getName() << " : " << topPlayer.getName() << " (" << topPlayer.getTotalPoints() << " points)" << std::endl;

    printLowVerbosity(outputFile);
}

// prints to output file with highest verbosity
void TeamDeathMatch::printHighVerbosity(std::ofstream& outputFile){
}

//default destructor
TeamDeathMatch::~TeamDeathMatch(){
}
