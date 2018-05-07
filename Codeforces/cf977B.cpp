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

int main(int args, char const *argv[]) {
  hash<string> hs;
  map<pair<string, size_t>, int> cnt;

  int n; cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i + 1 < n; ++i) {
    string t;
    t.push_back(s[i]);
    t.push_back(s[i + 1]);
    cnt[{t, hs(t)}]++;
  }
  int t = 0;
  string ans;
  for (const auto & kv : cnt) {
    if (t < kv.second) {
      t = kv.second;
      ans = kv.first.first;
    }
  }
  cout << ans;
}
