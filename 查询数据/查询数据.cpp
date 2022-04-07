#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n, m;
int a[100000 + 5];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x;
	sort(a, a + n);
	while (m--) {
		cin >> x;
		int l = 0, r = n;
		bool ok = false;
		while (l <= r) {
			int mid = l + r >> 1;
			if (x > a[mid]) {
				l = mid + 1;
			}
			else {
				if (x == a[mid]) {
					cout << "Yes\n";
					ok = true;
					break;
				}
				r = mid - 1;
			}
		}
		if (!ok) {
			cout << "No\n";
		}
	}
	return 0;
}