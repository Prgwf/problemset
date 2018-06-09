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
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;
  
char in[N];
int dist(pair<int, int> x, pair<int, int> y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}
int main(int args, char const *argv[]) {
  #ifdef LOCAL_TEST
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif

  map<char, pair<int, int>> pos;
  pos['@'] = pos['!']  = pos[':'] = {1, 1};
  pos['A'] = pos['B']  = pos['C'] = {1, 2};
  pos['D'] = pos['E']  = pos['F'] = {1, 3};  
  pos['G'] = pos['H']  = pos['I'] = {2, 1};
  pos['J'] = pos['K']  = pos['L'] = {2, 2};
  pos['M'] = pos['N']  = pos['O'] = {2, 3};
  pos['P'] = pos['Q']  = pos['R'] = pos['S'] = {3, 1};
  pos['T'] = pos['U']  = pos['V'] = {3, 2};
  pos['W'] = pos['X']  = pos['Y'] = pos['Z'] = {3, 3};
  
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", in + 1);
    int n = strlen(in + 1);
    in[0] = '@';
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += dist(pos[in[i - 1]], pos[in[i]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}