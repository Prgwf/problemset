#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

struct comp {
  bool operator () (const pair<int, string> &x, const pair<int, string> & y) const {
    if (x.first != y.first) {
      return x.first < y.first;
    } else {
      return x.second > y.second;
    }
  }
} ;
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> Q;
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
      string s;
      int x;
      cin >> s >> x;
      Q.push(make_pair(x, s));
    }

    int sum = 0;
    for (int i = m; i > 0; --i) {
      pair<int, string> u = Q.top();
      Q.pop();

      sum += i * u.first;
      ans.emplace_back(u.second);
    }

    cout << sum;
    for (const string & s : ans) {
      cout << " " << s;
    }
    cout << endl;
  }
}
