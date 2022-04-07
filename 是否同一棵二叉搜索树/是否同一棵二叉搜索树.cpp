
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
bool ok;
void Insert(int id, int x, int* a) {
	if (a[id] == 0) {
		a[id] = x;
		return;
	}
	if (x <= a[id]) {
		Insert(id << 1, x, a);
	}
	else {
		Insert(id << 1 | 1, x, a);
	}
}
void Input(int *a) {
	for (int i = 0,x; i < n; i++) {
		cin >> x;
		Insert(1,x,a);
	}
}
void DFS(int id,int *a,int *b) {
	if (a[id] == 0||!ok)
		return;
	//cout << a[id] << ' ' << b[id] <<' '<<id<<endl;
	if (a[id] != b[id]) {
		ok = false;
		return;
	}
	DFS(id << 1, a, b);
	DFS(id << 1 | 1, a, b);
}
int main() {
	int L;
	while (cin >> n,n) {
		int a[N] = {0};
		cin >> L;
		Input(a);
		while (L--) {
			int  b[N] = { 0 };
			Input(b);
			ok = true;
			DFS(1,a,b);
			cout << (ok ? "Yes" : "No") << endl;;
		}
	}
	return 0;
}