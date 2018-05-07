#include <bits/stdc++.h>
using namespace std;

int x, y;
double p, q;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %lf %lf", &x, &y, &p, &q);
    double te = 0, we = 0;
    te = (1 - q) * x;
    te += q * p * (x + y);

    we = q * y;
    we += (1 - q) * p * (y + x);

    if (te > we) printf("%s %.4lf\n", "tiger", te);         
    else printf("%s %.4lf\n", "wolf", we);      
  }
}