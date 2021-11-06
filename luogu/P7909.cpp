#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	if((l / n) < (r / n)) cout<<n - 1<<endl;
	else cout<<r % n<<endl;
	return 0;
}