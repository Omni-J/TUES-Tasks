
// Not completed 

#include <iostream>
using namespace std;

class  Point {
	double x_, y_;
public:

	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
	{}
	
	double get_x() const {
		return x_;
	}
	
	double get_y() const {
		return y_;
	}
	
	void print() const {
		cout << "(" << x_ << ", " << y_ << ")" << endl;
	}
	
	Point& operator+=(const Point& p){
		x_+=p.x_;
		y_+=p.x_;
		return *this;
	}
	Point& operator-=(const Point& p){
		x_-=p.x_;
		y_-=p.x_;
		return *this;
	}
};

Point operator+(const Point& p1, const Point& p2){
	Point res(p1.get_x()), p1.get_y());
	res+=p2;
	return res;
}

Point operator-(const Point& p1, const Point& p2){
	Point res(p1.get_x()), p1.get_y());
	res-=p2;
	return res;
}

Point operator-(const Point p){
	Point res(-p.get_x(), -p.get_y())
	return res;
}

ostream&  operator<<(ostream& out, const Point& p){

	out << '(' << p.get_x() << ', ' << p.get_y() << ')';
	return out;
}

int main(){
	Point p1(1,1), p2(2,2);
	p1.print();
	p2.print();
	
	p1+=p2;
	// p1.operato+=(p2);
	p1.print();
	
	p1-=p2;
	p1.print();
	
// ^^^^ Much to write above from class

	((cout << p) << p1) << p2 << endl;	
		
	
	
	return 0; 
}
