// post fix.cc
// design patterns elements of reusable object oriented software amazon
//composite pattern za d.m. !!!!!!!!!!!!!!!!

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Postfix;
class CalcError{};

class Op {
	Postfix& postfix_;
	string token_;
public:
	Op(Postfix& postfix, const string& token)
	: postfix_(postfix),
	  token_(token)
	{}
	
	string& get_token() const {
		return token_;
	}
	
	Postfix& get_postfix() {
		return postfix;
	}
	
	virtual void calc() = 0;

};

class Postfix{
	vector<Op*> context_;
	vector<double> stack_;
public:

	double get_val(){
		if(stack_.empty()){
			throw CaclError();
		}
		double val = stack_.back();
		stack_.pop_back();
		return val;
	}
	
	void put_val(double val){
		stack_.push_back(val)
	}

	void add_op(Op*){
		context_.push_back(op);
	}
	
	Op* get_op(const string& token){
		Op* op = 0;
		for(vector<Op*>::iterator it=context_.begin();
			it!= context_.end(); ++it) {
				
			if( (*it) -> get_token() == token ){
				op = *it;
			}		
		}
	}
	void run(istream& in){
		string token;
		while(true){
			in >> token;
			if(!in){
				break;
			}
			Op* op = get_op(token);
			if(op){
				op->calc();
				cerr << "op(" << token << "): res="
				 << stack_.back() <<endl;
			} else {
				istringstream istr(token);
				double val = 0;
				istr >> val;
				if(!istr){
					cerr << "bad value: " << token << endl;
					throw CalcError();
				}
				stack_.push_back(val);
				cerr << "data: " << val << endl;
			}
		}
	}
};

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

// Neg
// Sqrt

int main(){

	Postfix postfix;
	postfix.add_op(new Plus (postfix));
	postfix.add_op(new Minus (posfix));
	postfix.add_op(new Mult (posfix));
	postfix.add_op(new Div (posfix));
	
	postfix.add_op(new Neg (posfix));
	postfix_add_op(new Sqrt (postfix));
	postfix.run(cin);
	return 0;
}



