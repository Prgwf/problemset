#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 2000 + 20;
const int maxr = 2000 + 20;
const int maxnode = 2e5 + 20;
struct DLX {
  int U[maxnode], D[maxnode], L[maxnode], R[maxnode];
  int row[maxnode], col[maxnode];
  int S[maxn], H[maxr], ans[maxr], ansd, sz;
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
  void addNode(int r, int c) {
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


int mat[10][10];
vector<int> ans;
void Encode(int i, int j, int k) {
  int id = (i - 1) * 9 + j; // 格子编号
  int pid = (id - 1) * 9 + k; // 格子填k的方案编号

  /* 对于第i行第j列填写数字k时，其对应的序号为(i-1)*9+k */
  dlx.addNode(pid, (i - 1) * 9 + k);

  /* 对于第i行第j列填写数字k时，其对应的序号为81+(j-1)*9+k */
  dlx.addNode(pid, 81 + (j - 1) * 9 + k);

  /* 对于第i行第j列填写数字k时，位于第t个九宫，其对应的序号为162+(t-1)*9+k */
  int t = ((i - 1) / 3 * 3 + (j - 1) / 3) + 1;
  dlx.addNode(pid, 162 + (t - 1) * 9 + k);

  /* 对于第i行第j列填写数字k时，其对应的序号为243+(i-1)*9+j */
  dlx.addNode(pid, 243 + id);

}
void Decode(int x, int &i, int &j, int &k) {
  x--;

  k = x % 9; x /= 9;
  j = x % 9; x /= 9;
  i = x % 9;
  i++; j++; k++;
}
void Build() {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (mat[i][j]) {
        Encode(i, j, mat[i][j]);
      } else {
        for (int k = 1; k <= 9; ++k) {
          Encode(i, j, k);
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);

  while (T--) {
    dlx.init(9*9*9, 9*9*4);

    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        scanf("%d", &mat[i][j]);
      }
    }

    Build();
    vector<int> line;
    dlx.dance(line);
    for (int x : line) {
      static int i, j, k;
      Decode(x, i, j, k);
      mat[i][j] = k;
    }

    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        printf("%d%c", mat[i][j], j < 9 ? ' ' : '\n');
      }
    }
  }
}
