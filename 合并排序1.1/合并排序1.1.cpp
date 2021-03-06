//数据范围是2e6,毒瘤题

#include <bits/stdc++.h>
const int N = 2e6 + 5;
const int MANX = 4e6 + 5;
using namespace std;
#define inf 0x3f3f3f3f
int a[N], b[N], c[N], ret[MANX];
int n;
int uid;
int read() {
	int X = 0, w = 0; char ch = 0;
	while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
void Input(int* a) {
	n = read();
	for (int j = 1; j <= n; j++) {
		a[j] = read();
	}
}
void Sort(int* a, int* b, int* c, int* ret) {
	int aid, bid, cid;
	aid = bid = cid = 1;
	while (1) {
		int mii = min(min(a[aid], b[bid]), c[cid]);
		if (mii == inf)
			break;
		if (mii == a[aid]) {
			ret[++uid] = mii;
			aid++;
		}
		if (mii == b[bid]) {
			ret[++uid] = mii;
			bid++;
		}
		if (mii == c[cid]) {
			ret[++uid] = mii;
			cid++;
		}
	}
	return;
}
void Print(int* ret) {
	bool v = false;
	int id = 0;
	while (id<uid) {
		if (v) printf(" ");
		v = true;
		printf("%d", ret[++id]);
	}
	puts("");
}
int main() {
	memset(a, inf, sizeof a);
	memset(b, inf, sizeof b);
	memset(c, inf, sizeof c);
	Input(a);
	Input(b);
	Input(c);
	Sort(a, b, c, ret);
	Print(ret);
}
