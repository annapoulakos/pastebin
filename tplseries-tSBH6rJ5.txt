#include<iostream>
using namespace std;

template<int N>
struct Series {enum{value=N+Series<N-1>::value};};
template<>
struct Series<1>{enum{value=1};};
template<>
struct Series<0>{enum{value=0};};

int main(int argc, char*argv[])
{
	int x = Series<10>::value;
	printf("Series value: %d", x);
}