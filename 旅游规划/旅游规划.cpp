// 旅游规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e3 + 5;
#define inf 0x3f3f3f3f

int n, m, S, D;
struct node {
	int v, len, w;
};
vector<node>G[N];
int ret, retid;
int dis[N];
int len[N];
void BFS(int u) {
	queue<int>qu;
	qu.push(u);
	int vis[N] = { 0 };
	vis[u] = 1;
	memset(dis, inf, sizeof dis);
	memset(len, inf, sizeof len);
	dis[u] = 0;
	len[u] = 0;
	while( qu.size() ) {
		u = qu.front();
		qu.pop();
		vis[u] = 0;
		for( int i = 0; i < G[u].size(); i++ ) {
			int v = G[u][i].v;
			int lens = G[u][i].len;
			int w = G[u][i].w;
			if( len[u] + lens < len[v] ) {
				len[v] = len[u] + lens;
				dis[v] = dis[u] + w;
				if( vis[v] == 0 ) {
					vis[v] = 1;
					qu.push(v);
				}
			} else if( len[u] + lens == len[v] ) {
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
}
int main() {
	ret = inf;
	retid = 0;
	cin >> n >> m >> S >> D;
	for( int i = 0, u, v, w, l; i < m; i++ ) {
		cin >> u >> v >> l >> w;
		G[u].push_back({ v,l,w });
		G[v].push_back({ u,l,w });
	}
	BFS(S);
	cout << len[D] << ' ' << dis[D] << endl;
	return 0;
}

