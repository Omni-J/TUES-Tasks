#include <iostream>
using namespace std;

class Point {
	double x_,y_;
	
public:
/*	Point()
	: x_(0.0), y_(0.0)
	{}
*/	
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
	{}
	
	double get_x() const {
		return x_;
	}
	double get_y() const {
		return y_;
	}
	void print() const{
		cout << '(' << x_ << ',' << y_ << ')' << endl;
	}
};

void foo(int bar){
	cout << "foo(bar=" << bar << ')' << endl;
}
void foo(double bar){
	cout << "foo(bar=" << bar << ')' << endl;
}
void foo(int bar1,int bar2){
	cout << "foo(bar1=" << bar1 <<",bar2=" << bar2 << ')' << endl;
}
void bar(int foo1,int foo2=0){
	cout << "bar(foo1=" << foo1 << ", " << "foo2=" << foo2 << ')' << endl;
}
int main(){
	const Point origin(4.0,5.0);
	origin.print();
	
	Point p1(1,1), p2;
	p1.print();
	p2.print();
	
	foo(42);
	foo(42,21);
	bar(20);
	bar(15,15);
	return 0;
}
