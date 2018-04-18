/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

string str;
vector<int> S;

int check(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return 2;
  }
  if (ch >= '0' && ch <= '9') {
    return 0;
  }
  if (ch == '(') return -1;
  if (ch == ')') return 1;
}

void out(const string & s) {
  int n = s.size();
  if (n == 1) {
    return;
  }

  // (*****)
  if (s.front() == '(' && s.back() == ')') {
    int cnt = 0;
    int i = 0;
    while (i < n - 1) {
      if (s[i] == '(') {
        cnt++;
      }
      if (s[i] == ')') {
        cnt--;
      }
      if (cnt == 0) {
        goto nxt;
      }
      ++i;
    }
    if (i == n - 1) return;
  }

nxt:
  vector<string> ret;
  string t;
  int i = 0;
  while (i < n) {
    t.clear();
    if (check(s[i]) == 2) {
      if (i + 1 < n && check(s[i + 1]) == 0) {
        t.push_back(s[i]);
        t.push_back(s[i + 1]);
        i += 2;
      } else {
        t.push_back(s[i]);
        i++;
      }
      if (t.size()) ret.push_back(t);
    } else if (s[i] == '(') {
      int cnt = 0;
      while (i < n) {
        if (cnt != 0) t.push_back(s[i]);
        if (s[i] == '(') {
          ++cnt;
        } else if (s[i] == ')') {
          --cnt;
        }
        if (cnt == 0) {
          ++i;
          break;
        }
        ++i;
      }
      t.pop_back();
      if(t.size()) ret.push_back(t);
    }
  }

  cout << s << "=";
  for (int i = 0; i < (int)ret.size(); ++i) {
    if (i) cout << "+";
    cout << ret[i];
  }
  cout << endl;
}

void dfs(const string & s) {
  // cout << s << "###" << endl;
  if (s.size() == 1) {
    return;
  }

  if (s.size() == 2 && check(s[1]) == 0) {
    cout << s << "=" << s[0];
    int cnt = s[1] - '0';
    while (--cnt) {
      cout << "+" << s[0];
    }
    cout << endl;
    return;
  }

  int n = s.size();
  int l = -1, r = -1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (check(s[i]) == 2) {
      if (l < 0 && i + 1 < n && check(s[i + 1]) == 0) {
        dfs(s.substr(i, 2));
      }
    }

    if (s[i] == '(') {
      ++cnt;
      if (cnt == 1) {
        l = i + 1;
      }
    }
    if (s[i] == ')') {
      --cnt;
      if (cnt == 0) {
        r = i - 1;
        dfs(s.substr(l, r - l + 1));
        l = r = -1;
      }
    }
  }
  out(s);
}

int main() {
  // freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> str) {
    if (str[0] == '0') {
      break;
    }
    dfs(str);
    cout << "\n";
    // out(str);
  }
}
