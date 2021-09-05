#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, b, mod[N];
string a;
int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		cin>>a>>b;
		n = a.length();
		int tmp = 0;
		for(auto j : a) {
			if(j == '-') {
				continue;
			}
			tmp = ((tmp * 10) % b + (j - '0') % b) % b;
		}
		printf("Case %d: ", i);	
		if(!tmp) printf("divisible\n");
		else printf("not divisible\n");
	} 
	return 0;
}