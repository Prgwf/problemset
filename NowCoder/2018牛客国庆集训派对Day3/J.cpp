#include <bits/stdc++.h>
using namespace std;

vector< vector< int > > g;
vector< int > color;
vector< int > pre;
int loopEntry = -1;
void dfs(int x, int c, bool & flag) {
	if (flag) return;

	color[x] = c;
	for (int v : g[x]) {
		if (flag) break;

		if (color[v] == 0) {
			pre[v] = x;
			dfs(v, -c, flag);
		} else if (color[v] == c) {
			flag = true;
			pre[v] = x;
			loopEntry = v;
			return;
		}
	}
}

int main(int argc, const char * argv[]) {
	int n, m;
	scanf("%d %d", &n, &m);
	g.assign(n + 1, vector< int >());
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	bool flag = false;
	color.assign(n + 1, 0);
	pre.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (flag) break;

		if (color[i] == 0) {
			dfs(i, 1, flag);
			if (flag) {
				vector< int > out;
				int v = loopEntry;
				do {
					// printf(" %d", v);
					out.push_back(v);
					v = pre[v];
				} while (v != loopEntry);

				printf("%d\n", out.size());
				for (int i = 0; i < out.size(); ++i) {
					printf("%d%c", out[i], i < out.size() - 1 ? ' ' : '\n');
				}
			}
		}
	}

	if (!flag) {
		puts("0");
		for (int i = 1; i <= n; ++i) {
			printf("%d%c", (color[i] + 1) / 2, i < n ? ' ' : '\n');
		}
	}

	return 0;
}