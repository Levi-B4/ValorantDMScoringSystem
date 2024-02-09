#include <iostream>

#include "teamDeathMatch.h"
#include "DSString/dsstring.h"

using namespace std;

int main(int argc, char* argv[])
{
    argv = &argv[1];
    argc -= 1;
    TeamDeathMatch match(argv, argv[argc - 1]);

    return 0;
}
