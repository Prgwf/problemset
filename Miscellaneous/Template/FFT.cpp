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


/*a * b
void operator * (const vector<double>& v1, const vector<double>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while(S < s1 + s2) S <<= 1;
  vector<Complex> a(S,0), b(S,0);
  for(int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for(int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for(int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<int> res(S + 1);
  for(int i = 0; i < S; i++) {
    res[i] = a[i].real() + 0.5; 
  }
  for (int i = 0; i < S; ++i) {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
  int bound = 0;
  for (int i = S - 1; i >= 0; --i) {
    if (res[i]) {
      bound = i;
      break;
    }
  }
  for (int i = bound; i >= 0; --i) {
    putchar('0' + res[i]);
  }
  puts("");
}

char s1[maxn], s2[maxn];
vector<double> a, b;
int main() {
  while (scanf("%s", s1) != EOF) {
    scanf("%s", s2);
    a.clear(); b.clear();
    int n = strlen(s1);
    for (int i = 0; i < n; ++i) {
      a.push_back((double)(s1[n - i - 1] - '0'));
    }
    n = strlen(s2);
    for (int i = 0; i < n; ++i) {
      b.push_back((double)(s2[n - i - 1] - '0'));
    }
    a * b;
  }
}
*/

/*string
int main(int argc, char const* argv[]) {
  // freopen("data.in", "r", stdin);
  while (scanf("%s%s", S, T) != EOF) {
    slen = strlen(S);
    tlen = strlen(T);
    reverse(T, T + tlen);

    int n = 2;
    while (n < (slen + tlen)) n <<= 1;

    x.assign(n, 0);
    y.assign(n, 0);
    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < slen; ++i) {
      x[i] = S[i] == 'a' ? Complex(1, 0) : Complex(0, 0);
    }
    for (int i = 0; i < tlen; ++i) {
      y[i] = T[i] == 'b' ? Complex(1, 0) : Complex(0, 0);      
    }
    FFT(x, false); FFT(y, false);
    for (int i = 0; i < n; ++i) x[i] *= y[i];
    FFT(x, true);
    for (int i = 0; i < slen - tlen + 1; ++i) sum[i] = (int)(x[i + tlen - 1].real() + 0.5);

    x.assign(n, 0);
    y.assign(n, 0);
    for (int i = 0; i < slen; ++i) {
      x[i] = S[i] == 'b' ? Complex(1, 0) : Complex(0, 0);
    }
    for (int i = 0; i < tlen; ++i) {
      y[i] = T[i] == 'a' ? Complex(1, 0) : Complex(0, 0);      
    }
    FFT(x, false); FFT(y, false);
    for (int i = 0; i < n; ++i) x[i] *= y[i];
    FFT(x, true);
    for (int i = 0; i < slen - tlen + 1; ++i) sum[i] += (int)(x[i + tlen - 1].real() + 0.5);

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < slen - tlen + 1; ++i) {
      ans = min(ans, sum[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}*/