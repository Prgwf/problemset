#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
const int N = 1e6 + 5;

int n, k;
int a[N];
vector<int> Min, Max;
struct Deque {
  int val, idx;
  Deque(int v = 0, int x = 0) : val(v), idx(x) {}
} Q[N];
int head, tail;
void get_max() {
  int i;
  head = 1; tail = 0;
  for (i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) tail--;
    ++tail;
    Q[tail].val = a[i]; Q[tail].idx = i;
  }
  for (i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) tail--;
    ++tail;
    Q[tail].val = a[i]; Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) ++head;
    Max.push_back(Q[head].val);
  }
}
void get_min() {
  int i;
  head = 1; tail = 0;
  for (i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) tail--;
    ++tail;
    Q[tail].val = a[i]; Q[tail].idx = i;
  }
  for (i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) tail--;
    ++tail;
    Q[tail].val = a[i]; Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) ++head;
    Min.push_back(Q[head].val);
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  get_max(); get_min();
  for (int i = 0; i < Min.size(); ++i) {
    printf("%d%c", Min[i], i < Min.size() - 1 ? ' ' : '\n');
  }
  for (int i = 0; i < Max.size(); ++i) {
    printf("%d%c", Max[i], i < Max.size() - 1 ? ' ' : '\n');  
  }  
}