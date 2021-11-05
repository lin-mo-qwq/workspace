# notes

## acwing 346

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
