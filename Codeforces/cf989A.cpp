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
  
int main(int args, char const *argv[]) {
#ifdef LOCAL_TEST
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  string in;
  
  while (cin >> in) {
    string pat = "ABC";
    do {
      if (in.find(pat) != in.npos) {
        cout << "Yes";
        return 0;
      }
    } while (next_permutation(pat.begin(), pat.end()));
    cout << "No" << endl;
  }
  return 0;
}