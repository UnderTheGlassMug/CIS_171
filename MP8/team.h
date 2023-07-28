#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <string>
#include <iostream>

using namespace std;

class TeamClass
{
private:
    int totalPoints = 0;
    int mostPoints = 0;
    string mostPointsPlayer = "unknown";
    string teamName;
    PlayerClass player1;
    PlayerClass player2;
    PlayerClass player3;
    PlayerClass player4;
    PlayerClass player5;
    PlayerClass player6;
    PlayerClass player7;
    PlayerClass player8;
    PlayerClass player9;
    PlayerClass player10;
    PlayerClass player11;
    PlayerClass teamPlayers[11] = {player1, player2, player3, player4, player5, player6, player7, player8, player9, player10, player11};

public:
    TeamClass(string u_teamName);
    
    void setTeam(string u_teamName);
	
    void setPlayer(string fname, string lname, int number, int pointsScored, int playerNumber);
    
    void showTeam(int TeamNum);
    
    void showMostPointsPlayer(int teamNum);
    
    int gettotalPoints();
    
};

#endif
