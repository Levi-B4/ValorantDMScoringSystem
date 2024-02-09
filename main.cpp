#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_NO_POSIX_SIGNALS

#include "catch.hpp"

#include <iostream>

#include "teamDeathMatch.h"
#include "DSString/dsstring.h"

// Test flag
#define TEST false

// runs test.cpp using catch2 lib
int runCatchTests(int argc, char* argv[]){
    return Catch::Session().run(argc, argv);
}


int main(int argc, char* argv[])
{
    if(TEST){
        return runCatchTests(argc, argv);
    }

    argv = &argv[1];
    argc -= 1;
    TeamDeathMatch match(argv, argv[argc - 1]);

    return 0;
}
