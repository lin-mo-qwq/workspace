#include<bits/stdc++.h>
using namespace std;
const int M = 105; 
int len[M][M], n;
string ans[M][M];

string get(char x) {
	if(x == '[' || x == ']') {
		return "[]";
	} else {
		return "()";
	}
}

int main() {
	string a;
	cin>>a;
	n = a.length();
	memset(len, 0x3f, sizeof(len));
	for(int i = 0; i < n; i++) {
		len[i][i] = 1, len[i][i - 1] = 0;	
		ans[i][i] = get(a[i]);
	}

	for(int l = 0; l < n; l++) {
		for(int i = 0; i < n - l; i++) {
			int j = i + l;
			for(int k = i; k < j; k++) {
				if(len[i][k] + len[k + 1][j] < len[i][j]) {
					ans[i][j] = ans[i][k] + ans[k + 1][j];
					len[i][j] = len[i][k] + len[k + 1][j];
				}
			}
			if(a[i] == '[' && a[j] == ']') {
				if(len[i + 1][j - 1] < len[i][j]) {
					ans[i][j] = a[i] + ans[i + 1][j - 1] + a[j];
					len[i][j] = len[i + 1][j - 1];
				}
			} else if(a[i] == '(' && a[j] == ')') {
				if(len[i + 1][j - 1] < len[i][j]) {
					ans[i][j] = a[i] + ans[i + 1][j - 1] + a[j];
					len[i][j] = len[i + 1][j - 1];
				}
			}
		}
	}
	
	cout<<ans[0][n - 1]<<endl;
	return 0;
}