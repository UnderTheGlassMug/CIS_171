//Banking Information
//Ava Gullitti
//6-30-2023
/* This C++ program is designed to solve WCC machine problem 5. This problem requires the program to mange customer's banking information and then display the required information for each customer. The program will do it using five function. The first function, readAccountNo, will promt the user to enter an account number and then return. This function only accepts even positive account numbers less than 10,000. The secound function readBalanceAmount prompts the user to enter the opening balance amount and returns it. If the users enters an amount less than 1 or greater than $200,00 then the function should keep asking the user, by using a for loop, to enter an amount until user enters a value between 1 to $200,000. The fourth function, calculateDeposit, will accept the account balence as an argument and prompt the user to enter the ammount needed to deposit. The function will then calculate and return the new cumulative amount balance. The fourth function, addReturnBonus, accepts the opening balance as a argument, and calculate and return the new blance after the bounus percentage. This bounus changes based on the account amount. If the amount is between 1 and 100 the percentage is 2%. If the amount is between 101 and 500 the percentage is 3%. If the amount is between 501 and 1000 the percentage is 4%. If the amount is over 1000 the percentage is 5%. The fifth function, printAllInfo, accepts eight parameters (four account numbers and four account balances) and displays account balances for all the accounts. After these function are created the main function will run*/

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//defining importan variables




int main() {
    int balence = 10;
    cout << balence;
    return 0;
}
/*
int readBalanceAmount() {
    int balance;
	for (bool account = true; account;){
        cout << "Enter opening balance between $1 - $200,000:";
		cin >> balance;
		cout << endl;
		account = balance < 1 || balance > 200000 ;
    }
    return balance;
*/
