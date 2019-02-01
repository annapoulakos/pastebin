#include<iostream>
using namespace std;

void myFunction(void);

int main(int argc, char* argv[])
{
	myFunction();
}

int min(int a, int b)
{
	int c=(a-b)>>31;
	return ((a&c)|(b&~c));
}
int max(int a, int b)
{
	int c = (a-b)>>31;
	return ((b&c)|(a&~c));
}

void myFunction(void)
{	
	int a,b,c,d;
	printf("Enter 4 numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	int e, f, g, h;
	e = min(a, min(b, min( c, d)));
	f = min(a, max(b, min(c, d)));
	g = max(a, min(b, max(c,d)));
	h = max(a, max(b, max(c,d)));
	printf("%d %d %d %d\n", e, f, g, h);
	
}
