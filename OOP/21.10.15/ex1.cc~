#include <iostream>
using namespace std;


class Point {
	double x_,y_;
public:
	Point(double x,double y){
		x_ = x;
		y_ = y;
	}
	double get_x() const{
		return x_;
	}
	double get_y() const{
		return y_;
	}
	void set_x(double x){
		x_ = x;
	}
	void set_y(double y){
		y_ = y;
	}
	
	void print() const{
		cout << '(' << x_ << ',' << y_ << ')' << endl;
	}
};
int main(){
	const double pi = 3.14;
	cout << "pi=" << pi << endl;

	Point p1(1,2);
	p1.set_x(420.69);
	const Point Origin(0,0);
	//Origin.set_x(5.0);
	p1.print();
	Origin.print();
	

	return 0;
}
