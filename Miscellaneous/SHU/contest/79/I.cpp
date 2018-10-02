/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

const double eps = 1e-7;
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

struct point {
  double x, y;
  point(double a = 0, double b = 0) : x(a), y(b) {}

  point operator + (const point & rhs) const {
    return point(x + rhs.x, y + rhs.y);
  }

  point operator - (const point & rhs) const {
    return point(x - rhs.x, y - rhs.y);
  }
  

  double operator * (const point& rhs) const { 
    return x * rhs.x + y * rhs.y; 
  }

  double operator ^ (const point& rhs) const { 
    return x * rhs.y - y * rhs.x; 
  }


  point rotate(point b, double a) {
    double dx, dy;
    (*this - b).split(dx, dy);
    double tx = dx * cos(a) - dy * sin(a);
    double ty = dx * sin(a) + dy * cos(a);
    return point(tx, ty) + b;
  }

  void split(double &a, double &b) {
    a = x; b = y;
  }
} ;

struct line {
  point s, e;
  line() {}
  line(point _s, point _e) : s(_s), e(_e) {}
} ;

double dist(point x, point y) {
  return sqrt((x - y) * (x - y));
}

bool segxseg(line l1, line l2)
{
  return
    max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
    max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
    max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
    max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
    sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e-l1.e) ^ (l1.s - l1.e)) <= 0 &&
    sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e-l2.e) ^ (l2.s - l2.e)) <= 0;
}


bool point_on_seg(point p, line l) {
  return sgn((l.s - p) ^ (l.e - p)) == 0
    && sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0
    && sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
}

int point_in_poly(point p, vector<point> & poly) {
  int n = poly.size();
  int cont = 0;

  line ray, side;
  ray.s = p;
  ray.e.x = -100000000000.0;
  ray.e.y = p.y;

  for (int i = 0; i < n; ++i) {
    side.s = poly[i];
    side.e = poly[(i + 1) % n];

    if (point_on_seg(p, side)) {
      return 0;
    }

    if (sgn(side.s.y - side.e.y) == 0) {
      continue;
    }

    if (point_on_seg(side.s, ray)) {
      cont += (sgn(side.s.y - side.e.y) > 0);
    } else if (point_on_seg(side.e, ray)) {
      cont += (sgn(side.e.y - side.s.y) > 0);
    } else if (segxseg(ray, side)) {
      cont++;
    }
  }
  return (cont & 1) ? 1 : 0;
}

struct Solution {

  void work() {
    int T;
    scanf("%d", &T);

    while (T--) {
      int n, q;
      scanf("%d%d", &n, &q);

      vector<point> a;
      for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.push_back(point(x, y));
      }
      
      char shape[2];
      while (q--) {
        scanf("%s", shape);
        if (shape[0] == 'T') {
          vector<point> v;
          for (int i = 0; i < 3; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            v.push_back(point(x, y));
          }

          int ans = 0;
          for (auto p : a) {
            vector<int> temp(3);
            for (int i = 0; i < 3; ++i) {
              temp[i] = (v[i] - p) ^ (v[(i + 1) % 3] - p);
            }
            ans += (temp[0] > 0 && temp[1] > 0 && temp[2] > 0) 
              || (temp[0] < 0 && temp[1] < 0 && temp[2] < 0);
          }

          printf("%d\n", ans);
        } else if (shape[0] == 'R') {
          int rx, ry, r;
          scanf("%d%d%d", &rx, &ry, &r);
          
          int ans = 0;
          for (auto p : a) {
            int x = p.x;
            int y = p.y;
            if ((rx - x) * (rx - x) + (ry - y) * (ry - y) < r * r) {
              ++ans;
            }
          }

          printf("%d\n", ans);
        } else if (shape[0] == 'S') {
          int x0, y0, x1, y1;
          scanf("%d%d%d%d", &x0, &y0, &x1, &y1);

          int ans = 0;
          for (auto p : a) {
            int x = p.x;
            int y = p.y;
            if (x > x0 && x < x1 && y > y0 && y < y1) {
              ++ans;
            }
          }

          printf("%d\n", ans);
        }
      }
      puts("");
    }
  }

} ; 

Solution Woo;

int main() {
  Woo.work();
}

