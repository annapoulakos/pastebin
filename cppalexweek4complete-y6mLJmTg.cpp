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
/*
	@method:	ToDigit
	@params:	<char&> digit
	@return:	<int> -> This method returns VALID_DIGIT or ERROR_INVALID_DIGIT
*/
int ToDigit( char &digit );
/*
	@method:	ReadDials
	@params:	<char&> digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8
	@return:	<int> -> This method returns an integer in the following range:
				ERROR_INVALID_DIGIT, ERROR_BEGINS_WITH_0, ERROR_BEGINS_WITH_555, ERROR_NO_HYPHEN, SUCCESS
*/
int ReadDials( char &digit1, char &digit2, char &digit3, char &digit4, char &digit5, char &digit6, char &igit7, char &digit8 );

// Constant Definitions
const int ERROR_INVALID_DIGIT = -1;
const int ERROR_BEGINS_WITH_0 = -2;
const int ERROR_BEGINS_WITH_555 = -3;
const int ERROR_NO_HYPHEN = -4;

const int QUIT = -5;
const int VALID_DIGIT = 0;
const int SUCCESS = 0;

int main(int argc, char* argv)
{
	// Digit Variable declaration
	char digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;
	
	while(true)
	{
		int response = ReadDials( digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8 );
		
		if( QUIT == response ) break;
		
		switch( response )
		{
			case ERROR_INVALID_DIGIT: 	cout << "ERROR - An invalid character was entered." << endl; break;
			case ERROR_BEGINS_WITH_0: 	cout << "ERROR - Phone number cannot begin with 0." << endl; break;
			case ERROR_BEGINS_WITH_555: cout << "ERROR - Phone number cannot begin with 555." << endl; break;
			case ERROR_NO_HYPHEN: 		cout << "ERROR - Hyphen is not in the correct position." << endl; break;
			
			/*	NOTE	::	Default behaviour is to acknowledge the call. 	*/
			default:
				AcknowledgeCall( digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8 );
				break;
		}
	}
	
	return 0;
}

void AcknowledgeCall(char digit1, char digit2, char digit3, char digit4, char digit5, char digit6, char digit7, char digit8)
{
	cout << "Phone Number Dialed: " << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << digit7 << digit8 << endl;
}

int ReadDials( char &digit1, char &digit2, char &digit3, char &digit4, char &digit5, char &digit6, char &digit7, char &digit8 )
{
	cout << "Please enter a phone number (Q to quit): ";
	cin >> digit1;
	if ( digit1 == 'Q' )
	{
		return QUIT;
	}
	cin >> digit2 >> digit3 >> digit4 >> digit5 >> digit6 >> digit7 >> digit8;
	
	/*	NOTE	::	The value of the sum of all digits run through the ToDigit function should always be 0 for a valid number	*/
	/*			::	and less than 0 for an invalid number.	*/
	int value;
	value = ToDigit( digit1 ) + ToDigit( digit2 ) + ToDigit( digit3 ) + ToDigit( digit5 ) + ToDigit( digit6 ) + ToDigit( digit7 ) + ToDigit( digit8 );
	if ( value < 0 ) { return ERROR_INVALID_DIGIT; }
	
	if ( digit1 == '0' ) { return ERROR_BEGINS_WITH_0; }
	if ( digit4 != '-' ) { return ERROR_NO_HYPHEN; }
	if ( digit1 == '5' && digit2 == '5' && digit3 == '5' ) { return ERROR_BEGINS_WITH_555; }
	
	return SUCCESS;
}

int ToDigit( char &digit )
{
	/*	NOTE	::	If the number is valid, we need to convert the referenced 'digit' variable to the appropriate number. */
	/*			::	We simply return ERROR_INVALID_DIGIT in the switch if the number is not valid, and then always return VALID_DIGIT	*/
	/*			::	if everything checks out okay.	*/
	switch( toupper(digit) )
	{
		case '2': case 'A': case 'B': case 'C':
			digit = '2'; break;
		case '3': case 'D': case 'E': case 'F':
			digit = '3'; break;
		case '4': case 'G': case 'H': case 'I':
			digit = '4'; break;
		case '5': case 'J': case 'K': case 'L':
			digit = '5'; break;
		case '6': case 'M': case 'N': case 'O':
			digit = '6'; break;
		case '7': case 'P': case 'Q': case 'R': case 'S': 
			digit = '7'; break;
		case '8': case 'T': case 'U': case 'V':
			digit = '8'; break;
		case '9': case 'W': case 'X': case 'Y': case 'Z': 
			digit = '9'; break;
		case '0': case '1':
			break;
		default:
			return ERROR_INVALID_DIGIT;
	}
	return VALID_DIGIT;
}