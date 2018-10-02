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
#define zero(x) ((abs(x) < eps ? 1 : 0))
#define sgn(x) (abs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))
struct point
{
  double x, y;
  point(double a = 0, double b = 0) { x = a, y = b; }
  point operator-(const point& b) const { return point(x - b.x, y - b.y); }
  point operator+(const point& b) const { return point(x + b.x, y + b.y); }
  // 两点是否重合
  bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); }
  // 点积(以原点为基准)
  double operator*(const point& b) const { return x * b.x + y * b.y; }
  // 叉积(以原点为基准)
  double operator^(const point& b) const { return x * b.y - y * b.x; }
  // 绕P点逆时针旋转a弧度后的点
  point rotate(point b, double a)
  {
    double dx, dy;
    (*this - b).split(dx, dy);
    double tx = dx * cos(a) - dy * sin(a);
    double ty = dx * sin(a) + dy * cos(a);
    return point(tx, ty) + b;
  }
  // 点坐标分别赋值到a和b
  void split(double& a, double& b) { a = x, b = y; }
};
struct line
{
  point s, e;
  line() {}
  line(point ss, point ee) { s = ss, e = ee; }
};
double dist(point a, point b) { return sqrt((a - b) * (a - b)); }
// <0, *> 表示重合; <1, *> 表示平行; <2, P> 表示交点是P;
pair<int, point> spoint(line l1, line l2)
{
  point res = l1.s;
  if (sgn((l1.s - l1.e) ^ (l2.s - l2.e)) == 0)
    return make_pair(sgn((l1.s - l2.e) ^ (l2.s - l2.e)) != 0, res);
  double t = ((l1.s - l2.s) ^ (l2.s - l2.e)) / ((l1.s - l1.e) ^ (l2.s - l2.e));
  res.x += (l1.e.x - l1.s.x) * t;
  res.y += (l1.e.y - l1.s.y) * t;
  return make_pair(2, res);
}
// 快速排斥实验 + 跨立实验
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
//l1是直线,l2是线段
bool segxline(line l1, line l2)
{
  return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}
point pointtoline(point P, line L)
{
  point res;
  double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
  res.x = L.s.x + (L.e.x - L.s.x) * t, res.y = L.s.y + (L.e.y - L.s.y) * t;
  return dist(P, res);
}
point pointtosegment(point p, line l)
{
  point res;
  double t = ((p - l.s) * (l.e - l.s)) / ((l.e - l.s) * (l.e - l.s));
  if (t >= 0 && t <= 1)
    res.x = l.s.x + (l.e.x - l.s.x) * t, res.y = l.s.y + (l.e.y - l.s.y) * t;
  else
    res = dist(p, l.s) < dist(p, l.e) ? l.s : l.e;
  return res;
}
bool PointOnSeg(point p, line l)
{
  return
    sgn((l.s - p) ^ (l.e-p)) == 0 &&
    sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0 &&
    sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
}
double area(point p[], int n)
{
  double res = 0;
  for (int i = 0; i < n; i++) res += (p[i] ^ p[(i + 1) % n]) / 2;
  return abs(res);
}
// 点形成一个凸包, 而且按逆时针排序(如果是顺时针把里面的<0改为>0)
// 点的编号 : [0,n)
// -1 : 点在凸多边形外
// 0  : 点在凸多边形边界上
// 1  : 点在凸多边形内
int PointInConvex(point a, point p[], int n)
{
  for (int i = 0; i < n; i++)
    if (sgn((p[i] - a) ^ (p[(i + 1) % n] - a)) < 0)
      return -1;
    else if (PointOnSeg(a, line(p[i], p[(i + 1) % n])))
      return 0;
  return 1;
}
// 射线法,poly[]的顶点数要大于等于3,点的编号0~n-1
// -1 : 点在多边形外
// 0  : 点在多边形边界上
// 1  : 点在多边形内
int PointInPoly(point p, vector<point>& poly)
{
  int n = poly.size();
  int cnt;
  line ray, side;
  cnt = 0;
  ray.s = p;
  ray.e.y = p.y;
  ray.e.x = -100000000000.0; // -INF,注意取值防止越界
  for (int i = 0; i < n; i++)
  {
    side.s = poly[i], side.e = poly[(i + 1) % n];
    if (PointOnSeg(p, side)) return 0;
    //如果平行轴则不考虑
    if (sgn(side.s.y - side.e.y) == 0)
      continue;
    if (PointOnSeg(side.s, ray))
      cnt += (sgn(side.s.y - side.e.y) > 0);
    else if (PointOnSeg(side.e, ray))
      cnt += (sgn(side.e.y - side.s.y) > 0);
    else if (segxseg(ray, side))
      cnt++;
  }
  return cnt % 2 == 1 ? 1 : 0;
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

          vector<point> S{
              point(x0, y0),
              point(x0, y1),
              point(x1, y1),
              point(x1, y0)
          };
          int ans = 0;
          for (auto p : a) {
            ans += PointInPoly(p, S);
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

