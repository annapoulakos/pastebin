#include<iostream>
using namespace std;
char *cities[] = {"Los Angeles", "San Diego", "Oakland" };
char *activities[] = {"making a new appointment", "rescheduling an appointment", "billing questions", "talking to a nurse"};

int get_choice(int _c, char*_t, char*_o[])
{
	int ret;
	while(true)
	{
		printf("Please enter a%s from the following options:\n",_t);
		for(int i=0; i<_c;++i)
			printf("%d) %s\n",i+1,_o[i]);
		scanf("%d",&ret);
		if(ret>0&&ret<=_c)return ret-1;
	}
}

int main(int argc, char*argv[])
{
	char* c = cities[get_choice(3," location",cities)];
	char* a = activities[get_choice(4,"n activity",activities)];
	printf("%s: %s\n\n",c,a);
	return 0;
}