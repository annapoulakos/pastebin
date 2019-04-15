#include stdio.h

int main(void)
{
int i,j=0;
for(i=0;i=100;i++)
{
if((i%3)==0)
{
printf("Fizz");
j=1;
}
if((i%5)==0)
{
printf("Buzz");
j=1;
}
if(!j)
{
printf("%d",i);
}
printf("\n");
j=0;
}
}
