// 一元多项式的乘法与加法运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int ret[N << 1];
int a[N], b[N];
void Input(bool v) {
	int n;
	cin >> n;
	while (n--) {
		int c, x;
		cin >> c >> x;
		if (v)
			a[x] = c;
		else
			b[x] = c;
	}
}
void Print(int N) {
	bool v = false;
	for (int i = N; i >= 0; i--) {
		if (ret[i]) {
			if (v)
				cout << ' ';
			v = true;
			cout << ret[i] << ' ' << i;
		}
	}
	if (!v)
		cout << 0 << ' ' << 0;
	cout << endl;
}
void Mul() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret[i + j] += a[i] * b[j];
		}
	}
	Print(N << 1);
}
void Add() {
	for (int i = 0; i < N; i++) {
		ret[i] = a[i] + b[i];
	}
	Print(N);
}
int main() {
	Input(0);
	Input(1);
	Mul();
	Add();
	return 0;
}