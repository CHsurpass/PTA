
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e3 + 5;
#define inf 0x3f3f3f3f

int n, m;
vector<int>a;
void Input() {
	for( int i = 0, x; i < n; i++ ) {
		cin >> x;
		a.push_back(x);
	}
}
int main() {
	cin >> n;
	Input();
	Input();
	sort(a.begin(), a.end());
	cout << a[a.size() / 2 - 1] << endl;
	return 0;
}

