/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 20000 + 7;

int n, q;
int a[maxn], mep[1000000 + 20], tot;
int belong[maxn], block, num, l[maxn], r[maxn];
int sum[32][32][maxn];
int cnt[32][32];

void build() {
  block = pow(1.0 * n, 2.0 / 3.0);
  num = n / block;
  if (n % block) num++;
  for (int i = 1; i <= num; ++i) {
    l[i] = (i - 1) * block + 1;
    r[i] = i * block;
  }
  r[num] = n;

  for (int i = 1; i <= n; ++i) {
    belong[i] = (i - 1) / block + 1;
  }

  for (int i = 1; i <= num; ++i) {
    for (int j = i; j <= num; ++j) {
      for (int k = l[i]; k <= r[j]; ++k) {
        if (!sum[i][j][a[k]]) {
          cnt[i][j]++;
        }
        sum[i][j][a[k]]++;
      }
    }
  }
}

int query(int x, int y) {
  if (belong[x] == belong[y]) {
    map<int, int> temp;
    for (int i = x; i <= y; ++i) {
      temp[a[i]]++;
    }
    return temp.size();
  }

  int u = belong[x] + 1;
  int v = belong[y] - 1;
  for (int i = x; i < l[u] && i <= y; ++i) {
    if (!sum[u][v][a[i]]) {
      cnt[u][v]++;
    }
    sum[u][v][a[i]]++;
  }
  for (int i = y; i > r[v] && i >= x; --i) {
    if (!sum[u][v][a[i]]) {
      cnt[u][v]++;
    }
    sum[u][v][a[i]]++;
  }
  int ret = cnt[u][v];
  for (int i = x; i < l[u] && i <= y; ++i) {
    if (!--sum[u][v][a[i]]) {
      cnt[u][v]--;
    }
  }
  for (int i = y; i > r[v] && i >= x; --i) {
    if (!--sum[u][v][a[i]]) {
      cnt[u][v]--;
    }
  }
  return ret;
}

void update(int x, int y) {
  for (int i = 1; i <= num; ++i) {
    for (int j = i; j <= num; ++j) {
      if (l[i] <= x && x <= r[j]) {
        if (!--sum[i][j][a[x]]) {
          --cnt[i][j];
        }
      }
    }
  }
  if (!mep[y]) {
    mep[y] = ++tot;
  }
  a[x] = mep[y];
  for (int i = 1; i <= num; ++i) {
    for (int j = i; j <= num; ++j) {
      if (l[i] <= x && x <= r[j]) {
        if (!sum[i][j][a[x]]) {
          cnt[i][j]++;
        }
        sum[i][j][a[x]]++;
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (!mep[x]) {
      mep[x] = ++tot;
    }
    a[i] = mep[x];
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

/*
6 5
1 2 3 4 5 5
Q 1 4
Q 2 6
R 1 2
Q 1 4
Q 2 6
*/
