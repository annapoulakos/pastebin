#include<iostream>
using namespace std;
void Run(void);

int main(int argc, char*argv[])
{
	Run();
	return 0;
}

bool is_prime(int x)
{
ip_s:  {int y; goto ip_c;}
ip_l:  {for(int i=3;i<y;++i){if(!(x%i))goto ip_ef;}goto ip_et;}
ip_c:  {if(!(x%2))goto ip_ef;y=x/2;goto ip_l;}
ip_ef: {return false;}
ip_et: {return true;}
}
void Run(void)
{
l:
	int x;
	printf("Enter an integer greater than 1: ");scanf("%d", &x);
	if(x<2) goto l;
	
	printf("%d is", x);
	if(!is_prime(x)&&x!=2)
		printf(" not");
	printf(" prime.\n\n");
	
}