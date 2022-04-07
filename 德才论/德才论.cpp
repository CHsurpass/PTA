#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

struct node {
	string id;
	int dfen;
	int cfen;
	int sum;
	int clas;
	bool operator<(const node b) const {
		if (clas != b.clas)
			return clas < b.clas;
		if (sum != b.sum)
			return sum > b.sum;
		if (dfen != b.dfen)
			return dfen > b.dfen;
		return id < b.id;
	}
}a[N];

int n, l, h;
int main() {
	cin >> n >> l >> h;
	string id;
	int dfen;
	int cfen;
	int sum;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> id >> dfen >> cfen;
		///cout << id << '+' << dfen << '+'<<cfen << endl;
		sum = dfen + cfen;
		if (dfen >= h && cfen >= h) {
			a[i] = { id,dfen,cfen,sum,1 };
		}
		else if (dfen >= h && cfen >= l) {
			a[i] = { id,dfen,cfen,sum,2 };
		}
		else if (dfen >= l && cfen >= l && dfen >= cfen) {
			a[i] = { id,dfen,cfen,sum,3 };
		}
		else if (dfen >= l && cfen >= l) {
			a[i] = { id,dfen,cfen,sum,4 };
		}
		else {
			a[i] = { id,dfen,cfen,sum,5 };
			cnt++;
		}
	}

	sort(a, a + n);
	cout << n - cnt << endl;
	for (int i = 0; i < n - cnt; i++) {
		cout << a[i].id << ' ' << a[i].dfen << ' ' << a[i].cfen << endl;
	}
	return 0;
}