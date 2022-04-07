// 素数对猜想.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int vis[N];
void Prime() {
	for (int i = 2; i < 3000; i++) {
		if (vis[i] == 0) {
			for (int j = i + i; j < N; j += i) {
				vis[j] = 1;
			}
		}
	}
}
int main() {
	Prime();
	cin >> n;
	vector<int>ret;
	for (int i = 2; i <= n; i++) {
		if (vis[i] == 0) {
			ret.push_back(i);
		}
	}
	int cnt = 0;
	int len = ret.size();
	for (int i = 1; i < len; i++) {
		if (ret[i] - ret[i - 1] == 2) {
			cnt++;
		}
	}
	if (cnt == 0&&ret[1]-ret[0]==2) {
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
