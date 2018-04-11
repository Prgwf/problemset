#include <bits/stdc++.h>
using namespace std;

double ta, tb;
struct TPoint {
  double x, y;
} ;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf %lf", &ta, &tb);
    TPoint A, B;
    A = {cos(ta), sin(ta)};
    B = {cos(tb), sin(tb)};
    
    if (A.x >= 0 and A.y >= 0) {
      if ((B.x >= 0 and B.y <= A.y) or (B.x >= 0 and B.y <= 0) or (B.x <= 0 and B.y <= -A.y)) puts("clockwise");
      else puts("counterclockwise");
    } else if (A.x >= 0 and A.y <= 0) {
      if ((B.x >= 0 and B.y <= A.y) or (B.x <= 0 and B.y <= 0) or (B.x <= 0 and B.y <= -A.y)) puts("clockwise");
      else puts("counterclockwise");
    } else if (A.x <= 0 and A.y >= 0) {
      if ((B.x <= 0 and B.y >= A.y) or (B.x >= 0 and B.y >= 0) or (B.x >= 0 and B.y >= -A.y)) puts("clockwise");
      else puts("counterclockwise");
    } else if (A.x <= 0 and A.y <= 0) {
      if ((B.x <= 0 and B.y >= A.y) or (B.x <= 0 and B.y >= 0) or (B.x >= 0 and B.y >= -A.y)) puts("clockwise");
      else puts("counterclockwise");
    }
  }
}