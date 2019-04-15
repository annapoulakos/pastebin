/******************************************************************
 * Course:  CIS247C
 * Week: 3
 * Programmer:  Clint Thomas
 * Date: 09/21/2012
*******************************************************************/

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

class Employee 
{
   	string firstName;
	string lastName;
	char gender;
	int dependents;
	double annualSalary; 
	static int count;
		
    public:

	static int numEmployees()
	{
		return count;
	}
	
	Employee()//default constructor
	{
		firstName = "";
		lastName = "";
		// These three values should be set to the defined constants in case they change in a future revision.
		gender = DEFAULT_GENDER;
		dependents = MIN_DEPENDENTS;
		annualSalary = MIN_SALARY;
		count++;
	}

	Employee(string firstName, string lastName, char gender, int dependents, double salary)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		// Setting these with the accessor set methods is more appropriate
		// By doing so, we can guarantee that the values are within the correct bounds.
		this->setGender(gender);
		this->setDependents(dependents);
		this->setAnnualSalary(salary);
		count++;
	}
	//Accessors and mutators, one for each class attribute
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
	
	// setDependents overloaded function
	// @method:		+setDependents(string dep) : void
	// @param:		<string> dep -> The string we are using to set the number of dependents.
	// @return:		<void> -> This function should not return a value.
	void setDependents(string dep)
	{
		int newDep;
		newDep = atoi(dep.c_str());
		
		this->setDependents(newDep);
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
		cout<<"Weekly Salary:\t" << setprecision(2)<<showpoint<<fixed<<calculatePay();
				
	}
};




void DisplayApplicationInformation()
{  cout<<"Welcome to your first Object Oriented Program--Employee Class"
       <<"CIS247C, Week 2 Lab"
       <<"Name: Clint Thomas";       
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
{ cout<<"\nThe end of the CIS247C Week2 iLab.\n";}

int Employee::count =0;

	int main() 
	{
	
		//create two employee objects
		Employee employee1;  //declare and instantiate the object variable
		char gender;
		string str;
		
		DisplayApplicationInformation();
		
		//use a utility method to keep a consistent format to the output
		DisplayDivider("Employee 1");
		
		//access the employee objects members using the DOT notation
		employee1.setFirstName(GetInput("First Name "));
		employee1.setLastName(GetInput("Last Name "));
		
		str = GetInput("Gender ");
		gender = str.at(0);
		employee1.setGender(gender);  
		
		employee1.setDependents(GetInput("Dependents ")); 
		employee1.setAnnualSalary(atof(GetInput("Annual Salary ").c_str()));  		
		employee1.displayEmployee();
		
		DisplayDivider("Employee 2");
		//create a second employee object this time use the default constructor
		Employee employee2("Mary", "Noia", 'F', -2, 150000);
		employee2.displayEmployee();
		cout << endl;
		cout << "The total number of employees is " << Employee::numEmployees() <<endl<<endl;
        TerminateApplication();

//		cin.ignore().get();
		return 0;
	
	
		
	}