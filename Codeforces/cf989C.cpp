#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include <functional>
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int a, b, c, d;
char grid[55][55];
vector<string> ans;
void make(int x, char in, char out) {
  vector<string> ret(4, string(50, out));
  if (x) ret[3][0] = in;
  for (int j = 1; j < x; ++j) {
    int i = j % 3; 
    if (i == 0) i = 3;
    ret[i][j] = in;
  }
  for (const string & s : ret) {
    // cout << ret[i] << endl;
    ans.emplace_back(s);
  }
}
void solve(int x, char color) {
  while (x >= 49) {
    x -= 49;
    make(49, color, 'D');
  }
  if (x > 0) {
    if (x == 1) {
      string tmp(24, 'D');
      tmp.push_back(color);
      for (int i = 0; i < 25; ++i) tmp.push_back('D');
      ans.emplace_back(string(50, 'D'));
      ans.emplace_back(tmp);
      ans.emplace_back(string(50, 'D'));      
      return;

    }
    if (x == 2) {
      string tmp(24, 'D');
      tmp.push_back(color);
      tmp.push_back('D');
      tmp.push_back(color);
      for (int i = 0; i < 23; ++i) tmp.push_back('D');
      ans.emplace_back(string(50, 'D'));
      ans.emplace_back(tmp);
      ans.emplace_back(string(50, 'D'));      
      return;
    }
    assert(x < 49);
    make(x, color, 'D');
    x -= x;
  }
}
int main(int args, char const *argv[]) {
#ifdef LOCAL_TEST
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int aa = a, bb = b, cc = c, dd = d;
  d--;
  if (d <= 49) {
    c--;
    make(d, 'D', 'C');
    ans.emplace_back(string(50, 'C'));
  } else if (d <= 49 * 2) {
    b--; c--;
    make(49, 'D', 'C');
    ans.emplace_back(string(50, 'C'));
    make(d - 49, 'D', 'B');
    ans.emplace_back(string(50, 'B'));
  } else {
    a--; b--; c--;
    make(49, 'D', 'C');
    ans.emplace_back(string(50, 'C'));
    make(49, 'D', 'B');
    ans.emplace_back(string(50, 'B'));
    make(d - 49 * 2, 'D', 'A');
    ans.emplace_back(string(50, 'A'));
  }
  solve(a, 'A'); 
  solve(b, 'B'); 
  solve(c, 'C');
  ans.emplace_back(string(50, 'D'));
  int h = ans.size(), w = 50;
  // assert(h <= 50);
  function<map<char, int>(int, int)> check = [&](int h, int w) {
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    vector<int> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};    
    function<void(int, int)> dfs = [&](int x, int y) {
      vis[x][y] = true;
      for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= h || ty < 0 || ty >= w) continue;
        if (vis[tx][ty]) continue;
        if (ans[tx][ty] == ans[x][y]) dfs(tx, ty);
      }
    };
    map<char, int> cnt;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (vis[i][j] == false) {
          dfs(i, j);
          cnt[ans[i][j]]++;
        }
      }
    }
    return cnt;
  };
  map<char, int> cnt(check(h, w));
  assert(aa == cnt['A'] && bb == cnt['B'] && cc == cnt['C'] && dd == cnt['D']);
  // printf("A:%d\nB:%d\nC:%d\nD:%d\n", cnt['A'], cnt['B'], cnt['C'], cnt['D']);
  printf("%d %d\n", h, w);
  for (const string & s : ans) {
    cout << s << endl;
  }
  return 0;
}