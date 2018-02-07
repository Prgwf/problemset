#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 50050;

int T, n, s[N];
int wa[N], wb[N], wv[N], wc[N];
int sa[N], rk[N], height[N];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void build(int *r, int n, int m) {
  int *x=wa,*y=wb;

  for(int i=0; i<m; ++i) wc[i]=0;
  for(int i=0; i<n; ++i) wc[x[i]=r[i]]++;
  for(int i=1; i<m; ++i) wc[i]+=wc[i-1];
  for(int i=n-1; i>=0; --i) sa[--wc[x[i]]]=i;

  int p=1;
  for(int j=1; p<n; j<<=1,m=p){
    p=0;
    for(int i=n-j; i<n; ++i) y[p++]=i;
    for(int i=0; i<n; ++i) if(sa[i]>=j) y[p++]=sa[i]-j;
    for(int i=0; i<n; ++i) wv[i]=x[y[i]];
    for(int i=0; i<m; ++i) wc[i]=0;
    for(int i=0; i<n; ++i) wc[wv[i]]++;
    for(int i=1; i<m; ++i) wc[i]+=wc[i-1];
    for(int i=n-1; i>=0; --i) sa[--wc[wv[i]]]=y[i];
    swap(x,y); x[sa[0]]=0; p=1;
    for(int i=1; i<n; ++i) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
  }

  for(int i=1; i<n; ++i) rk[sa[i]]=i;
  int k=0;
  for(int i=0; i<n-1; height[rk[i++]]=k){
    if(k) --k;
    for(int j=sa[rk[i]-1]; r[i+k]==r[j+k]; ++k);
  }
}
int dp[N][20];
void rmq_init() {
  int *x = height;
  for (int i = 1; i <= n; ++i) dp[i][0] =  x[i];
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int rmq(int x, int y) {
  int l = rk[x];
  int r = rk[y];
  if (l > r) swap(l, r);
  int k = log(r - l + 1) / log(2.0);
  return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    char ch[4];
    for (int i = 0; i < n; ++i) {
      scanf("%s", ch);
      s[i] = ch[0] - 'a' + 1;
    }
    s[n] = 0;
    build(s, n + 1, 3);
    rmq_init();
    
    int ans = 0;
    for (int L = 1; L <= n; ++L) {
      for (int i = 0; i + L < n; i += L) {
        int lcp = rmq(i, i + L);
        int tmp = lcp / L + 1;
        int k = i - (L - lcp % L);
        if (k >= 0 && lcp % L) {
          if (rmq(k, k + L) >= lcp) {
            ++tmp;
          }
        }
        ans = max(ans, tmp);
      }       
    }
    printf("%d\n", ans);     
  }
}