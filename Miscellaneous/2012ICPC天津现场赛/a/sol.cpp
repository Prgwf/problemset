#include <bits/stdc++.h>
using namespace std;

map<string, int> id;
map<int, string> arc;
int tot;

int num[55];

vector<int> ans;

int to[13] = {0, 8, 9, 17, 18, 26, 27, 28, 29, 30, 31, 32, 33};
bool spj() {
  int cnt = 0;
  for (int i = 0; i < 34; ++i) cnt += (num[i] == 2);
  if (cnt == 7) return true;

  
  int flag = 1;
  cnt = 0;

  for (int i = 0; i < 13; ++i) {
    if (num[to[i]] > 2) break;
    if (num[to[i]] == 2 and flag) {
      cnt++;
      flag = 0;
    } else if (num[to[i]] == 1) cnt++; 
  }
  if (not flag and cnt == 13) return true;

  return false;
}

int tmp[55];
bool check(int dui) {
  memcpy(tmp, num, sizeof(num));
  tmp[dui] -= 2;

  int i;

  i = 0;
  while (i < 9) {
    while (i < 9 and not tmp[i]) ++i;
    if (tmp[i] >= 3) {
      tmp[i] -= 3; 
    } else if (i + 2 < 9 and tmp[i] and tmp[i + 1] and tmp[i + 2]) {
      tmp[i]--;
      tmp[i + 1]--;
      tmp[i + 2]--;
    } else if (i < 9) {
      return false;
    }
  }

  while (i < 18) {
    while (i < 18 and not tmp[i]) ++i;
    if (tmp[i] >= 3) {
      tmp[i] -= 3; 
    } else if (i + 2 < 18 and tmp[i] and tmp[i + 1] and tmp[i + 2]) {
      tmp[i]--;
      tmp[i + 1]--;
      tmp[i + 2]--;
    } else if (i < 18) {
      return false;
    }
  }

  while (i < 27) {
    while (i < 27 and not tmp[i]) ++i;
    if (tmp[i] >= 3) {
      tmp[i] -= 3; 
    } else if (i + 2 < 27 and tmp[i] and tmp[i + 1] and tmp[i + 2]) {
      tmp[i]--;
      tmp[i + 1]--;
      tmp[i + 2]--;
    } else if (i < 27) {
      return false;
    }
  }

  while (i < 34) {
    while (i < 34 and not tmp[i]) ++i;
    if (tmp[i] >= 3) tmp[i] -= 3;
    else if (i < 34) return false;
  }
  
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  char kind[] = {'m', 's', 'p', 'c'};
  string t;
  tot = 0;
  for (int j = 0; j < 4; ++j) 
  for (char i = '1'; i <= '9'; ++i) {
    t = i;
    t += kind[j];         
    id[t] = tot++;
    arc[id[t]] = t;
  }
  tot = 34;
  
  int T;
  cin >> T;
  while (T--) {
    string tile;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 13; ++i) {
      cin >> tile;
      num[id[tile]]++;
    }

    ans.clear();
    for (int i = 0; i < 34; ++i) {
      num[i]++;
      if (num[i] > 4) {
        num[i]--; 
        continue;
      } 

      if (spj()) {
        ans.push_back(i);
        num[i]--;
        continue;
      }

      int flag = 0;
      for (int j = 0; j < 34; ++j) {
        if (num[j] >= 2 and check(j)) {
          flag = 1;
          break;
        }
      }
      if (flag) ans.push_back(i);
      num[i]--;
    }
    if (ans.size()) {           
      cout << ans.size();
      for (int i : ans) cout << " " << arc[i];
      cout << endl;
    } else {
      cout << "Nooten" << endl;
    } 
  }
}