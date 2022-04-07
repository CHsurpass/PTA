
#include<bits/stdc++.h>
using namespace std;

struct node {
    int x, y, w;
    bool operator<(const node& a) const {
        return w < a.w;
    }
}a[5000];
int n, m;
int f[5005];
int edg;
int Find(int x) {
    return x == f[x] ? x : f[x] = Find(f[x]);
}
bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if( x != y ) {
        f[x] = y;
        return true;
    }
    return false;
}
int main() {
    for( int i = 0; i < 5005; i++ )
        f[i] = i;
    cin >> n >> m;
    for( int i = 0, x, y, w; i < m; i++ ) {
        cin >> x >> y >> w;
        a[i] = { x,y,w };
    }
    sort(a, a + m);
    int sum = 0;
    for( int i = 0, x, y, w; i < m; i++ ) {
        x = a[i].x;
        y = a[i].y;
        w = a[i].w;
        if( Union(x, y) ) {
            sum += w;
            edg++;
        }
    }
    if( edg != n - 1 )
        cout << -1 << endl;
    else
        cout << sum << endl;
}
