#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef set<int>::iterator IIt;
int w, h, n;
set<int> l1, l2;
multiset<int> s1, s2;
int main() {
	scanf("%d%d%d", &w, &h, &n);
	l1.insert(0), l1.insert(h);
	l2.insert(w), l2.insert(0);
	s1.insert(h), s2.insert(w);
	for(int i = 1, tmp = 0; i <= n; i++) {
		char opt, s[5];
		scanf("%s", s);
		opt = s[0];
		scanf("%d", &tmp);
		if(opt == 'H') {
			if(l1.find(tmp) != l1.end()) goto result;
			l1.insert(tmp);	
			IIt l = l1.lower_bound(tmp);
			IIt r = l1.upper_bound(tmp);
			--l;
			if(s1.find(*r - *l) != s1.end()) 
				s1.erase(s1.find(*r - *l));
			s1.insert(tmp - *l);
			s1.insert(*r - tmp);
		}
		if(opt == 'V') {
			if(l2.find(tmp) != l2.end()) goto result;
			IIt l = l2.lower_bound(tmp);
			IIt r = l2.upper_bound(tmp);
			--l;
			l2.insert(tmp);
			if(s2.find(*r - *l) != s2.end())
				s2.erase(s2.find(*r - *l));
			s2.insert(tmp - *l);
			s2.insert(*r - tmp);
		}
		result: 
			long long lh = *(--s1.end()), lw = *(--s2.end());
			printf("%lld\n", lh * lw);
	}
	return 0;
}