#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

typedef complex<double> Complex;
const long double PI = acos(0.0) * 2.0;
void FFT(vector<Complex>& a, bool inverse) {
  int n = a.size();
  for (int i = 0, j = 0; i < n; i++) {
    if (j > i) swap(a[i], a[j]);
    int k = n;
    while (j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  double pi = inverse ? -PI : PI;
  for (int step = 1; step < n; step <<= 1) {
    double alpha = pi / step;
    for (int k = 0; k < step; k++) {
      Complex omegak = exp(Complex(0, alpha * k));
      for (int Ek = k; Ek < n; Ek += step << 1) {
        int Ok = Ek + step;
        Complex t = omegak * a[Ok];
        a[Ok] = a[Ek] - t;
        a[Ek] += t;
      }
    }
  }

  if (inverse)
    for (int i = 0; i < n; i++) a[i] /= n;
}

const int maxn = 1e5 + 20;
char S[maxn], T[maxn];
int sum[maxn], slen, tlen, n;

void work(const char & ch) {
  vector<Complex> x(n);
  vector<Complex> y(n);
  for (int i = 0; i < slen; ++i) {
    x[i] = S[i] == ch ? Complex(1, 0) : Complex(0, 0);
  }
  for (int i = 0; i < tlen; ++i) {
    y[i] = T[i] == ch ? Complex(1, 0) : Complex(0, 0);
  }
  FFT(x, false);
  FFT(y, false);
  for (int i = 0; i < n; ++i) x[i] *= y[i];
  FFT(x, true);
  for (int i = 0; i < slen - tlen + 1; ++i) sum[i] += (int)(x[i + tlen - 1].real() + 0.5);
}

int main(int argc, char const* argv[]) {
  // freopen("data.in", "r", stdin);
  while (scanf("%s%s", S, T) != EOF) {
    slen = strlen(S);
    tlen = strlen(T);
    reverse(T, T + tlen);

    n = 2;
    while (n < (slen + tlen)) n <<= 1;

    memset(sum, 0, sizeof(sum));
    work('a');
    work('b');
    work('c');

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < slen - tlen + 1; ++i) {
      ans = min(ans, tlen - sum[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}