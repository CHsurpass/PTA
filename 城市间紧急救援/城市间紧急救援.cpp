/*****************************************************************************
* @author  : xhc                                                             *
*****************************************************************************/

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

const int N1 = 1e1 + 5;
const int N2 = 1e2 + 5;
const int N3 = 1e3 + 5;
const int N4 = 1e4 + 5;
const int N5 = 1e5 + 5;
const int N6 = 1e6 + 5;
const int N7 = 1e7 + 5;
#define ll long long
#define pb push_back
#define ft(i, st, n) for(int i = st; i < (int)(n); i ++)
#define fte(i, st, n) for(int i = st; i <= (int)(n); i ++)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define scanf scanf_s
int n, m;
string s;
stringstream ss;
int st, en;
int a[N3];
int dis[N3];
bool vis[N3];
int head[N3];
int sum[N3];
int cnt[N3];
struct node {
	int v, w;
};
vector<node>G[N3];
void Input() {
	cin >> n >> m >> st >> en;
	ft(i, 0, n) {
		cin >> a[i];
	}
	int u, v, w;
	ft(i, 0, m) {
		cin >> u >> v >> w;
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}
	return;
}
void Init() {
	ft(i, 0, n) {
		head[i] = -1;
		dis[i] = inf;
		sum[i] = vis[i] = false;
		cnt[i] = 0;
	}
}
void BFS(int u) {
	queue<int>qu;
	qu.push(u);
	dis[u] = 0;
	sum[u] = a[u];
	cnt[u] = 1;
	while( !qu.empty() ) {
		u = qu.front();
		vis[u] = 0;
		qu.pop();
		ft(i, 0, G[u].size()) {
			int v = G[u][i].v;
			int w = G[u][i].w;
			if( dis[v] > dis[u] + w ) {
				dis[v] = dis[u] + w;
				sum[v] = sum[u] + a[v];
				head[v] = u;
				cnt[v] = cnt[u];
				if( vis[v] == 0 ) {
					vis[v] = 1,
						qu.push(v);
				}
			} else if( dis[v] == dis[u] + w && sum[v] < sum[u] + a[v] ) {
				sum[v] = sum[u] + a[v];
				head[v] = u;
				cnt[v] ++;
				if( vis[v] == 0 ) {
					vis[v] = 1,
						qu.push(v);
				}
			} else if( dis[v] == dis[u] + w ) {
				cnt[v] ++;
			}
		}
	}
}
void Solve() {
	Init();
	BFS(st);
	return;
}
bool v;
void dfs(int id) {
	if( id != -1 ) {
		dfs(head[id]);
		if( v ) cout << ' ';
		v = true;
		cout << id;
	}
}
void Print() {
	cout << cnt[en] << ' ' << sum[en] << endl;
	dfs(en);
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Input();
	Solve();
	Print();
	return 0;
}

