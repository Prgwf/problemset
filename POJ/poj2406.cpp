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

const int N = 1000000 + 20;
const int INF = 0x3f3f3f3f;

int fail[N];
void get_fail(const char *s, int n) {
  fail[0] = -1;
  int k = -1; // 当前匹配长度
  int i = 0;
  while (i < n) {
    if (k == -1 || s[i] == s[k]) {
      fail[++i] = ++k; // 下一个位置若失配，前面有k个匹配的，跳至第k+1
    } else {
      k = fail[k];
    }
  }
}
char s[N];
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  while (scanf("%s", s) != EOF) {
    if (s[0] == '.') break;
    int n = strlen(s);
    get_fail(s, n);
    if (n % (n - fail[n]) == 0) {
      printf("%d\n", n / (n - fail[n]));
    } else {
      printf("1\n");
    }
  }
  return 0;
}