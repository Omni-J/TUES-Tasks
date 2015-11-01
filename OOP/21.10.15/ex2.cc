#include <iostream>
using namespace std;

class Foo{
	const int bar_;
	
public:
	Foo(int bar) 
	: bar_(bar)
	{
		// bar_ = bar;
	}
	int get_bar() const {
		return bar_;
	}
	/*void set_bar (double bar){
		bar_ = bar;
	}*/
};

int main(){
	
	Foo f1(42);
	cout << f1.get_bar() << endl;
	
	const double pi = 3.14;
	return 0;
}
