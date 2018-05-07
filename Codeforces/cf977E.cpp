#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200000 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
int deg[N];
int color[N];
vector<vector<int>> G;
vector<int> nodes[N];
void dfs(int x, int k) {
  color[x] = k;
  nodes[k].push_back(x);

  for (int v : G[x]) {
    if (!color[v]) {
      dfs(v, k);
    }
  }
}
int main(int args, char const *argv[]) {
  scanf("%d %d", &n, &m);
  G.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
    deg[x]++; deg[y]++;
  }

  int cnt = 1;
  for (int i = 1; i <= n; ++i) {
    if (!color[i]) {
      dfs(i, cnt++);
    }
  }

  int ans = 0;
  for (int i = 1; i < cnt; ++i) {
    vector<int> & block = nodes[i];
    int flag = 1;
    for (int v : block) {
      if (deg[v] != 2) {
        flag = 0;
        break;
      }
    }
    if (flag) ans++;
  }
  printf("%d\n", ans);
}
