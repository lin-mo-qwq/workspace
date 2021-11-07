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



