#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 100005;

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

int n, s[N];
bool check(int k) {
  int mn = inf;
  int mx = -inf;
  for (int i = 1; i <= n; ++i) {
    if (height[i] >= k) {
      mn = min(mn, min(sa[i], sa[i - 1]));
      mx = max(mx, max(sa[i], sa[i - 1]));
      if (mx - mn > k) return 1;
    } else {
      mn = sa[i];
      mx = sa[i];
    }
  }  
  return 0;
}

int main() {
  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", s + i);
    }
    for (int i = 0; i + 1 < n; ++i) {
      s[i] = s[i + 1] - s[i];
    }
    for (int i = 0; i < n - 1; ++i) {
      s[i] += 100;
    }
    s[n - 1] = 0;

    // printf("before build\n");
    build(s, n, 256);

    // printf("after build\n");
    int lb = 0, ub = N - 1, ans = 0;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (check(mid)) {
        ans = mid;
        lb = mid + 1;  
      } else {
        ub = mid - 1;
      }
    }
    printf("%d\n", ans >= 4? ans + 1: 0);
  }
  return 0; 
}