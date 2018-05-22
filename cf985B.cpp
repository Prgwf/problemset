#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 5000 + 20;
const int INF = 0x3f3f3f3f;
  
int n, m;
char raw[N][N];
int grid[N][N];
int col[N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", raw[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      grid[i][j] = raw[i][j] - '0';
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      col[j] += grid[i][j];
    }
  }

  int flag = 0;
  for (int i = 1; i <= n; ++i) {
    flag = 1;
    for (int k = 1; k <= m; ++k) {
      if (col[k] == 1 && grid[i][k] == 1) {
        flag = 0; break;
      }
    }
    if (flag) {
      printf("%s\n", "YES");
      return 0;
    }
  }
  printf("%s\n", "NO");
  return 0;
}