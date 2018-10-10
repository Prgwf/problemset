#include <bits/stdc++.h>
using namespace std;
template<class T>
inline bool read(T &n){
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

const int N = 123456;
int root, tot;
int ch[N][2], pre[N], val[N], size[N], tag[N];
int n, m;
void Treavel(int x)
{
    if(x)
    {
        Treavel(ch[x][0]);
        printf("%2d: (lson: %d, rson: %d), father: %d, \tsize=%2d,value=%2d\n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x]);
        Treavel(ch[x][1]);
    }
}
void PushDown(int x) {
    if (tag[x]) {
        swap(ch[x][0], ch[x][1]);
        tag[ch[x][0]] ^= 1;
        tag[ch[x][1]] ^= 1;
        tag[x] ^= 1; assert(tag[x] == 0);
    }
}
void PushUp(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
}
void Rotate(int x) {
    const int y = pre[x], z = pre[y], k = ch[y][1] == x;
    PushDown(y); PushDown(x);
    ch[z][ch[z][1] == y] = x;
    pre[x] = z;
    ch[y][k] = ch[x][k ^ 1];
    pre[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y;
    pre[y] = x;
    PushUp(y); PushUp(x);
}
void Splay(int x, int goal) {
    while (pre[x] != goal) {
        int y = pre[x], z = pre[y];
        if (z != goal) {
            (ch[y][0] == x) ^ (ch[z][0] == y) ? Rotate(x) : Rotate(y);
        }
        Rotate(x);
    }
    if (goal == 0) root = x;
}
int Kth(int u, int k) {
    PushDown(u);
    int s = size[ch[u][0]];
    if (s + 1 == k) return u;
    if (s >= k) return Kth(ch[u][0], k);
    else return Kth(ch[u][1], k - s - 1);
}
void Reverse(int l, int r) {
    l = Kth(root, l);
    r = Kth(root, r + 2);
    Splay(l, 0); Splay(r, l);
    int u = ch[r][0];
    tag[u] ^= 1;
}
void Insert(int x) {
    int u = root, fa = 0;
    while (u) {
        fa = u;
        u = ch[u][x > val[u]];
    }
    assert(u == 0);
    u = ++tot;
    if (fa) {
        ch[fa][x > val[fa]] = x;
    }
    val[u] = x;
    ch[u][0] = ch[u][1] = 0;
    pre[u] = fa;
    size[u] = 1;
    Splay(u, 0);
}
void print(int r) {
    PushDown(r);
    if (ch[r][0]) print(ch[r][0]);
    if (val[r] > 1 && val[r] < n + 2) printf("%d ", val[r] - 1);
    if (ch[r][1]) print(ch[r][1]);
}
int main() {
#ifdef BIUBIUBIU
    freopen("../Workspace/in.txt", "r", stdin);
    freopen("../Workspace/out.txt", "w", stdout);
#endif
    read(n); read(m);
    for (int i = 1; i <= n + 2; ++i) {
        Insert(i);
    }
    // Treavel(root);
    for (int i = 0; i < m; ++i) {
        int l, r;
        read(l); read(r);
        Reverse(l, r);
    }
    print(root); printf("\n");
}