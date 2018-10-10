#include <bits/stdc++.h>
using namespace std;

const int N = 123456;
#define lson o << 1
#define rson o << 1 | 1
int n, m, k;
vector< vector< int > > T;
vector< int > result;
struct Node {
    int l, r, cnt, tag;
} tr[N * 4];
tuple< int, int, int > draw[N];
int sz[N], fa[N], dep[N], son[N], top[N], tid[N], arc[N], tot;
void build(int l, int r, int o = 1) {
    tr[o] = {l, r, 0, 0};
    if (l == r) return;
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m + 1, r, rson);
}
void push_up(int o) {
    tr[o].cnt = max(tr[lson].cnt, tr[rson].cnt);
}
void push_down(int o) {
    if (tr[o].tag) {
        int &t = tr[o].tag;
        tr[lson].cnt += t;
        tr[rson].cnt += t;
        tr[lson].tag += t;
        tr[rson].tag += t;
        t = 0; assert(tr[o].tag == 0);
    }
}
void solve(int o, int x) {
    if (tr[o].l == tr[o].r) {
        // cerr << tr[o].l << " is " << x << endl;
        result[arc[tr[o].l]] = x;
        tr[o].cnt = -1 * 0x3f3f3f3f;
        return;
    }

    push_down(o);
    if (tr[lson].cnt == k) solve(lson, x);
    if (tr[rson].cnt == k) solve(rson, x);
    push_up(o);
}
void update(int l, int r, int x, int o = 1) {
    if (l <= tr[o].l && tr[o].r <= r) {
        // cerr << "update " << tr[o].l << ", " << tr[o].r << " --> " << x << endl;
        tr[o].cnt++;
        tr[o].tag++;
        if (tr[o].cnt == k) solve(o, x);
        return;
    }

    push_down(o);
    int m = (tr[o].l + tr[o].r) / 2;
    if (l <= m) update(l, r, x, lson);
    if (r > m) update(l, r, x, rson);
    push_up(o);
}
void dfs(int u, int p, int d) {
    sz[u] = 1;
    fa[u] = p;
    dep[u] = d;
    for (int v : T[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}
void link(int u, int first) {
    top[u] = first;
    tid[u] = ++tot;
    arc[tot] = u;
    if (son[u] != -1) link(son[u], first);
    for (int v : T[u]) {
        if (v == fa[u] || v == son[u]) continue;
        link(v, v);
    }
}
void modify(int u, int v, int c) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(tid[top[u]], tid[u], c);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    update(tid[u], tid[v], c);
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    T.assign(n + 1, vector<int>());
    result.assign(n + 1, int());
    memset(son, -1, sizeof(son));
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        T[x].push_back(y);
        T[y].push_back(x);
    }
    dfs(1, -1, 0);
    link(1, 1);
    build(1, n);
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        draw[i] = make_tuple(u, v, c);
    }
    for (int i = m; i >= 1; --i) {
        int u, v, c;
        tie(u, v, c) = draw[i];
        modify(u, v, c);
        // cerr << "modify " << u << ", " << v << " --> " << c << endl;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", result[i], i < n ? ' ' : '\n');
    }
    return 0;
}