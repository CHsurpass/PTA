// 六度空间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

vector<int>G[N];
int n, m;
int vis[N];
int ans;
struct node {
	int u, cnt;
};
void BFS(int u) {
	queue<node>qu;
	qu.push({u,0});
	memset(vis, 0, sizeof vis);
	vis[u] = 1;
	while (qu.size()) {
		int u = qu.front().u;
		int cnt = qu.front().cnt;
		qu.pop();
		if (cnt > 6) {
			continue;
		}
		ans++;
		for (int i = 0; i < G[u].size(); i++) {	
			int v = G[u][i];
			if (vis[v] == 0) {
				vis[v] = 1;
				qu.push({v,cnt+1});
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0,u,v; i < m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		ans = 0;
		BFS(i);
		printf("%d: %.2f%%\n", i, 100.0 * ans / n);
	}
	return 0;
}
