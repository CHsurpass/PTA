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
	string s;
	int sc, id, kid, aid;
	bool operator<(const node a) const {
		if( sc != a.sc ) {
			return sc > a.sc;
		}
		return s < a.s;
	}
}a[N5];
int sc, uid, st, id, temp;
void Input() {
	uid = -1;
	st = 0;
	cin >> n;
	fte(i, 1, n) {
		cin >> m;
		ft(j, 0, m) {
			cin >> s >> sc;
			a[++uid] = { s,sc,i };
		}
		sort(a + st, a + uid + 1);
		id = 1;
		a[st].kid = id;
		temp = st;
		fte(i, st + 1, uid) {
			id++;
			if( a[i].sc == a[temp].sc ) {
				a[i].kid = a[temp].kid;
			} else {
				a[i].kid = id;
				temp = i;
			}
		}
		st = uid + 1;
	}
	return;
}
void Solve() {
	sort(a, a + uid + 1);
	temp = 0;
	id = 1;
	a[0].aid = id;
	fte(i, 1, uid) {
		id++;
		if( a[i].sc == a[temp].sc ) {
			a[i].aid = a[temp].aid;
		} else {
			a[i].aid = id;
			temp = i;
		}
	}
	return;
}
void Print() {
	cout << uid + 1 << endl;
	fte(i, 0, uid) {
		cout << a[i].s << ' ' << a[i].aid << ' ' << a[i].id << ' ' << a[i].kid << endl;
	}
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
