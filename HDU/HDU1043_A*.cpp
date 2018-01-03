/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;
struct node {
  int state, pos;
  int F, G, H;
  bool operator < (const node& rhs) const {
    return F > rhs.F;
  }
} ;
struct path {
  int pre, dir;
} fa[maxn];
priority_queue<node> Q;
int mark[maxn];
int G[maxn];
int fact[maxn];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
string dir = "udlr";
stack<int> S;
char buf[2];
char str[20];
bool check(int x, int y) {
  if (x < 0 || x > 2 || y < 0 || y > 2) return 0;
  return 1;
}
int cantor() {
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    int cont = 0;
    for (int j = i + 1; j < 9; ++j) {
      if (str[j] < str[i]) {
        ++cont;
      }
    }
    ret += cont * fact[9 - i - 1];
  }
  return ret;
}
void decantor(int state) {
  vector<int> left;
  for (int i = 1; i <= 9; ++i) {
    left.push_back(i);
  }
  for (int i = 0; i < 9; ++i) {
    int r = state % fact[9 - i - 1];
    int t = state / fact[9 - i - 1];
    state = r;
    sort(left.begin(), left.end());
    str[i] = '0' + left[t];
    str[i] = (str[i] == '9' ? 'x' : str[i]);
    left.erase(left.begin() + t);
  }
}
void input() {
  str[0] = buf[0];
  for (int i = 1; i < 9; ++i) {
    scanf("%s", buf);
    str[i] = buf[0];
  }
}
char buffer[20];
int H(int state) {
  memcpy(buffer, str, sizeof(str));
  decantor(state);
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    if (i < 8 && str[i] - '0' != i + 1) {
      ret++;
    }
    if (i == 8 && str[i] != 'x') {
      ret++;
    }
  }
  memcpy(str, buffer, sizeof(buffer));
  return ret;
}
void Astar(int state, int pos) {
  memset(mark, 0, sizeof(mark));
  memset(G, -1, sizeof(G));
  while (!Q.empty()) {
    Q.pop();
  }
  while (!S.empty()) {
    S.pop();
  }

  mark[state] = 2;
  G[state] = 0;
  fa[state] = {-1, -1};
  int th = H(state);
  Q.push({state, pos, 0 + th, 0, th});
  while (!Q.empty()) {
    node now = Q.top(); Q.pop();
    mark[now.state] = 2;
    decantor(now.state);
    if (now.state == 0) {
      int cur = now.state;
      while (true) {
        if (fa[cur].pre == -1) {
          break;
        }
        S.push(fa[cur].dir);
        cur = fa[cur].pre;
      }
      break;
    }
    int x, y, tx, ty, ts, tp;
    x = now.pos / 3;
    y = now.pos % 3;
    for (int i = 0; i < 4; ++i) {
      tx = x + dx[i];
      ty = y + dy[i];
      if (!check(tx, ty)) {
        continue;
      }
      tp = 3 * tx + ty;
      swap(str[tp], str[now.pos]);
      ts = cantor();
      swap(str[tp], str[now.pos]);
      if (!mark[ts] || (mark[ts] == 1 && now.G + 1 < G[ts])) {
        mark[ts] = 1;
        G[ts] = now.G + 1;
        fa[ts] = {now.state, i};
        Q.push({ts, tp, G[ts] + H(ts), G[ts], H(ts)});
      }
    }
  }

  while (!S.empty()) {
    putchar(dir[S.top()]);
    S.pop();
  }
  puts("");
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);

  fact[0] = 1;
  for (int i = 1; i < 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  while (~scanf("%s", buf)) {
    input();

    int sum = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] == 'x') continue;
      for (int j = 0; j < i; j++) {
        if (str[j] == 'x') continue;
        if (str[i] < str[j]) sum++;
      }
    }
    if (sum & 1) {
      puts("unsolvable");
      continue;
    }
    int pos;
    for (int i = 0; i < 9; ++i) {
      if (str[i] == 'x') {
        pos = i;
      }
    }
    int state = cantor();
    Astar(state, pos);
  }
}
