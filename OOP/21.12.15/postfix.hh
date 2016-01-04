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
