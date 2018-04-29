
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{

		long long  n; cin >> n;
		cin >> s;
		int len = s.length();

		long long sum = (n + 1)*n / 2;
		if (sum % 2 != 0)cout << -1 << endl;
		else
		{
			for (int i = 0; i < len; i++)
				if (s[i] == '1')s[i] = '3';
				else s[i] = '1';
			long long now = sum / 2;
			for (int i = len - 1; i >= 0; i--)
			{
				if (now >= i + 1)s[i]++,now-=(i+1);
			}cout << s << endl;
		}

	}
}
