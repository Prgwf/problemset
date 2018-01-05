/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

vector<int> str_to_num(const string &str) {
  vector<int> ret;
  int L = str.size();
  int i, j = 0;
  for (i = L - 1; i > 2; i -= 4) {
    if (i - 3 >= 0) {
      ret.push_back((str[i -3] - '0') * 1000
        + (str[i - 2] - '0')* 100 
        + (str[i - 1] - '0') * 10
        + (str[i] - '0'));
    }
  }
  if (i == 0) {
    ret.push_back(str[0] - '0');
  } else if (i == 1) {
    ret.push_back((str[0] - '0') * 10 + (str[1] - '0'));
  } else if (i == 2) {
    ret.push_back((str[0] - '0') * 100 + (str[1] - '0') * 10 + str[2] - '0');
  }
  while (!ret.empty() && ret.back() == 0) {
    ret.pop_back();
  }
  return ret;
}

vector<int> add(const vector<int> &x, const vector<int> &y) {
  vector<int> ret;
  int xn = x.size();
  int yn = y.size();
  int i = 0, j = max(xn, yn);

  if (xn == 0 && yn == 0) {
    return {};
  }



}

struct Solution {

  void work(istream &in, ostream &out) {
    
  } 

} ; 

Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

