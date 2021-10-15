#include<bits/stdc++.h>
using namespace std;
const int N = 22;
int n, cnt[N], ans;
string a[N], head;

bool checkLink(string a, string b) {
	if(a == head && b.find(a) == 0)  
		return true;
	string last = "";
	for(int i = a.size() - 1; i >= 0; i--) {
		last = a[i] + last;
		if(b.find(last) == 0 && last.size() != b.size()) return true;	
	}
	return false;
}

string link(string a, string b) {
	string last = "";
	int pos = 0;
	if(a == head) return b;
	for(int i = a.size() - 1; i >= 0; i--) {
		last = a[i] + last;
		if(b.find(last) == 0 && b.size() != last.size()) {
			pos = i;
			break;
		} 
	}
	last = "";
	for(int i = pos - 1; i >= 0; i--) {
		last = a[i] + last;
	}
	last = last + b;
	return last;
}

void dfs(string word) {
	ans = max((int)word.size(), ans);
	for(int i = 1; i <= n; i++) {
		if(checkLink(word, a[i]) && cnt[i] < 2) {
			cnt[i]++;
			dfs(link(word, a[i]));
			cnt[i]--;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> head;
	dfs(head);
	cout << ans;
	return 0;
}