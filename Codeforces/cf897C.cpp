#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int N = 100000 + 7;

int q, n;
ll k;
ll L[N];
vector<pair<ll, ll>> pos[N];
string f0 = " What are you doing at the end of the world? Are you busy? Will you save us?";
string str[5];
ll A_len, B_len, C_len;
void init() {
  str[0] = " What are you doing while sending \"";
  str[2] = " \"? Are you busy? Will you send \"";
  str[4] = " \"?";

  A_len = str[0].size() - 1;
  B_len = str[2].size() - 1;
  C_len = str[4].size() - 1;
  // cerr << A_len << " " << B_len << " " << C_len << endl;
  L[0] = f0.size() - 1;
  pos[0] = {{1, 1}, {2, 2}, {3, 3}};
  for (int i = 1; i < N; ++i) {
    pos[i].assign(5, pair<ll, ll>());
  }
  for (int i = 1; i < N; ++i) {
    ll r;
    L[i] = L[i - 1] * 2LL + 1LL * (A_len + B_len + C_len);
    if (L[i] > 1e18 + 100LL) L[i] = 1e18 + 100LL;
    pos[i][0] = {1, A_len};
    r = pos[i][0].second;
    pos[i][1] = {r + 1, r + L[i - 1]};
    r = pos[i][1].second;
    pos[i][2] = {r + 1, r + B_len};
    r = pos[i][2].second;
    pos[i][3] = {r + 1, r + L[i - 1]};
    r = pos[i][3].second;
    pos[i][4] = {r + 1, r + C_len};
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);

  init();
  while (cin >> q) {
    string ret;
    for (int i = 0; i < q; ++i) {
      cin >> n >> k;
      if (k > L[n]) {
        ret.push_back('.');
        continue;
      }


      do {
        if (n == 0) {
          ret.push_back(f0[k]);
          break;
        }

        int t;
        for (t = 0; t < 5; ++t) {
          if (k >= pos[n][t].first && k <= pos[n][t].second) break;
        }
        assert(t < 5);
        if (t & 1) {
          k -= pos[n][t - 1].second;
          --n;
          continue;
        } else {
          if (t) k -= pos[n][t - 1].second;
          // cout << "k=" << k << " char=" << str[t][k] << endl;
          ret.push_back(str[t][k]);
          break;
        }
      } while (true);
    }
    cout << ret << endl;
  }
  return 0;
}
