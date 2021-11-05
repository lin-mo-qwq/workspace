

# 脑抽合集

## acwing 363

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
