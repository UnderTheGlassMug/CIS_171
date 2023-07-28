#include "player.h"
#include "team.h"
#include <string>
#include <iostream>
#include <iomanip> 
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
	 teamPlayers[playerNumber].setPlayer(fname, lname, number, pointsScored);
	 totalPoints += pointsScored;
	 if (pointsScored > mostPoints) {
	 	mostPoints = pointsScored;
	 	mostPointsPlayer = fname + " " + lname;
	 }
}

void TeamClass::showTeam(int teamNum)
{
	cout << "TEAM #" << teamNum << endl;
	cout << "Team's name: " << teamName << endl;
	cout << "Team's points: " << totalPoints << endl << endl;
	
	cout << "Players of TEAM #" << teamNum << " : ";
	for (int i = 0; i < 10; i++) {
		cout << teamPlayers[i].getfname() << " " << teamPlayers[i].getlname() << ", ";
		
	}
	cout << teamPlayers[10].getfname() << " " << teamPlayers[10].getlname() << endl;
	cout << left << setw(24) << "Player Name" << setw(24) << "Player Number" << setw(24) << "Player Points" << endl;
	cout << left << setw(24) << "***********" << setw(24) << "***********" << setw(24) << "***********" << endl;
	for (int num = 1; num < 10 ; num++) {
		string fullname = ". " + teamPlayers[num - 1].getfname() + " " + teamPlayers[num - 1].getlname();
		cout << num << setw(23) << fullname << setw(24) << teamPlayers[num - 1].getnumber() << setw(24) << teamPlayers[num - 1].getpointsScored() << endl;
	}
	
	for (int num = 10; num < 12 ; num++) {
		string fullname = ". " + teamPlayers[num - 1].getfname() + " " + teamPlayers[num - 1].getlname();
		cout << num << setw(22) << fullname << setw(24) << teamPlayers[num - 1].getnumber() << setw(24) << teamPlayers[num - 1].getpointsScored() << endl;
	}
	cout << endl;
}

void TeamClass::showMostPointsPlayer(int teamNum)
{
	cout << "The player with the most points on Team #" << teamNum << " is " << mostPointsPlayer << endl;
}

int TeamClass::gettotalPoints() { return totalPoints; }
