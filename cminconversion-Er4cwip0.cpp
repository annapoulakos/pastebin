#include<iostream>
using namespace std;
#define a(b,c,d)b nn(b c,b d){return c%d;}b rn(b c, b d){return c/d;}
a(int, x,y);
int main(int argc,char*argv[])
{
	int m;
	printf("Enter centimeters: ");scanf("%d", &m);
	m = m*0.393700787;
	printf("Yards: %d, Feet: %d, Inches: %d",rn(rn(m,12),3),nn(rn(m,12),3),nn(m,12));
}