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

int wa[N], wb[N], wc[N], wv[N];
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

int n, k, s[N];
struct Deque {
  int v, i;
} Q[N];
int head, tail;
int main() {
  scanf("%d %d", &n, &k); k--;
  for (int i = 0; i < n; ++i) scanf("%d", s + i);
  vector<int> b;
  for (int i = 0; i < n; ++i) b.push_back(s[i]);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; ++i) s[i] = lower_bound(b.begin(), b.end(), s[i]) - b.begin() + 1;
  n++; s[n - 1] = 0;
  build(s, n, n);

  int *x = height, ans = 0;
  head = 1; tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].v >= x[i]) --tail;
    ++tail; Q[tail].v = x[i]; Q[tail].i = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].v >= x[i]) --tail;
    ++tail; Q[tail].v = x[i]; Q[tail].i = i;
    while (head <= tail && Q[head].i < i - k + 1) ++head;
    ans = max(ans, Q[head].v);
  } 

  printf("%d\n", ans);
  return 0; 
}