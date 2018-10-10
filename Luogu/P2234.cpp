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

const int N = 5e6 + 5;
int root, tot;
int ch[N][2], pre[N], val[N];
//void Treavel(int x)
//{
//    if(x)
//    {
//        Treavel(ch[x][0]);
//        printf("%2d: (lson: %d, rson: %d), father: %d, \tsize=%2d,value=%2d\n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x]);
//        Treavel(ch[x][1]);
//    }
//}
void PushDown(int x) {

}
void PushUp(int x) {

}
void Rotate(int x) {
    const int y = pre[x], z = pre[y], k = (ch[y][1] == x);
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
            (ch[z][0] == y) ^ (ch[y][0] == x) ? Rotate(x) : Rotate(y);
        }
        Rotate(x);
    }
    if (goal == 0) root = x;
}
void Insert(int x) {
    int u = root, fa = 0;
    while (u && val[u] != x) {
        fa = u;
        u = ch[u][x > val[u]];
    }
    if (u) {
        ;
    } else {
        u = ++tot;
        if (fa) ch[fa][x > val[fa]] = u;
        ch[u][0] = ch[u][1] = 0;
        val[u] = x;
        pre[u] = fa;
    }
    Splay(u, 0);
}
void Find(int x) {
    int u = root;
    if (!u) return;
    while (ch[u][x > val[u]] && val[u] != x) u = ch[u][x > val[u]];
    Splay(u, 0);
}
int GetNode(int x, int k) {
    Find(x);
    int u = root;
    if (val[u] >= x && k == 1) return u;
    if (val[u] <= x && k == 0) return u;
    u = ch[u][k];
    while (ch[u][k ^ 1]) u = ch[u][k ^ 1];
    return u;
}
int main() {
#ifdef BIUBIUBIU
    freopen("../Workspace/in.txt", "r", stdin);
    freopen("../Workspace/out.txt", "w", stdout);
#endif

    Insert(-214748647);
    Insert(+214748647);

    int n, x;
    read(n); read(x);
    int ans = x;
    Insert(x);
    for (int i = 1; i < n; ++i) {
        read(x);
        int last = GetNode(x, 0);
        int next = GetNode(x, 1);
        ans += min(abs(val[last] - x), abs(val[next] - x));
        // printf("+%d\n", min(abs(val[last] - x), abs(val[next] - x)));
        Insert(x);
    }
    // Treavel(root);
    printf("%d\n", ans);
}