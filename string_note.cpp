#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;


int main(){
	
	/**
	 * string copy initialize, not include the '\0'
	 * so sizeof(s) = 5, strlen(c) = 6 
	 * strlen() calculate the lenght between '\0', need #include<string.h>
	 **/
	string s = "hello";	
	char c[] = "hello";
	
	cout << "s size is: " << s.size() << endl << sizeof(c) << endl << strlen(c) << endl;
	cout << "====================" << endl;	

	const string hexdigits = "0123456789ABCDEF";
	cout << " Enter a series of numbers between 0 and 15"
	     << " sparated by space. Hit ENTER when finished: " << endl;
	string result;
	string::size_type n;
	while(cin >> n)
	{
		if(n<hexdigits.size())
			result += hexdigits[n];
		if(getchar() == '\n')
		{
			cout << "Your hex number is: " << result <<endl;
			break;
		}
		
	}
	//cout << "Your hex number is: " << result <<endl;
	return 0;
}
