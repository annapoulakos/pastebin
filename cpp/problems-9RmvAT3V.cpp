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

class Function
{
private: 
	double m_x;
	
public:
	Function(double _):m_x(_) {}
	
	double y() { return (pow(m_x,4) - 3*m_x); }
	double x() { return m_x; }
};


void force_larger(double &a, double &b)
{
	if (b>a) return;
	a-=b;b+=a;a=b-a;
}

void Run(void)
{
	double mn, mx;
	printf("Enter the min and max values: ");scanf("%lf %lf", &mn, &mx);
	int points;
	printf("Enter the number of points: ");scanf("%d", &points);
	
	vector<Function> funcs;
	for(int i=0; i<points; ++i) { 
		double diff = mx - mn + 1;
		double dist = diff/points;
		double x = mn + i*dist; 
		Function f(x); 
		funcs.push_back(f); }
	
	for(vector<Function>::iterator it = funcs.begin();
		it != funcs.end();
		++it)
	{
		printf("(x = %.4f, y = %.4f)\n", (*it).x(), (*it).y());
	}
}