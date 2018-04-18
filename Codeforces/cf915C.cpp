#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int num[20];

int flag = 0;
void dfs(int pos, int lead, int limit, string ret) {
  if (flag) return;

  if (pos == -1) {
    flag = 1;
    cout << ret << endl;
    return;
  }
  int up = limit ? num[pos] : 9;
  for (int i = up; i >= 0; --i) {
    if (lead && i == 0) continue;
    if (cnt[i] > 0) {
      cnt[i]--;
      dfs(pos - 1, lead && i == 0, limit && i == num[pos], ret + char(i + '0'));
      cnt[i]++;
    }
  }
}

int main() {
  string a, b;
  cin >> a >> b;

  if ((int)a.size() < (int)b.size()) {
    sort(a.begin(), a.end(), greater<char>());
    cout << a << endl;
    return 0;
  }

  for (char & ch : a) {
    cnt[ch - '0']++;
  }

  reverse(b.begin(), b.end());
  int bl = b.size();
  for (int i = 0; i < bl; ++i) {
    num[i] = b[i] - '0';
  }
  dfs(bl - 1, 1, 1, "");
}
