#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
int a[N];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	map<int, int>mp;
	for (int i = 0,x; i < n; i++) {
		cin >> x;
		a[i] = x;
		mp[x]++;
	} 
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(mp[a[i]], ret);
	}
	cout << n - ret << endl;
}