//Soccer Game
//Ava Gullitti
//7-28-2023
/* This C++ program is designed to solve WCC machine problem 7. Machine problem 7 requires the program to correctly identify spelling mistakes. It will do this by first reading an input file of the name "mp7spelling.txt". From this file it extracts the correct spelling of the word and the users attempts at spelling this word correctly. Then the program will  create 5 different functions. The first function will check if the spelling is correct. The second will check if a character has been inserted into the word. The third one will see if the user accidentally switched two characters around. The fourth one will check if a character was deleted and the last one will check if a letter has been inserted. Once all of the words have been classified a switch statement will decide what to output to the text file. It also keeps track of how many times each error has occurred. Once the program reaches the end of the text file it will print the final counts and close the input and output files. */

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "player.h"
#include "team.h"
using namespace std;

//Creating variables to count the different types of typo
int cor, sub, tran, del, ins, err;

// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile("teams.txt");
//opening my output file
ofstream fout("output.txt");

//Running the main function
int main() {
	
	//reading the last lines of the text file to get the words to search for
	int count = 1;
	
	string line;
	string word;
		
	// Getting a line of words from the text file
	getline(MyReadFile, line);
		
	//making a string stream from the line
	stringstream ss(line);
	ss >> word;
	TeamClass argentine(word);
		
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		// Getting a line of words from the text file
		getline(MyReadFile, line);	
		//making a string stream from the line
		stringstream ss(line);
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		argentine.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);
	}
	argentine.showTeam(1);
	
	
	//BRAZIL
	getline(MyReadFile, line);
		
	//making a string stream from the line
	stringstream ss2(line);
	ss2 >> word;
	
	TeamClass brazil(word);
		
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		// Getting a line of words from the text file
		getline(MyReadFile, line);	
		//making a string stream from the line
		stringstream ss(line);
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		brazil.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);
	}
	brazil.showTeam(2);
	
	//FRANCE
	getline(MyReadFile, line);
		
	//making a string stream from the line
	stringstream ss3(line);
	ss3 >> word;
	
	TeamClass france(word);
		
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		// Getting a line of words from the text file
		getline(MyReadFile, line);	
		//making a string stream from the line
		stringstream ss(line);
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		france.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);
	}
	france.showTeam(3);
	
	//POTUGAL
	getline(MyReadFile, line);
		
	//making a string stream from the line
	stringstream ss4(line);
	ss4 >> word;
	
	TeamClass potugal(word);
		
	for (int playerIndex = 0; playerIndex < 11; playerIndex++) {
		//making input varaiables
		int playerNumber;
		string firstName;
		string lastName;
		int pointsScored;
		
		// Getting a line of words from the text file
		getline(MyReadFile, line);	
		//making a string stream from the line
		stringstream ss(line);
		ss >> playerNumber >> firstName >> lastName >> pointsScored;
		potugal.setPlayer(firstName, lastName, playerNumber, pointsScored, playerIndex);
	}
	potugal.showTeam(4);
	
	argentine.showMostPointsPlayer(1);
	brazil.showMostPointsPlayer(2);
	france.showMostPointsPlayer(3);
	potugal.showMostPointsPlayer(4);
	
	TeamClass teamlist[4] = {argentine, brazil, france, potugal};
	// Close the file input and output files
	
	MyReadFile.close();
	fout.close();
	return 0;
}


