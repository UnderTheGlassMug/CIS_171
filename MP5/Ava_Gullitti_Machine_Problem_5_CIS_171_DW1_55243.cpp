//Banking Information
//Ava Gullitti
//6-30-2023
/* This C++ program is designed to solve WCC machine problem 5. This problem requires the program to mange customer's banking information and then display the required information for each customer. The program will do it using five function. The first function, readAccountNo, will promt the user to enter an account number and then return. This function only accepts even positive account numbers less than 10,000. The secound function readBalanceAmount prompts the user to enter the opening balance amount and returns it. If the users enters an amount less than 1 or greater than $200,00 then the function should keep asking the user, by using a for loop, to enter an amount until user enters a value between 1 to $200,000. The fourth function, calculateDeposit, will accept the account balence as an argument and prompt the user to enter the ammount needed to deposit. The function will then calculate and return the new cumulative amount balance. The fourth function, addReturnBonus, accepts the opening balance as a argument, and calculate and return the new blance after the bounus percentage. This bounus changes based on the account amount. If the amount is between 1 and 100 the percentage is 2%. If the amount is between 101 and 500 the percentage is 3%. If the amount is between 501 and 1000 the percentage is 4%. If the amount is over 1000 the percentage is 5%. The fifth function, printAllInfo, accepts eight parameters (four account numbers and four account balances) and displays account balances for all the accounts. After these function are created the main function will run. In the main function first it will display the developer details using a for loop. Then another for loop will run asking the user for 4 customers account numbers and opening balences. After these account details have be entered the program will calculate and add the return bonus to the account balance for each account. Then a main menu will appear while the user has not choosen option C. Option A will allow the user to deposit a specfic amount of money to the account. Option B will allow the user to view the account information of the four accounts and option c will allow the user to exit the program and view the final account information*/

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//defining variables
int currentAccountNum;
int accountIndex;
char option;

// creating arrays for account numbers and balances
int accountNo[4] = {};
double balance[4] = {};

//defining five function
int readAccountNo();
double readBalanceAmount();
double calculateDeposit(double balence);
double addReturnBonus(double balance);
void printAllInfo(int accountNo0, int accountNo1, int accountNo2, int accountNo3, double balance0, double balance1, double balance2, double balance3);

//Running the main function
int main() {
    //Displays the developer’s details using a for loop
    for (int i = 0; i < 1 ; i++) {
    	cout << "*****************************************************************************" << endl << "*****************************************************************************" << endl;
    	cout << "Name: Ava Gullitti Section: DW1                      Due Date: June, 30, 2023" << endl;
    	cout << "*****************************************************************************" << endl << "*****************************************************************************" << endl;
    }
    
    //adding 4 customers account number and balance and claculating the bonus
    cout << "Enter data for 4 customers" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "For customer " << i+1 << endl;
        // calling both the readAccountNo() and readBalanceAmount() functions
        accountNo[i] = readAccountNo();
        balance[i] = readBalanceAmount();
        //adding the bonus to the balence
        balance[i] = addReturnBonus(balance[i]);
    }
    
    //creating the main menu
    while (option != 'C') {
        //displaing main menu
        cout << endl << "MAIN MENU" << endl;
        cout << "A -    Do deposit\nB -    View accounts\nC -    Exit the program\nOption - ";
        //asking the user for an option
        cin >> option;
        
        //Decideing what the program should run based on the option the user entered
        switch(option) {
            case 'A': //Deposit option
                cout << endl << "Account Number:"; // Asking for which account to deposit to
                cin >> currentAccountNum;
                for (int i = 0; i < 4; i++) { //finding the index of the account number given
                    if (accountNo[i] == currentAccountNum) {
                        accountIndex = i;
                    }
                }
                balance[accountIndex] = calculateDeposit(balance[accountIndex]); //finding the balance of the account with that index in the balance list
                break;
            case 'B'://view account option
                cout << endl;
                printAllInfo(accountNo[0], accountNo[1], accountNo[2], accountNo[3], balance[0], balance[1], balance[2], balance[3]);
                break;
            case 'C'://exit opition
                break;
            default://didn't enter an option
                cout << "\nERROR! Enter option A, B, or C.\n";
                break;
        }
    } 
    
    //displaingthe final screen
    cout << endl;
    printAllInfo(accountNo[0], accountNo[1], accountNo[2], accountNo[3], balance[0], balance[1], balance[2], balance[3]);
    cout << endl << "Have a good day!";
    return 0;
}

//This function asks the user for the correct account number
int readAccountNo() {
    int accountNo;
    //the for loop woll run until the account variable is false
	for (bool account = true; account;){
        cout << "Enter an even positive account number less than 10000:";
		cin >> accountNo;
		cout << endl;
		// the account variable becomes false when the account number is between 0 and 10000 and is even
		account = accountNo < 0 || accountNo > 10000 || accountNo % 2 != 0;
    }
    //returns the correct account number
	return accountNo;
}

//This function asks the user for a opening balance
double readBalanceAmount() {
    double balance;
    //this for loop will run until the account variable is true
	for (bool account = true; account;){
        cout << "Enter opening balance between $1 - $200,000:";
		cin >> balance;
		cout << endl;
		//the account varaiable is true when the balance is between 1 and 200000
		account = balance < 1 || balance > 200000 ;
    }
    //returns the balance
    return balance;
}

//this function calculates the new balence after a deposit it takes in the balence variable as parameter
double calculateDeposit(double balance) {
    double deposit;
    double newBalance;
    cout << "Enter the amount needed to deposit: ";
	cin >> deposit;
	cout << endl;
	//adds the deposit to the balance
	newBalance = balance + deposit;
	//returns the new balance
    return newBalance;
}

//this function adds the bonus to the account balance it takes in the balance variable as a parameter
double addReturnBonus(double balance) {
    double bonus;
    double percentage;
    double newBalance;
    //checking the balance ammount to assign the correct bonus percentage
    if (balance > 1 &&  balance < 101) { //between $1-100
        percentage = .02; //2% bonus
    } else if (balance >= 101 &&  balance < 501) { //between $101-500
        percentage = .03; //3% bonus
    } else if (balance >= 501 &&  balance < 1000) { //between $501-1000
        percentage = .04; //4% bonus
    } else { // greater than $1000
        percentage = .05; //5% bonus
    }
    //finding the bonus
	bonus = balance * percentage;
	//finding the new balance
	newBalance = balance + bonus;
	//returning the new balance
    return newBalance;
}

//This function displays account information
//it takes if 4 intager account numbers and 4 double balances and dispalys them
void printAllInfo(int accountNo0, int accountNo1, int accountNo2, int accountNo3, double balance0, double balance1, double balance2, double balance3) {
    cout << "================================= Balance Accounts ==========================" << endl;
    cout << "=============================================================================" << endl;
    cout << "Balance amount for Customer account number " << setw(4) << accountNo0 << setw(14) << fixed << setprecision(2) << balance0 << endl;
    cout << "Balance amount for Customer account number " << setw(4) << accountNo1 << setw(14) << fixed << setprecision(2) << balance1 << endl;
    cout << "Balance amount for Customer account number " << setw(4) << accountNo2 << setw(14) << fixed << setprecision(2) << balance2 << endl;
    cout << "Balance amount for Customer account number " << setw(4) << accountNo3 << setw(14) << fixed << setprecision(2) << balance3 << endl;
    cout << "=============================================================================" << endl;
}
