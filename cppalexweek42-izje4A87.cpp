/**************************************
*	Week 4 iLab
*	Function Testing
*
**************************************/
using namespace std;

// Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>

// Function prototypes
/*
	@method:	AcknowledgeCall
	@params:	<char> digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8
	@return:	<void> -> This method does not return a value.
*/
void AcknowledgeCall(char digit1, char digit2, char digit3, char digit4, char digit5, char digit6, char digit7, char digit8);
int ReadDials( char &digit1, char &digit2, char &digit3, char &digit4, char &digit5, char &digit6, char &igit7, char &digit8 );

int ToDigit( char digit );


int main(int argc, char* argv)
{
	// Digit Variable declaration
	char digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;
	
	// Constant Definitions
	const int ERROR_INVALID_DIGIT = -1;
	const int ERROR_BEGINS_WITH_0 = -2;
	const int ERROR_BEGINS_WITH_555 = -3;
	const int ERROR_NO_HYPHEN = -4;
	
	const int QUIT = -5;
	const int VALID_DIGIT = 0;
	const int SUCCESS = 0;
	
	while(true)
	{
		
		
		AcknowledgeCall( digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8 );
	}
	
	return 0;
}

void AcknowledgeCall(char digit1, char digit2, char digit3, char digit4, char digit5, char digit6, char digit7, char digit8)
{
	cout << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << digit7 << digit8 << endl;
}

int ReadDials( char &digit1, char &digit2, char &digit3, char &digit4, char &digit5, char &digit6, char &igit7, char &digit8 )
{
	cout << "Please enter a phone number: ";
	cin >> digit1;
	if ( digit1 == 'Q' )
	{
		return QUIT;
	}
	cin >> digit2 >> digit3 >> digit4 >> digit5 >> digit6 >> digit7 >> digit8;
	
	int value;
	value = ToDigit( digit1 );
	if ( value == ERROR_INVALID_DIGIT ) { return ERROR_INVALID_DIGIT; }
	if ( value == 0 ) { return ERROR_BEGINS_WITH_0; }
	if ( digit4 != '-' ) { return ERROR_NO_HYPHEN; }
	if ( ToDigit( digit1 ) == 5 && ToDigit( digit2 ) == 5 && ToDigit( digit3 ) == 5 ) { return ERROR_BEGINS_WITH_555; }
	
	return SUCCESS;
}