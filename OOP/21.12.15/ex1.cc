// post fix.cc
// design patterns elements of reusable object oriented software amazon
//composite pattern za d.m. !!!!!!!!!!!!!!!!

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

#ifndef OPERATION_HH__
#define OPERATION_HH__

#ifndef POSTFIX_HH__
#define POSTFIX_HH__

class Postfix;
class CalcError{};

class Swap: public Op {
public:
	Swap(Postfix& postfix)
	: Op(postfix, "fix")
	{}
	
	void calc(){
		double val1 = get_postfix().get_val();
		double val1 = get_postfix().get_val();
		
		
	}
}

class BinOp: public Op{
public:
	BinOp(Postfix& postfix, const string& token)
	: Op(postfix, token)
	{}
	
	virtual double eval(double val1, double val2) = 0;
	
	void calc() const {
		double val1 = get_postfix().get_val();
		double val2 = get_postfix().get_val();
		
		double res = eval(val1, val2);
		get_postfix().put_val(res);
	}
	
};

class Plus: public BinOp{
public:
	Plus(Postfix& postfix)
	: BinOp(postfix, "+")
	{}
	
	double eval(double val1, double val2) const {
		return val1 + val2
	}
	
	
};

class Minus: public BinOp{
public:
	Minus(Postfix& postfix)
	: BinOp(postfix, "-")
	{}
		
	double eval(double val1, double val2){
		return val2 - val1;
	}	
};


class Mult: public BinOp{
public:
	Mult(Postfix& postfix)
	: BinOp(postfix, "*")
	{}
		
	double eval(double val1, double val2){
		return val2 * val1;
	}	
};


class Div: public BinOp{
public:
	Div(Postfix& postfix)
	: BinOp(postfix, "/")
	{}
		
	double eval(double val1, double val2){
		return val2 / val1;
	}	
};

class UnaryOp: public Op{
public:
	UnaryOp(Postfix& postfix, const string& token)
	: Op(postfix, token)
	{}
	
	virtual double eval(double val) const = 0;
	
	void calc() {
		double val = get_postfix().get_val();
		
		double res = eval(val);
		get_postfix().put_val(res);
	}
	
}; 

class Neg: public UnaryOp {
public:
	Neg(Postfix& postfix)
	: UnaryOp(postfix, "neg")
	{}
	
	double eval(double val) const {
		return -val;
	}
};

class Sqrt: public UnaryOp {
public:
	Sqrt(Postfix& postfix)
	: UnaryOp(postfix, "sqrt")
	{}
	
	double eval(double val) const {
		return val * val;
	}
};

class Dup: public Op{
public:
	Dup(Postfix& postfix)
	: Op(postfix, "dup")
	{}
	
	void calc(){
		double val = get_postfix().get_val();
		get_postfix().put_val(val);
		get_postfix().put_val(val);
	}
}

// Neg
// Sqrt

class CompositeOp: public Op{
	vector<OP*> ops_;
public:
	CompositeOp(Postfix& postfix, string token)
	: Op(postfix, token)
	{}
	
	void calc(){
		for(vector<Op*>::iterator it = ops_.begin();
			it!=ops_end(); ++it) {
			
			
			}
	}
}

int main(){

	Postfix postfix;
	postfix.add_op(new Plus (postfix));
	postfix.add_op(new Minus (posfix));
	postfix.add_op(new Mult (posfix));
	postfix.add_op(new Div (posfix));
	
	postfix.add_op(new Neg (posfix));
	postfix_add_op(new Sqrt (postfix));
	postfix_add_op(new Dup (postfix));
	postfix_add_op(new Swap (postfix));
	postfix.run(cin);
	return 0;
}



