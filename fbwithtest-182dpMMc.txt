#include<iostream>
using namespace std;

#include<cmath>
#include<ctime>
#include<cstdio>

void (*f_ptr)(int) = NULL;
void with_switch(int iter)
{
	for(int i=1, c=0;i<=iter;++i, ++c)
	{
		switch(++c)
		{
			case 3: case 6: case 9: case 12:
				printf("Fizz\t\t"); break;
			case 5: case 10:
				printf("Buzz\t\t"); break;
			case 15: printf("FizzBuzz\t");c=0;break;
			default: printf("%d\t\t",i);break;
		}
	}
}
void with_mod(int iter)
{
	for(int i=1;i<=iter;++i)
	{
		if(!(i%3)&&!(i%5)) printf("FizzBuzz\t");
		else if(!(i%3)) printf("Fizz\t\t");
		else if (!(i%5)) printf("Buzz\t\t");
		else printf("%d\t\t",i);
	}
}

double test(int iter, void (*f_ptr)(int))
{
	clock_t start,end;
	double ret = 0.0;
	
	for(int i = 0; i<5; ++i)
	{
		start=clock();
		f_ptr(iter);
		end = clock();
		ret += end-start;
	}

	return (ret/5);
}

void main_test(int iter)
{
	double timer, timer2;

	timer = test(iter, &with_switch);
	timer2 = test(iter, &with_mod);
	printf("Sample Size: %d\n", iter);
	printf("Switch: %0.2f\n",timer);
	printf("Modulo: %0.2f\n\n",timer2);
	system("pause");
}

int main(int argc, char*argv[])
{
	main_test(100);
	main_test(500);
	main_test(1000);
	main_test(5000);
	main_test(10000);
	
	return 0;
}
