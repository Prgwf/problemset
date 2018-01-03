#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 20;
const int chsz = 26;
struct Tire {
  int tot;
  int root;
  int fail[maxn], next[maxn][chsz], end[maxn];
  int newnode() {
    for (int i = 0; i < chsz; ++i) {
      next[tot][i] = -1;
    }
    end[tot++] = 0;
    return tot - 1;
  }

  void init() {
    tot = 0;
    root = newnode();
  }

  void insert(const char* str) {
    int now = root;
    while (*str) {
      int chid = *str - 'a';
      if (next[now][chid] == -1) next[now][chid] = newnode();
      now = next[now][chid];
      ++str;
    }
    ++end[now];
  }

  void build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < chsz; ++i) {
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }
    }

    while (!q.empty()) {
      int now = q.front(); q.pop();
      for (int i = 0; i < chsz; ++i) {
        if (next[now][i] == -1) {
          next[now][i] = next[fail[now]][i];
          printf("%c is not exist refer to %c\n", i + 'a', i + 'a');
        } else {
          fail[next[now][i]] = next[fail[now]][i];
          q.push(next[now][i]);
        }
      }
    }
  }

  int solve(const char *str) {
    int ret = 0, k = 0;
    while (*str) {
      int chid = *str - 'a';
      k = next[k][chid];
      int j = k;
      while (j) {
        ret += end[j];
        end[j] = 0;
        j = fail[j];
      }
      ++str;
    }
    return ret;
  }

} AC;
int N;
inline void work() {
  static char buf[1000020];
  scanf("%d", &N);
  AC.init();
  for (int i = 0; i < N; ++i) {
    scanf("%s", buf);
    AC.insert(buf);
  }
  AC.build();
  scanf("%s", buf);
  printf("%d\n", AC.solve(buf));
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
