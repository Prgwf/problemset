#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

int n;
vector<pair<int, int>> a;
int fa[N];
int find(int x) {
  if (x != fa[x]) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  fa[x] = y;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }

  for (int i = 0; i <= n; ++i) fa[i] = i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i != j) {
      if (a[i].first == a[j].first
        or a[i].second == a[j].second) {
          unite(i, j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (fa[i] == i) {
      ans++;
    }
  }
  printf("%d\n", ans - 1);
}
