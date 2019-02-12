/******************************************************************
	* Course:  		CIS247C
	* Week: 		4
	* Programmer:  	Jim P 
	* Date: 		2012-09-30
	*
	* Note:			See documentation for more information about this
	*				application.
***********************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <iomanip>

using namespace std;

const double 	MIN_SALARY 		= 50000;
const double 	MAX_SALARY 		= 250000;
const int 		MAX_DEPENDENTS 	= 10;
const int 		MIN_DEPENDENTS 	= 0;
const char 		DEFAULT_GENDER 	= 'N'; //N stands for not identified
const int 		NUMBER_WEEKS 	= 52;
const int 		MAX_VACATION 	= 52;
const int 		MIN_VACATION 	= 0;

/*
	@class:		iEmployee
	@methods:	<double> calculatePay(void) :> Returns the pay.
	@notes:		This is an abstract class interface.
*/
class iEmployee
{
	public:
	virtual double calculatePay(void) =0;
};

/*
	@class: 	Benefit
	@vars:		<string> healthInsurance
	@vars:		<string> lifeInsurance
	@vars:		<int> vacation
	@methods:	<string> getHealthInsurance, setHealthInsurance
	@methods:	<string> getLifeInsurance, setLifeInsurance
	@methods:	<int> getVacation, setVacation
	@methods:	<void> displayBenefits -> Displays benefits.
*/
class Benefit
{
	private:
	string healthInsurance;
	string lifeInsurance;
	int vacation;
	
	public:
	
	/*
		@method:	Default constructor
	*/
	Benefit()
	{
		healthInsurance = "";
		lifeInsurance = "";
		vacation = MIN_VACATION;
	}
	
	/*
		@method:	Constructor
		@params:	<string> healthInsurance
		@params:	<string> lifeInsurance
		@params:	<int> vacation
		
		@note:		Uses Benefit::setVacation method to clamp vacation appropriately.
	*/
	Benefit( string healthInsurance, string lifeInsurance, int vacation )
	{
		this->healthInsurance = healthInsurance;
		this->lifeInsurance = lifeInsurance;
		this->vacation = this->setVacation( vacation );
	}
	
	
	/*
		@method:	getHealthInsurance
		@return:	<string> Returns this->healthInsurance
	*/
	string getHealthInsurance()
	{	
		return this->healthInsurance;
	}
	/*
		@method:	setHealthInsurance
		@params:	<string> Health
		@return:	<void> This function should not return a value
	*/
	void setHealthInsurance (string Health)
	{
		this->healthInsurance = Health;
	}
	
	/*
		@method:	getLifeInsurance
		@return:	<string> Returns this->lifeInsurance
	*/
	string getLifeInsurance()
	{
		return this->lifeInsurance;
	}
	/*
		@method:	setLifeInsurance
		@params:	<string> Life
		@return:	<void> This function should not return a value
	*/
	void setLifeInsurance (string Life)
	{
		this->lifeInsurance = Life;
	}
	
	/*
		@method:	getVacation
		@return:	<int> Returns this->vacation
	*/
	int getVacation()
	{
		return this->vacation;
	}
	
	/*
		@method:	Benefit::setVacation()
		@params:	<int> vac -> The number of vacation days to set.
		@return:	This function does not return a value.
		
		@summary:	This function sets the vacation days for the Benefit object. 
		This value is clamped between MIN_VACATION and MAX_VACATION (see above).
	*/
	void setVacation (int vac)
	{
		if (vac >= MIN_VACATION && vac <= MAX_VACATION)
		{
			this->vacation = vac;
		}
		else if (vac < MIN_VACATION)
		{
			this->vacacation = MIN_VACATION;
		}
		else
		{	
			this->vacation = MAX_VACATION;
		}
	}
	
	/*
		@method:	displayBenefits
		@return:	<void> This method should not return a value.
	*/
	void displayBenefits()
	{
		cout <<"Benefit Information\n";
		cout <<"_______________________________________________________________________________________________ \n";
		cout << "Health Insurance: \t\t" << this->healthInsurance << "\n";
		cout << "Life Insurance: \t\t" << this->lifeInsurance << "\n";
		cout << "Vacation: \t\t" << this->vacation << "\n";
	}
	
};

/*
	@class:		Employee
	@requires:	iEmployee
	@vars:		<static int> numEmployees
	@vars:		<string> firstName
	@vars:		<string> lastName
	@vars:		<char> gender
	@vars:		<int> dependents
	@vars:		<double> annualSalary
	@vars:		<Benefit> benefit
	@methods:	<string> getFirstName, setFirstName
	@methods:	<string> getLastName, setLastName
	@methods:	<char> getGender, setGender
	@methods:	<int> getDependents, setDependents
	@methods:	<double> getAnnualSalary, setAnnualSalary
	@methods:	<double> iEmployee.calculatePay
	@methods:	<void> displayEmployee
	@methods:	<int> Employee::getNumEmployees
*/
class Employee: public iEmployee
{	
    private:
	static int numEmployees;
	
   	string firstName;
	string lastName;
	char gender;
	int dependents;
	double annualSalary; 
	
    public:
	Benefit benefit;
	
	/*
		@method:	Default Constructor
	*/
	Employee()
	{
		this->firstName = "";
		this->lastName = "";
		this->gender = DEFAULT_GENDER;
		this->dependents = MIN_DEPENDENTS;
		this->annualSalary = MIN_SALARY;
		this->numEmployees += 1;
	}
	
	/*
		@method:	Constructor
		@params:	<string> firstName
		@params:	<string> lastName
		@params:	<char> gender
		@params:	<int> dependents
		@params:	<double> salary
	*/
	Employee( string firstName, string lastName, char gender, int dependents, double salary )
	{
		//use the THIS keyword to distinguish between the class attributes and the parameters
		this->firstName = firstName;
		this->lastName = lastName;
		this->gender = this->setGender( gender );
		this->dependents = this->setDependents( dependents);
		this->annualSalary = this->setAnnualSalary( salary );
		//each time a constructor is called, increment the the class level numEmployees variable
		this->numEmployees += 1;
	} 
	
	/*
		@method:	Default destructor
		@note:		This method is only to decrement this->numEmployees when an <Employee> loses focus
	*/
	~Employee()
	{
		this->numEmployees -= 1;
	}
	
	/*
		@method:	Employee::getNumberEmployees()
		@return:	<int> Employee::numEmployees
	*/
	static int getNumberEmployees()
	{
		return numEmployees;
	}
	
	
	/*
		@method:	getFirstName()
		@return:	<string> Returns this->firstName.
	*/
	string getFirstName()
	{
		return this->firstName;
	}
	/*
		@method:	setFirstName
		@params:	<string> name
		@return:	<void> This method should not return a value.
	*/
	void setFirstName(string name)
	{
		this->firstName = name;
	}
	/*
		@method:	getLastName
		@return:	<string> Returns this->lastName.
	*/
	string getLastName()
	{
		return this->lastName;
	}
	/*
		@method:	setLastName
		@params:	<string> name
		@return:	<void> This method should not return a value.
	*/
	void setLastName(string name)
	{
		this->lastName = name;
	}
	/*
		@method:	getGender
		@return:	<char> Returns this->gender.
	*/
	char getGender()
	{
		return this->gender;
	}
	/*
		@method:	setGender
		@params:	<char> gen
		@return:	<void> This method should not return a value.
		
		@notes:		This method clamps this->gender to the following values:
					{ 'f, 'F', 'm', 'M', DEFAULT_GENDER ('N') }
	*/
	void setGender(char gen)
	{
		switch (gen)
		{
			case 'f':case 'F': case 'M':case 'm':
			this->gender = gen;
			break;
			default:
			this->gender = DEFAULT_GENDER;
		}
	}
	/*
		@method:	getDependents
		@return:	<int> Returns this->dependents
	*/
	int getDependents()
	{
		return this->dependents;
	}
	/*
		@method:	setDependents
		@params:	<int> dep
		@return:	<void> This method should not return a value.
		
		@notes:		This method clamps the value of this->dependents
					To the range defined by
					{ MIN_DEPENDENTS, MAX_DEPENDENTS }
	*/
	void setDependents(int dep)
	{
		if (dep >= MIN_DEPENDENTS && dep <= MAX_DEPENDENTS)
		{
			this->dependents = dep;
		}
		else if (dep < MIN_DEPENDENTS)
		{
			this->dependents = MIN_DEPENDENTS;
		}
		else
		{
			this->dependents = MAX_DEPENDENTS;
		}
	}
	/*
		@method:	getAnnualSalary
		@return:	<double> Returns this->annualSalary
	*/
	double getAnnualSalary()
	{
		return this->annualSalary;
	}
	/*
		@method:	setAnnualSalary
		@params:	<double> salary
		@return:	<void> This method should not return a value.
		
		@notes:		This method clamps the value of this->salary
					to the range defined by:
					{ MIN_SALARY, MAX_SALARY }
	*/
	void setAnnualSalary(double salary)
	{
		if (salary >= MIN_SALARY && salary <= MAX_SALARY)
		{
			this->annualSalary = salary;
		}
		else if (salary < MIN_SALARY)
		{
			this->annualSalary = MIN_SALARY;
		}
		else
		{
			this->annualSalary = MAX_SALARY;
		}
	}
	/*
		@method:	calculatePay
		@return:	<double> this->annualSalary / NUMBER_WEEKS
		
		@note:		This method is required by iEmployee
	*/
	double calculatePay()
	{
		return this->annualSalary/NUMBER_WEEKS;
	}
	/*
		@method:	displayEmployee
		@return:	<void> This method should not return a value.
		
		@notes:		This method displays pertinent information about this class.
	*/
	void displayEmployee()
	{
		cout << "Employee Information\n";
		cout << "____________________________________________________________\n";
		cout << "Name: \t\t" << this->firstName << " " << this->lastName << "\n";
		cout << "Gender:\t\t" << this->gender << "\n";
		cout << "Dependents: \t" << this->dependents << "\n";
		cout << "Annual Salary:\t" << setprecision(2) << showpoint << fixed << this->annualSalary << "\n";
		cout << "Weekly Salary:\t" << setprecision(2) << showpoint << fixed << this->calculatePay() <<"\n";
		
	}
};

/*	NOTE	::	Initialize Employee::numEmployees	*/ 
int Employee::numEmployees=0;

/*
	@method:	DisplayApplicationInformation
	@return:	<void> This function does not return a value.
*/
void DisplayApplicationInformation()
{  cout << "Welcome to your first Object Oriented Program--Employee Class" << endl
		<< "CIS247C, Week 4 Lab" << endl
		<< "Name: Jim P <admin@jimpoulakos.com" << endl << endl;
}
/*
	@method:	DisplayDivider
	@params:	<string> message
	@return:	<void> This function does not return a value.
	@notes:		This method displays a simple divider with the passed value in the center
*/
void DisplayDivider( string message )
{cout << "\n*************** " + message + " *********************\n";}

/*
	@method:	GetInput
	@params:	<string> message
	@return:	<string> This function returns user input.
*/
string GetInput( string message )
{
	string mystring;
	cout << "Please enter your " << message;
	getline( cin, mystring );
	return mystring;
}

/*
	@method:	TerminateApplication
	@return:	<void> This function does not return a value.
	@notes:		This function is called at the end of the application.
*/
void TerminateApplication()
{ cout << "\nThe end of the CIS247C Week3 iLab.\n"; }

int main() 
{
	/*	NOTE	::	Instantiate initial <Employee>	*/
	/*	NOTE	::	Propagate with user input	*/
	Employee employee1;
	char gender;
	string str;
	
	/*	NOTE	::	Basic information display for the user.	*/
	DisplayApplicationInformation();
	
	DisplayDivider("Employee 1");
	
	/*	NOTE	::	Get user input in this section	*/
	employee1.setFirstName(GetInput("First Name "));
	employee1.setLastName(GetInput("Last Name "));
	str = GetInput("Gender ");
	gender = str.at(0);
	employee1.setGender(gender);
	employee1.setDependents( atoi( GetInput( "Dependents " ).c_str() ) ); 
	employee1.setAnnualSalary( atof( GetInput( "Annual Salary " ).c_str() ) );
	employee1.benefit.setHealthInsurance( GetInput( "Health Insurance " ) );
	employee1.benefit.setLifeInsurance ( GetInput ( "Life Insurance " ) );
	employee1.benefit.setVacation( atoi( GetInput ( "Vacation " ).c_str() ) ); 	
	employee1.displayEmployee();
	employee1.benefit.displayBenefits();
	
	DisplayDivider( "Number of Employee Object Created" );
	cout << "\nNumber of employees: " << Employee::getNumberEmployees();
	endl(cout); endl(cout);
	
	/*	NOTE	::	Create second <Employee> object programatically for testing purposes	*/
	DisplayDivider("Employee 2");
	Employee employee2("Mary", "Noia", 'F', 2, 150000);
	Benefit benefit1 = Benefit( "Humana", "Northwestern Mutual", 14 );
	employee2.benefit = benefit1;
	employee2.displayEmployee();
	employee2.benefit.displayBenefits();
	
	DisplayDivider("Employee Summary");
	DisplayDivider( "Number of Employee Object Created" );
	cout << "\nNumber of employees: " << Employee::getNumberEmployees();
	endl(cout); endl(cout);
	
	/*	NOTE	::	Application termination function	*/
	TerminateApplication();
}