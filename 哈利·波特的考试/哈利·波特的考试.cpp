// 哈利·波特的考试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e2 + 5;
#define inf 0x3f3f3f3f

int n, m;
struct node {
	int v, w;
};
vector<node>G[N];
int ret, retid;
int dis[N];
void BFS(int u) {
	queue<int>qu;
	qu.push(u);
	int vis[N] = { 0 };
	vis[u] = 1;
	memset(dis, inf, sizeof dis);
	dis[u] = 0;
	while( qu.size() ) {
		u = qu.front();
		qu.pop();
		vis[u] = 0;
		for( int i = 0; i < G[u].size(); i++ ) {
			int v = G[u][i].v;
			int w = G[u][i].w;
			if( dis[u] + w < dis[v] ) {
				dis[v] = dis[u] + w;
				if( vis[v] == 0 ) {
					vis[v] = 1;
					qu.push(v);
				}
			}
		}
	}
}
void FF(int id) {
	int mxx = 0;
	bool v = true;
	for( int i = 1; i <= n; i++ ) {
		if( dis[i] != inf && mxx < dis[i] ) {
			mxx = dis[i];
		}
		if( dis[i] == inf ) {
			v = false;
		}
	}
	if( ret > mxx && v ) {
		ret = mxx;
		retid = id;
	}
}
int main() {
	ret = inf;
	retid = 0;
	cin >> n >> m;
	for( int i = 0, u, v, w; i < m; i++ ) {
		cin >> u >> v >> w;
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}
	for( int i = 1; i <= n; i++ ) {
		BFS(i);
		FF(i);
	}
	if( retid ) {
		cout << retid << ' ' << ret << endl;
	} else {
		cout << retid << endl;
	}
	return 0;
}
