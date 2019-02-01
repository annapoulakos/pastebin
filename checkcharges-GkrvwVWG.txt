#include<iostream>
#include<iomanip>
using namespace std;

int main(int argc, char*argv[])
{
	// Constant definitions
	const double MONTHLY_CHARGE = 10;
	const double CHECK_10 = 0.10;
	const double CHECK_8 = 0.08;
	const double CHECK_6 = 0.06;
	const double CHECK_4 = 0.04;
	
	int num_checks;
	double check_charge, total_charges;
	
	cout << "Please enter the number of checks written in the last month.\n";
	cin >> num_checks;
	
	cout << fixed << showpoint << setprecision(2);
	
	if(num_checks < 20)
		check_charge = CHECK_10;
	else if (num_checks >=20 && num_checks <=39)
		check_charge = CHECK_8;
	else if (num_checks >=40 && num_checks <=59)
		check_charge = CHECK_6;
	else
		check_charge = CHECK_4;
		
	total_charges = (num_checks * check_charge) + MONTHLY_CHARGE;
	cout << "You have been chargd " << total_charges << " in fees. \n";
	return 0;
}
