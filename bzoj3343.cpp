/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1000000 + 7;
int n, q;
int a[maxn], b[maxn];
int add[maxn]; // lazy tag
int block, num, l[maxn], r[maxn], belong[maxn];

void reset(int x) {
  int lb = l[x];
  int ub = r[x];

  for (int i = lb; i <= ub; ++i) {
    b[i] = a[i];
  }
  sort(b + lb, b + ub + 1);
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
  for (int i = 1; i <= num; ++i) {
    reset(i);
  }
}


int find(int x, int v) {
  int lb = (x - 1) * block + 1;
  int ub = min(x * block, n);
  int R = ub, ans = ub;
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (b[mid] >= v) {
      ans = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  return R - ans + 1;
}


void update(int x, int y, int z) {
  if (belong[x] == belong[y]) {
    for (int i = x; i <= y; ++i) {
      a[i] += z;
    }
    return;
  }

  for (int i = x; i <= r[belong[x]]; ++i) {
    a[i] += z;
  }
  for (int i = l[belong[y]]; i <= y; ++i) {
    a[i] += z;
  }
  reset(belong[x]);
  reset(belong[y]);
  for (int i = belong[x] + 1; i < belong[y]; ++i) {
    add[i] += z;
  }
}

int query(int x, int y, int z) {
  int sum = 0;
  if (belong[x] == belong[y]) {
    for (int i = x; i <= y; ++i) {
      if (a[i] + add[belong[i]] >= z) {
        ++sum;
      }
    }
    return sum;
  }

  for (int i = x; i <= r[belong[x]]; ++i) {
    if (a[i] + add[belong[i]] >= z) {
      ++sum;
    }
  }
  for (int i = l[belong[y]]; i <= y; ++i) {
    if (a[i] + add[belong[i]] >= z) {
      ++sum;
    }
  }
  for (int i = belong[x] + 1; i < belong[y]; ++i) {
    sum += find(i, z - add[i]);
  }
  return sum;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a  + i);
  }
  build();
  char opt[2];
  int x, y, z;
  for (int i = 0; i < q; ++i) {
    scanf("%s%d%d%d", opt, &x, &y, &z);
    if (opt[0] == 'M') {
      update(x, y, z);
    } else {
      printf("%d\n", query(x, y, z));
    }
  }
}
