cmake_minimum_required(VERSION 3.5)
project(ValorantDMScoringSystem LANGUAGES CXX)
set (EXE_NAME ValorantDMScoringSystem)

# input files
set (input01 "testInputs/100thieves.txt")
set (input02 "testInputs/faze.txt")
set (input03 "testInputs/match1.txt")

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${EXE_NAME} ./main.cpp
    teamDeathMatch.h teamDeathMatch.cpp
    team.h team.cpp
    DSString/dsstring.cpp DSString/dsstring.h
    player.h player.cpp
    catch.hpp
    test.cpp)

include(GNUInstallDirs)
install(TARGETS ValorantDMScoringSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
