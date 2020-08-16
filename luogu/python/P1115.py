
mem = {};

def dp(pos, k):
	if (pos , k) in mem :
		return mem[(pos , k)]
	if k==1 :
		return int(s[0:pos])

	rss=0

	for x in range(k-1 , pos) :
		rss = max(rss, dp(x , k-1) * int(s[x:pos]))
	
	mem[(pos , k)]=rss

	return mem[(pos , k)];

n , k=map(int,input().split());
s=input(); 
print(dp(n,k+1))