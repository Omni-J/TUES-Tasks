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
