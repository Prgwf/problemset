#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 300000 + 20;
const int INF = 0x3f3f3f3f;

int m;
int L[N], R[N], ans[N];
int fa[N], sum[N];
int find(int x) {
  if (x == fa[x]) return x;
  int f = fa[x];
  fa[x] = find(fa[x]);
  sum[x] += sum[f];
  return fa[x];
}
void unite(int x, int y, int s) {
  int fx = find(x);
  int fy = find(y);

  if (fx == fy) return;

  fa[fy] = fx;
  sum[fy] = s + (sum[x] - sum[y]);
}
int main(int args, char const *argv[]) {
  while (scanf("%d", &m) != EOF) {
    vector<int> a;
    for (int i = 0; i < m; ++i) {
      scanf("%d %d %d", L + i, R + i, ans + i);
      a.push_back(L[i]);
      a.push_back(R[i]);
      a.push_back(L[i]-1);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int n = a.size();
    for (int i = 0; i < m; ++i) {
      L[i] = lower_bound(a.begin(), a.end(), L[i]) - a.begin() + 1;
      R[i] = lower_bound(a.begin(), a.end(), R[i]) - a.begin() + 1;
    }
    for (int i = 0; i <= n; ++i) fa[i] = i;
    int flag = 1;
    for (int i = 0; i < m; ++i) {
      int x = L[i] - 1;
      int y = R[i];
      if (find(x) == find(y)) {
        if (ans[i] != sum[y] - sum[x]) {
          flag = 0;
        }
      } else {
        unite(x, y, ans[i]);
      }
    }
    printf("%s\n", flag? "2333!(=v=)":"666~~~(=_=)");
  }
}
