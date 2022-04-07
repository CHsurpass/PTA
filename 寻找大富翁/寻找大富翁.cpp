#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define ll long long

int a[N + 5];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    string s, c;
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    m = min(n, m);
    for( int i = 0; i < m; i++ ) {
        cout << a[i];
        if( i != m - 1 ) cout << ' ';
    }
    return 0;
}