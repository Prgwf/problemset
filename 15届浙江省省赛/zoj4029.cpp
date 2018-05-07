#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000000;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 500000 + 5;
const int INF = 0x3f3f3f3f;

int T, n, m, a[N];
ll asum[N], rsum[N][31];
ll get(int l, int r) {
	assert(l > 0);
	return asum[r] - asum[l - 1];
}
ll get_rem(int l, int r, int b) {
	assert(l > 0);
	return rsum[r][b] - rsum[l - 1][b];
}
ll solve(int l, int r, int b) {
	ll ret = get(l, r) - get_rem(l, r, b);
	assert(ret >= 0);
	ret /= (ll)b;
	return ret;
}
int find(int x) {
	int ans = -1;
	int lb = 1, ub = n;
	while (lb <= ub) {
		int mid = (lb + ub) / 2;
		if (a[mid] <= x) {
			ans = mid;
			lb = mid + 1;
		} else {
			ub = mid - 1;
		}
	}
	return ans;
}
int main() {
	// freopen("data.in", "r", stdin);
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}

		sort(a + 1, a + n + 1, less<int>());

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < 31; ++j) {
				rsum[i][j] = rsum[i - 1][j] + (a[i] % j);
			}
			asum[i] = asum[i - 1] + a[i];
		}

		ll ans = 0;
		for (int i = 1; i <= m; ++i) {
			int p;
			scanf("%d", &p);
			int P = 1;
			int l = 1, r = -1;
			ll t = 0;
			for (int j = 1; j < 31; ++j) {
				if (r >= n) break;
				int Pbak = P;
				P *= p;
				if (Pbak != P / p) {
					t += solve(l, n, j);
					t %= mod;
					break;
				}

				r = find(P);
				if (r < l) continue;
				t += solve(l, r, j);
				t %= mod;
				l = r + 1;
			}
			ans += 1LL * i * t % mod;
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
