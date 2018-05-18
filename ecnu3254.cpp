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

const int N = 300000 + 20;
const int INF = 0x3f3f3f3f;

typedef unsigned long long ull;
ull base = 131;
ull p[N];
vector<vector<ull>> hs;
void build(vector<ull> & h, const string & str) {
  h.push_back(0);
  int n = str.size();
  for (int i = 0; i < n; ++i) {
    h.push_back(h[i] * base + (str[i]));
  }
}
ull get(const vector<ull> & h, int l, int r) {
  l++; r++;
  return h[r] - h[l - 1] * p[r - l + 1];
}

int n;
string T;
vector<string> s;
bool check(int k) {
  int l = -k, i = 0, L = T.size();
  bool ok = 1;
  vector<ull> has;
  vector<ull> & hst = hs[0];
  while (l + k - 1 < L) {
    if (ok) {
      i++;
      l += k;
      string & str = s[i];
      has.clear();
      for (int j = 0; j + k - 1 < (int)str.size(); ++j) {
        has.push_back(get(hs[i], j, j + k - 1));
      }
      sort(has.begin(), has.end());
    }
    
    ull key = get(hst, l, l + k - 1);
    if (binary_search(has.begin(), has.end(), key)) {
      ok = 1;
      if (i >= n) return true;
    }
    else {
      ok = 0;
      ++l;
    }
  }
  return false;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  p[0] = 1;
  for (int i = 1; i < N; ++i) p[i] = p[i - 1] * base;
  
  int mxl = 2e9;
  cin >> T >> n;
  mxl = min(mxl, (int)T.size());
  hs.assign(n + 1, vector<ull>());
  build(hs[0], T);
  s.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    build(hs[i], s[i]);
    mxl = min(mxl, (int)s[i].size());
  } 

  int ans = -1;
  int lb = 1, ub = mxl; 
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (check(mid)) {
      ans = mid;
      lb = mid + 1;
    } else {
      ub = mid - 1;
    }
  }
  cout << ans;
  return 0;
}