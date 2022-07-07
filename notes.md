# notes

- [ ] ## acwing 346


将一颗树扩展为完全图, 且完全图中的最小生成树仍为该树

在跑一遍Kruskal时, 将一连通块中所有节点向另一连通块中所有节点各连一条边, 且连的边大于将这两个连通块联通起来的最小边

并查集维护连通块内节点数量时

``` cpp
for(int i = 1; i <= n; i++) p[i] = i, size[i] = i; // ✗
for(int i = 1; i <= n; i++) p[i] = i, size[i] = 1; // ✓
```

并查集找根

``` cpp
int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return x; // ✗
    return p[x]; // ✓
}
```

## lougu P7910
用链表直接维护即可

遍历链表元素时

``` cpp
void find(int now, int cnt) {
	if(lst[now].nxt != 0) {
		if(now != 0) a[lst[now].id] = cnt;
		find(lst[now].nxt, ++cnt);
	} else {
		a[lst[now].id] = cnt; // 如果缺了这一行就不会遍历到最后一个元素
		return ;
	}
}
```

##  lougu P7912

将每个块用队列维护, 相同时直接合并

``` cpp
while(q2.size()) {
    auto add = q2.front(); q2.pop();
    while(q2.size()) {
        auto x = q2.front(); 
        if(a[x.fnt] == a[add.fnt]) { // ✗ 首元素可能被访问过
        if(a[x.til] == a[add.til]) { // ✓ 
            add.til = x.til;
            q2.pop();
        } else break;
    }
    q.push(add);
}
```



## lougu 7911

用map直接维护即可

## acwing 1146

建一个超级原点, 向每个发电站连一条边, 边权为$v_i$ , 问题就转化为求新图上的最小生成树

## acwing 1145

在跑Kruskal时, 至整个图中只剩下k个联通块即可, 答案为加的最后一条边

## acwing 1148

次小生成树, 遍历所有非树边, 将其加入生成树中, 再删去原最小生成树上路径最大的一条边, 注意到最大边的权值可能与该边相等, 因此要求出严格次小边, 删去严格次小边, 统计答案即可

## codeforce 804A
^ 表异或
a, b, c 取任意正整数时
(a ^ b) + (b ^ c) + (a ^ c) 始终为偶数
存在 a = 0, b = 0, c = n / 2时
(a ^ b) + (b ^ c) + (a ^ c) = n

## codeforce 804B
单解找不到找通解

## codeforce 804C
对于每个元素x, 存在一个区间其MEX值为 x + 1
则, 该元素移动后位置必定在该区间之内
若该区间左端点为l, 右端点为r, 则该元素移动范围为(r - l + 1) - x 
若该元素为区间端点, 则, 无法移动 
从小到大枚举计算

## codeforce 804D
引理：在区间[l, r]内, 只要区间内最大元素频数不超过(r - l + 1) / 2, 则该区间可以被删去
设dp[i]为在数组a[1, i]内, 通过操作可得到的最大元素数目
dp[i] = max(dp[i], dp[j] + 1) (a[i] == a[j] 且 [j + 1, i - 1] 可被删去)
当且仅当 [i + 1, n] 可别删去是dp[i] 才能被取到

注意 ：初始化时需将初值设为无穷小，不然一开始被排除在外的数（[1, i - 1]被删去）也能转移到dp[i], 最终可能被取到答案
```
memset(dp, 0, sizeof dp) // wrong
memset(dp, -0x3f, sizeof dp) // right
```