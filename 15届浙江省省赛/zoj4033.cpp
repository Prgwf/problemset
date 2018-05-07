#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int main() {
	// freopen("data.in", "r", stdin);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		ll sum = 1LL * n * (n + 1) / 2LL;
		if (sum & 1) {
			cout << "-1";
			cout << endl;
			continue;
		}

		for (char & ch : s) {
			int k = ch - '0';
			if (k & 1) ch = '3';
			else ch = '1';
		}
		sum /= 2;
		ll cur = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (cur + (ll)(i+ 1) <= sum) {
				s[i]++;
				cur += (ll)(i + 1);
			}
		}
		cout << s;
		cout << endl;
	}
}
