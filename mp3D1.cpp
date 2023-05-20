// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double tonPerCar = 74.5;
double amountOfCars = 87;
double surcharge = .0031;
double pricePerShortTon = 65.47;
string railroadName = "Ironton and Tylerville";
string destination = "Flint Edison #4";

int main() {
    // Write C++ code here
    double coalWeight = amountOfCars * tonPerCar;
    double valueOfShipment = coalWeight * pricePerShortTon;
    double totalSurcharge = valueOfShipment * surcharge;
    cout.setf(ios::left);
    cout << "KERBAA & M COAL TRAIN REPORT – Ava Gullitti" << endl << endl;
    cout << setw(18) << "Railroad Name:" << railroadName << endl;
    cout << setw(18) << "Destination:" << destination << endl << endl;
    cout << setw(31) << setfill('.') << "Number of ore cars:" << "   " << right << setw(9) << setfill(' ') << amountOfCars << endl;
    cout << fixed;
    cout << left << setw(31) << setfill('.') << "Total weight of coal" << "   " << right << setw(9) << setfill(' ') << setprecision(2) << coalWeight << endl;
    cout << left << setw(31) << setfill('.') << "Current Cost per short ton" << " $ " << right << setw(9) << setfill(' ') << setprecision(2) << pricePerShortTon << endl;
    cout << left << setw(31) << setfill('.') << "Total Value of Shipment" << " $ " << right << setw(9) << setfill(' ') << setprecision(2) << valueOfShipment << endl;
    cout << left << setw(31) << setfill('.') << "Current Surcharge" << "  " << right << setw(10) << setfill(' ') << setprecision(2) << surcharge*100 << "%" << endl << endl;
    cout << left << setw(31) << setfill('.') << "Total Surcharge(Est)" << " $ " << right << setw(9) << setfill(' ') << setprecision(2) << totalSurcharge << endl;
    return 0;
}