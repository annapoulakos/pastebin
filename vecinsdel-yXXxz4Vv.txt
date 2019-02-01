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

class vector_wrapper
{
private:
	vector<int> m_vData;
	
public:
	vector_wrapper(){}
	
	void push_back(const int n) { m_vData.push_back(n); }
	void const display(void)
	{
		printf("{");
		for(vector<int>::iterator it = m_vData.begin();
			it != m_vData.end();
			++it)
		{
			printf(" %d", *it);
		}
		printf(" }\n");
	}
	void erase(const int n)
	{
		vector<int>::iterator found = m_vData.end();
		for(vector<int>::iterator it = m_vData.begin();
			it != m_vData.end();
			++it)
		{
			if(n == *it) found = it;
		}
		if(found == m_vData.end())
			printf("Value not found in list.\n\n");
		else
			m_vData.erase(found);
	}
};

void Run(void)
{
	vector_wrapper myVector;
	printf("Please enter the numbers you wish to use: \n");
	for(int i=0;i<10;++i) 
	{
		int j;
		scanf("%d", &j);
		myVector.push_back(j);
	}
	printf("Contents of the vector: \n");
	myVector.display();
	
	int n;
	printf("Please enter a number to erase from the vector: ");scanf("%d", &n);
	myVector.erase(n);
	printf("Contents of the vector: \n");
	myVector.display();
}
