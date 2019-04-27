
/**
 * C++ prime
 * string
 *
 * 9.43  9.44
 */



#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cstdio>
using namespace std;

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
	for(auto cur=s.begin(); cur<s.end()-oldVal.size(); )
	{
		//if(oldVal == s.substr(cur, cur+oldVal.size()))		// substr(pos, n) maybe cannot use iterator as pos, pos need a int number
		if(oldVal == string{cur, cur+oldVal.size()})
		{
			cur = s.erase(cur, cur+oldVal.size());
			cur = s.insert(cur, newVal.begin(), newVal.end());
			// below code will run an error result, and why?
			// s.erase(cur, cur+oldVal.size());
                        // s.insert(cur, newVal.begin(), newVal.end());
			cur += newVal.size();
		}
		++ cur;
	}
}

auto other_replace_with(string &s, string const& oldVal, string const& newVal)
{
	for(size_t pos=0; pos < s.size()-oldVal.size(); )
	{
		if(s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal)
			s.replace(pos, oldVal.size(), newVal),
			pos += newVal.size();
		else
			++ pos;		
	}
}

int main(){

	vector<char> v{'h','e','l','l','o'};
	string ss(v.begin(), v.end());
	cout << ss << endl;
	
	
	string s{ "To drive straight thru is a foolish, tho courageous act." };
    	cout<< "before replace: "<< s << endl;
	replace_with(s, "tho", "though");
    	replace_with(s, "thru", "through");
	cout << "after replace: " << s << endl;


	s= "To drive straight thru is a foolish, tho courageous act." ;
        cout<< "before replace: "<< s << endl;
        other_replace_with(s, "tho", "though");
        other_replace_with(s, "thru", "through");
        cout << "after replace: " << s << endl;


	// find operator
	string numbers("0123456789"), name("r2d2");
	auto pos = name.find_first_of(numbers);
	cout<<pos<<endl;
	pos = name.find_first_not_of(numbers);
	cout<<pos<<endl;
	
	// value excharge
	int value = 100;
	string hunderd = to_string(value);
	cout << "type is: " << typeid(hunderd).name() << ", value is: " << hunderd << endl;
	double d = stod(hunderd);
	cout << "type is: " << typeid(d).name() << ", value is: " << d << endl;
	int i = stoi(hunderd);
	cout << "type is: " << typeid(i).name() << ", value is: " << i << endl;

	return 0;
}	
