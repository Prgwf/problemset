#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

struct Node {
  int x;
  vector<shared_ptr<Node>> chs;

  Node(int value)
    : x(value), chs(0) {

    }
  Node(const shared_ptr<Node> &lch, const shared_ptr<Node> &rch)
    : x(-1), chs(0) {
      chs.push_back(lch);
      chs.push_back(rch);
    }
} ;

shared_ptr<Node> build(const string & s, int & i) {
  if (isdigit(s[i])) {
    shared_ptr<Node> o = make_shared<Node>(s[i] - '0');
    i++;
    return o;
  } else if (s[i] == '(') {
    i++;
    shared_ptr<Node> lson(build(s, i));
    assert(s[i] == '?');
    i++;
    shared_ptr<Node> rson(build(s, i));
    assert(s[i] == ')');
    i++;
    return make_shared<Node>(lson, rson);
  }
}

typedef pair<int, int> pii;
vector<pii> dfs(const shared_ptr<Node> & o, int cnt, bool add) {
  if (o->x != -1) {
    vector<pii> leaf(1, {o->x, o->x});
    return leaf;
  }

  vector<pii> L(dfs(o->chs[0], cnt, add));
  vector<pii> R(dfs(o->chs[1], cnt, add));

  vector<pii> ans(min(cnt + 1, (int)(L.size() + R.size())), {1e9, -1e9});
  for (int i = 0; i < (int)L.size(); ++i) {
    pii l(L[i]);
    for (int j = 0; j < (int)R.size(); ++j) {
      if (i + j >= ans.size()) break;

      pii r(R[j]);
      int max_ = -1e9, min_ = 1e9;
      if (add) {
        if (i + j + 1 < (int)ans.size()) {
          max_ = l.second + r.second;
          min_ = l.first + r.first;
          ans[i+j+1].first = min(ans[i+j+1].first, min_);
          ans[i+j+1].second = max(ans[i+j+1].second, max_);
        }
        if (i + j + 0 < (int)ans.size()) {
          max_ = l.second - r.first;
          min_ = l.first - r.second;
          ans[i+j+0].first = min(ans[i+j+0].first, min_);
          ans[i+j+0].second = max(ans[i+j+0].second, max_);
        }
      } else {
        if (i + j + 1 < (int)ans.size()) {
          max_ = l.second - r.first;
          min_ = l.first - r.second;
          ans[i+j+1].first = min(ans[i+j+1].first, min_);
          ans[i+j+1].second = max(ans[i+j+1].second, max_);
        }
        if (i + j + 0 < (int)ans.size()) {
          max_ = l.second + r.second;
          min_ = l.first + r.first;
          ans[i+j+0].first = min(ans[i+j+0].first, min_);
          ans[i+j+0].second = max(ans[i+j+0].second, max_);
        }
      }
    }
  }
  return ans;
}

int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string str;
  int P, M;
  cin >> str >> P >> M;

  int i = 0;
  shared_ptr<Node> root = build(str, i);

  vector<pii> ans;
  int sum;
  if (P > M) {
    ans = dfs(root, M, 0);
    sum = ans[M].second;
  } else {
    ans = dfs(root, P, 1);
    sum = ans[P].second;
  }
  cout << sum;
  return 0;
}
