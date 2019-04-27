#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;


int main(){
	
	int a[5]{1,2,3,5,4};
	vector<int> v;
	// initial
	for(auto tmp:a)
	{
		v.push_back(tmp);
		cout<<tmp<<" ";
	}		
	cout << endl;
	for(auto tmp_v:v)
	{
		cout << tmp_v << " ";
	}
	cout << endl;
	// operator element
	/** range for use the iterator of vector, will use begin(v), end(v),
	 * so if you add or delete the element, the iterator will not change,
	 * it maybe cause some programmer error!!
	 **/
	for(auto &tmp_v:v)
	{
		tmp_v *= 2;
	}
 	
	for(auto tmp_v:v)
	{
		cout << tmp_v << " ";
	}
	cout << endl;
	// delete element
	v.erase(std::begin(v)+2);
 	
	for(auto tmp_v:v)
	{
		cout << tmp_v << " ";
	}
	cout << endl;
	// delete elements
	v.erase(std::begin(v)+0, std::end(v));
 	
	cout << "delete all elements is start!"<<endl;
	for(auto tmp_v:v)
	{
		cout << tmp_v << " ";
	}
	cout << "delete all elements is done!"<<endl;
	return 0;
}
