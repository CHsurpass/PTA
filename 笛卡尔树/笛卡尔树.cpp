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
struct node {
	int k1, k2, l, r;
}tree[N3];
int head[N3];
int st;
int a[N3];
int uid;
bool ok;
void Input() {
	int k1, k2, l, r;
	cin >> n;
	fill(head, head + n, -1);
	ft(i, 0, n) {
		cin >> k1 >> k2 >> l >> r;
		tree[i] = { k1,k2,l,r };
		head[l] = i;
		head[r] = i;
	}
	return;
}
void push_up(int id, int l, int r) {
	if( l != -1 && tree[id].k2 >= tree[l].k2 ) {
		tree[id].k2 = tree[l].k2, ok = false;
	}
	if( r != -1 && tree[id].k2 >= tree[r].k2 ) {
		tree[id].k2 = tree[r].k2, ok = false;
	}
}
void DFS(int id) {
	if( id != -1 && ok ) {
		DFS(tree[id].l);
		a[++uid] = tree[id].k1;
		DFS(tree[id].r);
		push_up(id, tree[id].l, tree[id].r);
	}
}
void dfs_jud() {
	int temp = a[0];
	ft(i, 1, n) {
		if( a[i] <= temp ) {
			ok = false;
			break;
		}
		temp = a[i];
	}
}
void Solve() {
	ft(i, 0, n) {
		if( head[i] == -1 ) {
			st = i;
			break;
		}
	}
	uid = -1;
	ok = true;
	DFS(st);
	if( ok ) {
		dfs_jud();
	}
	return;
}
void Print() {
	if( ok ) cout << "YES" << endl;
	else cout << "NO" << endl;
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
