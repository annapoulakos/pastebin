#include<iostream>
using namespace std;

struct measurement_t
{
public:
	measurement_t(const float &x, const float &y):h(x),w(y){}
	measurement_t(const measurement_t &m): h(m.h), w(m.w){}
	measurement_t() {h =0; w=0;}
	float h, w;
	float get_area() const{return h*w;}
};

class rectangle
{
private:
	measurement_t m_measurements;
	
public:
	rectangle(const float& h, const float& w):m_measurements(h,w){}
	float difference(const rectangle &other) const {return get_area()-other.get_area();}
	float get_area() const{return m_measurements.get_area();}
	measurement_t get_measurements() { return m_measurements; }
};

class yard
{
private:
	rectangle inner;
	rectangle outer;
	float rate;
	
public:
	yard(const rectangle&h, const rectangle&y):inner(h), outer(y){ force_smaller(); rate = 2.0; }
	float time_to_cut() const { return outer.difference(inner) / yard::rate; }
	void force_smaller() { if (outer.difference(inner) < 0) {rectangle t = outer; outer = inner; inner = t; }}
};

rectangle get_new_rectangle()
{
	float w;
	printf("Enter a width: ");scanf("%f",&w);
	float h;
	printf("Enter a height: ");scanf("%f",&h);
	return rectangle(h,w);
}
int main(int argc,char*argv[])
{
	rectangle (*get_house)(void) = NULL;
	rectangle (*get_yard)(void) = NULL;
	get_house = &get_new_rectangle; get_yard = &get_new_rectangle;
	
	
	yard y(get_house(),get_yard());
	
	printf("It will take %0.2f seconds to mow this lawn.", y.time_to_cut());
}