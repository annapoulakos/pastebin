/******************************************************************
 * Course:  CIS247C
 * Week: 3
 * Programmer:  Prof.Nana Liu
 * Date: 07/21/2011
 * 
 * Class Name:  Employee
 * Class Description:
 * The employee class implements the following UML class diagram:
 		---------------------------------------
       	Employee 
        ---------------------------------------
        -firstName:				string
        -lastName:				string
        -gender:				char
        -dependents				int
        -annualSalary			double
        -static numEmployees	int
        ---------------------------------------
        +Employee()
        +calculatePay()					double
        +static getNumberEmployees		int
        +displayEmployee()				void
        +getFirstName()					string
        +setFirstName(in name: string)	void
        +getLastName()					string
        +setLastName(in name: string)	void
        +getGender():					char
        +setGender(in gen: char)		void
        +getDependents()				int
        +setDependents(in dep: int)		void
        +setDependents(in dep: string)	void
        getAnnualSalary()				double
        setAnnualSalary(in sal: double)	void
        setAnnualSalary(in sal: string) void
        ---------------------------------------
***********************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <iomanip>

using namespace std;

	const double MIN_SALARY = 50000;
	const double MAX_SALARY = 250000;
	const int MAX_DEPENDENTS = 10;
	const int MIN_DEPENDENTS = 0;
	const char DEFAULT_GENDER = 'N'; //N stands for not identified
	const int NUMBER_WEEKS = 52;
	const int MAX_VACATION = 52;
	const int MIN_VACATION = 0;

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


class Benefit
{
string healthInsurance;
string lifeInsurance;
int vacation;

public:

Benefit()
{
	healthInsurance = "";
	lifeInsurance = "";
	vacation = 0;
}

Benefit( string healthInsurance, string lifeInsurance, int vacation )
{
	this->healthInsurance = healthInsurance;
	this->lifeInsurance = lifeInsurance;
	this->vacation = vacation;
}

string getHealthInsurance()
{	
	return healthInsurance;
}

void setHealthInsurance (string Health)
{
	healthInsurance = Health;
}

string getLifeInsurance()
{
	return lifeInsurance;
}

void setLifeInsurance (string Life)
{
	lifeInsurance = Life;
}

int getVacation()
{
	return vacation;
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
	vacation = vac;
}
	else if (vac < MIN_VACATION)
	{
		vacacation = MIN_VACATION;
	}
	else
	{	
		vacation = MAX_VACATION;
	}
}

void displayBenefits()
{
	cout <<"Benefit Information\n";
cout <<"_______________________________________________________________________________________________ \n";
	cout << "Health Insurance: \t\t" <<healthInsurance << "\n";
	cout << "Life Insurance: \t\t" <<lifeInsurance << "\n";
	cout << "Vacation: \t\t" <<vacation << "\n";
}

};

class Employee: public iEmployee
{	//declare static variable accessible, which is accessible by all objects of the class
    static int numEmployees;
		
   	string firstName;
	string lastName;
	char gender;
	int dependents;
	double annualSalary; 

    public:
	Benefit benefit;
	
	Employee()//default constructor
	{
		firstName = "";
		lastName = "";
		gender = 'N';
		dependents = 0;
		annualSalary = 50000;
		//each time a constructor is called, increment the the class level numEmployees variable
		this->numEmployees += 1;
	}
	//create a parameterized construct, not required and shown only for demonstration
	Employee(string firstName, string lastName, char gender, int dependents, double salary)
	{
		//use the THIS keyword to distinguish between the class attributes and the parameters
		this->firstName = firstName;
		this->lastName = lastName;
		this->gender = this->setGender(gender);
		this->dependents = dependents;
		this->annualSalary = salary;
		//each time a constructor is called, increment the the class level numEmployees variable
		this->numEmployees += 1;
	}  
	
	//a static method that returns the number of employee object that are created
	static int getNumberEmployees()
	{
		return numEmployees;
	}

	//Accessors and mutators, one for each class attribute
	
	/*
		@method:	getFirstName()
		@params:	<void>
		@return:	<string> Returns this->firstName;
	*/
	string getFirstName()
	{
		return firstName;
	}
	void setFirstName(string name)
	{
		firstName = name;
	}
	string getLastName()
	{
		return lastName;
	}
	void setLastName(string name)
	{
		lastName = name;
	}
	char getGender()
	{
		return gender;
	}
	void setGender(char gen)
	{
		switch (gen)
		{
		case 'f':case 'F': case 'M':case 'm':
				gender = gen;
				break;
			default:
				gender = DEFAULT_GENDER;
		}
	}
	int getDependents()
	{
		return dependents;
	}
	void setDependents(int dep)
	{
		if (dep >= MIN_DEPENDENTS && dep <= MAX_DEPENDENTS)
		{
			dependents = dep;
		}
		else if (dep < MIN_DEPENDENTS)
		{
			dependents = MIN_DEPENDENTS;
		}
		else
		{
			dependents = MAX_DEPENDENTS;
		}
	}
	double getAnnualSalary()
	{
		return annualSalary;
	}
	void setAnnualSalary(double salary)
	{
		if (salary >= MIN_SALARY && salary <= MAX_SALARY)
		{
			annualSalary = salary;
		}
		else if (salary < MIN_SALARY)
		{
			annualSalary = MIN_SALARY;
		}
		else
		{
			annualSalary = MAX_SALARY;
		}
	}
	double calculatePay()
	{
		return annualSalary/NUMBER_WEEKS;
	}
	void displayEmployee()
	{
		cout<<"Employee Information\n";
		cout<<"____________________________________________________________\n";
		cout<<"Name: \t\t" <<firstName << " " << lastName << "\n";
		cout<<"Gender:\t\t" << gender << "\n";
		cout<<"Dependents: \t" << dependents << "\n";
		cout<<"Annual Salary:\t" << setprecision(2)<<showpoint<<fixed<<annualSalary << "\n";
		cout<<"Weekly Salary:\t" << setprecision(2)<<showpoint<<fixed<<calculatePay()<<"\n";
				
	}
};


int Employee::numEmployees=0;//supply initial value to static data members

     /****************************************************************
	 * Description: Employee test main()
	 * 
	 * This program tests the Employee class by creating an object
	 * of the class and performing the following operations:
	 * 
	 * 1. Create an Employee object using the default constructor. 
	 * 2. Prompt for and then set the first name, last name, gender, dependents, and annual salary.  (Remember that you have to convert gender, dependents, and annual salary from strings to the appropriate data type.) 
	 * 3. Display the employee information. 
	 * 4. CalculatePay to determine the weekly pay and store the returned value in pay. 
	 * 5. Create a second Employee object using the default constructor, setting each of the attributes with appropriate valid values
	 * 
	 * Programmer: Prof.Nana Liu
	 * Course:  CIS247C
	 * Week 3 Lab Assignment
	 * Date: 07/21/2011
	 * ****************************************************************/

void DisplayApplicationInformation()
{  cout<<"Welcome to your first Object Oriented Program--Employee Class"
       <<"CIS247C, Week 3 Lab"
       <<"Name: Prof.Nana Liu";       
}

void DisplayDivider(string message)
{cout<<"\n*************** " + message + " *********************\n";}

string GetInput( string message)
{ string mystring;
  cout<<"Please enter your "<<message;
  getline(cin, mystring);
  return mystring;
}

void TerminateApplication()
{ cout<<"\nThe end of the CIS247C Week3 iLab.\n";}

	int main() 
	{
		//create two employee objects
		Employee employee1;  //declare and instantiate the object variable
		char gender;
		string str;
		
		//always provide some type of application information to the user--don't leave them cold!
		DisplayApplicationInformation();
		
		//use a utility method to keep a consistent format to the output
		DisplayDivider("Employee 1");
		
		//access the employee objects members using the DOT notation
		employee1.setFirstName(GetInput("First Name "));
		employee1.setLastName(GetInput("Last Name "));
		
		str = GetInput("Gender ");
		gender = str.at(0);
		employee1.setGender(gender);  
		
		employee1.setDependents(atoi( GetInput("Dependents ").c_str())); 
		employee1.setAnnualSalary(atof(GetInput("Annual Salary ").c_str()));
		employee1.benefit.setHealthInsurance(GetInput("Health Insurance "));
		employee1.benefit.setLifeInsurance (GetInput ("Life Insurance "));
		employee1.benefit.setVacation (atoi(GetInput ("Vacation ").c_str())); 	
		employee1.displayEmployee();
		employee1.benefit.displayBenefits();

		//use the Class level static method to display the number of employees
		cout<<"--- Number of Employee Object Created ----";
		cout<<"\nNumber of employees: " << Employee::getNumberEmployees();
		
		DisplayDivider("Employee 2");
		//create a second employee object this time use the default constructor
		Employee employee2("Mary", "Noia", 'F', 2, 150000);
		
		// TODO: Add benefit information
		Benefit benefit1 = Benefit( "Humana", "Northwestern Mutual", 14 );
		employee2.benefit = benefit1;
		
		employee2.displayEmployee();
		employee2.benefit.displayBenefits();

		DisplayDivider("Employee Summary");
		cout<<"\n--- Number of Employee Object Created ----";
		cout<<"\nNumber of employees: " <<Employee::getNumberEmployees();
		
		TerminateApplication();
		
		
	}