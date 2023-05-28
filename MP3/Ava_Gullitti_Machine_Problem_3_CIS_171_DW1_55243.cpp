//Monthly Cell Phone Bill Calculator
//Ava Gullitti
//5-21-2023
/* The program is designed to solve Machine problem 3 for WCC’s Intro to C class. The challenege was to read a cell phone log, and determine how many mintues the caller was charged and what the total cost is. This programs solves this problem by opening the phone log using an ifstream object. After the if stream object has been opened an ofstream object will be initialized and create a text file outputFileMP3.txt which will save the cellphone charges on a report. After the output file has been created a while loop will run until the last line of the input file has been reached. Each loop of the while loop th program will do the following. Extract data from one line of the input file. Use if and else statements to determine the cost for each phone call accoring the the phone plan's specification. Then out put the time, duration, type of call, minutes used so far, and the cost on the output file. Some important phone plan specificaions included, daytime calls are charged are 200 minutes, area calls are charged $0.29 per minute, long distance calls are charged $0.69 per minute, and daytime calls are between 6am-5:59pm. After the while loop has finshed the input and output streams will be closed*/

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//defining importan variables
int timeOfDay, callTime, totalCallTime, chargedMinutes;
double charge, cost;
string areaOrLongDist;
//setting the total bill to zero
double totalBill = 0;

//Creating an object to read the input file
ifstream inputMP3;
//creating an object to output the report on
ofstream outputMP3;

int main() {
    // creating and output file
    outputMP3.open("outputFileMP3.txt");
    //Starting the first few lines of the report
    outputMP3 << "Cellphone charges - MP3 by Ava Gullitti" << endl << endl;
    outputMP3 << "Time  Duration       Type of call   Minutes used so far    Cost" << endl << endl;
    // Opening the input file
    inputMP3.open("inputMP3.txt");
    
 	//reading a line from the file each loop and stopping when it reaches the end
	while (!inputMP3.eof()){
	    //extracting data from the file
	    inputMP3 >> timeOfDay >> callTime >> areaOrLongDist;
	    
	    if (timeOfDay > 600 && timeOfDay < 1799) { //if day time call this will determine the charge
	    	//finding the total call time
	    	totalCallTime = totalCallTime + callTime;
	    	chargedMinutes = totalCallTime - 200;
	    	//determining wether there is a charge on the call
	    	if (chargedMinutes > 0) {// if there is the cost will change if it is in area
	    		if (areaOrLongDist == "A") {//charge is lower in area
	    			charge = .29;
	    		} else {//charge is higher for long distance calls
	    			charge = 0.69;
	    		}
	    		//adding the calculated cost to the total cost
	    		cost = charge*callTime;
	    		totalBill = totalBill + cost;
	    	} else {//if there isn't the cost is zero
	    		cost = 0;
	    	}
	    	//adding a line to the call log
	    	outputMP3 << setfill('0') << setw(4) << timeOfDay << setfill(' ') << setw(8) << callTime << setw(15) << areaOrLongDist << setw(17) << totalCallTime << setw(15) << "$" << setprecision(2) << fixed << cost << endl;
	    } else { //if nightime call there is no charge
	    		//adding line to the call  log
	    		outputMP3 << setfill('0') << setw(4) << timeOfDay << setfill(' ') << setw(8) << callTime << setw(15) << areaOrLongDist << setw(30) << "Night Calls Are Free" << endl;
	    }
    	}
	
	//adding the total bill for the month
	outputMP3 << endl << "Total Monthly Bill : $" <<setprecision(2) << fixed << totalBill << endl; 
	
    //Closing the output and input files
    outputMP3.close();
    inputMP3.close();
    return 0;
}
