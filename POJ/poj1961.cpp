#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e6 + 5;

int n;
char s[N];
int fail[N];
void get_fail() {
  fail[0] = -1;
  int i = 0, j = -1;
  while (i < n) {
    while (j != -1 && s[i] != s[j]) j = fail[j];
    ++i; ++j;
    fail[i] = j;  
  }
}
int main() {
  int kase = 0;
  while (scanf("%d", &n) != EOF && n) {
    scanf("%s", s);
    get_fail();
    printf("Test case #%d\n", ++kase);
    for (int i = 0; i < n; ++i) {
      int j = i + 1;
      int T = j - fail[j];
      if (j % T || j / T <= 1) {
        continue;
      }
      printf("%d %d\n", j, j / T);
    }
    puts("");
  }
}