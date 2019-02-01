/*
Write a program that will input a phrase and convert 
it to pig latin.  Put each word in a separate element 
of a string array.  Remove the first letter from each 
word and concatenate it to the end of the word followed 
by "ay".
*/

#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

// Custom Defines
// Use the _DELIMITER_ definition to make instant changes
// to what will be used as the delimiter for words. 
// In this case, we are using a space as the delimiter.
#define _DELIMITER_ " "

// Function Definitions
string pigLatinString(string);

int main(void)
{
	cout << "*** You will be prompted to enter a string of  ***" << endl;
	cout << "*** words. The string will be converted into   ***" << endl;
	cout << "*** Pig Latin and the results displayed.       ***" << endl;
	cout << "*** Enter as many strings as you would like.   ***" << endl;

	while (true)
	{
		string theString;
		cout << "Enter a group of words or ENTER to quit:";
		getline(cin, theString);

		// Break the loop if the user only pressed ENTER
		if (theString.empty())
			break;
		else
		{
			cout << "Original: " << theString << endl;
			cout << "New: " << pigLatinString(theString) << endl << endl;
		}
	}

	return 0;
}

// Function Implementations
string pigLatinString(string original)
{
	// Define needed variables
	// retString is the string we will be returning after making changes.
	// end signifies the end of the word in the original string.
	string	retString = "";
	int		end = original.find_first_of(_DELIMITER_);

	// Continue looping until you reach the end limit of the string
	while(end != string::npos)
	{
		// Create a temporary string variable to hold each word
		// Remove the word from the original string
		// Then set the end of the word to the next word's end.
		string word	= original.substr(0,end);
		original	= original.substr(end+1);
		end			= original.find_first_of(_DELIMITER_);

		// This is the part that actually does the pig-latin
		// Takes the word minus the first letter and appends it on
		// our return string. Then appends the first letter of the
		// word to our return string. Finally, we add "ay " to the 
		// end of our return string before continuing on our way.
		retString += word.substr(1);
		retString += word.substr(0,1);
		retString += "ay ";
	}

	// Don't forget to add the last word to our return string
	// using the same rules as for other words.
	retString += original.substr(1);
	retString += original.substr(0,1);
	retString += "ay";

	return retString;
}