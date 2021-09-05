#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, a[N];
typedef unordered_map<int, int> umap; 
umap mask, NewMask, tmp;

void findCnt(int len, int cnt, umap &ret) {
	if(ret.count(len) == 0) ret[len] = cnt;
	else {
		ret[len] = min(ret[len], cnt);
		return ;
	}
	findCnt(len / 2, cnt + 1, ret);
	if(len & 1) findCnt(len / 2 + 1, cnt + 1, ret);	
}

int findMin() {
	for(int i = 1; i <= n; i++) {
		tmp.clear();
		findCnt(a[i], 0, tmp);
		if(i != 1) {
			NewMask.clear();
			for(auto i : tmp) {
				if(mask.count(i.first)) 
					NewMask[i.first] = mask[i.first] + i.second;
			}
			mask = NewMask;
		} else mask = tmp; 
	}

	int ans = 1e9 + 5;
	for(auto i : mask) 
		ans = min(ans, i.second);
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 	
		scanf("%d", &a[i]);

	printf("%d\n", findMin());
	return 0;
}