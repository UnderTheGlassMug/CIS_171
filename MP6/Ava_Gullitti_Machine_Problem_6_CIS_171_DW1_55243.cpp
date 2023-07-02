//Cross Word
//Ava Gullitti
//7-7-2023
/* This C++ program is designed to solve WCC machine problem 6. This problem requires the program to read a file that has an 8 by 8 table of letter followed by a set of words to search for. The progam must read this table fill it into a 2-dim array and find the words in the table. The output of the program shows the row and column location and direction of each word given. If the word is not found it will as display that result. The first thing this programdoes is open the input file and create a text file name MP6Output.txt. Then the program will intialize global variables as well as three functions to find words in different positions on the 8 by 8 table. After this the main function will run. First inputing the 8 by 8 table in the input file to a 2 dim array and then adding the words listed below this text file to a word list. Next the program will add the 8 by 8 table to the output file alond with the words. Then for each word in the wordlist the program will runthree functions finding the words that are vertical, diagonal, or horizontial. If the functions can't find the word the program will output this result. It doesthis by setting a bool variable to false and passing it by reference to each of the functions and if the functions find a word it will set this variable to true.*/

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile("input6.txt");
//opening my output file
ofstream fout("MP6Output.txt");

//Creating the 2-Dim array
char crossWord [8] [8];
string wordList [5];
bool wordFound = false;

void findHorz(char crossWord [8] [8], string word, bool& wordFound);
void findDiag(char crossWord [8] [8], string word, bool& wordFound);
void findVert(char crossWord [8] [8], string word, bool& wordFound);

//Running the main function
int main() {
	// Two for loops to create a 2-Dim array of the cross word
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++){
			MyReadFile >> crossWord [row] [col];
		}
	}
	
	//reading the last lines of the text file to get the words to search for
	int count = 0;
	while (!MyReadFile.eof( )) { //runs until the end of the file
		// Output the text from the file
		MyReadFile >> wordList[count];// adding these to a wordlist
		count++;
	}
	
	//Displaying the crossword
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++){
			fout << "	" <<crossWord [row] [col];
		}
		fout << endl;
	}
	
	//displaying the words
	for (int i = 0; i < count; i++) {
		fout << wordList[i] << endl;
	}
	
	//displaying the output
	fout << "Output:" << endl;
	fout << "	" << left << setfill('_') << setw(10) << "Word" << setw(10) << "Row" << setw(10) << "Column" << "Direction" << endl << setfill(' ');
	//Displaying each word its position or if it couldn't find the word
	for (int word = 0; word < sizeof(wordList)/sizeof(string); word++) {//running for each word in the word list
		wordFound = false;//setting varable to false because no words have been found yet
		findHorz(crossWord, wordList[word], wordFound);//this function finds horizontal words
		findDiag(crossWord, wordList[word], wordFound);// this function finds diagonal words
		findVert(crossWord, wordList[word], wordFound);// this function finds vertical words
		if (wordFound == false) {//if none of the functions found the word it will output not found
			fout << "	" << left << setw(10) << wordList[word] << setw(10) << " " << setw(10) << " " << "Not Found" << endl;
		}
	}
	
	// Close the file input and output files
	MyReadFile.close();
	fout.close();
	return 0;
}

//This function finds words that are horizontial it takes in the crossword and a word as well as the wordFound bool which is passed by reference
void findHorz(char crossWord [] [8], string word, bool& wordFound) {
	for (int row = 0; row < 8; row++) { //for each row
		for (int col = 0; col <= 8 - wordList[0].size(); col++){ // and each column minus the colums that are impossible to have the word be located in
			if(crossWord [row] [col] == toupper(word [0])) {// if the crossword letter equal to the first letter of the word
				//save this letters position
				int rowPose = row;
				int colPose = col;
				for (int colPlus = 1; colPlus < word.size(); colPlus++){ //then for the size of the word
					if ((crossWord [row] [col + colPlus] == toupper(word [colPlus]) && (colPlus == word.size() -1))) {//if the letter is equal to the the words letter and that letteris the last letter
						fout << "	" << left << setw(10) << word << setw(10) << rowPose << setw(10) << colPose << "Horizontal" << endl;// output the word to the output file
						wordFound = true;// signify this word has be found	
					} else if (crossWord [row] [col + colPlus] == toupper(word [colPlus])) {//if the next crossword letter is equal to the next letter in the word
						continue;
					} else { //if the next crossword letter is not equal to the next letter in the word
						break;
					} 
				}
			}
		}
	}
	return;
}

//This function finds words that are Diagonal it takes in the crossword and a word as well as the wordFound bool which is passed by reference
void findDiag(char crossWord [] [8], string word, bool& wordFound) {
	//starting the search in the bottom left corner
	int colPose = 0;
	int rowPose = 7;
	for (int diag = 0; diag < 16; diag++) {//running this loop for each diagonal row
		while (colPose < 8 && colPose >= 0 && rowPose < 8 && rowPose >= 0 ) {//while the crossword array is not being overindexed
			int count = 1;//keeps track of how many matching letters
			if (crossWord [rowPose] [colPose] == toupper(word[0])) { // if the crossword letter equal to the first letter of the word
				while ((crossWord [rowPose + count ] [colPose + count] == toupper(word[count])) && ((rowPose + count < 8 ) || (colPose + count < 8))) {//while the next crossword letter is equal to the next letter in the word and the crossword array is not being overindexed
					count++;//adds to the count variable
				}
			} 
			if (count == word.size()) {// if the amount of matching letters matches the length of the word
				fout << "	" << left << setw(10) << word << setw(10) << rowPose << setw(10) << colPose << "Diagonal" << endl;// output the word to the output file
				wordFound = true;//signify that this word has been found
			} 
			//these variables force the while loop to search diagonally
			colPose++;
			rowPose++;
		}
		if (diag < 7) { //if it is the first 7 diagonal rows
			//make the starting row one higer
			rowPose = 6 - diag;
			colPose = 0;
		} else {
			// make the starting row one column to the right
			rowPose = 0;
			colPose = diag - 7;
		}
	}
	return;
}

//This function finds words that are vertical it takes in the crossword and a word as well as the wordFound bool which is passed by reference
void findVert(char crossWord [] [8], string word, bool& wordFound) {
	for (int col = 0; col < 8; col++) {// for each column
		for (int row = 0; row <= 8 - wordList[0].size(); row++){// search down the rows minus the rows where the word can't be located
			if(crossWord [row] [col] == toupper(word [0])) {//if the crossword letter equals the first letter in the word
				//save this position
				int rowPose = row;
				int colPose = col;
				for (int rowPlus = 1; rowPlus < word.size(); rowPlus++){// for the length of the word
					if ((crossWord [row + rowPlus] [col] == toupper(word [rowPlus]) && (rowPlus == word.size() -1))) {//if the letter is equal to the the words letter and that letter is the last letter
						fout << "	" << left << setw(10) << word << setw(10) << rowPose << setw(10) << colPose << "Vertical" << endl;// output the word to the text file
						wordFound = true;//signify that this word has been found
					} else if (crossWord [row + rowPlus] [col] == toupper(word [rowPlus])) {// if the next crossword letter is equal to the next letter in the word
						continue;
					} else {//if the letters don't match exit the loop
						break;
					} 
				}
			}
		}
	}
	return;
}

