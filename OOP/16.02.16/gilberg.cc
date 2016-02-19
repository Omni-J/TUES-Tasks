#include <iostream>
using namespace std;

class HibertCurve : public Shape {

int height_, level_;

public:

  HilbertCurve(int height=10, int level=1) : height_(height), level_(level)
  {}

  void draw(){
    a(level_, height_);
  }

  void a(int i, int h) {

	if(i<=0) {
		return;
	}
	d(i-1, h);
	cout << '-' << h << ' ' << 0 << ' ' << "rlineto" << endl;
	a(i-1, h);
	cout << 0 << ' ' << '-' << h << ' ' << "rlineto" << endl;
	a(i-1, h);
	cout << h << ' ' << 0 << ' ' << "rlineto" << endl;
	b(i-1, h);

}

void b(int i, int h) {
	if(i<=0) {
		return;
	}
	c(i-1, h);
	cout << 0 << ' ' << h << ' ' << "rlineto" << endl;
	b(i-1, h);
	cout << h << ' ' << 0 << ' ' << "rlineto" << endl;
	b(i-1, h);
	cout << 0 << ' ' << '-' << h << ' ' << "rlineto" << endl;
	a(i-1, h);
}

void c(int i, int h) {
	if(i<=0) {
		return;
	}
	b(i-1, h);
	cout << h << ' ' << 0 << ' ' << "rlineto" << endl;
	c(i-1, h);
	cout << 0 << ' ' << h << ' ' << "rlineto" << endl;
	c(i-1, h);
	cout << '-' << h << ' ' << 0 << ' ' << "rlineto" << endl;
	d(i-1, h);
}

void d(int i, int h) {
	if(i<=0) {
		return;
	}
	a(i-1, h);
	cout << 0 << ' ' << '-' << h << ' ' << "rlineto" << endl;
	d(i-1, h);
	cout << '-' << h << ' ' << 0 << ' ' << "rlineto" << endl;
	d(i-1, h);
	cout << 0 << ' ' << h << ' ' << "rlineto" << endl;
	c(i-1, h);
}
};


int main() {
	cout << "newpath" << endl;
	int h = 512;
	int x0 = 64 + h/2;
	int y0 = 64 + h/2;
	for(int i = 1; i<6; ++i) {
	  h /=2;
	  x0 += h/2;
	  y0 += h/2;
	  cout << x0 << " " << y0 << " moveto" << endl;
	  a(i, h);
	  // cout << i << " setlinewidth" << endl;
	  cout << "stroke" << endl;
	}
	cout << "showpage" << endl;

	return 0;
}
