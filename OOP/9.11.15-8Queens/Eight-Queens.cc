

/* !!! Not Completed !!! */
/* ! BackTracking algorithm ! */

#include <iostream>
#include <vector>
using namespace std;

void print_table(vector<int>& table){
	for(int i=0; i<table.size(); ++i){
		cout << "(" << i << ", " << table[i] << ")" << endl;
	}
}

bool is_possible_pos(vector<int>&table, int i, int j){
	for(int k=0; k<i; ++k){
		if (table[k]==j){
			return false;
		}
		if ( (k - table[k]) == (i - j)) { //Proverka na 1viq diagonal 
			return false;
		}
		if ( (k + table[k]) == (i + j)) { // Proverka na 2riq diagonal 
			return false;
		}
	}
	return true;	
	
}

void queens(vector<int>& table, int i){
	if(i==table.size()){
		cout << "Solution found..." << endl;
		print_table(table);
		return;
	}
	for(int j=0; j<table.size(); ++j){
		if( is_possible_pos(table, i, j) ){
			table[i] = j;
			queens(table, i+1);
		}
	}
}

class Stack{
	vector<int> data_;
public:
	void push(int val){
		data_.push_back(val);
	}
	int pop (){
		int val = data_.back();
		data_.pop_back();
		return val;
	}
	bool empty() const {
		return data_.empty();
	}
};

void queens_iter(int size){
	
	vector<int> table(size);
	Stack where;
	
	int i = 0;
	while(i<size){	
	
	// Not completed 
	
	}
}

int main(){
	vector<int> table(4);
	
	queens(table, 0);
	return 0;
}
