#include<iostream>
using namespace std;
void Run(void);

int main(int argc, char*argv[])
{
	Run();
	return 0;
}

namespace Electric_Company
{ 
	const float m_rate = 0.17;
	const float m_rate_low = 0.10;
	const float m_surcharge = 0.10;
	const float m_differential = 250.0;
	
	float get_hourly_rate(float hours)
	{
		if(hours < Electric_Company::m_differential) return hours * Electric_Company::m_rate_low;
		
		float charge = Electric_Company::m_differential * Electric_Company::m_rate_low;
		hours -= Electric_Company::m_differential;
		charge += hours * Electric_Company::m_rate;
		
		return charge;
	}
	
	float get_total_charges(float hours)
	{
		float charge = get_hourly_rate(hours);
		float surcharge = charge * Electric_Company::m_surcharge;
		
		return charge + surcharge;
	}
}

void Run(void)
{
	float hrs;
	printf("Enter number of kilowatt hours: "); scanf("%f", &hrs);
	
	printf("Price for %.2f kilowatt hours = %.2f\n\n", hrs, Electric_Company::get_total_charges(hrs));
}
