#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int mn = INT_MAX;
    long long result = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        mn = min(mn, x);

        result += x;
    }

    if (n == 1)
    {
        result = 0;
    }
    else if (n == 2)
    {
        ;
    }
    else
    {
        result += 1LL * (n - 2) * mn;
    }
    printf("%lld\n", result);
    return 0;
}
