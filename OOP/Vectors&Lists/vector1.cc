#include<iostream>
#include<vector>

using namespace std;
void print(vector<int>& v)
{
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout<<endl;
}
int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v1(arr, arr + 10);
	
	cout << v1.size() << endl;	
	print(v1);
	vector<int>::iterator it = v1.begin();
	v1.insert(it, -1);
	print(v1);
	
	it = v1.end();
	v1.insert(it, 1000);
	print(v1);
	
	it = v1.begin();
	it += 2;
	v1.insert(it, 33000);
	print(v1);
	
	it = v1.begin();
	it += 2;
	v1.erase(it);
	print(v1);
	
	v1.erase(v1.begin(), v1.end());
	print(v1);
	
	
	return 0;
}
