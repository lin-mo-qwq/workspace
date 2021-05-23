#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int f[N][N];
int main() {
	string a;
	cin>>a;
	int n = a.length();
	
	for(int i = 0; i < n; i++) 
		f[i][i] = 1;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] == a[j]) f[i][j] = f[i + 1][j - 1] + 2;
			else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
		}
	}
	printf("%d\n", n - f[0][n - 1]);
	return 0;
}