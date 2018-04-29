#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

string str;
int p, m;

struct Node {
  int num;
  vector<shared_ptr<Node>> chs;

  Node(int x)
    : num(x), chs(2) {

    }
  Node(const shared_ptr<Node> &l, const shared_ptr<Node> & r)
    : num(0), chs(0) {
      chs.push_back(l);
      chs.push_back(r);
    }
} ;

shared_ptr<Node> build(const string & s, int & i) {
  if (i == (int)s.size()) {
    assert(false);
  }

  if (isdigit(s[i])) {
    shared_ptr<Node> it = make_shared<Node>(s[i] - '0');
    i++;
    return it;
  } else if (s[i] == '(') {
    i++;

    shared_ptr<Node> it(build(s, i));
    assert(s[i] == '?');

    i++;

    shared_ptr<Node> root(build(s, i));
    assert(s[i] == ')');

    i++;

    return make_shared<Node>(it, root);
  } else {
    assert(false);
  }
}
vector<pair<int, int>> Solve(const shared_ptr<Node> & it, int Max, bool k) {
  if (it->num == 0) {
    vector<pair<int, int>> lv(Solve(it->chs[0], Max, k));
    vector<pair<int, int>> rv(Solve(it->chs[1], Max, k));
    
    vector<pair<int, int>> ansv(min(Max + 1, int(lv.size() + rv.size())), {1e9, -1e9});

    for (int i = 0; i < lv.size(); ++i) {
      auto lp(lv[i]);
      for (int j = 0; j < rv.size(); ++j) {
        auto rp(rv[j]);
        for (int d = 0; d < 2; ++d) {
          if (i + j + d >= ansv.size()) continue;
          int mx, mn;
          if (d ^ k) {
            mx = lp.second - rp.first;
            mn = lp.first - rp.second;
          } else {
            mx = lp.second + rp.second;
            mn = lp.first + rp.first;
          }
          ansv[i + j + d].first = min(ansv[i + j + d].first, mn);
          ansv[i + j + d].second = max(ansv[i + j + d].second, mx);
        }
      }
    }
    return ansv;
  } else {
    vector<pair<int, int>> v(1, {it->num, it->num});
    return v;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> str >> p >> m;
  int i = 0;
  shared_ptr<Node> root = build(str, i);

  int ans;
  vector<pair<int, int>> v;
  if (p > m) {
    v = Solve(root, m, false);
    ans = v[m].second;
  } else {
    v = Solve(root, p, true);
    ans = v[p].second;
  }
  cout << ans;
  return 0;
}
