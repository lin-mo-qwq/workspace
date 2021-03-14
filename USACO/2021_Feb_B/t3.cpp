#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int angle_from_direction(char a)
{
	if(a == 'E') return 0;
	if(a == 'N') return 90;
	if(a == 'W') return 180;
	if(a == 'S') return 270;
}

int angle_change(char a,char b)
{
	int theta1 = angle_from_direction(a);
	int theta2 = angle_from_direction(b);
	if(theta2 == (theta1 + 90)%360) return 90;
	else if(theta2 == theta1) return 0;
	else if(theta2 == (theta1 + 270)%360) return -90;
	else assert(false);	//fence should not backtrack on itself
}

void test(string s)
{
	int total_change = 0;
	for(int i=0;i<s.size();i++)
		total_change += angle_change(s[i],s[(i+1)%s.size()]);
	if(total_change == 360) cout << "CCW\n";
	else cout << "CW\n";
}

int main()
{
	int N;
	string s;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		test(s);
	}
}