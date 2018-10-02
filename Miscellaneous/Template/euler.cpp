const long maxn = 200000;
long prime[maxn] = {0}, num_prime = 0;
int not_prime[maxn] = {1, 1};
void get_prime() {
  for (int i = 2; i < maxn; ++i) {
    if (!not_prime[i]) prime[++num_prime] = i;
    for (int j = 1; j <= num_prime && i * prime[j] < maxn; ++j) {
      not_prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}

int phi[maxn];
void get_phi() {
  int i, j, k;
  k = 0;
  for (i = 2; i < maxn; i++) {
    if (not_prime[i] == false) {
      prime[k++] = i;
      phi[i] = i - 1;
    }
    for (j = 0; j < k && i * prime[j] < maxn; j++) {
      not_prime[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      }
    }
  }
}

vector<int> a[N];
// prime factor
for (int i = 2; i <= 1000000; ++i) {
  if (a[i].size() > 0) continue;
  for (int j = i; j <= 1000000; j += i) {
    a[j].push_back(i);
  }
}
// all factor
for (int i = 1; i <= 1000000; ++i) {
  for (int j = i; j <= 1000000; j += i) {
    a[j].push_back(i);
  }
}
