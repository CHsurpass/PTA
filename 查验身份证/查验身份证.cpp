#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
string s;
string val = "10X98765432";
int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
int main() {
	cin >> n;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int sum = 0;
		bool v = true;
		for (int j = 0; j < 17; j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				sum += (s[j] - '0')*w[j];
			}
			else {
				v = false;
				break;
			}
		}
		if (v&&val[sum%11]==s[17]) {
			continue;
		}
		ok = false;
		cout << s << endl;
	}
	if (ok)
		cout << "All passed\n";
	return 0;
}