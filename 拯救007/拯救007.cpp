
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11


int vis[N];
int dis[N];
int n,m;
double D;
struct node {
    double x,y;
}a[N];
int uid = -1;
bool judge(node now) {
    if (now.x == 0 && now.y == 0) {
        if (now.x - D - 15 +50 <= esp || now.x + D + 15 -50 >= esp || now.y - D - 15 +50 <= esp || now.y + D + 15 -50 >=esp)
            return true;
    }
    if (now.x - D + 50 <= esp || now.x + D - 50 >= esp || now.y - D + 50 <= esp || now.y + D - 50 >= esp)
        return true;
    return false;
}
int vew[N];
bool BFS(double x,double y) {
    queue<node>qu;
    qu.push({x,y});
    double len = inf;
    while(qu.size()) {
        node u = qu.front();
        qu.pop();
        if (judge(u))
            return true;
        for(int i = 0;i < n;i++) {
            if(vis[i]==0) {
                if(u.x==0&&u.y==0) {
                    ///len = sqrt((u.x-a[i].x)*(u.x-a[i].x)+(u.y-a[i].y)*(u.y-a[i].y))-15;
                    len = (u.x-a[i].x)*(u.x-a[i].x)+(u.y-a[i].y)*(u.y-a[i].y)+15*15-sqrt((u.x-a[i].x)*(u.x-a[i].x)+(u.y-a[i].y)*(u.y-a[i].y))*30.0;
                }
                else {
                    ///len =  sqrt((u.x-a[i].x)*(u.x-a[i].x)+(u.y-a[i].y)*(u.y-a[i].y));
                    len =  (u.x-a[i].x)*(u.x-a[i].x)+(u.y-a[i].y)*(u.y-a[i].y);
                }
                if(D*D-len >= esp) {
                    qu.push({a[i].x,a[i].y});
                    if (vew[i])
                        return true;
                    vis[i] = 1;
                }
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);

    cin>>n>>D;
    double x, y;
    bool v = false;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        a[i] = {x,y};
        if (judge(a[i])) {
            vew[i] = 1;
            v = true;
        }
    }
    if (!v) {
        cout << "No\n";
        return 0;
    }
    if(BFS(0,0)){
        cout<<"Yes\n";
    }
    else {
        cout<<"No\n";
    }
    return 0;
}
