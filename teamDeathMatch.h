#ifndef TEAMDEATHMATCH_H
#define TEAMDEATHMATCH_H

#include "DSString/dsstring.h"
#include "team.h"

class TeamDeathMatch
{
public:
    // constructor - params: int numFiles, char** fileList, char* verbosity
    TeamDeathMatch(int numFiles, char** fileList, char* verbosity);

    // prints to output file with minimum verbosity
    void printLowVerbosity();
    // prints to output file with medium verbosity
    void printMediumVerbosity();
    // prints to output file with highest verbosity
    void printHighVerbosity();

    //default destructor
    ~TeamDeathMatch();

private:
    DSString fileList[4];
    Team teams[2];
    DSString verbosity;

    // reads team file and creates team object in teams
    void readTeamFile(DSString filePath);

    // reads match file and adds stats to teams
    void readMatchFile(DSString filePath);

};

#endif // TEAMDEATHMATCH_H
