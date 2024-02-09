#ifndef TEAMDEATHMATCH_H
#define TEAMDEATHMATCH_H

#include "DSString/dsstring.h"
#include "team.h"

#include <fstream>
#include <iostream>

class TeamDeathMatch
{
public:
    // default constructor
    TeamDeathMatch();
    // constructor - params: int numFiles, char** fileList, char* verbosity
    TeamDeathMatch(char** fileList, char* verbosity);


    // reads team file and creates team object in teams - params: DSString filePath, int teamNumber
    void readTeamFile(char* filePath, Team* team);
    // reads match file and adds stats to teams - params: DSString filePath
    void readMatchFile(char* filePath);

    // prints to output file with minimum verbosity
    void printLowVerbosity(std::ofstream& outputFile);
    // prints to output file with medium verbosity
    void printMediumVerbosity(std::ofstream& outputFile);
    // prints to output file with highest verbosity
    void printHighVerbosity(std::ofstream& outputFile);


    //default destructor
    ~TeamDeathMatch();

private:
    DSString fileList[4];
    Team teamA;
    Team teamB;
    DSString verbosity = "";
};

#endif // TEAMDEATHMATCH_H
