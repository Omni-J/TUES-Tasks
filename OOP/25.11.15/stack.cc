#include <cstdlib>
using namespace std;

class Static{
	int array_[20];
	int number_;
public:
	Static(int i=10){
		number_ = i;
	}
};

int main(){
	Static* s1 = new Static(20);
	Static* s_array = new Static[20];
	return 0;
}
