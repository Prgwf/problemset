#include <bits/stdc++.h>
using namespace std;

bool spj(set<int> & s)
{
    vector<int> v{s.begin(), s.end()};
    return (v[2] == 3 * v[0] && v[1] == 2 * v[0]);
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> result;
    for (int i = n, factor = 1; i != 0; i /= 2, factor *= 2)
    {
        if (i == 3)
        {
            {
                result.push_back(factor);
                result.push_back(factor);
                result.push_back(3 * factor);
                break;
            }
        }
        int k = (i + 1) / 2;
        for (int j = 0; j < k; ++j)
        {
            result.emplace_back(factor);
        }
    }
    for (int x : result)
    {
        printf("%d ", x);
    }
}