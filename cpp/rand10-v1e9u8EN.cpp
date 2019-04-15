#include<iostream>
#include<ctime>
using namespace std;
void f(int&x){x=rand()%10+1;}
int main(int argc,char*argv[])
{
	srand(time(NULL));
	int i=10,x=0,y=0;
	for(;i-->0;)
	{f(x);f(y);printf("#%d: (%d, %d) : sum(%d) : %s\n", 10-i, x,y, x+y, (x>y)?"Greater":"Less than or equal");
	}
}