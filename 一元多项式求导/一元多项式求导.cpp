// 一元多项式求导.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int a[N];
stringstream ss;
void Input() {
	int c, x;
	while (cin>>c>>x) {
		a[x] = c;
	}
}
void Print(int N) {
	bool v = false;
	for (int i = N-1; i >= 0; i--) {
		if (a[i]) {
			if (v)
				cout << ' ';
			v = true;
			cout << a[i] << ' ' << i;
		}
	}
	if (!v)
		cout << 0 << ' ' << 0;
	cout << endl;
}
void fff() {
	for (int i = 1; i < N; i++) {
		a[i-1] = a[i]*i;
	}
}
int main() {
	Input();
	fff();
	Print(N);
	return 0;
}