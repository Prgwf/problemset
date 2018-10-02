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

const int N = 5000 + 20;
const int INF = 0x3f3f3f3f;

const int maxn = 1024 + 10;
const int maxr = 4096 + 10;
const int maxnode = maxr * 4 + maxn;
struct DLX {
    int n, sz; // 列数，结点总数
    int S[maxn]; // 各列结点数

    int row[maxnode], col[maxnode]; // 各结点行列编号
    int L[maxnode], R[maxnode], U[maxnode], D[maxnode]; // 十字链表

    int ansd, ans[maxr]; // 解

    void init(int n) { // n是列数
        this->n = n;

        // 虚拟结点
        for(int i = 0; i <= n; i++) {
            U[i] = i; D[i] = i; L[i] = i - 1; R[i] = i + 1;
        }
        R[n] = 0; L[0] = n;

        sz = n + 1;
        memset(S, 0, sizeof(S));
    }

    void addRow(int r, vector<int> columns) {
        int first = sz;
        for(int i = 0; i < columns.size(); i++) {
            int c = columns[i];
            L[sz] = sz - 1; R[sz] = sz + 1; D[sz] = c; U[sz] = U[c];
            D[U[c]] = sz; U[c] = sz;
            row[sz] = r; col[sz] = c;
            S[c]++; sz++;
        }
        R[sz-1] = first; L[first] = sz - 1;
    }

    // 顺着链表，遍历除s外的其他元素  #define FOR(i, A, s) for(int i = A[s]; i != s; i = A[i])
    void remove(int c) {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        for(int i = D[c]; i != c; i = D[i])
            for(int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[col[j]];
            }
    }

    void restore(int c) {
        for(int i = U[c]; i != c; i = U[i])
            for(int j = L[i]; j != i; j = L[j]) {
                ++S[col[j]];
                U[D[j]] = j;
                D[U[j]] = j;
            }
        L[R[c]] = c;
        R[L[c]] = c;
    }

    // d为递归深度
    bool dfs(int d) {
        if(R[0] == 0) { // 找到解
            ansd = d; // 记录解的长度
            return true;
        }
        int c = R[0]; //第一个未删除的列
        for(int i = R[0]; i != 0; i = R[i])
            if(S[i] < S[c]) c = i;

        remove(c); // 删除第c列
        for(int i = D[c]; i != c; i = D[i]) { // 用结点i所在行覆盖第c列
            ans[d] = row[i];
            for(int j = R[i]; j != i; j = R[j]) remove(col[j]); // 删除结点i所在行能覆盖的所有其他列
            if(dfs(d + 1)) return true;
            for(int j = L[i]; j != i; j = L[j]) restore(col[j]); // 恢复结点i所在行能覆盖的所有其他列
        }

        restore(c); // 恢复第c列
        return false;
    }

    bool solve(vector<int> &v) {
        v.clear();
        if(!dfs(0)) return false;
        for(int i = 0; i < ansd; i++) v.push_back(ans[i]);
        return true;
    }
} dlx;

const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;
int encode(int i, int j, int k) {
  return i * 256 + j * 16 + k + 1;
}
tuple<int, int, int> decode(int x) {
  x--;
  int i, j, k;
  k = x % 16; x /= 16;
  j = x % 16; x /= 16;
  i = x % 16;
  return make_tuple(i, j, k);
}

char raw[20][20];
bool read() {
  for (int i = 0; i < 16; ++i) {
    if (scanf("%s", raw[i]) == EOF) return false;
  }
  return true;
}

void build() {
  for (int r = 0; r < 16; ++r) 
  for (int c = 0; c < 16; ++c) 
  for (int v = 0; v < 16; ++v) {
    if (raw[r][c] == '-' || raw[r][c] == 'A' + v) {
      vector<int> columns;
      columns.push_back(encode(SLOT, r, c));
      columns.push_back(encode(ROW, r, v));
      columns.push_back(encode(COL, c, v));
      columns.push_back(encode(SUB, (r/4)*4+c/4, v));
      dlx.addRow(encode(r, c, v), columns);
    }
  }
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int kase = 0;
  while (read()) {
    if (kase++) puts("");

    dlx.init(16*16*4);
    build();
    vector<int> ans;
    dlx.solve(ans);
    for (int i = 0; i < (int)ans.size(); ++i) {
      int x, y, w;
      tie(x, y, w) = decode(ans[i]);
      raw[x][y] = 'A' + w;
    }
    for (int i = 0; i < 16; ++i) {
      puts(raw[i]);
    }
  }
  return 0;
}
