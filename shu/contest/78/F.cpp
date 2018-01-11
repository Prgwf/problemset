/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 10000;

struct Matrix {
  int n;
  ll mat[2][2];
  Matrix (int size) : n(size) {
    clear();
  }
  void clear() {
    memset(mat, 0, sizeof(mat));
  } 

  void unit() {
    for (int i = 0; i < n; ++i) {
      mat[i][i] = 1;
    }
  }

  Matrix operator * (const Matrix & rhs) const {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (mat[i][j]) {
        for (int k = 0; k < n; ++k) {
          ret.mat[i][k] = (1LL * ret.mat[i][k] 
                        + mat[i][j] * rhs.mat[j][k] % moder) % moder;
        }
      }
    }
    return ret;
  }

  vector<ll> operator * (const vector<ll> & rhs) {
    vector<ll> ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[i] = (ret[i] + mat[i][j] * rhs[j] % moder) % moder;
      }
    }
    return ret;
  }

  Matrix operator ^ (ll b) {
    Matrix ret(n);
    ret.unit();
    Matrix base = *this;

    while (b) {
      if (b & 1) 
        ret = ret * base;

      base = base * base;
      b >>= 1;
    }
    return ret;
  }
} ;
struct Solution {

  void work() {

    int n;
    while (cin >> n) {
      if (n < 0) {
        break;
      }

      if (n <= 1) {
        cout << n << endl;
      } else {
        Matrix raw(2);
        raw.mat[0][0] = 1;
        raw.mat[0][1] = 1;
        raw.mat[1][0] = 1;
        vector<ll> col{1, 0};
        raw = raw ^ (n - 1);        
        vector<ll> ans = raw * col;
        cout << ans[0] << endl;
      }
    }
  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

