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
	int d;
	node* l, * r;
};
int a[N3], b[N3];
int uid;
bool ok;
node* root;
node* root1;
node* Insert(int x, node* root) {
	if( root == NULL ) {
		node* p = (node*) malloc(sizeof(node));
		p->d = x;
		p->l = p->r = NULL;
		return p;
	}
	if( root->d <= x ) {
		root->r = Insert(x, root->r);
	} else {
		root->l = Insert(x, root->l);
	}
	return root;
}
void pq(node* root) {
	if( root != NULL ) {
		swap(root->l, root->r);
		pq(root->l);
		pq(root->r);
		//swap(root->l, root->r); //效果一样,但不能中序交换
	}
}
void Input() {
	root = NULL;
	root1 = NULL;
	cin >> n;
	ft(i, 0, n) {
		cin >> a[i];
		root = Insert(a[i], root);
	}
	return;
}
bool v;
void DFS(node* root, bool flag) {
	if( root != NULL ) {
		if( !flag )
			b[++uid] = root->d;
		DFS(root->l, flag);
		DFS(root->r, flag);
		if( flag ) {
			if( v ) cout << ' ';
			v = true;
			cout << root->d;
		}
		return;
	}
}
void Jud() {
	ft(i, 0, n) {
		if( b[i] != a[i] ) {
			ok = false;
		}
	}
}
void Solve() {
	uid = -1;
	ok = true;
	DFS(root, 0);
	uid = -1;
	Jud();
	if( !ok ) {
		ok = true;
		uid = -1;
		pq(root);
		DFS(root, 0);
		Jud();
	}
	return;
}
void Print() {
	if( ok ) {
		cout << "YES" << endl;
		DFS(root, 1);
	} else {
		cout << "NO" << endl;
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
