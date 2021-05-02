#include<bits/stdc++.h>
using namespace std;
typedef multiset<int>::iterator Itt;
int n, m;
multiset<int> q;
int main() {
	cin.tie(0);
	scanf("%d", &n);
	while(n--) {
		string opt;
		cin>>opt;
		if(opt == "Push") {
			scanf("%d", &m);
			q.insert(m);
		}
		else { 
			scanf("%d", &m);
			Itt l = q.upper_bound(m);
			if(l == q.begin()) {
				printf("No Element!\n");
			} else {
				--l;
				printf("%d\n", *l);
			 	q.erase(l);
			}
		}
	}
	return 0;
}