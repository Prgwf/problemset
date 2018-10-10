#include <bits/stdc++.h>

using namespace std;

const int N = 3030;
const int inf = 0x3f3f3f3f;

struct Edge {
    int from, to, cap, flow, cost;
};

struct MCMF {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];
    int d[N];
    int p[N];
    int a[N];

    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; ++i) G[i].clear();
        edges.clear();
    }

    void add_edge(int from, int to, int cap, int cost) {
        edges.push_back({from, to, cap, 0, cost});
        edges.push_back({to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool SPFA(int s, int t, int &flow, int &cost) {
        for (int i = 0; i < n; ++i) d[i] = inf;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = inf;

        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < (int) G[u].size(); ++i) {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }

        if (d[t] == inf) return false;
        // if (d[t] >= 0) return false;

        // add flow
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }

        return true;
    }

    int run(int s, int t) {
        int flow = 0, cost = 0;
        while (SPFA(s, t, flow, cost));
        return cost;
    }

} min_cost;


int n, m;
int cost[105];
int has[105];
int main() {
    cost[0] = 0;
    for (int i = 1; i <= 100; ++i) {
        cost[i] = 2 * i - 1;
        has[i] = 0;
    }

    min_cost.init(3005);
    int S = 0, T = 3000;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        min_cost.add_edge(S, i, 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        min_cost.add_edge(i, n + a, 1, 0);
        min_cost.add_edge(n + a, T, 1, cost[++has[a]]);
        min_cost.add_edge(i, n + b, 1, 0);
        min_cost.add_edge(n + b, T, 1, cost[++has[b]]);
    }
//    cerr << "Here" << endl;
    printf("%d\n", min_cost.run(S, T));
}