#include<bits/stdc++.h>
using namespace std;

string read()
{
	int n;
	char c;
	string s, s1;
	while(cin >> c)
	{
		if(c == '[')
		{
			cin >> n;
			s1 = read();
			while(n--) s += s1;
		}
		else if(c == ']')
			return s;
		else
			s += c;
	}
}

int main()
{
	cout<<read()<<endl;
	return 0;
}