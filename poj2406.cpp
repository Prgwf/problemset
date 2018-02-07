#include <cstdio>
#include <cstring>

const int N = 1e6 + 5;
int n;
char s[N];
int fail[N];
void get_next() {
  fail[0] = -1;
  int i = 0;
  int j = -1;
  while (i < n) {
    while (j != -1 && s[j] != s[i]) j = fail[j];
    ++i; ++j;
    fail[i] = j;
  }
}
int main() {
  while (scanf("%s", s) != EOF && s[0] != '.') {
    // puts(s);
    n = strlen(s);
    get_next();
    
    int t = n - fail[n];
    if (n % t) puts("1");
    else printf("%d\n", n / t);
  }
}