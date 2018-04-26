#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


const int N = 500 + 20;
const double eps = 1e-7;
int city[N][N];
int radar[N][N];
int n, m, k, T;

bool check(double r) {
  
}

int main(int argc, char const *argv[])
{
  // freopen("data.in", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &n, &m, &k);
    int x, y;
    memset(city, 0, sizeof(city));
    memset(radar, 0, sizeof(radar));
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &x, &y);
      city[x][y] = 1;
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", &x, &y);
      radar[x][y] = 1;
    }
    double lb = 0, ub = 2e9;
    double ans = -1;
    for (int i = 0; i < 200; ++i) {
      double mid = (lb + ub) / 2.0;
      if (check(mid)) ub = mid;
      else lb = mid;
    }
    
  }
  return 0;
}