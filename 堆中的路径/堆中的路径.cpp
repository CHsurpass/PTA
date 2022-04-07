
// 堆中的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n, m;
int a[N<<2];
int len;
void Up(int len) {
	if (len > 1) {
		int par = len >> 1;
		if (a[par] > a[len]) {
			swap(a[par], a[len]);
			Up(par);
		}
	}
}
void Insert(int x) {
	if (len == 0) {
		a[len++] = 0;
	}
	a[len++] = x;
	Up(len-1);
}
void Print(int id) {
	bool v = false;
	while (id) {
		if (v) cout << ' ';
		v = true;
		cout << a[id];
		id >>= 1;
	}
	cout << endl;
}
int main() {
	cin >> n >> m;
	for (int i = 0,x; i < n; i++) {
		cin >> x;
		Insert(x);
	}
	for (int i = 0,id; i < m; i++) {
		cin >> id;
		Print(id);
	}
	return 0;
}