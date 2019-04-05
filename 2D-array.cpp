#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){
	int a[2][3] = {{1,2,3},{11,22,33}};
	int (*p)[3] = a;
	p = &a[2];
	/**
	 * tha array name is the same as pointer & iterator, 
	 * and can use ++ and begin(), end();
	 * the under line out put is:
	 * a is : 0x7ffc3d924180
	 * a[1] is: 0x7ffc3d92418c
	 * a[1][1] is: 22
	 * &a[1]: 0x7ffc3d92418c
	 * p is: 0x7ffc3d924198
 	 **/
	cout<<"a is : " << a<<endl;
	cout<<"a[1] is: " << a[1]<<endl;
	cout<<"a[1][1] is: " << a[1][1]<<endl;
	cout<<"&a[1]: " << &a[1]<<endl;
	cout<<"p is: " << p <<endl;
	
	/**
	 * for each operator :
	 * auto &row:a 
	 * 	row is a reference of a , output of row is a pointer indicate a array;
	 * auto row:a
	 * 	row is a pointer, output of row is a pointer, maybe not indicate a array;
	 * */	
	for(auto &row : a)
	{
		cout << row << "**********" <<endl;
		
		for(auto col : row)
			cout << col << " ";
		cout << endl;
	}
	
	/**
	 * the same as upper code, 
	 * if use 
	 * auto row:a
	 * the row maynot indicate a  array, so begin() and end() will be build fail;
	 * */
	//for(auto row =begin(a); row != end(a); ++row)
	for(auto &row : a)
	{
		cout <<"each row : " << row <<endl;
		for(auto i = begin(row); i!=end(row); ++i)
		{
			cout << *i <<endl;
		}
	}
	return 0;
}
