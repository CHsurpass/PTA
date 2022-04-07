#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
int vis[15];
int G[15][15];
int ret = inf;
void DFS(int id, int sum, int cnt) {
	if (cnt == n) {
		ret = min(ret, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			DFS(i, sum + G[id][i], cnt + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0,x; j <= n; j++) {
			cin >> x;
			G[i][j] = x;
		}
	}
	DFS(0, 0, 0);
	cout << ret << endl;
}