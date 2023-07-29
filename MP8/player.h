//This class is created for each player. Each player has a name, number, and points score.
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class PlayerClass
{
private:
    string fname;
    string lname;
    int number;
    int pointsScored;

public:
    //creater function
    PlayerClass(string u_fname = "none", string u_lname = "none", int u_number = 0, int u_pointsScored = 0);
	
    //resetting player variable
    void setPlayer(string fname, string lname, int number, int pointsScored);
    
    //getter functions
    string getfname();
    string getlname();
    int getnumber();
    int getpointsScored();
    
};

#endif
