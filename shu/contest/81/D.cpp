/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  cin.ignore();

  /*
   * 0 --> stay ...
   * 1 --> cinema
   * 2 --> cocktail bar
   * 3 --> disco
   * */
  for (int cas = 1; cas <= T; ++cas) {
    string line, str;
    getline(cin, line);
    stringstream ss(line);
    map<string, set<int>> vote;
    while (ss >> str) {
      vote[str] = set<int>();
    }

    if (vote.count("Anne")) {
      vote["Anne"].insert(1);
    }

    if (vote.count("Karin") && vote.count("Bob")) {
      vote["Bob"].insert(3);
    }

    if (vote.count("Charly") && vote.count("Karin")) {
      vote["Karin"].insert(3);
    }
    if (!vote.count("Charly") && vote.count("Anne") && vote.count("Karin")) {
      vote["Karin"].insert(1);
    }
    if (!vote.count("Charly") && !vote.count("Anne") && vote.count("Karin")) {
      vote["Karin"].insert(2);
    }

    if (vote.count("Dave") && vote.count("Bob")) {
      vote["Bob"].insert(2);
    }

    if (vote.count("Charly") && vote.count("Anne")) {
      vote["Charly"].insert(1);
      vote["Anne"].insert(1);
    }

    if (vote.count("Anne") && !vote.count("Charly") && vote.count("Edward")) {
      vote["Edward"].insert(2);
    } else if (vote.count("Edward")) {
      vote["Edward"].insert(1);
    }

    if (vote.count("Edward") && vote.count("Bob")) {
      vote["Bob"].insert(2);
    }

    if (!vote.count("Bob") && !vote.count("Anne") && vote.count("Frank")) {
      vote["Frank"].insert(1);
    } 
    if (vote.count("Anne") && vote.count("Frank")) {
      vote["Frank"].insert(3);
    }

    if (!vote.count("Anne") && vote.count("Bob")) {
      vote["Bob"].insert(2);
    }

    int cnt[4] = {0};
    for (auto kv : vote) {
      if (kv.second.size() == 1) {
        cnt[*kv.second.begin()]++;
      }
    }

    cout << "Scenario #" << cas << ":\n";
    if (cnt[1] > cnt[2] && cnt[1] > cnt[3]) {
      cout << "cinema" << endl;
    } else if (cnt[2] > cnt[1] && cnt[2] > cnt[3]) {
      cout << "cocktail bar" << endl;
    } else if (cnt[3] > cnt[1] && cnt[3] > cnt[2]) {
      cout << "disco" << endl;
    } else {
      cout << "stay at the Hacienda" << endl;
    }
    cout << endl;
  }
}
