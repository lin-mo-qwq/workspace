#include<bits/stdc++.h>
using namespace std;

const int M = 2005;
char s[M], ans[M];

bool match(int l, int r)
{
	while(l != r && s[l] == s[r]) l++, r--;
	if(s[l] < s[r]) return true;
	else return false;
}

int main()
{
	int n, cnt = 0;
	scanf("%d%s", &n, s + 1);
	int l = 1, r = n;
	
	while(l <= r)
	{
		int tmp_l = l, tmp_r = r;
		if(s[l] < s[r]) ans[++cnt] = s[l], l++;
		else if(s[r] < s[l]) ans[++cnt] = s[r], r--;
		else
		{
			if(match(l , r)) 
				ans[++cnt] = s[l], l++;
			else
				ans[++cnt] = s[r], r--;
		}
	}

	for(int i = 1; i <= cnt; i++)
	{
		printf("%c", ans[i]);
		if(!(i % 80)) puts("");
	}

	return 0;
}