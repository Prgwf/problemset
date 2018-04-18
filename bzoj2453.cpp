/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 10000 + 7;

int n, q;
int a[maxn];
int b[maxn], pre[maxn], last[1000000 + 7];
int block, num, l[maxn], r[maxn], belong[maxn];

void reset(int x) {
  for (int i = l[x]; i <= r[x]; ++i) {
    pre[i] = b[i];
  }
  sort(pre + l[x], pre + r[x] + 1);
}

void build() {
  block = sqrt(n);
  num = n / block;
  if (n % block) num++;
  for (int i = 1; i <= num; ++i) {
    l[i] = (i - 1) * block + 1;
    r[i] = i * block;
  }
  r[num] = n;

  for (int i = 1; i <= n; ++i) {
    belong[i] = (i - 1) / block + 1;

    b[i] = last[a[i]];
    last[a[i]] = i;
  }

  for (int i = 1; i <= num; ++i) {
    reset(i);
  }
}

int find(int x, int v) {
  int lb = l[x], ub = r[x];
  int ans = l[x];
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (pre[mid] < v) {
      ans = mid;
      lb = mid + 1;
    } else {
      ub = mid - 1;
    }
  }
  return ans - l[x] + 1;
}

int query(int x, int y) {
  int sum = 0;
  if (belong[x] == belong[y]) {
    for (int i = x; i <= y; ++i) {
      if (b[i] < x) {
        ++sum;
      }
    }
    return sum;
  }

  for (int i = x; i <= r[belong[x]]; ++i) {
    if (b[i] < x) {
      ++sum;
    }
  }
  for (int i = belong[x] + 1; i < belong[y]; ++i) {
    sum += find(i, x);
  }
  for (int i = l[belong[y]]; i <= y; ++i) {
    if (b[i] < x) {
      ++sum;
    }
  }
  return sum;
}

void update(int x, int y) {
  for (int i = 1; i <= n; ++i) {
    last[a[i]] = 0;
  }
  a[x] = y;
  for (int i = 1; i <= n; ++i) {
    int t = b[i];
    b[i] = last[a[i]];
    last[a[i]] = i;
    if (t != b[i]) {
      reset(belong[i]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }

  build();
  char opt[2];
  int x, y;
  for (int i = 0; i < q; ++i) {
    scanf("%s%d%d", opt, &x, &y);
    if (opt[0] == 'Q') {
      printf("%d\n", query(x, y));
    } else {
      update(x, y);
    }
  }
}
