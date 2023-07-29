//Soccer Game
//Ava Gullitti
//7-28-2023
/* This C++ program is designed to solve WCC machine problem 8. This problem requires the program to read an input file containing soccer data. From this data 4 team class ojects are created containg 11 player class objects. After the player information has been inputed to the team class, the calss will display the team's information allong with the player on the team that scored the most points. The program will also display the 2 teams that scored the most points.*/

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "player.h"
#include "team.h"
using namespace std;

//creating global variables
string line;
string word;

// Reading from the text file
ifstream MyReadFile("teams.txt");
//opening my output file
ofstream fout("output.txt");

//Running the main function
int main() {
	//ARGENTINE	
	getline(MyReadFile, line);// Getting first line of words from the text file
	stringstream ss(line);//making a string stream from the line
	ss >> word; //extracting team name from file
	TeamClass argentine(word);//creating a team object with that team name
	
	//then for the next eleven lines
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		getline(MyReadFile, line);// Getting specific line from the text file	
		stringstream ss(line);//making a string stream from the line
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		argentine.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);//extracing data from string stream
	}
	argentine.showTeam(1, fout);//displaying team information
	
	
	//BRAZIL
	getline(MyReadFile, line);//reading from the line of the text file
	stringstream ss2(line);//making a string stream from the line
	ss2 >> word;//extracing word from stream
	TeamClass brazil(word);//creating a team object with the name BRAZIL
	
	//then for next eleven lines
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		getline(MyReadFile, line);// Getting a line of words from the text file	
		stringstream ss(line);//making a string stream from the line
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		brazil.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);//inputting player information into the team object
	}
	brazil.showTeam(2, fout);//displaying team information
	
	//FRANCE
	getline(MyReadFile, line);// reading a line from the file
	stringstream ss3(line);//making a string stream from the line
	ss3 >> word;//extracting name from stream
	TeamClass france(word);// creating a team object with the name that was extracted
	
	//then for next 11 lines
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		getline(MyReadFile, line);// Getting a line of words from the text file	
		stringstream ss(line);//making a string stream from the line
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		france.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);//input player information to team class
	}
	france.showTeam(3, fout);// displaying team information
	
	//POTUGAL
	getline(MyReadFile, line);//reading a line from the file
	stringstream ss4(line);//making a string stream from the line
	ss4 >> word;//extracting a word from the file
	TeamClass potugal(word);//making a team object with that name
	
	//then for next 11 lines
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		getline(MyReadFile, line);// Getting a line of words from the text file
		stringstream ss(line);//making a string stream from the line
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		potugal.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);//inputting player information in to the team object
	}
	potugal.showTeam(4, fout);//displaying the team information
	
	//displaying the player the has the post points for each team
	argentine.showMostPointsPlayer(1, fout);
	brazil.showMostPointsPlayer(2, fout);
	france.showMostPointsPlayer(3, fout);
	potugal.showMostPointsPlayer(4, fout);
	
	//creating a list of all the teams
	TeamClass teamList[4] = {argentine, brazil, france, potugal};
	
	//figuring out the first and secound place teams
	int mostPoints = 0;
	int mostPointsNumber = 0;
	int secoundMostPoints = 0;
	int secoundMostPointsNumber = 0;
	//for each team
	for (int counter = 0; counter < 4; counter++) {
		if (teamList[counter].gettotalPoints() > mostPoints) {//if the team has the most points
			//save the old team with the most points
			secoundMostPoints = mostPoints;
			secoundMostPointsNumber = mostPointsNumber;
			//replace old team with new team
			mostPoints = teamList[counter].gettotalPoints();
			mostPointsNumber = counter + 1;
		}
	}
	//displaying the top two teams to the text files
	fout << endl << "The top two teams with the most points are:" << endl;
	fout << "Team #" << mostPointsNumber << " with points " << mostPoints << " and Team #" << secoundMostPointsNumber << " with points " << secoundMostPoints << endl;
	
	// Close the file input and output files
	MyReadFile.close();
	fout.close();
	return 0;
}


