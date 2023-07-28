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
    PlayerClass(string u_fname = "none", string u_lname = "none", int u_number = 0, int u_pointsScored = 0);

    void setPlayer(string fname, string lname, int number, int pointsScored);
    
    void showStats();
    string getfname();
    string getlname();
    int getnumber();
    int getpointsScored();
    
};

#endif
