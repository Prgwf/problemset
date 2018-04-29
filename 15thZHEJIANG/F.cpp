#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const ll mod = 1e9;
int a[N], AM[N][31], p[N];
ll AS[N][31];
int main()
{
	int T;
  scanf("%d", &T);
	while (T--)
	{
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	//	a[n + 1] = mod * 10; n++;
		sort(a + 1, a + n+1);
		for (int i = 1; i <= m; i++)scanf("%d", &p[i]);
		for (int j = 1; j < 31; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				AM[i][j] = a[i] % j;
				AS[i][j] = AS[i - 1][j] + 1LL * AM[i][j];
			}
		}
		for (int i = 1; i <= n; i++)AS[i][0] = AS[i-1][0] + 1LL * a[i];
		ll ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int Ppos = 1;
			for (ll j = 1,NJ=p[i]; j < 31; j++,NJ*=(ll)p[i])
			{
				if (NJ/(ll)p[i] > (ll)a[n])break;
				int nextpos = upper_bound(a + 1, a + n + 1, NJ) - a;//返回右开
				ll tmp = (AS[nextpos -1][0] - AS[Ppos-1][0]) /(j);
	//			cout << AS[prepos - 1][0] - AS[Ppos - 1][0] <<' '<<j<< endl;
				tmp -= (AS[nextpos -1][j] - AS[Ppos-1][j]) / (j);
				tmp %= mod;
				ans += (tmp*i)%mod;
				ans %= mod;
				Ppos = nextpos;
			}
	//		cout << ans << endl;
		}
    printf("%lld\n", ans);
	}
}
