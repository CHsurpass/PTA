// 数据范围是2e6, 毒瘤题

#include <bits/stdc++.h>
const int N = 6e6 + 5;
using namespace std;
#define inf 0x3f3f3f3f
int a[N];
int n;
int uid;
int read() {
	int X = 0, w = 0; char ch = 0;
	while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
void Input() {
	n = read();
	for (int j = 1; j <= n; j++) {
		a[++uid] = read();
	}
}
void Print() {
	bool v = false;
	int id = 0;
	while (id < uid) {
		if (v) printf(" ");
		v = true;
		printf("%d", a[++id]);
	}
	puts("");
}
int main() {
	Input();
	Input();
	Input();
	sort(a + 1, a + uid + 1);
	Print();
}
