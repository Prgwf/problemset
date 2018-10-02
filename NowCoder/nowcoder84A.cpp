#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

string str;
char mx[N];
int main() {
  ios_base::sync_with_stdio(false);

  cin >> str;
  int n = str.size();
  mx[n - 1] = str.back();
  for (int i = n - 2; i >= 0; --i) {
    mx[i] = max(mx[i + 1], str[i]);
  }
  string ret;
  for (int i = 0; i < n; ++i) {
    if (str[i] == mx[i]) {
      ret.push_back(str[i]);
    }
  }
  cout << ret << endl;
}
