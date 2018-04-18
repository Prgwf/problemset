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
  void dfs(int i, ll v, vector<ll> &Vprime, vector<ll> &num) {
    if (i == (int)Vprime.size()) {
      num.push_back(v);
      return;
    }

    dfs(i + 1, v, Vprime, num);

    while (v <= up / Vprime[i]) {
      dfs(i + 1, v *= Vprime[i], Vprime, num);
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
    for (int i = 0; i < n; i += 2) {
      prime[0].push_back(init[i]);
    }
    for (int i = 1; i < n; i += 2) {
      prime[1].push_back(init[i]);
    }

    vector<ll> num[2];
    dfs(0, 1LL, prime[0], num[0]);
    dfs(0, 1LL, prime[1], num[1]);

    ll k;
    in >> k;

    sort(num[0].begin(), num[0].end(), greater<ll>());
    sort(num[1].begin(), num[1].end(), less<ll>());

    ll lb = 1LL, ub = (ll)1e18, ans;
    while (lb <= ub) {
      ll mid = (lb + ub) / 2LL;

      ll temp = 0LL;
      int j = 0;
      for (ll x : num[0]) {
        while (j < (int)num[1].size() && num[1][j] <= mid / x) {
          ++j;
        }
        temp += j;
      }

      if (temp >= k) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }

    out << ans << endl;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

