#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
#define inf 0x3f3f3f3f

ll a[N];
ll n, m;
int read() {
    int X = 0, w = 0; char ch = 0;
    while( !isdigit(ch) ) { w |= ch == '-'; ch = getchar(); }
    while( isdigit(ch) ) X = ( X << 3 ) + ( X << 1 ) + ( ch ^ 48 ), ch = getchar();
    return w ? -X : X;
}
void write(int x) {
    if( x < 0 ) putchar('-'), x = -x;
    if( x > 9 ) write(x / 10);
    putchar(x % 10 + '0');
}
int du[N];
int f[N];
int Find(int x) {
    return f[x] == x ? f[x] : f[x] = Find(f[x]);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if( x != y ) {
        f[x] = y;
    }
}
string s, c;
map<string, int>mp;
int main() {
    n = read();
    for( int i = 1, u, v, w; i <= n; i++ ) {
        cin >> s >> c;
        mp[s]++;
        mp[c]++;
    }
    ll mxx = 0;
    ll ret = 0;
    map<string, int>::iterator it = mp.begin();
    for( it; it != mp.end(); it++ ) {
        if( mxx < it->second ) {
            mxx = it->second;
            s = it->first;
        }
    }
    for( it = mp.begin(); it != mp.end(); it++ ) {
        if( mxx == it->second ) {
            ret++;
        }
    }
    cout << s << ' ' << mxx;
    if( ret > 1 )
        cout << ' ' << ret << endl;
    return 0;
}


