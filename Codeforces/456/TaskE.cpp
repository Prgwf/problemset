/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

struct Solution {
  const ll up = (ll)1e18;
  void dfs(int depth, ll v, vector<ll> &Vprime, vector<ll> &num) {
    if (depth == Vprime.size()) {
      num.push_back(v);
      return;
    }

    dfs(depth + 1, v, Vprime, num);

    while (v <= up / Vprime[depth]) {
      dfs(depth + 1, v * Vprime[depth], Vprime, num);
      v *= Vprime[depth];
    }
  }
  void work(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<int> init(n);

    for (int i = 0; i < n; ++i) {
      in >> init[i];
    }
    sort(init.begin(), init.end());

    vector<ll> prime[2];
    for (int i = 0; i < n; ++i) {
      prime[i & 1].push_back(1LL * init[i]);
    }

    vector<ll> num[2];
    dfs(0, 1LL, prime[0], num[0]);
    dfs(1, 1LL, prime[1], num[1]);

    ll k;
    in >> k;

    sort(num[0].begin(), num[0].end(), greater<ll>());
    sort(num[1].begin(), num[1].end());

  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

