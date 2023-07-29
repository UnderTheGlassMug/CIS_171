#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class TeamClass
{
private:
    int totalPoints = 0;//totalteam points
    int mostPoints = 0;//the most points scored by player on team
    string mostPointsPlayer = "unknown";//player who scored most points
    string teamName;
    //player on team
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
    //list of players
    PlayerClass teamPlayers[11] = {player1, player2, player3, player4, player5, player6, player7, player8, player9, player10, player11};

public:
    //constructor
    TeamClass(string u_teamName);
    //setting the team
    void setTeam(string u_teamName);
    //setting a player on the team
    void setPlayer(string fname, string lname, int number, int pointsScored, int playerNumber);
    //displaying the team's information
    void showTeam(int TeamNum, ofstream& fout);
    //finding the player with the most points
    void showMostPointsPlayer(int teamNum, ofstream& fout);
    //gettter functions
    int gettotalPoints();
    string getteamName();
    
};

#endif
