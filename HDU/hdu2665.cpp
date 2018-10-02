#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll T, ll b) {ll res=1;T%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*T%mod;T=T*T%mod;}return res;}
ll gcd(ll T, ll b) { return b ? gcd(b, T % b) : T; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

struct node {
  int sum;
  int l, r;
} T[N * 40];
int id = 0;
int root[N];
void update(int l, int r, int &x, int y, int pos) {
  x = ++id; T[x] = T[y]; T[x].sum++;

  if (l == r) return;

  int m = (l + r) / 2;
  if (pos <= m) {
    update(l, m, T[x].l, T[y].l, pos);
  } else {
    update(m + 1, r, T[x].r, T[y].r, pos);
  }
}
int query(int l, int r, int x, int y, int k) {
  if (l == r) return l;
  int sum = T[T[y].l].sum - T[T[x].l].sum;
  int m = (l + r) / 2;
  if (k <= sum) {
    return query(l, m, T[x].l, T[y].l, k);
  } else {
    return query(m +1, r, T[x].r, T[y].r, k - sum);
  }
}
int val[N];
vector<int> A;
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, q;
    scanf("%d %d", &n, &q);
    A.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", val + i);
      A.push_back(val[i]);
    }
    id = 0;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for (int i = 1; i <= n; ++i) val[i] = lower_bound(A.begin(), A.end(), val[i]) - A.begin() + 1;
    for (int i = 1; i <= n; ++i) update(1, n, root[i], root[i - 1], val[i]);
    while (q--) {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      printf("%d\n", A[query(1, n, root[l - 1], root[r], k) - 1]);
    }
  }
}
