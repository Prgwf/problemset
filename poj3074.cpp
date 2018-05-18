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
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 1000 + 20;
const int INF = 0x3f3f3f3f;
const int maxnnode = 5e5 + 20;

struct DLX {
  int U[maxnnode], D[maxnnode], L[maxnnode], R[maxnnode];
  int row[maxnnode], col[maxnnode];
  int S[N], H[N], ans[N], ansd, sz;
  int n, m; // n行， m列

  void init(int n, int m) {
    this->n = n;
    this->m = m;
    for (int i = 0; i <= m; i++) {
      L[i] = i - 1; R[i] = i + 1; U[i] = D[i] = i;
    }
    L[0] = m; R[m] = 0;
    sz = m + 1;
    memset(S, 0, sizeof(S));
    memset(H, -1, sizeof(H));
  }
  void link(int r, int c) {
    row[sz] = r; col[sz] = c;
    U[sz] = U[c]; D[sz] = c;
    D[U[sz]] = sz; U[D[sz]] = sz;
    if (H[r] == -1) {
      L[sz] = sz; R[sz] = sz;
      H[r] = sz;
    } else {
      R[sz] = H[r]; L[sz] = L[H[r]]; L[R[sz]] = sz; R[L[sz]] = sz;
    }
    S[col[sz]]++; sz++;
  }
  void remove(int c) {
    R[L[c]] = R[c]; L[R[c]] = L[c];
    for (int i = D[c]; i != c; i = D[i]) {
      for (int j = R[i]; j != i; j = R[j]) {
        U[D[j]] = U[j]; D[U[j]] = D[j];
        S[col[j]]--;
      }
    }
  }
  void restore(int c) {
    for (int i = U[c]; i != c; i = U[i]) {
      for (int j = L[i]; j != i; j = L[j]) {
        U[D[j]] = j; D[U[j]] = j;
        S[col[j]]++;
      }
    }
    R[L[c]] = c; L[R[c]] = c;
  }
  bool dfs(int d) {
    if (R[0] == 0) {
      ansd = d;
      return true;
    }
    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i]) {
      if (S[i] < S[c]) c = i;
    }
    remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
      ans[d] = row[i];
      for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
      if (dfs(d + 1)) return true;
      for (int j = L[i]; j != i; j = L[j]) restore(col[j]);
    }
    restore(c);
    return false;
  }
  bool dance(vector<int> &v) {
    v.clear();
    if (!dfs(0)) return false;
    for (int i = 0; i < ansd; i++) {
      v.push_back(ans[i]);
    }
    return true;
  }
} dlx;

char raw[9 * 9 + 5];
int grid[10][10];
void Set(int i, int j, int k) {
  int id = (i - 1) * 9 + j;
  int pid = (id - 1) * 9 + k;

  dlx.link(pid, (i-1)*9+k); // row
  dlx.link(pid, 81+(j-1)*9+k); // col 
  int t = ((i-1)/3*3+(j-1)/3)+1; // block
  dlx.link(pid, 162+(t-1)*9+k); 
  dlx.link(pid, 243+(i-1)*9+j);
}
void Get(int x, int &i, int &j, int &k) {
  x--;
  k = x % 9; x /= 9;
  j = x % 9; x /= 9;
  i = x % 9;
  i++; j++; k++;
}
void build() {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (grid[i][j]) Set(i, j, grid[i][j]);
      else for (int k = 1; k <= 9; ++k) Set(i, j, k);
    }
  }
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  while (scanf("%s", raw + 1) != EOF) {
    if (raw[1] == 'e') break;

    dlx.init(9*9*9, 9*9*4);
    memset(grid, 0, sizeof(grid));    
    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        char c = raw[(i - 1)*9 + j];
        if (c !='.') grid[i][j] = c - '0';
      }
    }
    build();
    vector<int> ans;
    dlx.dance(ans);
    for (int i = 0; i < ans.size(); ++i) {
      int v=  ans[i];
      int x, y, w;
      Get(v, x, y, w);
      grid[x][y] = w;
    }
    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        putchar(grid[i][j] + '0');
      }
    }
    printf("\n");
  }
  return 0;
}
