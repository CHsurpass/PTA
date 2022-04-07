// 数组元素循环右移问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[105];
bool v;
void Print(int s, int e) {
	for (int i = s; i < e; i++) {
		if (v)
			cout << ' ';
		v = true;
		cout << a[i];
	}
}
int main() {
	cin >> n >> m;
	m %= n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Print(n-m, n);
	Print(0,n-m);
	return 0;
}
