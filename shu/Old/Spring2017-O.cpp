/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a,b) scanf("%d%d",&a, &b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a, &b, &c)
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) sort(all(x)); v.erase(unique(all(v)), end())
#define mp(a,b) make_pair(a,b)
#define clr(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

//gcd lcm
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int a[55];
bool boy[55];
vector<int> ret;
int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int n;
	while(~iscanf(n)) {
		ret.clear();
		for(int i = 1; i <= n; i++) {
			iscanf(a[i]);
		}
		clr(boy, 0);
		for(int i = 1; i <= n; i++) {
			for(int j = a[i]; j >= 1; j--) {
				if(!boy[j]) {
					boy[j] = true;
					// cout << j << endl;
					ret.push_back(a[i] - j + 1);
					j = 1;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(i)  printf(" ");
			printf("%d", ret[i]);
		}
		printf("\n");
	}
	return 0;
}
