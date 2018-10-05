#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, L, a;
    cin >> n >> L >> a;

    int cur = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int ti, li;
        cin >> ti >> li;
        if (ti - cur >= a)
        {
            ans += (ti - cur) / a;
        }
        cur = ti + li;
    }
    if (L - cur >= a)
    {
        ans += (L - cur) / a;
    }
    cout << ans << endl;
}