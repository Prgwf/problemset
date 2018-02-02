#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 20;
int n, m, dis[N];
set<int> all, mp[N], tmp;
int vis[N];
void solve() {
    scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            all.insert(i); 
            mp[i].clear();
        }
        memset(dis, -1, sizeof(dis));
        int u, v, s;
        while (m--)
        {
            scanf("%d%d", &u, &v);
            mp[u].insert(v);
            mp[v].insert(u);
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                all.erase(i);
                queue<int>q;
                q.push(i);
                while (!q.empty())
                {
                    tmp.clear();
                    u = q.front();
                    q.pop();
                    vis[u] = 1;
                    cnt ++;
                    set<int>::iterator v = all.begin();
                    for (; v != all.end(); v++) 
                    {
                        if (mp[u].find(*v) == mp[u].end()) 
                        {
                            dis[*v] = dis[u] + 1;
                            tmp.insert(*v); 
                            q.push(*v);     
                        }
                    }
                    for (v = tmp.begin(); v != tmp.end(); v++) 
                        all.erase(*v);
                }
                ans.push_back(cnt);
            }
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(int i = 0;i < ans.size();i++)
        {
            if(i)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
}
int main() {
  solve();
}