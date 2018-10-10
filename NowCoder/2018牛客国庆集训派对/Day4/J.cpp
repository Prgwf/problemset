#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int x;
    string pre, cur;
    set<int> result;
    for (int i = 1; i <= n; ++i)
    {
        result.insert(i);
    }

    cin >> x >> pre;
    result.erase(x);

    for (int i = 1; i < m; ++i)
    {
        cin >> x >> cur;
        if (cur != pre)
        {
            result.erase(x);
        }
        pre = cur;
    }

    vector<int> out{result.begin(), result.end()};

    for (int i = 0; i < out.size(); ++i)
    {
        printf("%d%c", out[i], i + 1 < out.size() ? ' ' : '\n');
    }

    return 0;
}