//Finding Abundant Number
//6/7/2023
//Ava Gullitti
/* This C++ script was designed to solve WCC Machine Problem 4.  The problem requires the script to find all the abundant numbers which are smaller to or equal to the smallest natural number that has exactly six proper divisors. This number is 64 and the script will output four lines for each number between 0 and 65. The first line states wether or not the number is abundant. Secound line is a list of the numbers proper divisors. The third is the sum of the proper divisors. Finally the last line that is outputted is the number of proper divisors. The program does this by starting a for loop for each number. For each loop of this for loop two other for loops will run outputting a vector of the numbers divisors and the sum of all of these divisors. Finally, determine if the number is abundant outputting the result to the MP4output.txt file. It will also print out the natural number that has exactly six proper divisors*/

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

//defining importan variables
int sum;
string isOrIsNot;
vector<int> divisors;
// Create and open a text file
ofstream output("MP4output .txt");

int main() {
	for (int num = 1; num < 65; num++) {//looping till the smallest natural number that has exactly six proper divisors
		//clearing the divisors vector before calculating
		divisors.clear();
		
		//creating a list of divisors
		for (int divisor = 1; divisor < num; divisor++) {//dividing till it reaches the number
			if (num % divisor == 0){//if the number is a factor then adding it to a vector
				divisors.push_back(divisor);
			}
		}
		
		//finding the sum of these divisors
		int sum = 0;//clearing the sum varaible
		for (int i = 0; i < divisors.size(); i++) {
			sum = sum + divisors.at(i);//adding all of the sums together
		}
		
		//determining wether the number is abundant
		if (sum > num){ // if it is
			isOrIsNot = " IS ";
		} else { // if it is not
			isOrIsNot = " IS NOT ";
		}
		
		//outputting important information to the output file
		if (divisors.size() == 0 ) {//if the number is one
			output << "THE NUMBER " << num << isOrIsNot << "AN ABUNDANT NUMBER" << endl;
			output << "1 has no proper divisors" << endl; 
			output << "There is no sum if there are no proper divisors" << endl;
			output << "There are no proper divisors for the number " << num << endl << endl;
		
		} else if (divisors.size() == 1 ) { // if the number has one proper divisor
			output << "THE NUMBER " << num << isOrIsNot << "AN ABUNDANT NUMBER" << endl;
			output << "The proper divisor of " << num << " is 1" << endl; 
			output << "The sum of the proper divisors is " << sum << " which is less than the number " << num << endl;
			output << "There is " << divisors.size() << " proper divisor for the number " << num << endl << endl;
		
		} else if (divisors.size() == 2 ) {//if the number has two proper divisor
			output << "THE NUMBER " << num << isOrIsNot << "AN ABUNDANT NUMBER" << endl;
			output << "The proper divisors of " << num << " are ";
			for (int i = 0; i < divisors.size(); i++) {
				if (not(i+1 == divisors.size())){
					output << divisors.at(i) << " ";
				} else {
					output << "and " << divisors.at(i) << endl;
				}
			}
			output << "The sum of the proper divisors is ";
			for (int i = 0; i < divisors.size(); i++) {
				if (i == 0){
					output << divisors.at(i);
				} else {
				output << "+" << divisors.at(i);
				}
			}
			output << " or " << sum << " which is less than the number " << num << endl;
			output << "There are " << divisors.size() << " proper divisors for the number " << num << endl << endl;
		
		
		} else {
			output << "THE NUMBER " << num << isOrIsNot << "AN ABUNDANT NUMBER" << endl;
			output << "The proper divisors of " << num << " are ";
			for (int i = 0; i < divisors.size(); i++) {
				if (not(i+1 == divisors.size())){
					output << divisors.at(i) << ", ";
				} else {
					output << "and " << divisors.at(i) << endl;
				}
			}
			output << "The sum of the proper divisors is ";
			for (int i = 0; i < divisors.size(); i++) {
				if (i == 0){
					output << divisors.at(i);
				} else {
				output << "+" << divisors.at(i);
				}
			}
			output << " or " << sum << " which is less than the number " << num << endl;
			output << "There are " << divisors.size() << " proper divisors for the number " << num << endl << endl;
			}
	}
	
	output << "64 is the natural number that has exactly six proper divisors." << endl;
	// Close the file
	output.close();
	
	return(0);
}
