
#include<bits/stdc++.h>
using namespace std;

int n;
char c;
void Print(int space, int len) {
	for (int i = 0; i < space; i++) {
		cout << ' ';
	}
	for (int j = 0; j < len; j++) {
		cout << c;
	}
	cout << endl;
}
int main() {
	cin >> n >> c;
	if (n == 1) {
		cout << c << endl;
		cout << 0 << endl;
		return 0;
	}
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (mid * mid * 2 - 1 < n)
			l = mid + 1;
		else
			r = mid - 1;
	}
	int h = r * 2 - 1;
	int space = -1;
	int len = 1 + r * 2;
	int sum = 0;
	for (int i = 1; i <= h; i++) {
		if (i <= r) {
			space++;
			len -= 2;
		}
		else {
			space--;
			len += 2;
		}
		Print(space, len);
		sum += len;
	}
	cout << n - sum << endl;
	system("pause");
	return 0;
}

