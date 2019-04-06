#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

template <typename T>
int binarySearch(vector<T> Sorted_list,T target)
{
	auto beg = Sorted_list.begin();
	auto end = Sorted_list.end();
	auto mid = Sorted_list.begin() + (end - beg)/2;	// cannot use (end+beg)/2, cannot use "+" op for two iterator

	while(mid != end && *mid != target)
	{
		if(*mid < target)
			beg = mid + 1;
		else 
			end = mid;
		mid = mid + (end - beg) / 2;
	}
	return (*mid == target)? (mid-Sorted_list.begin()) : -1;
}

int main(){
	
	/**
	 * rvalue: when a object is used as ravale,
	 * 	   it use the object real values
	 * lvalue: when a object is used as lvalue,
	 * 	   it use the identity of object(the position at memory)
	 * lvalue can use as rvalue, otherwise not.
	 * 
	 * eg:
	 * '=': auto a = b = 5; a and b both lvalue, 5 is rvalue.
	 * 	so we can use like this: a = b = 5;
	 * '&':	auto* a = &b; b is lvalue, a is point of b, a is rvalue.
	 * '*' '[]' : lvalue
	 **/
	int a = 10;
	auto b = a;
	int i;
	//i + 1 = 5;	//error: lvalue required as left operand of assignment
	
	auto p = &a;
	cout << "p is :" << p << endl;
	//auto p1 = &5;		// error: lvalue required as unary ‘&’ operand
	

	// test binary search
	vector<string> s_list {"a", "bb", "ccc"};
	vector<int> list {1, 3 , 7, 9, 100};
	string target = "bb";

	auto index_1 = binarySearch(s_list, target);
	auto index_2 = binarySearch(list, 5);
	
	cout << "the \"bb\" at s_list: " << index_1 << endl;
	cout << "the 5 at list: " << index_2 << endl;
	
	return 0;
}
