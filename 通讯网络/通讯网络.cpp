#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

struct node {
	int x, y;
}a[N], vis[N][15];
struct edg {
	int u, v;
	ll w;
	bool operator<(const edg a) const {
		return w < a.w;
	}
}E[N];
int n;
int mxx, myy;
int uid;
ll Len(int i, int j) {
	return (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
}
int f[N];
int Find(int x) {
	return x == f[x] ? x : f[x] = Find(f[x]);
}
ll sum;
void Union(int x, int y, ll w) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		f[x] = y;
		sum += w;
	}
}
bool vew[N][15];
int dx[][2] = { 0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1 };
void BFS(int id) {
	queue<node> qu;
	memset(vew, false, sizeof vew);
	while (qu.size())
		qu.pop();
	qu.push(a[id]);
	vew[a[id].x][a[id].y] = true;
	int cnt = 0;
	while (qu.size()) {
		node now = qu.front();
		qu.pop();
		if (cnt >= 50)
			break;
		for (int i = 0; i < 8; i++) {
			int x = now.x + dx[i][0];
			int y = now.y + dx[i][1];
			if (x >= 0 && x <= mxx && y >= 0 && y <= myy) {
				if (vis[x][y].x) {
					int v = vis[x][y].y;
					E[++uid] = { id,v,Len(id,v) };
					cnt++;
				}
				if (vew[x][y] == false) {
					vew[x][y] = true;
					qu.push({ x,y });
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		mxx = max(mxx, x);
		myy = max(myy, y);
		a[i] = { x,y };
		vis[x][y] = { 1,i };
	}
	uid = -1;
	for (int i = 0; i < n; i++) {
		BFS(i);
	}
	sort(E, E + uid + 1);
	for (int i = 0; i < n; i++) {
		f[i] = i;
	}
	for (int i = 0; i <= uid; i++) {
		Union(E[i].u, E[i].v, E[i].w);
	}
	cout << sum << endl;
}