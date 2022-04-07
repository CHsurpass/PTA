// Have Fun with Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

string s;
int main() {
	cin >> s;
	string ret = "";
	int f = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		int n = s[i] - '0';
		n <<= 1;
		n += f;
		f = 0;
		if (n >= 10) {
			f = n / 10;
			n %= 10;
		}
		ret += n + '0';
	}
	if (f) {
		ret += f + '0';
	}
	reverse(ret.begin(), ret.end());
	string str = ret;
	sort(str.begin(), str.end());
	sort(s.begin(), s.end());
	cout << (s == str?"Yes\n":"No\n");
	cout << ret << endl;
}
