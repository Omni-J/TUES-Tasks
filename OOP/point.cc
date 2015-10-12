#include <iostream>

using namespace std;

struct Point {
	double _x;
	double _y;
	
	double get_x() {
		return _x;
	}
	
	double get_y() {
		return _y;
	}
};

int main() {
	
	Point p1;
	p1._x = 1.0;
	p1._y = 2.0;
	
	cout << p1.get_x() << endl;
	cout << p1.get_y() << endl;
	
	return 0;
}
