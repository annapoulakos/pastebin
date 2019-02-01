#include<iostream>
using namespace std;

int main(int argc, char*argv[])
{
	for(int i=1,c=1;i<=100;++i,++c)
	{
		switch(c)
		{
			case 3: case 6: case 9: case 12:
				printf("Fizz\t\t"); break;
			case 5: case 10:
				printf("Buzz\t\t"); break;
			case 15: printf("FizzBuzz\t");c=0;break;
			default: printf("%d\t\t",i);break;
		}
		
	}
	return 0;
}