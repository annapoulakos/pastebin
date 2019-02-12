#include<iostream>
using namespace std;
void Run(void);

int main(int argc, char*argv[])
{
	Run();
	return 0;
}

#include<vector>
#include<algorithm>
struct Comparator { bool operator() (int i, int j) { return (i<j); } } myComparer;
void Display(vector<int> v)
{
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		printf("%d ", *it);
		
	printf("\n\n");
}
void Run(void)
{
	int n;
	vector<int> v;
	printf("Array sorting. Enter -1 to quit\n\n");
	printf("Enter a number: "); scanf("%d", &n);
	while(n != -1)
	{
		v.push_back(n);
		printf("Enter a number: "); scanf("%d", &n);
	}
	
	printf("Current array: \n");
	Display(v);
	
	sort(v.begin(), v.end(), myComparer);
	printf("Sorted array:\n");
	Display(v);	
}
