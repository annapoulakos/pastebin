#include<iostream>
using namespace std;
void Run(void);

int main(int argc, char*argv[])
{
	Run();
	return 0;
}

#define a(b,c,d)b c d{return x-((x-y)&(x-y)>>31);}
a(int,_,(int x, int y));

void Run(void)
{
	int n1, n2;
	printf("Enter two numbers: ");scanf("%d %d", &n1, &n2);
	printf("\nThe larger number is: %d\n\n",_(n1,n2));
}
