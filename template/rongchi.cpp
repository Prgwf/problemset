for (int i = 2; i * i <= n; ++i) {
  if (n % i == 0) {
    factor.push_back(i);
    do {
      n /= i;
    } while (n % i == 0);
  }
}
if (n > 1) factor.push_back(n);
int tot = factor.size();

top = 0;
Q[top++] = -1;
for (int i = 0; i < tot; ++i) {
  int k = top;
  for (int j = 0; j < k; ++j) {
    Q[top++] = Q[j] * factor[i] * (-1);
  }
}
