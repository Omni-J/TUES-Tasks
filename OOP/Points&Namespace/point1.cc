#include <iostream>

using namespace std;

class Point {
	double _x;
	double _y;
	
public:
	void set_x(double val) {
		_x = x;
	}
	
	void set_y(double val) {
		_y = y;
	}

	void get_x() {
		return _x;
	}
	
	void get_y() {
		return _y;
	}
};

int main() {
	Point p1;
	
	p1.set_x(5.0);
	
	return 0;
}

