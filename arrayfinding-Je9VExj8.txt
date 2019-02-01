#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
class Array
{
private:
	vector<T> my_values;
	void constructor_insert(T i) { my_values.push_back(i); }
	
public:
	Array(const vector<T>& nVec):my_values(nVec){}
	Array() {}
	
	void Add(T i) { my_values.push_back(i); }
	void find_all(T i)
	{
		vector<T> ret;
		for(vector<T>::size_type it = 0;
			it < my_values.size();
			++it)
		{
			if( my_values[it] == i ) ret.push_back(it);
		}
		
		if(ret.size()==0) {printf("The number you are looking for was not found.\n\n");return;}
		
		for(vector<T>::iterator it = ret.begin();
			it != ret.end();
			it++)
		{
			printf("Number %d found at position %d.\n", i, *it);
		}
	}
	void display_all()
	{
		printf("The numbers you entered are ");
		for(vector<T>::iterator it=my_values.begin();
			it != my_values.end();
			++it)
		{
			printf("%d ", *it);
		}
		printf("\n\n");
	}
};

int main(int argc, char*argv[])
{
	int elem;
	printf("Enter number of elements: ");scanf("%d", &elem);
	int i = elem;
	Array<int> my_array;
	while(i-->0)
	{
		printf("Input a number for the array: ");scanf("%d",&elem);
		my_array.Add(elem);
	}
	
	my_array.display_all();
	
	printf("Enter a number to search for ");scanf("%d", &elem);
	my_array.find_all(elem);
}