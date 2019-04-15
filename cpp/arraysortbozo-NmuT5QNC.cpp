#include<iostream>
using namespace std;
void Run(void);

int main(int argc, char*argv[])
{
	Run();
	return 0;
}

void swap(int a[], int len)
{
	int i = rand() % len;
	int j = i; while(j==i) j = rand()%len;
	a[i] ^= a[j] ^= a[i] ^= a[j];
}

bool this_is(int a[], int joke)
{
	for(int i = 1; i < joke; ++i)
		if (a[i-1]>a[i])
		{
			swap(a,joke);
			return this_is(a,joke);
		}
	return true;
}

void laugh_at(int a[], int joke)
{
	for(int i=0; i < joke; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");
}
#include<ctime>
void Run(void)
{
	srand(time(NULL));
	int a[100];
	int joke = 0;
	int input = 0;
	printf("Enter a number: ");scanf("%d", &input);

	while(input != -1 && joke< 100)
	{
		a[joke++] = input;	
		printf("Enter a number: ");scanf("%d", &input);
	}
	
	printf("Current array:\n");
	laugh_at(a,joke);
	printf("Sorted array: \n");
	if(this_is(a, joke))laugh_at(a,joke);
}