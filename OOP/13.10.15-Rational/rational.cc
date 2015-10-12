#include <iostream>
using namespace std;

class RationalError{};

class Rational{
	long num_; //4islitel
	long den_; //Znamenatel
	long gcd(long a, long b){
		long r = a % b;
		while (r!=0){
			a = b;
			b = r;
			r = a % b;
	 	}
		return b;
	}
	void normalize(){
		if(num_==0){
			den_=1;
			return;
		}
		long d = gcd(num_, den_);
		num_/=d;
		den_/=d;
		if(den_<0){
			num_= - num_;
			den_= - den_;
		}
	}
public:
	Rational(long num,long den) {
		if(den==0){
			cout<<"OOOPS! zero denominator..."<<endl;
			throw RationalError();
		}
		num_= num;
		den_= den;
		normalize(); // Durji vsi4ko vuvedeno v normalna forma
	}
	void print() {
		cout<<'('<< num_<<'/'<<den_<<')'<<endl;
	}
	void add(Rational other){
		num_ = num_ * other.den_+ den_*other.num_;
		den_ = den_*other.den_;
		normalize();
	}
	void sub(Rational other){
		num_ = num_ * other.den_- den_*other.num_;
		den_ = den_*other.den_;
		normalize();
	}
	void mul(Rational other){
		num_ = num_ * other.num_; //num_*=other.num_; e sushtoto
		den_ = den_ * other.num_;
		normalize();
	}
	
	void div(Rational other){
		if(other.num_==0){
			cout<<"OOPPS: division by zero..." << endl;
			throw RationalError();
		}
		num_*=other.den_;
		den_*=other.num_;
		normalize();
	
	}
	bool equal(Rational other){
		return num_ == other.num_ && den_==other.den_;
	}
	bool greater(Rational other){
		return num_*other.den_>other.num_*den_; //WATTTTT
	}
	bool less(Rational other){
		return num_*other.den_<other.num_*den_;//Wattt
	}
};

int main(){
	Rational r1(3,6), r2(1,2), r3(2,4);
	r1.print();
	r2.print();
	r3.print();
	Rational r4(-3,6), r5(3,-6);
	r4.print();
	r5.print();
	
	r1.add(r2);
	r1.print();
	
	Rational r6(3,2);
	r6.sub(r2);
	r6.print();
	
	r2.sub(r3);
	r2.print();
	
	Rational r7(3,4), r8(1,2);
	r7.mul(r8);
	r7.print();
	r7.div(r8);
	r7.print();	
	
	// r7.div(Rational(0,1)); Greshka i trqbva da throwne
	
	r3.print();
	cout<<r7.greater(r3)<<endl;
	cout<<r7.less(r3)<<endl;
	
	return 0;
}

