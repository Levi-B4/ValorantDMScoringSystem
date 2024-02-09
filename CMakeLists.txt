cmake_minimum_required(VERSION 3.5)

project(ValorantDMScoringSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ValorantDMScoringSystem main.cpp
    teamDeathMatch.h teamDeathMatch.cpp
    team.h team.cpp
    DSString/dsstring.cpp DSString/dsstring.h
    player.h player.cpp)

include(GNUInstallDirs)
install(TARGETS ValorantDMScoringSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
