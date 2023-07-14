//Spelling Correction System
//Ava Gullitti
//7-14-2023
/* This C++ program is designed to solve WCC machine problem 7. Machine problem 7 requires the program to correctly identify spelling mistakes. It will do this by first reading an input file of the name "mp7spelling.txt". From this file it extracts the correct spelling of the word and the users attempts at spelling this word correctly. Then the program will  create 5 different functions. The first function will check if the spelling is correct. The second will check if a character has been inserted into the word. The third one will see if the user accidentally switched two characters around. The fourth one will check if a character was deleted and the last one will check if a letter has been inserted. Once all of the words have been classified a switch statement will decide what to output to the text file. It also keeps track of how many times each error has occurred. Once the program reaches the end of the text file it will print the final counts and close the input and output files. */

// inculding necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//Creating variables to count the different types of typo
int cor, sub, tran, del, ins, err;

// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile("mp7spelling.txt");
//opening my output file
ofstream fout("MP7Output.txt");

//creating a enum of the different types of errors
enum errorType { CORRECT, SUBSTITUTION, TRANSPOSITION, DELETION, INSERTION, ERROR };

//initializing function
void checkCorrect(string word, string firstWord, errorType& error); 
void checkSubstitution(string word, string firstWord, errorType& error);
void checkTransposition(string word, string firstWord, errorType& error);
void checkDeletion(string word, string firstWord, errorType& error);
void checkInsertion(string word, string firstWord, errorType& error);

//Running the main function
int main() {
	
	//reading the last lines of the text file to get the words to search for
	string line;
	while (!MyReadFile.eof( )) { //runs until the end of the file
		// Getting a line of words from the text file
		getline(MyReadFile, line);
		
		//making a string stream from the line
		stringstream ss(line);
		
		//intializing variables for each loop
		errorType error;
		string word;
		string firstWord;
		int count = 0;
		
		//runs for each word in the line
		while (ss >> word) {
			if (count==0) {//this will save the first word which is the correct word
				 firstWord = word;
				 fout << endl << "*****Starting a new line*****" << endl;//recording to text file
				 fout << "The word being checked is " << firstWord << endl << endl;
			} else { //this will run for every word listed after the first word 
				//Make the defualt state a word that is too badly misspelled
				error = ERROR;
				
				//running functions to check each word for typo
				checkCorrect(word, firstWord, error);
				checkSubstitution(word, firstWord, error);
				checkTransposition(word, firstWord, error);
				checkDeletion(word, firstWord, error);
				checkInsertion(word, firstWord, error);
				
				//this switch statement will decide what to output to the text file for each state
				switch(error)
				{
					case SUBSTITUTION:
						fout << "User word is " << word << endl;
						fout << "The user word has one character substituted" << endl << endl;
						sub++;//this con't how many of these errors were found
						break;
					case CORRECT:
						fout << "User word is " << word << endl;
						fout << "The user word is correct" << endl << endl;
						cor++;
						break;
					case TRANSPOSITION:
						fout << "User word is " << word << endl;
						fout << "The user word contains a transposition" << endl << endl;
						tran++;
						break;
					case DELETION:
						fout << "User word is " << word << endl;
						fout << "The user word has one character deleted" << endl << endl;
						del++;
						break;
					case INSERTION:
						fout << "User word is " << word << endl;
						fout << "The user word has one character inserted" << endl << endl;
						ins++;
						break;
					case ERROR:
						fout << "User word is " << word << endl;
						fout << "The user word is too bad to be a misspelling" << endl << endl;
						err++;
						break;
				}
			}	
			count++;
		}
	}
	
	//outputting how many times each error occured
	fout << "There were " << cor << " correct words" << endl;
	fout << "There were " << sub << " words with a substitution" << endl;
	fout << "There were " << tran << " words with a transposition" << endl;
	fout << "There were " << del << " words with a deletion" << endl;
	fout << "There were " << ins << " words with a insertion" << endl;
	fout << "There were " << err << " words that were way off" << endl;
	
	// Close the file input and output files
	MyReadFile.close();
	fout.close();
	return 0;
}

//this function will change the enum state to CORRECT if the word matchs the correct word
void checkCorrect(string word, string firstWord, errorType& error) {
	if (word == firstWord) {
		error = CORRECT;
	}
}

//this function will check if one charater in the word has been replaced
void checkSubstitution(string word, string firstWord, errorType& error) {
	if (word.size() == firstWord.size()) {//if the word is the same length as the correct word
		int missedLetter = 0;
		for (int letter = 0; letter < word.size(); letter++){//runs for the length of the word
			if (word[letter] == firstWord[letter]) {//checks if the letters matches
				continue;
			} else {
				missedLetter++;//adding each time a letter doesn't match
			}
		}
		if (missedLetter == 1) {//if only one letter doesn't match
			error = SUBSTITUTION;
		}
		
	}
}

//this function will check if two adjacent charaters have switched
void checkTransposition(string word, string firstWord, errorType& error) {
	if (word.size() == firstWord.size()) {//if the word is the same size as the correct word
		for (int letter = 0; letter < word.size() - 1; letter++) {//run one less than the length of the word
			string tranWord = word; //saves the word
			char backChar = word[letter];//saves the letter
			char frontChar = word[letter+1];
			char swap [3] = {frontChar, backChar, '\0'};//swaps the two letters and saves to an array
			tranWord.insert(letter,swap);//inserts the new letters
			tranWord.erase(letter+2, 2);//deletes the old letter
			if (tranWord == firstWord) {//if the swapped letters match the correct word
				error = TRANSPOSITION;
			}
		}
	}
}

//checks if a letter has been deleted from a word
void checkDeletion(string word, string firstWord, errorType& error) {
	if (word.size() == firstWord.size()-1) { //if the word is one less than the correct word
		for (int letter = 0; letter < firstWord.size(); letter++) {//runs for each letter in the correct word
			string firstWordCopy = firstWord;//saves correct word
			firstWordCopy.erase(letter, 1);//erases one charater from correct
			if (firstWordCopy == word) { //if the copy matches the word
				error = DELETION;
			}
		}
	}
}


//checks if a letter has been inserted into a word
void checkInsertion(string word, string firstWord, errorType& error) {
	if (word.size() == firstWord.size()+1) {//if the size is one more than the correct word
		for (int letter = 0; letter < word.size(); letter++) { //runs the length of the word
			string wordCopy = word;// saves word
			wordCopy.erase(letter, 1);// erases wone letter
			if (wordCopy == firstWord) {//if thecopy of the word matches the correct word
				error = INSERTION;
			}
		}
	}
}

