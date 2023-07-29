#include "player.h"
#include <string>
#include <iostream>
using namespace std;

// player constructor
PlayerClass::PlayerClass(string u_fname, string u_lname, int u_number, int u_pointsScored)
{
    setPlayer(u_fname, u_lname, u_number, u_pointsScored);
}

// player member function
void PlayerClass::setPlayer(string u_fname, string u_lname, int u_number, int u_pointsScored)
{
    fname = u_fname;
    lname = u_lname;
    number = u_number;
    pointsScored = u_pointsScored;
}

//getter functions
string PlayerClass::getfname() { return fname; }
string PlayerClass::getlname() { return lname; }
int PlayerClass::getnumber() { return number; }
int PlayerClass::getpointsScored() { return pointsScored; }

