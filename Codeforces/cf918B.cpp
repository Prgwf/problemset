#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  string name, ip;
  map<string, string> mep;
  for (int i = 0; i < n; ++i) {
    cin >> name >> ip;
    mep[ip] = name;
  }

  string opt;
  for (int i = 0; i < m; ++i) {
    cin >> opt >> ip;
    cout << opt << " " << ip << " #";
    ip.pop_back();
    cout << mep[ip];
    cout << "\n";
  }
  cout.flush();
}