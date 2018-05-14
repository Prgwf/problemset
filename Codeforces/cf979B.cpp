#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n;
string color[3];
int cnt[3];
const string out[3] = {
  "Kuro",
  "Shiro",
  "Katie"
};
int main(int args, char const *argv[]) {
  cin >> n;
  for (int i = 0; i < 3; ++i) cin >> color[i];
  for (int i = 0; i < 3; ++i) {
    map<char, int> mep;
    for (char & c : color[i]) {
      mep[c]++;
      cnt[i] = max(cnt[i], mep[c]);
    }
    if (cnt[i] == (int)color[i].size() && n == 1) {
      cnt[i]--;
    } else {
      cnt[i] = min(cnt[i] + n, (int)color[i].size());
    }
  }
  int mx = 0, ret = -1;
  for (int i = 0; i < 3; ++i) {
    if (mx < cnt[i]) {
      mx = cnt[i];
      ret = i;
    }
  }
  for (int i = 0; i < 3; ++i) {
    if (i != ret && mx == cnt[i]) {
      printf("Draw\n");
      return 0;
    }
  }
  printf("L = %d\n", mx);
  cout << out[ret];
}
