#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    map<char, int> cnt;

    cin >> str;
    for (const char & c : str) {
        cnt[c]++;
    }

    string ret;
    vector<char> to_delete;
    do {
        for (auto & kv : cnt) {
            ret.push_back(kv.first);
            if (--kv.second == 0) {
                to_delete.push_back(kv.first);
            }
        }
        for (const char & c : to_delete) cnt.erase(c);
    } while (!cnt.empty());
    cout << ret << endl;
}