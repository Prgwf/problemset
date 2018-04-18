#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 20;
int n, ans;
int a[N];
int vis[N];

void bfs() {
    queue<int> Q;
    Q.push(1);
    vis[1] = 0;

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        
//        printf("now at %d   ", x);
 //       printf("vis[%d] = %d\n", x, vis[x]);

        for (int i = 1; i <= a[x]; ++i) {
            int t = x + i;
            if (t > n) continue;
            if (vis[t] <= vis[x] + 1) continue;
            Q.push(t);
            vis[t] = vis[x] + 1;
        }
    }
    printf("%d\n", vis[n]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    memset(vis, 0x3f, sizeof(vis));
    bfs();
}