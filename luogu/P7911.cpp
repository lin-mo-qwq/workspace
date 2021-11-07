#include<bits/stdc++.h>
using namespace std;
map<string, int> ser;
bool check(string a) {
	long long cnt = 0, sum = -1, flag = 0;
	for(int i = 0; i < (int)a.size(); i++) {
		if(a[i] != '.' && a[i] != ':') {
			sum = max(sum, 0ll);
			sum = sum * 10 + a[i] - '0';
			if(sum == 0) {
				if((i + 1) < (int)a.size() && '0' <= a[i + 1] 
				  && a[i + 1] <= '9')
					return false;
			}
		} else if(a[i] == '.') {
			++cnt; 
			if(cnt >= 4 || sum > 255 || sum == -1) return false;
			sum = -1;
		} else {
			++cnt; flag = 1;
			if(cnt != 4 || sum > 255 || sum == -1) return false;
			sum = -1;
		}
	}
	if(sum == -1 || sum > 65535 || cnt < 4 || flag == 0) return false;
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	string typ, a;
	for(int i = 1; i <= n; i++) {
		cin>>typ>>a;
		if(!check(a)) puts("ERR");
		else if(typ == "Server") {
			if(ser[a] != 0) {
				puts("FAIL");	
			} else {
				puts("OK");
				ser[a] = i;
			}
		} else {
			if(ser[a] != 0) {
				printf("%d\n", ser[a]);
			} else {
				puts("FAIL");
			}
		}
	}
	return 0;
}