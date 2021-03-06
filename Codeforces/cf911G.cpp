/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

#define lson o << 1
#define rson o << 1 | 1

const int maxn = 2e5 + 20;

int n;
vector<int> v;
struct SegTree {
	struct node {
		int l, r, vis;
		int pos[102];
	} a[maxn * 4];

	void build(int l, int r, int o = 1) {
		a[o].l = l;
		a[o].r = r;
		a[o].vis = 0;
		for (int i = 1; i <= 100; ++i) {
			a[o].pos[i] = i;
		}

		if (l + 1 == r) {
			return;
		}
		int m = (l + r) / 2;
		build(l, m, lson);
		build(m, r, rson);
	}

	void push_down(int o) {
		if (a[o].vis) {
			for (int i = 1; i <= 100; ++i) {
				a[lson].pos[i] = a[o].pos[a[lson].pos[i]];
				a[rson].pos[i] = a[o].pos[a[rson].pos[i]];
			}
			for (int i = 1; i <= 100; ++i) {
				a[o].pos[i] = i;
			}
			a[o].vis = 0;
			a[lson].vis = a[rson].vis = 1;
		}
	}

	void update(int l, int r, pair<int, int> pii, int o = 1) {
		if (l <= a[o].l && a[o].r <= r) {
			a[o].vis = 1;
			for (int i = 1; i <= 100; ++i) {
				if (a[o].pos[i] == pii.first) {
					a[o].pos[i] = pii.second;
				}
			}
			return;
		}

		push_down(o);
		int m = (a[o].l + a[o].r) / 2;
		if (l < m) update(l, r, pii, lson);
		if (r > m) update(l, r, pii, rson);
	}

	void query(int o = 1) {
		if (a[o].l + 1 == a[o].r) {
			v[a[o].l] = a[o].pos[v[a[o].l]];
			return;
		}
		push_down(o);
		int m = (a[o].l + a[o].r) / 2;
		query(lson);
		query(rson);
	}
} seg;

struct TaskG {
	void solve(std::istream& in, std::ostream& out) {
		in >> n;
		v.resize(n + 2);

		for (int i = 1; i <= n; ++i) {
			in >> v[i];
		}

		seg.build(1, n + 1);

		int m;
		in >> m;
		for (int q = 0; q < m; ++q) {
			int l, r, x, y;
			in >> l >> r >> x >> y;
			seg.update(l, r + 1, {x, y});
		}

		seg.query();

		for (int i = 1; i <= n; ++i) {
			out << v[i] << " ";
		}
		out.flush();
	}
};
