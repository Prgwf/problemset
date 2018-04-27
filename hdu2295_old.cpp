#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


const int N = 200 + 20;
const double eps = 1e-7;
struct DLX {
  int n, m, id;                       // 行列数、节点数
  int U[N*N], D[N*N], L[N*N], R[N*N];   // 第i个结点的上下左右一个
  int row[N*N], col[N*N];               // 第i个结点所有行列
  int S[N], H[N];                       // H[i]: 选择了i行， S[j]: 覆盖了j列
  int ansd, ans[N];
  bool vis[N*N];

  void init(int n, int m) {
    this->n = n;
    this->m = m;
    for (int i = 0; i <= m; ++i) {
      S[i] = 0;
      U[i] = D[i] = i;
      L[i] = i - 1;
      R[i] = i + 1;
    }
    R[m] = 0; L[0] = m;
    id = m;
    for (int i = 1; i <= n; ++i) {
      H[i] = -1;
    }
  }

  void link(int r, int c) {
    ++S[col[++id] = c];
    row[id] = r;          // 该结点的行数为r
    D[id] = D[c];         // 向下指向c的下面的第一个结点
    U[D[c]] = id;         // c的下面的第一个结点的上面为id
    U[id] = c;            // id的上面为列指针
    D[c] = id;            // 列指针指向的第一个该列中的元素设为si
    if (H[r] < 0) {
      // 如果第r行没有元素
      H[r] = L[id] = R[id] = id;
    } else {
      R[id] = R[H[r]];    // id的右边为行指针所指的右边第一个元素
      L[R[H[r]]] = id;    // 行指针所指的右边第一个元素的左侧为id
      L[id] = H[r];       // id的左侧为行指针
      R[H[r]] = id;       // 行指针的右侧为id
    }
  }

  /*重复覆盖
  1、如果矩阵为空，得到结果，返回
  2、从矩阵中选择一列，以选取最少元素的列为优化方式
  3、删除该列及其覆盖的行
  4、对该列的每一行元素：删除一行及其覆盖的列，
  5、进行下一层搜索，如果成功则返回
  6、恢复现场，跳至4
  7、恢复所选择行
  */
  bool dance(int d, int limit) {
    if (d > limit or  d + check() > limit) return false;
    if (R[0] == 0) {
      // 全部覆盖了
      ansd = d;
      return true;
    }

    int c = R[0]; // 表头结点指向的第一个列
    for (int i = R[0]; i != 0; i = R[i]) { //枚举列头指针
      if (S[i] < S[c]) {
        // 找到列中元素个数最少的
        c = i;
      }
    }
    for (int i = D[c]; i != c; i = D[i]) { // 枚举该列的元素
      ans[d] = row[i]; // 记录该列元素的行
      remove(i);
      for (int j = R[i]; j != i; j = R[j]) {
        remove(j);
      }
      if (dance(d + 1, limit)) return true;
      for (int j = L[i]; j != i; j = L[j]) {
        restore(j);
      }
      restore(i);
    }
    return false;
  }

  void remove(int c) {
    // c为元素编号，
    // 而非列号, 即删除该元素所在的列，包括它自身和列头指针*/
    for (int i = D[c]; i != c; i = D[i]) {
      L[R[i]] = L[i];
      R[L[i]] = R[i];
    }
  }

  void restore(int c) {
    for (int i = U[c]; i != c; i = U[i]) {
      L[R[i]] = R[L[i]] = i;
    }
  }

  int check() {
    /*
    强剪枝。
    这个剪枝利用的思想是A*搜索中的估价函数。
    对于当前的递归深度K下的矩阵，估计其最好情况下（即最少还需要多少步）才能出解。
    也就是，如果将能够覆盖当前列的所有行全部选中，去掉这些行能够覆盖到的列，将这个操作作为一层深度。
    重复此操作直到所有列全部出解的深度是多少。
    如果当前深度加上这个估价函数返回值，其和已然不能更优（也就是已经超过当前最优解），则直接返回，不必再搜。
    */
    memset(vis, 0, sizeof(vis));
    int ret = 0;
    for (int c = R[0]; c != 0; c = R[c]) vis[c] = true;
    for (int c = R[0]; c != 0; c = R[c]) {
      if (vis[c]) {
        ret++;
        vis[c] = false;
        for (int i = D[c]; i != c; i = D[i]) {
          for (int j = R[i]; j != i; j = R[j]) {
            vis[col[j]] = false;
          }
        }
      }
    }
    return ret;
  }

} dlx;

int Xradar[N], Yradar[N];
int Xcity[N], Ycity[N];
double dist[N][N];
int n, m, k, T;
int mat[N][N];
bool check(double x) {
  memset(mat, 0, sizeof(mat));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dist[i][j] <= x) {
        mat[i][j] = 1;
      }
    }
  }

  dlx.init(m, n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j]) {
        dlx.link(i + 1, j + 1);
      }
    }
  }
  return dlx.dance(0, k);
}
int main(int argc, char const *argv[])
{
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    memset(Xcity, 0, sizeof(Xcity));
    memset(Ycity, 0, sizeof(Ycity));
    memset(Xradar, 0, sizeof(Xradar));
    memset(Yradar, 0, sizeof(Yradar));

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", Xcity + i, Ycity + i);
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", Xradar + i, Yradar + i);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = sqrt((Xradar[i] - Xcity[j]) * (Xradar[i] - Xcity[j])
        + (Yradar[i] - Ycity[j]) * (Yradar[i] - Ycity[j]));
      }
    }

    double lb = 0, ub = 3e4;
    for (int i = 0; i < 50; ++i) {
      double mid = (lb + ub) / 2.0;
      if (check(mid)) ub = mid;
      else lb = mid;
    }
    printf("%.6f\n", lb);
  }
  return 0;
}
