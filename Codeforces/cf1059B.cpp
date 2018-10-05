#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
char fake[1005][1005];
bool fail(int x, int y)
{
    if (x - 1 < 1 || x + 1 > n || y - 1 < 1 || y + 1 > m)
    {
        return true;
    }

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (grid[x + i][y + j] == '.' && !(i == 0 && j == 0))
            {
                return true;
            }
        }
    }
    return false;
}
void print(int x, int y)
{
    if (fail(x, y))
    {
        return;
    }

    char t = fake[x][y];
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            fake[x + i][y + j] = '#';
        }
    }
    fake[x][y] = t;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", grid[i] + 1);
        for (int j = 1; j <= m; ++j)
        {
            fake[i][j] = '.';
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            print(i, j);
        }
    }

    bool flag = 1;
    for (int i = 1; i <= n; ++i)
    {
        // printf("%s    %s\n", grid[i] + 1, fake[i] + 1);
        for (int j = 1; j <= m; ++j)
        {
            if (grid[i][j] != fake[i][j])
            {
                flag = 0;
            }
        }
    }

    printf("%s\n", flag ? "YES" : "NO");
}