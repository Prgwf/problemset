#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
vector<vector<pair<int, int>>> T;
int f[105][105][30];
bool dfs(int x, int y, int state) {
  if (f[x][y][state] != -1) return f[x][y][state];

  int & ans = f[x][y][state];
  for (const pair<int, int> & pii : T[x]) {
    int v = pii.first;
    int w = pii.second;
    if (w < state) continue;
    if (!dfs(y, v, w)) {
      return ans = 1;
    }
  }
  return ans = 0;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d %d", &n, &m);
  T.assign(n + 1, vector<pair<int, int>>());
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    char s[2];
    scanf("%d %d %s", &x, &y, s);
    w = s[0] - 'a' + 1;
    T[x].push_back({y, w});
  }

  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dfs(i, j, 0);
      if (f[i][j][0]) putchar('A'); else putchar('B');
    }
    puts("");
  }
  return 0;
}
