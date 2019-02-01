#include<iostream>
#include<iterator>
using namespace std;
#define a(b,_,d)\
	_ d=b;\

a(10,int,z);
int f= 0x6425;
int main(int argc, char*argv[])
{
	int*_ = new int[z];
	int* ptr = _;

	istream_iterator<int>it(cin);

	int i=1;
	do { *_++=*it++; }while(++i <z);
	
	_= ptr;
	for(;*_++;)
	{
		printf((char*)&f,*_);printf("\n");
	}
	
	return 0;
}