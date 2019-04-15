/*
CIS170C - Week 5 iLab 
Part One: Create a Video Game Player Program
*/
using namespace std;
#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

const int MAX_PLAYERS = 100;

void InputData( int* scores, string* names, int &num );
void DisplayPlayerData( int* scores, string* names, int num );
float CalculateAverageScore( int* scores, int num );
void DisplayBelowAverage( int* scores, string* names, float average, int num );

int main( int argc, char* argv )
{
	int 	player_score[ MAX_PLAYERS ];
	string 	player_name[ MAX_PLAYERS ];
	int		num_players = 0;
	float	average_score = 0.0;
	
	InputData( player_score, player_name, num_players );
	DisplayPlayerData( player_score, player_name, num_players );
	average_score = CalculateAverageScore( player_score, num_players );
	DisplayBelowAverage( player_score, player_name, average_score, num_players );
	return 0;
}

void InputData( int* scores, string* names, int &num )
{
	while( num < MAX_PLAYERS )
	{
		string name; int score;
		cout << "Please enter the player's name: ";
		cin >> name;
		if( "Q" == name ) break;
		
		names[num] = name;
		
		cout << "Please enter the player's score: ";
		cin >> score;
		
		scores[num] = score;
		
		num++;
	}
}

void DisplayPlayerData( int* scores, string* names, int num )
{
	cout << endl << "Name\tScore" << endl << endl;
	for( int i = 0; i < num; i++ )
	{
		cout << names[i] << "\t" << scores[i] << endl;
	}
	
	cout << endl;
}

float CalculateAverageScore( int* scores, int num )
{
	float average = 0.0;
	int sum = 0;
	for( int i = 0; i < num; i++ )
	{
		sum = sum + scores[i];
	}
	// Alternate format: 
	// average = static_cast<float>sum / static_cast<float>num;
	average = (float)sum / (float)num;
	
	cout << "Average score: " << average << endl << endl;
	
	return average;
}

void DisplayBelowAverage( int* scores, string* names, float average, int num )
{
	cout << "Below Average" << endl << endl;
	for( int i = 0; i < num; i++ )
	{
		if( scores[i] < average ) cout << names[i] << "\t" << scores[i] << endl;
	}
}