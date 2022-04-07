#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
int main() {
	cin >> n;
	int sum = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		sum += x;
	}
	if (sum == 21) {
		cout << "Yes\n";
	}
	else if (sum < 21 && 21-sum <= 5) {
		cout << "Just so so " << 21 - sum << endl;
	}
	else {
		cout << "No " << abs(21 - sum) << endl;
	}
}