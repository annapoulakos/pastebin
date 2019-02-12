#include<iostream>
using namespace std;

int main(int argc, char*argv[])
{	
	for(int i=1;i<=100;++i)
	{
		if(!(i%3)&&!(i%5)) printf("FizzBuzz\t");
		else if(!(i%3)) printf("Fizz\t\t");
		else if (!(i%5)) printf("Buzz\t\t");
		else printf("%d\t\t",i);
	}
	return 0;
}
