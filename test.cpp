#include "catch.hpp"
#include <type_traits>

#include <fstream>
#include <iostream>

#include "DSString/dsstring.h"

TEST_CASE("ValorantDMScoringSystem", "[ValorantDMScoringSystem]"){

/*
 *  String
 */

    DSString* stringsArray[3];

    stringsArray[0] = new DSString("test1");
    stringsArray[1] = new DSString("yo");
    stringsArray[2] = new DSString();

    DSString testStr = "testStr";

    DSString nonPtrArray[1];
    nonPtrArray[0] = "nonPtr";

    SECTION("String concatination operators"){
        REQUIRE((*stringsArray[0] += "yo") == "test1yo");
        *stringsArray[0] = "test1";

        REQUIRE((*stringsArray[1] += testStr) == "yotestStr");
        *stringsArray[1] = "yo";

        REQUIRE((*stringsArray[1] += 'x') == "yox");
        *stringsArray[1] = "yo";
    }

    SECTION("String functions"){

        // size()
        REQUIRE(stringsArray[0]->size() == 5);
        REQUIRE(stringsArray[2]->size() == 0);

        // findChar(const char searchChar)
        REQUIRE(stringsArray[0]->findChar('s') == 2);
        REQUIRE(stringsArray[0]->findChar('y') == -1);

        // findChar(const char searchChar, const int numInstance)
        REQUIRE(stringsArray[0]->findChar('t', 1) == 0);
        REQUIRE(stringsArray[0]->findChar('t', 2) == 3);
        REQUIRE(stringsArray[0]->findChar('t', 3) == -1);

        // deleteIndex(const int index)
        stringsArray[0]->deleteIndex(1);
        REQUIRE(*stringsArray[0] == "tst1");
        stringsArray[0]->deleteIndex(3);
        REQUIRE(*stringsArray[0] == "tst");
        *stringsArray[0] = "test1";
    }

    SECTION("String Comparison Operators"){
        /*
         *  TODO: this doesnt error out even tho it isnt in bounds
         *  makes me think theres a leak
         *  will error out if in at end of previous section
         *      REQUIRE(!(*stringsArray[3] == "notEmpty"));
         */

        REQUIRE(!(*stringsArray[2] == "notEmpty"));

        REQUIRE(testStr == "testStr");
        REQUIRE(nonPtrArray[0] == "nonPtr");


        REQUIRE(*stringsArray[0] == "test1");
        REQUIRE(!(*stringsArray[0] == *stringsArray[1]));

        REQUIRE(!(*stringsArray[0] < "test1"));
        REQUIRE(*stringsArray[1] < *stringsArray[0]);

        REQUIRE(!(*stringsArray[0] > "test1"));
        REQUIRE(*stringsArray[0] > *stringsArray[1]);

        REQUIRE(*stringsArray[0] <= "test1");
        REQUIRE(*stringsArray[1] <= *stringsArray[0]);

        REQUIRE(*stringsArray[0] >= "test1");
        REQUIRE(*stringsArray[0] >= *stringsArray[1]);

        REQUIRE(*stringsArray[2] == "");
    }

    SECTION("String Indexing"){
        REQUIRE((*stringsArray[0])[0] == 't');
        REQUIRE((*stringsArray[1])[1] == 'o');
        REQUIRE((*stringsArray[2])[0] == '\0');
    }

    SECTION("Substrings"){
        REQUIRE(stringsArray[0]->substring(1, 3) == "est");
        REQUIRE(stringsArray[1]->substring(0, 1) == "y");

        REQUIRE(stringsArray[0]->substring(3,0) == "");
        REQUIRE(stringsArray[0]->substring(stringsArray[0]->size() - 1, 3) == "");
        REQUIRE(stringsArray[0]->substring(0, 0) == "");


        REQUIRE(stringsArray[0]->substring(2, -5) == "tes");
        REQUIRE(stringsArray[0]->substring(2, -2) == "es");
        REQUIRE(stringsArray[0]->substring(0, -3) == "t");
        REQUIRE(stringsArray[0]->substring(stringsArray[0]->size() - 1, -2) == "t1");

        REQUIRE(stringsArray[0]->substring(3, 999) == "t1");

        REQUIRE(stringsArray[0]->substring(1) == "est1");
    }

    SECTION("c_string"){
        REQUIRE(*stringsArray[0] == stringsArray[0]->c_str());
        REQUIRE(*stringsArray[0] == stringsArray[0]->c_str());
    }

    SECTION("File input/output"){
        // output
        DSString filePath = "./testFile.txt";

        std::ofstream testOutFile;
        testOutFile.open(filePath.c_str());

        testOutFile << DSString("hello\n");
        testOutFile << DSString("Test Test") << std::endl;

        testOutFile.close();

        // input
        DSString fileTestString;

        std::ifstream testInFile;
        testInFile.open(filePath.c_str());

        testInFile >> fileTestString;
        REQUIRE(fileTestString == "hello");

        testInFile >> fileTestString;
        REQUIRE(fileTestString == "Test Test");

        testInFile.close();

        std::ofstream clearFile;
        clearFile.open(filePath.c_str());
        clearFile.close();
    }
}
