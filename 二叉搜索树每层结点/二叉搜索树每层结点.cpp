
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
void Print(int s, int e) {

}
string s;
typedef struct node {
    int d;
    node* l, * r;
}tree;
node* Insert(int x, node* root) {
    if (root == NULL) {
        node* p = (node*)malloc(sizeof(node));
        p->d = x;
        p->l = p->r = NULL;
        root = p;
        return root;
    }
    if (root->d < x) {
        root->r = Insert(x, root->r);
    }
    else
        root->l = Insert(x, root->l);
    return root;
}
struct nodes {
    node *nd;
    int t;
};
int uid = -1;
void BFS(node* root, int x) {
    queue<nodes>qu;
    qu.push({ root ,0 });
    bool v = false;
    int now = -1;
    while (qu.size()) {
        nodes p = qu.front();
        qu.pop();
        if (p.nd  !=NULL) {
            if (p.t != now) {
                now = p.t;
                v = false;
                if (now)
                    cout << endl;
            }
            if (v)
                cout << ' ';
            v = true;
            cout << p.nd->d;
            qu.push({ p.nd->l,p.t + 1 });
            qu.push({ p.nd->r,p.t + 1 });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    node* root = NULL;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        root = Insert(x, root);
    }
    BFS(root,0);
    return 0;
}
