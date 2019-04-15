#include<iostream>
using namespace std;
char* sizes[] = { "2x6x4", "2x10x4", "6x8x8", "10x12x4", "14x16x2", "18x20x6" };
bool get_shipping(char* i[])
{
	printf("Would you like 3-Day or Overnight shipping? (type exactly 3-Day or Overnight) ");scanf("%s", i);
	return (*i=="3-Day"||*i=="Overnight")?true:false;
}
bool get_boxes(char*c)
{
	cin.ignore(256,'\n');
	printf("Please choose from one of the following box sizes:\n\n");
	for(int i=1;i<6;i++)
		printf("%c - %s\n", i+64, sizes[i]);
	scanf("%c", c);
	if(*c >71) *c -=32;
	return (*c>64&&*c<71)?false:true;
}
bool get_qty(int *b,char*c)
{
	cin.ignore(256,'\n');
	printf("How many %s boxes would you like?", sizes[*c-65]);scanf("%d", b);
	return (*b<0)?true:false;
}
int main(int argc, char*argv[])
{
	float cost[6] = {4.45, 4.95, 6.35, 7.15, 8.05, 9.65};
	int b;char* i[32];char* c = new char;	
	while(get_shipping(i));while(get_boxes(c));while(get_qty(&b,c));
	printf("%s shipping charges\n", i);
	printf("$%0.2f for %d boxes of size %s", b * cost[*c-65], b, sizes[*c-65]);
}