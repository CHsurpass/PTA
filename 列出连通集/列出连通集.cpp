// 列出连通集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n, m;
int G[N][N];
int vis[N];
void DFS(int id) {
	cout << id << ' ';
	for (int i = 0; i < n; i++) {
		if (G[id][i] && vis[i] == 0) {
			vis[i] = 1;
			DFS(i);
		}
	}
}
void BFS(int u) {
	queue<int>qu;
	qu.push(u);
	while (qu.size()) {
		u = qu.front();
		qu.pop();
		cout << u << ' ';
		for (int i = 0; i < n; i++) {
			if (G[u][i]&&vis[i] == 0) {
				vis[i] = 1;
				qu.push(i);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0, u,v; i < m; i++) {
		cin >> u >> v;
		G[u][v] = 1;
		G[v][u] = 1;
	}
	for(int i = 0;i < n;i++) {
		if (vis[i]==0) {
			vis[i] = 1;
			cout << "{ ";
			DFS(i);
			cout<<"}" << endl;
		}
	}
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			cout << "{ ";
			BFS(i);
			cout << "}" << endl;
		}
	}
	return 0;
}