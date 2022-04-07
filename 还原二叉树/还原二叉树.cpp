// 还原二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

int n;
string pre, ins;
int tree[N];
int uid;
void Build(int id,int st,int en) {
	for (int i = st; i < en; i++) {
		if (pre[uid] == ins[i]) {
			tree[id] = int(pre[uid]);
			uid++;
			Build(id << 1, st, i); 
			Build(id << 1 | 1, i+1, en);
		}
	}
}
void dFS(int id, int h) {
	if (tree[id]) {
		dFS(id << 1, h + 1),
		dFS(id << 1 | 1, h + 1);
		cout << char(tree[id]);
	}
	return;
}
int DFS(int id,int h) {
	if (tree[id]) {
		return max(DFS(id << 1, h + 1), DFS(id << 1 | 1, h + 1));
	}
	return h;
}
int main() {
	cin >> n >> pre >> ins;
	Build(1,0,n);
	cout << DFS(1, 0) << endl;
	return 0;
}