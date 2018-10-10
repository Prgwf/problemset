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
int ch[N][2], pre[N], val[N], sz[N], cnt[N];
void Treavel(int x)
{
    if(x)
    {
        Treavel(ch[x][0]);
        printf("%2d: (lson: %d, rson: %d), father: %d, \tsize=%2d,value=%2d\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x]);
        Treavel(ch[x][1]);
    }
}
void PushUp(int o) {
    sz[o] = sz[ch[o][0]] + sz[ch[o][1]] + cnt[o];
}
void Rotate(int x) {
    int y = pre[x];
    int z = pre[y];
    int k = ch[y][1] == x;
    ch[z][ch[z][1] == y] = x;
    pre[x] = z;
    ch[y][k] = ch[x][k ^ 1];
    pre[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y;
    pre[y] = x;
    PushUp(y);
}
void Splay(int x, int goal) {
    while (pre[x] != goal) {
        int y = pre[x];
        int z = pre[y];
        if (z != goal) {
            (ch[z][0] == y) ^ (ch[y][0] == x) ? Rotate(x) : Rotate(y);
        }
        Rotate(x);
    }
    if (goal == 0) root = x;
}
void Insert(int x) {
    int u = root;
    int p = 0;
    while (u != 0 && val[u] != x) {
        p = u;
        u = ch[u][x > val[u]];
    }
    if (u != 0) {
        cnt[u]++;
    } else {
        u = ++tot;
        if (p != 0) {
            ch[p][x > val[p]] = u;
        }
        ch[u][0] = ch[u][1] = 0;
        pre[u] = p;
        val[u] = x;
        sz[u] = cnt[u] = 1;
        assert(u == tot);
    }
    Splay(u, 0);
}
void Find(int x) {
    int u = root;
    if (!u) return;
    while (ch[u][x > val[u]] && x != val[u]) {
        u = ch[u][x > val[u]];
    }
    Splay(u, 0);
}
int GetNode(int x, int k) {
    Find(x);
    int u = root;
    if (val[u] > x && k == 1) return u;
    if (val[u] < x && k == 0) return u;
    u = ch[u][k];
    while (ch[u][k ^ 1]) u = ch[u][k ^ 1];
    return u;
}
void Remove(int x) {
    int last = GetNode(x, 0);
    int next = GetNode(x, 1);
    Splay(last, 0); Splay(next, last);
    int v = ch[next][0];
    if (cnt[v] > 1) {
        cnt[v]--;
        Splay(v, 0);
    } else {
        ch[next][0] = 0;
    }
}
int Kth(int k) {
    int u = root;
    if (sz[u] < 0) {
        return 0;
    }
    while (true) {
        int lch = ch[u][0];
        if (k > sz[lch] + cnt[u]) {
            k -= sz[lch] + cnt[u];
            u = ch[u][1];
        } else {
            if (sz[lch] >= k) {
                u = lch;
            } else {
                return val[u];
            }
        }
    }
}
int Rank(int x) {
    Find(x);
    return sz[ch[root][0]];
}
int main() {
#ifdef BIUBIUBIU
    freopen("../Workspace/in.txt", "r", stdin);
    freopen("../Workspace/out.txt", "w", stdout);
#endif
    int n;
    read(n);
    Insert(INT_MAX);
    Insert(INT_MIN);
    for (int i = 1; i <= n; ++i) {
        int opt, x;
        read(opt); read(x);
        switch (opt) {
            case 1: {
                Insert(x);
            } break;
            case 2: {
                Remove(x);
            } break;
            case 3: {
                printf("%d\n", Rank(x));
            } break;
            case 4: {
                printf("%d\n", Kth(x + 1));
            } break;
            case 5: {
                printf("%d\n", val[GetNode(x, 0)]);
            } break;
            case 6: {
                printf("%d\n", val[GetNode(x, 1)]);
            } break;

            default: assert(false);
        }
    }
    // Treavel(root);
}