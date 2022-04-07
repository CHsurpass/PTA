#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int main() {
	int a, b;
	cin >> a >> b;
	int cnt = b - a;
	cnt = cnt / 100.0 + 0.5;
	printf("%02d:%02d:%02d\n", cnt / 3600, (cnt - cnt / 3660 * 3600) / 60, cnt % 60);
}