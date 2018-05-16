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
char grid[N][N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%s", grid[i] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j] == '.') grid[i][j] = '0';
      if (isdigit(grid[i][j])) {
        int k = grid[i][j] - '0';
        int cnt = 0;
        for (int x = -1; x <= 1; ++x) {
          for (int y = -1; y <= 1;  ++y) {
            if (!x && !y) continue;
            int tx = i + x;
            int ty = j + y;
            if (tx <= 0 || tx > n || ty <= 0 || ty > m) continue;
            if (grid[tx][ty] == '*') {
              ++cnt;
            }
          }
        }
        if (cnt != k) {
          printf("No\n");
          return 0;
        }
      }
    }
  }
  printf("Yes\n");
  return 0;
}
