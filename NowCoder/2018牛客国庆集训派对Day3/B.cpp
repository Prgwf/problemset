#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
const ll mod = (ll)1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll inv(ll x) { return powmod(x, mod - 2); }

vector< vector< int > > g;
vector< int > fa;
vector< ll > dp1, dp2;

void dfs1(int x, int p)
{
	fa[x] = p;
	dp1[x] = 1LL;
	for (int v : g[x]) {
		if (v == p) continue;
		dfs1(v, x);
		dp1[x] = dp1[x] * (dp1[v] + 1) % mod;
	}
}
void dfs2(int x, int p)
{
	if (p == -1)
	{
		assert(x == 1);
		dp2[x] = 1;
	}
	else
	{
		if ((dp1[x] + 1) % mod == 0)
		{
			for (int v : g[p])
			{
				if (v == x || v == fa[p])
				{
					continue;
				}
				dp2[x] = dp2[x] * (dp1[v] + 1) % mod;
			}
			dp2[x] = dp2[x] * dp2[p] % mod + 1;
		}
		else
		{
			dp2[x] = ((dp1[p] * inv(dp1[x] + 1) % mod) *  dp2[p] % mod) + 1;
		}
	}

	for (int v : g[x])
	{
		if (v == p) continue;
		dfs2(v, x);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	g.assign(n + 1, vector< int >());
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	fa.assign(n + 1, -1);
	dp1.assign(n + 1, 1);
	dfs1(1, -1);

	dp2.assign(n + 1, 1);
	dfs2(1, -1);

	for (int i = 1; i <= n; ++i)
	{
		printf("%I64d\n", dp1[i] * dp2[i] % mod);
	}
}