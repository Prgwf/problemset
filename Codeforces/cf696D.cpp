/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix; 

const int inf = 0x3f3f3f3f;
const int maxn = 200 + 5;
const int mxch = 26;

ll n, l;
int a[maxn];
char s[maxn][maxn];
int id, root;
Matrix mat, ret, tmp;
struct node {
  int son[mxch];
  int fail;
  int cnt;
} T[maxn];

int getid(char ch) {
  return ch - 'a';
}

void new_node(int & o) {
  o = ++id;
  memset(T[o].son, -1, sizeof(T[o].son));
  T[o].cnt = 0;
}

void init() {
  id = 0;
  new_node(root);
}

void insert(const string & s, const int  & value) {
  int pt = root;
  for (char ch : s) {
    int k = getid(ch);
    if (T[pt].son[k] < 0) {
      new_node(T[pt].son[k]);
    }
    pt = T[pt].son[k];
  }
  T[pt].cnt += value;
}

void build() {
  queue<int> Q;

  for (int i = 0; i < mxch; ++i) {
    int & id = T[root].son[i];
    if (id < 0) {
      id = root;
    } else {
      T[id].fail = root;
      Q.push(id);
    }
  }

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop(); 
    T[u].cnt += T[T[u].fail].cnt;

    for (int i = 0; i < mxch; ++i) {
      int & id = T[u].son[i];
      if (id < 0) {
        id = T[T[u].fail].son[i];
      } else {
        T[id].fail = T[T[u].fail].son[i];
        Q.push(id);
      }
    }
  } 
}


Matrix operator * (const Matrix & x, const Matrix & y) {
  Matrix ret(id + 2, vector<ll>(id + 2, -1e18));
  for (int k = 1; k <= id; ++k) {
    for (int i = 1; i <= id; ++i) {
      for (int j = 1; j <= id; ++j) {
        ret[i][j] = max(x[i][k] + y[k][j], ret[i][j]);
      }
    }
  }
  return ret;
}

void solve() {
  l--;
  ret = mat;
  while (l) {
    if (l & 1) {
      ret = ret * mat;
    }
    l >>= 1;
    mat = mat * mat;
  }

  ll ans = -1;
  for (int i = 1; i <= id; ++i) {
    ans = max(ans, ret[root][i]);
  }
  printf("%lld\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  init();
  string word;
  for (int i = 1; i <= n; ++i) {
    cin >> word; 
    insert(word, a[i]);
  }

  build();

  mat.assign(id + 2, vector<ll>(id + 2, -1e18));
  for (int i = 1; i <= id; ++i) {
    /*
    for (int j = 0; j < mxch; ++j) {
      mat[i][T[i].son[j] = -1e18;
    }
    */
    for (int j = 0; j < mxch; ++j) {
      int k = T[i].son[j];
      mat[i][k] = T[k].cnt;
    }
  }

  solve();
}
