
namespace elsys {

	class Student {
	
	};
	
	class Teacher {
	
	};
	
};	

namespace tues {

	class Student {
	
	};
	
	class Teacher {
	
	};
};

int main(){
	// 1st way of defining objects from namespaces
	elsys::Teacher t1;
	tues::Teacher t2;
	
	using elsys::Student; //Only including Student from elsys
	Student stl;
	// Teacher t3 Not working
	
	//using tues::Student Compile error or override
	
	using namespace std;
	using namespace elsys;
	
	
	return 0;
}
