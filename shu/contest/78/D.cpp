/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

struct Solution {

  void work() {
    vector<string> str, bak;
    vector<string> ans;
    string line;
    while (getline(cin, line)) {
      bak.emplace_back(line);

      line.erase(remove(line.begin(), line.end(), ' '), line.end());
      line.erase(remove(line.begin(), line.end(), '\t'), line.end());
      for (char & ch : line) {
        if (ch >= 'A' && ch <= 'Z') {
          ch += 32;
        }
      }
      str.emplace_back(line);
    }

    int n = str.size();
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < n; ++i) {
      if (str[i].find("<document") != str[i].npos) {
        flag1 = 1;
        continue;
      } 
      if (str[i].find("</document") != str[i].npos) {
        flag1 = 0;
        continue;
      } 
      if (str[i].find("<message") != str[i].npos) {
        flag2 = 1;
        continue;
      } 
      if (str[i].find("</message") != str[i].npos) {
        flag2 = 0;
        continue;
      }

      if (flag1 && flag2) {
        ans.push_back(bak[i]);
      }
    }

    for (string & s : ans) {
      reverse(s.begin(), s.end());
      while (s.back() == ' ' || s.back() == '\t') {
        s.pop_back();
      }
      reverse(s.begin(), s.end());
    }
    for (string & s : ans) {
      cout << s << "\n";
    }
    cout.flush();
  }

} ; 
Solution Woo;
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

