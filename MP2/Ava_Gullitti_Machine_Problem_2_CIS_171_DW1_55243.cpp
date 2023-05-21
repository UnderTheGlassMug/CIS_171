//Ore Shipment Report Creater
//Ava Gullitti
//5-21-2023
/* The program is designed to solve Machine problem 2 for WCC’s Intro to C class. This problem requires the program to produce very specifically formatted reports about coal shipments. The program receives an input file named inputmp2.txt. From this file the program is able to extract the name of the railroad company, destination of the shipment, number of ore cars, and the current price of coal per short ton. The program assumes that there is 74.5 tons of ore per car and that the surcharge is .31%. Using the inputted variables the program then calculates the amount of coal, the total value of the shipment, and the surcharge using basic algebra. Finally, the program will output this information to a text file named outputmp3.txt. Utilizing setfill characters the program meets the strict formatting requirements of these reports. */

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//defining importan variables
double tonPerCar = 74.5;
double surcharge = .0031;
string railroadName = "";
string destination = "";
int amountOfCars;
double pricePerShortTon;

//Creating an object to read the input file
ifstream input;
//creating an object to output the report on
ofstream outputmp2;

int main() {
    // Reading input file
    input.open("inputmp2.txt");
    //Getting the name of the railroad
    getline(input, railroadName);
    //Getting the destination of the shipment
    getline(input, destination);
    //Getting the number of ore cars
    input >> amountOfCars;
    //Getting the current price
    input >> pricePerShortTon;
    
    
    //Calculating the weight of the coal, vaule of the shipment, and the total surcharge
    double coalWeight = amountOfCars * tonPerCar;
    double valueOfShipment = coalWeight * pricePerShortTon;
    double totalSurcharge = valueOfShipment * surcharge;
    
    //Creating a file to output the report
    outputmp2.open("outputmp2.txt");
    
    //Formatting the report properly
    outputmp2.setf(ios::left);
    outputmp2 << "KERBAA & M COAL TRAIN REPORT – Ava Gullitti" << endl << endl;
    outputmp2 << setw(18) << "Railroad Name:" << railroadName << endl;
    outputmp2 << setw(18) << "Destination:" << destination << endl << endl;
    outputmp2 << setw(31) << setfill('.') << "Number of ore cars:" << "   " << right << setw(9) << setfill(' ') << amountOfCars << endl;
    outputmp2 << fixed;
    outputmp2 << left << setw(31) << setfill('.') << "Total weight of coal" << "   " << right << setw(9) << setfill(' ') << setprecision(2) << coalWeight << " short tons" << endl;
    outputmp2 << left << setw(31) << setfill('.') << "Current Cost per short ton" << " $ " << right << setw(9) << setfill(' ') << setprecision(2) << pricePerShortTon << endl;
    outputmp2 << left << setw(31) << setfill('.') << "Total Value of Shipment" << " $ " << right << setw(9) << setfill(' ') << setprecision(2) << valueOfShipment << endl;
    outputmp2 << left << setw(31) << setfill('.') << "Current Surcharge" << "  " << right << setw(10) << setfill(' ') << setprecision(2) << surcharge*100 << "%" << endl << endl;
    outputmp2 << left << setw(31) << setfill('.') << "Total Surcharge(Est)" << " $ " << right << setw(9) << setfill(' ') << setprecision(2) << totalSurcharge << endl;
    
    //Closing the output and input files
    outputmp2.close();
    input.close();
    return 0;
}
