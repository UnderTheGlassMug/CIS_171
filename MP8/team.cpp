#include "player.h"
#include "team.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;

// Team constructor
TeamClass::TeamClass(string u_teamName)
{
	setTeam(u_teamName);
}

// Team member function
void TeamClass::setTeam(string u_teamName)
{
	teamName = u_teamName;
}

void TeamClass::setPlayer(string fname, string lname, int number, int pointsScored, int playerNumber)
{
	 //adding to the player object
	 teamPlayers[playerNumber].setPlayer(fname, lname, number, pointsScored);
	 //adding all the points the team scored
	 totalPoints += pointsScored;
	 //finding and saving the player that scored the most points
	 if (pointsScored > mostPoints) {
	 	mostPoints = pointsScored;
	 	mostPointsPlayer = fname + " " + lname;
	 }
}

//this function outputs the teams information to the output file
void TeamClass::showTeam(int teamNum, ofstream& fout)
{
	fout << "TEAM #" << teamNum << endl;
	fout << "Team's name: " << teamName << endl;
	fout << "Team's points: " << totalPoints << endl << endl;
	
	fout << "Players of TEAM #" << teamNum << " : ";
	for (int i = 0; i < 10; i++) {
		fout << teamPlayers[i].getfname() << " " << teamPlayers[i].getlname() << ", ";
		
	}
	fout << teamPlayers[10].getfname() << " " << teamPlayers[10].getlname() << endl;
	fout << left << setw(24) << "Player Name" << setw(24) << "Player Number" << setw(24) << "Player Points" << endl;
	fout << left << setw(24) << "***********" << setw(24) << "***********" << setw(24) << "***********" << endl;
	for (int num = 1; num < 10 ; num++) {
		string fullname = ". " + teamPlayers[num - 1].getfname() + " " + teamPlayers[num - 1].getlname();
		fout << num << setw(23) << fullname << setw(24) << teamPlayers[num - 1].getnumber() << setw(24) << teamPlayers[num - 1].getpointsScored() << endl;
	}
	
	for (int num = 10; num < 12 ; num++) {
		string fullname = ". " + teamPlayers[num - 1].getfname() + " " + teamPlayers[num - 1].getlname();
		fout << num << setw(22) << fullname << setw(24) << teamPlayers[num - 1].getnumber() << setw(24) << teamPlayers[num - 1].getpointsScored() << endl;
	}
	fout << endl;
}

//this function displays the player with the most points to the output file
void TeamClass::showMostPointsPlayer(int teamNum, ofstream& fout)
{
	fout << "The player with the most points on Team #" << teamNum << " is " << mostPointsPlayer << endl;
}

//getter functions
int TeamClass::gettotalPoints() { return totalPoints; }
string TeamClass::getteamName() { return teamName; }
