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
	int uid;
	double sc;
	int id;
	bool operator<(const node a) const {
		return sc > a.sc;
	}
}au[N3], tot[N3], sumau[N3], sumtot[N3];
int auss[N3], totss[N3], sumauss[N3], sumtotss[N3];
double aus, tots, sum;
int uid = -1;
int id;
int auidtemp, totidtemp, sumauidtemp, sumtotidtemp;
void Input() {
	cin >> n >> m;
	ft(i, 0, n) {
		cin >> aus >> tots >> sum;
		uid++;
		au[uid] = { uid,aus };
		tot[uid] = { uid,tots };
		sumau[uid] = { uid,aus / sum };
		sumtot[uid] = { uid,tots / sum };
	}
	return;
}
void ff(int uid, int id, int* a) {
	a[uid] = id;
	return;
}
void FF(node* au, int* temp, int i) {
	if( au[i].sc == au[*temp].sc ) {
		au[i].id = au[*temp].id;
	} else {
		au[i].id = id;
		*temp = i;
	}
}
void Solve() {
	sort(au, au + uid + 1);
	sort(tot, tot + uid + 1);
	sort(sumau, sumau + uid + 1);
	sort(sumtot, sumtot + uid + 1);
	id = 1;
	auidtemp = totidtemp = sumauidtemp = sumtotidtemp = 0;
	au[0].id = tot[0].id = sumau[0].id = sumtot[0].id = 1;
	ft(i, 1, n) {
		id++;
		FF(au, &auidtemp, i);
		FF(tot, &totidtemp, i);
		FF(sumau, &sumauidtemp, i);
		FF(sumtot, &sumtotidtemp, i);
	}
	ft(i, 0, n) {
		ff(au[i].uid, au[i].id, auss);
		ff(tot[i].uid, tot[i].id, totss);
		ff(sumau[i].uid, sumau[i].id, sumauss);
		ff(sumtot[i].uid, sumtot[i].id, sumtotss);
	}
	return;
}
void Print() {
	int cnt;
	bool v = false;
	while( m-- ) {
		cin >> uid;
		id = auss[uid];
		cnt = 1;
		if( totss[uid] < id ) id = totss[uid], cnt = 2;
		if( sumauss[uid] < id ) id = sumauss[uid], cnt = 3;
		if( sumtotss[uid] < id ) id = sumtotss[uid], cnt = 4;
		if( v ) cout << ' ';
		v = true;
		cout << id << ":" << cnt;
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
