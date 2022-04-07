// 一元多项式的乘法与加法运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
#define inf 0x3f3f3f3f
#define ll long long
#define esp 1e-11

char aaa[N];
char bbb[N];
int n;
int uid;
int ff(string s) {
	if (s == "-") {
		uid++;
		return uid;
	}
	int n;
	stringstream ss;
	ss << s; ss >> n; ss.clear();
	return n; 
}
struct node {
	int l, r;
}aat[N], bbt[N];
int heada, headb, head[N];
bool ok;
int maxn;
int Head() {
	for (int i = 0; i < n; i++) {
		if (head[i] == -1)
			return i;
	}
}
void Input(node *at,char *a,int *heads) {
	cin >> n;
	maxn = max(maxn, n);
	string c, l, r;
	uid = 9;
	memset(head, -1, sizeof head);
	for (int i = 0; i < n; i++) {
		cin >> c >> l >> r;
		int idl = ff(l);
		int idr = ff(r);
		head[idl] = i;
		head[idr] = i;
		a[i] = c[0];
		at[i] = { idl,idr };
	}
	*(heads) = Head();
}
bool v = false;
void DFS(int ida, int idb) {
	if (ida >= 10 && idb >= 10 || !ok)
		return;
	//cout << aaa[ida] << ' ' << bbb[idb] << endl;
	if (aaa[ida] != bbb[idb]) {
		v = true;
		if (head[idb] == -1 || aaa[ida] != bbb[bbt[head[idb]].r]) {
			ok = false;
			return;
		}
		swap(bbt[head[idb]].l, bbt[head[idb]].r);
		return;
	}
	DFS(aat[ida].l, bbt[idb].l);
	if (v) {
		v = false;
		DFS(aat[ida].l, bbt[idb].l);
		DFS(aat[ida].r, bbt[idb].r);
		return;
	}
	DFS(aat[ida].r, bbt[idb].r);
}
int main() {
	ok = true;
	Input(aat,aaa,&heada);
	Input(bbt,bbb,&headb);
	if (maxn) {
		DFS(heada, headb);
	}
	cout<<(ok?"Yes":"No");
	return 0;
}